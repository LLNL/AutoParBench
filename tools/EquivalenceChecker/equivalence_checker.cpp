//******************************************************************************************************************//
// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
// and Federal University of Minas Gerais
// SPDX-License-Identifier: (BSD-3-Clause)
//*****************************************************************************************************************//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

#include "equivalence_checker.h"

using namespace std;

std::string JSONParser::replace_all(std::string str, std::string from, std::string to) {
  int pos = 0;
  while((pos = str.find(from, pos)) != std::string::npos) {
    str.replace(pos, from.length(), to);
    pos = pos + to.length();
  }
  return str;
}

void JSONParser::cleanStr(std::string & desc) {
  if (desc.size() < 3)
    return;
  desc.erase(desc.begin(), desc.begin() + 2);
  desc.erase(desc.end() - 3, desc.end()); 
}

void JSONParser::extractSTRINGObject(std::string & desc, std::string & str) {
  if (desc[0] == '\"') {
    int i = 1;
    for (int ie = desc.size(); i != ie;i++) {
      if (desc[i] == '\\') {
	i++;
	str = str + desc[i];
	continue;
      }
      if (desc[i] == '\"') {
      	break;
      }
      str = str + desc[i];
    }
    desc.erase(desc.begin(), desc.begin() + i + 1);
  }
}

void JSONParser::extractCLASSObject(std::string & desc, std::string & str) {
   if (desc[0] == '{') {
    int posEnd = desc.find("\n},\n");
    int endSize = 4;
    if (posEnd == std::string::npos) {
      posEnd = desc.find("\n}\n");
      endSize = 3;
    }
    for (int i = 1; i < posEnd; i++)
      str += desc[i];
    str = replace_all(str,"\n","");
    desc.erase(desc.begin(), desc.begin() + posEnd + endSize);
  }
}

void JSONParser::createVectorToARRAYObj(std::string & desc, std::vector<std::string> & obj, bool recover_op,  std::vector<std::string> & ops) {
  std::string info = std::string();
  if (desc == std::string())
    return;
  do {
    std::size_t nextV = desc.find(",");
    if (nextV == std::string::npos)
      break;
    info = std::string();
    for (int i = 0;(i < ((desc.size() < nextV) ? desc.size() : nextV)); i++)
      info += desc[i];
    // HERE
    if (recover_op) {
      std::string op;
      extractReductionOperator(info, op);
      ops.push_back(op);
    }
    obj.push_back(info);
    desc.erase(desc.begin(), desc.begin() + nextV + 1);
 
  } while(true);
}

void JSONParser::extractARRAYObject(std::string & desc, std::string & str) {
  if (desc[0] == '[') {
    desc.erase(desc.begin(), desc.begin() + 1);
    while (true) {
      std::string obj = std::string();
      extractSTRINGObject(desc, obj);
      str += obj + ",";
      if (desc[0] == ']')
	break;
      desc.erase(desc.begin(), desc.begin() + 1);
    }
    desc.erase(desc.begin(), desc.begin() + 1);
  }
}

void JSONParser::extractObject(std::string & desc, std::string & name, std::string & obj) {
  if (desc[0] == '\"') {
    extractSTRINGObject(desc, name);
    desc.erase(desc.begin(), desc.begin() + 1);
  }
  if (desc[0] == '\"') {
    extractSTRINGObject(desc, obj);
  }
  else if (desc[0] == '{') {
    extractCLASSObject(desc, obj);
  }
  else if (desc[0] == '[') {
    extractARRAYObject(desc, obj);
  }
  if (desc[0] == ',') {
    desc.erase(desc.begin(), desc.begin() + 1);
  }
}

void JSONParser::insertField(parallel_loop *data, std::string name, std::string obj) {
  if (name == "file") {
    data->filename = obj;
  }
  if (name == "loop id") {
    data->loop_id = std::stoi(obj);
  }
  if (name == "function") {
    data->loop_function = obj;
  }
  else if (name == "loop line") {
    data->loop_line = std::stoi(obj);
  }
  else if (name == "loop column") {
    data->loop_column = std::stoi(obj);
  }
  else if (name == "ordered") {
    data->ordered = (obj=="true");
  }
  else if (name == "offload") {
    data->offload = (obj=="true");
  }
  else if (name == "multiversioned") {
    data->multiversioned = (obj=="true");
  }
  else if (name == "induction variable") {
    data->induction_variable = obj;
  }
  else if (name == "pragma type") {
    data->pragma_type = obj;
  }
  else if (name == "private") {
    createVectorToARRAYObj(obj, data->private_prag, false, data->private_prag);
  }
  else if (name == "firstprivate") {
    createVectorToARRAYObj(obj, data->first_private_prag, false, data->first_private_prag);
  }
  else if (name == "lastprivate") {
    createVectorToARRAYObj(obj, data->last_private_prag, false, data->last_private_prag);
  }
  else if (name == "linear") {
    createVectorToARRAYObj(obj, data->linear_prag, false, data->linear_prag);
  }
  else if (name == "reduction") {
    createVectorToARRAYObj(obj, data->reduction_prag, true, data->reduction_prag_op);
  }
  else if (name == "map to") {
    createVectorToARRAYObj(obj, data->map_to, false, data->map_to);
  }
  else if (name == "map from") {
    createVectorToARRAYObj(obj, data->map_from, false, data->map_from);
  }
  else if (name == "map tofrom") {
    createVectorToARRAYObj(obj, data->map_tofrom, false, data->map_tofrom);
  }
  else if (name == "dependence list") {
    createVectorToARRAYObj(obj, data->dependence_list, false, data->dependence_list);
  }
}

void JSONParser::normalizeCompoundAssignmentOperator(std::string op, std::string & desc) {
  std::string opNormalized = op + "=";
  std::string reduction_clause = std::string();

  if (desc.find(opNormalized, 0) != std::string::npos) {
    for (int i = 0, ie = desc.find(opNormalized, 0); i != ie; i++)
      reduction_clause += desc[i]; 

    reduction_clause = reduction_clause + "=" + reduction_clause + op;

    for (int i = desc.find(opNormalized, 0) + op.size() + 1, ie = desc.size(); i != ie; i++)
      reduction_clause += desc[i];

    desc = reduction_clause;
  }
}

bool JSONParser::containsCompoundAssignmentOperator(std::string & desc) {
  if ((desc.find("+=", 0) != std::string::npos) ||
      (desc.find("-=", 0) != std::string::npos) ||
      (desc.find("*=", 0) != std::string::npos) ||
      (desc.find("/=", 0) != std::string::npos) ||
      (desc.find("%=", 0) != std::string::npos) ||
      (desc.find("&=", 0) != std::string::npos) ||
      (desc.find("|=", 0) != std::string::npos) ||
      (desc.find("^=", 0) != std::string::npos) ||
      (desc.find(">>=", 0) != std::string::npos) ||
      (desc.find("<<=", 0) != std::string::npos))
    return true;
  return false;
}

bool JSONParser::normalizeExpression(std::string & desc) {
  desc = replace_all(desc," ","");
  desc = replace_all(desc,"\t","");
  desc = replace_all(desc,"\n","");

  while (containsCompoundAssignmentOperator(desc)) {
    normalizeCompoundAssignmentOperator("+", desc);
    normalizeCompoundAssignmentOperator("-", desc);
    normalizeCompoundAssignmentOperator("*", desc);
    normalizeCompoundAssignmentOperator("/", desc);
    normalizeCompoundAssignmentOperator("%", desc);
    normalizeCompoundAssignmentOperator("&", desc);
    normalizeCompoundAssignmentOperator("|", desc);
    normalizeCompoundAssignmentOperator("^", desc);
    normalizeCompoundAssignmentOperator("<<", desc);
    normalizeCompoundAssignmentOperator(">>", desc);
  }
  return true;
}

void JSONParser::processGenericObject(std::string & objName, std::string & desc, bool fileType) {
  generic_obj data;
  std::string name = std::string();
  std::string obj = std::string();
 
  for (extractObject(desc, name, obj); (name != std::string()); extractObject(desc, name, obj)) {
    if (name == "pragma type")
      data.pragma_type = obj;
    else if (name == "file")
      data.filename = obj;
    else if (name == "function") 
      data.function_name = obj;
    else if (name == "loop id") 
      data.loop_id = std::stoi(obj);
    else if (name == "statement id")
      data.instruction_id = std::stoi(obj);

    name = std::string();
    obj = std::string();
  }

  if (fileType == true) {
    reference_objs[objName] = data;
  }
  else {
    tool_objs[objName] = data;
  }
}

bool JSONParser::representSameDirective(std::string & pragma_ref, std::string & pragma_tool) {
  if ((pragma_ref.find("atomic",0) != std::string::npos) &&
      (pragma_tool.find("atomic",0) != std::string::npos))
    return true;
  if (pragma_ref != pragma_tool) {
    return false;
  }
  return true;
}

bool JSONParser::areObjectsEquivalent(std::string & objRef, std::string & objTool) {
  // atomic directives are normalized and represented as reduction
  // So, some of them are not checked there.
  if (reference_objs[objRef].filename != tool_objs[objTool].filename) {
    return false;
  }
  if (reference_objs[objRef].function_name != tool_objs[objTool].function_name) {
    return false;
  }
  if (reference_objs[objRef].loop_id != tool_objs[objTool].loop_id) {
    return false;
  }
  if (reference_objs[objRef].instruction_id != tool_objs[objTool].instruction_id) {
    return false;
  }
  if (!representSameDirective(reference_objs[objRef].pragma_type, tool_objs[objTool].pragma_type)) {
    return false;
  }
  return true;
}

bool JSONParser::areObjectsEquivalent(std::vector<std::string> & vectRef, std::vector<std::string> & vectTool) {
  std::map<std::string, bool> mapRef;
  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    mapRef[vectRef[i]] = false;
  }
  
  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    for (int j = 0, je = vectTool.size(); j != je; j++) {
      if (areObjectsEquivalent(vectRef[i], vectTool[j])) {
        mapRef[vectRef[i]] = true;
	break;
      }
    }
  }

  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    if (mapRef[vectRef[i]] == false) {
      return false;
    }
  }

  return true;
}

void JSONParser::processParallelLoop(std::string & desc, bool fileType) {
  parallel_loop data;
  data.induction_variable = std::string();
  std::string name = std::string();
  std::string obj = std::string();

  for (extractObject(desc, name, obj); (name != std::string()); extractObject(desc, name, obj)) {
    insertField(&data, name, obj);
    name = std::string();
    obj = std::string();
  }
  if (fileType == true) {
    if (data.filename == std::string()) {
      cout << "BUG THERE!\n";
    }
    reference[std::make_pair(data.filename, std::make_pair(data.loop_function,data.loop_id))] = data;
  }
  else {
    tool[std::make_pair(data.filename, std::make_pair(data.loop_function,data.loop_id))] = data;
  }
}

void JSONParser::readEquivalenceClasses(std::string filename) {
  std::string line = std::string();
  std::string info = std::string();
  std::ifstream file(filename);
  if (file.is_open()) {
    while (getline(file, line)) {
	info = info + line;
    }
    file.close();
  }
  cleanStr(info);
  std::string name = std::string();
  std::string obj = std::string();

  for (extractObject(info, name, obj); (name != std::string()); extractObject(info, name, obj)) {
    std::vector<std::string> omp_class;
    createVectorToARRAYObj(obj, omp_class, false, omp_class);
    for (int i = 0, ie = omp_class.size(); i != ie; i++) {
      equivalent_classes[omp_class[i]] = name;
    }
    name = std::string();
    obj = std::string();
  }
}

void JSONParser::readFile(std::string filename, bool fileType) {
  std::string line = std::string();
  std::string info = std::string();
  std::ifstream file(filename);
  if (file.is_open()) {
    while (getline(file, line)) {
      info = info + line + "\n";
    }
    file.close();
  }
  cleanStr(info);
  info += ",\n";
  if (info.size() < 2)
    return;
  std::string name = std::string();
  std::string obj = std::string();

  for (extractObject(info, name, obj); (name != std::string()); extractObject(info, name, obj)) {
    if (name.find("loop - object id : ") != std::string::npos)
      processParallelLoop(obj, fileType);
    else
      processGenericObject(name, obj, fileType);
    name = std::string();
    obj = std::string();
  }
}

std::string JSONParser::getEquivalentAtTargetContext(std::string prag, bool offload) {
  if (offload == false)
    return prag;
  if (prag == "parallel for")
    return "target parallel for";
  if (prag == "parallel for simd")
    return "target parallel for simd";
  if (prag == "distribute parallel for")
    return "target teams distribute parallel for";
  if (prag == "distribute parallel for simd")
    return "target teams distribute parallel for simd";
  if (prag == "distribute simd")
    return "target teams distribute simd";
  return std::string();
}

bool JSONParser::isEquivalent(std::string prag1, std::string prag2) {
  return (equivalent_classes[prag1] == equivalent_classes[prag2]);
}

void JSONParser::appendVector(std::vector<std::string> & dest, std::vector<std::string> & src) {
  for (int i = 0, ie = src.size(); i != ie; i++) {
    dest.push_back(src[i]);
  }
}

// To compare two vectors, we need at least the same attributes as present in the reference.
// We consider valid if the tool inserts more clauses.
bool JSONParser::equivalentVectors(std::vector<std::string> & vectRef, std::vector<std::string> & vectTool) {
  std::map<std::string, bool> mapRef;
  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    mapRef[vectRef[i]] = false;
  }
  for (int i = 0, ie = vectTool.size(); i != ie; i++) {
    if (mapRef.count(vectTool[i]) > 0)
      mapRef[vectTool[i]] = true;
  }
  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    if (mapRef[vectRef[i]] == false)
      return false;
  }
  return true;
}

bool JSONParser::equivalentReductions(std::vector<std::string> & vectRef, std::vector<std::string> & vectRef_ops, std::vector<std::string> & vectTool, std::vector<std::string> & vectTool_ops) {
  std::map<std::string, bool> mapRef;
  std::map<std::string, std::string> mapRef_ops;
  std::map<std::string, std::string> mapTool_ops;
  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    mapRef[vectRef[i]] = false;
    mapRef_ops[vectRef[i]] = vectRef_ops[i];
  }
  for (int i = 0, ie = vectTool.size(); i != ie; i++) {
    mapTool_ops[vectTool[i]] = vectTool_ops[i];
    if (mapRef.count(vectTool[i]) > 0)
      mapRef[vectTool[i]] = true;
  }
  for (int i = 0, ie = vectRef.size(); i != ie; i++) {
    if (mapRef[vectRef[i]] == false)
      return false;
    // Denoting equivalent implicit operators:
    if (mapRef_ops[vectRef[i]] == "none" ||
        mapTool_ops[vectTool[i]] == "none" ||
	mapRef_ops[vectRef[i]] == mapTool_ops[vectTool[i]] ||
	((mapRef_ops[vectRef[i]] == "+") && (mapTool_ops[vectTool[i]] == "-")) ||
	((mapRef_ops[vectRef[i]] == "+") && (mapTool_ops[vectTool[i]] == "-")))
      continue;
    return false;
  }
  return true;
}


void JSONParser::extractReductionOperator(std::string & clause, std::string & op) {
  op = "none";
  if (clause.find(":") != std::string::npos) {
    op = clause[0];
    clause.erase(clause.begin(), clause.begin() + 2);
  }
}

void JSONParser::classify(parallel_loop *refData, parallel_loop *toolData) {
  if ((refData->filename != toolData->filename) ||
      (refData->loop_id != toolData->loop_id) ||
      (refData->loop_function != toolData->loop_function)) {
    return;
  }
  
  // Consider Implicit OpenMP Rules:
  if (toolData->induction_variable != std::string())
    if (std::find(toolData->private_prag.begin(), toolData->private_prag.end(), toolData->induction_variable) == toolData->private_prag.end())
      toolData->private_prag.push_back(toolData->induction_variable); 

  std::string more_info = std::string();
  std::string ground_truth = std::string();
  if (detailed == true) {
    more_info = std::to_string(refData->loop_line) + " | ";
    ground_truth = " | " + std::string(((refData->pragma_type != "NULL") ? "YES" : "NO"));
  }

  // Is not possible to compare lines and/or columns, they will depend of the tool.
  // Checking the pragma type:
  if ((refData->pragma_type == "NULL") &&
      ((toolData->pragma_type == "NULL") || (toolData->multiversioned == true))) {
    cout << more_info + "TN" + ground_truth + "\n";
    return;
  }

  if ((refData->pragma_type == "NULL") && (toolData->pragma_type != "NULL")) {
    cout << more_info + "FP" + ground_truth + "\n";
    return;
  }

  if ((refData->pragma_type != "NULL") && (toolData->pragma_type == "NULL")) {
    cout << more_info + "FN" + ground_truth + "\n";
    return;
  }

  // Check if the pragmas are equivalent
  if (!isEquivalent(getEquivalentAtTargetContext(refData->pragma_type, refData->offload),
      getEquivalentAtTargetContext(toolData->pragma_type, toolData->offload))) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check the ordered attribute: it need to be the same for both versions:
  if (refData->ordered != toolData->ordered) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // We do not consider shared clause to validate the results: It is default.

  // Check if the private clauses are equivalent.
  // We need do consider valid if the tool mark as first or last private a
  // private variable.
  //appendVector(toolData->private_prag, toolData->first_private_prag);
  //appendVector(toolData->private_prag, toolData->last_private_prag);
  if (!equivalentVectors(refData->private_prag, toolData->private_prag)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the first private clauses are equivalent.
  if (!equivalentVectors(refData->first_private_prag, toolData->first_private_prag)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the last private clauses are equivalent.
  if (!equivalentVectors(refData->last_private_prag, toolData->last_private_prag)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the linear private clauses are equivalent.
  if (!equivalentVectors(refData->linear_prag, toolData->linear_prag)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the reduction clauses are equivalent.
  if (!equivalentReductions(refData->reduction_prag, refData->reduction_prag_op, toolData->reduction_prag, toolData->reduction_prag_op)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the map:to clauses are equivalent.
  appendVector(toolData->map_to, toolData->map_tofrom);
  if (!equivalentVectors(refData->map_to, toolData->map_to)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the map:from clauses are equivalent.
  appendVector(toolData->map_from, toolData->map_tofrom);
  if (!equivalentVectors(refData->map_from, toolData->map_from)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the map:tofrom clauses are equivalent.
  if (!equivalentVectors(refData->map_tofrom, toolData->map_tofrom)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Check if the objects are equivalent
  if (!areObjectsEquivalent(refData->dependence_list, toolData->dependence_list)) {
    cout << more_info + "DP" + ground_truth + "\n";
    return;
  }

  // Valid pragmas:
  cout << more_info + "TP" + ground_truth + "\n";
}

void JSONParser::classify() {
  for (std::map<std::pair<std::string,std::pair<std::string,int> >, parallel_loop>::iterator IT = reference.begin(), ITE = reference.end(); IT != ITE; IT++) {
    if (IT->first.first == std::string())
      continue;
    if (tool.count(IT->first) == 0) {
      cout << "N/A\n";
      continue;
    }
    classify(&reference[IT->first], &tool[IT->first]);
  }
}

void JSONParser::printVectDiffs(std::vector<std::string> refData, std::vector<std::string> toolData) {
  cout << "Variables in the Reference list are :\n";
  for (int i = 0, ie = refData.size(); i < ie; i++) {
    cout << "( " << refData[i] << " )";
    if (i != (ie - 1))
      cout << ",";
  }
  cout << "\nVariables in the Tool list are :\n";
  for (int i = 0, ie = toolData.size(); i < ie; i++) {
    cout << "( " << toolData[i] << " )";
    if (i != (ie - 1))
      cout << ",";
  }
  cout << "\n";
}

void JSONParser::printVectDiffs(std::vector<std::string> refData, std::vector<std::string> refData_ops, std::vector<std::string> toolData, std::vector<std::string> toolData_ops) {
  cout << "Variables in the Reference list are :\n";
  for (int i = 0, ie = refData.size(); i < ie; i++) {
    if (refData_ops[i] == "none")
      cout << "( " << refData[i] << " )";
    else
      cout << "( " << refData_ops[i] << ":" << refData[i] << " )";
    if (i != (ie - 1))
      cout << ",";
  }
  cout << "\nVariables in the Tool list are :\n";
  for (int i = 0, ie = toolData.size(); i < ie; i++) {
    if (toolData[i] == "none")
      cout << "( " << toolData[i] << " )";
    else
      cout << "( " << toolData_ops[i] << ":" << toolData[i] << " )";
    if (i != (ie - 1))
      cout << ",";
  }
  cout << "\n";
}


void JSONParser::debug_classification(parallel_loop *refData, parallel_loop *toolData) {
  if ((refData->filename != toolData->filename) ||
      (refData->loop_id != toolData->loop_id) ||
      (refData->loop_function != toolData->loop_function)) {
    cout << "Compared json objects did not represent the same loop:";
    cout << " - REFERENCE FILE : " << refData->filename << " TOOL FILE : " << toolData->filename << "\n";
    cout << " - REFERENCE FUNCTION : " << refData->loop_function << " TOOL FUNCTION : " << toolData->loop_function << "\n";
    cout << " - REFERENCE LOOP RELATIVE POSITION : " << refData->loop_id << " TOOL LOOP RELATIVE POSITION : " << toolData->loop_id << "\n";
    cout << " - REFERENCE LOOP LINE : " << refData->loop_line << " TOOL LOOP LINE : " << toolData->loop_line << "\n";
    cout << " - REFERENCE LOOP COLUMN : " << refData->loop_column << " TOOL LOOP COLUMN : " << toolData->loop_column << "\n";

    return;
  }

  cout << " - REFERENCE FILE : " << refData->filename << "\n";
  cout << " - REFERENCE FUNCTION : " << refData->loop_function << "\n";
  cout << " - REFERENCE LOOP RELATIVE POSITION : " << refData->loop_id << "\n";
  cout << " - REFERENCE LOOP LINE : " << refData->loop_line << " TOOL LOOP LINE : " << toolData->loop_line << "\n";
  cout << " - REFERENCE LOOP COLUMN : " << refData->loop_column << " TOOL LOOP COLUMN : " << toolData->loop_column << "\n";

  // Is not possible to compare lines and/or columns, they will depend of the tool.
  // Checking the pragma type:
  if ((refData->pragma_type == "NULL") &&
      ((toolData->pragma_type == "NULL") || (toolData->multiversioned == true))) {
    cout << "TN - Both JSON represents sequential loops.\n";
    return;
  }

  if ((refData->pragma_type == "NULL") && (toolData->pragma_type != "NULL")) {
    cout << "FP - The tool parallelizes a loop that is not parallel in the reference.\n";
    return;
  }

  if ((refData->pragma_type != "NULL") && (toolData->pragma_type == "NULL")) {
    cout << "FN - The tool is not able to parallelize a loop that is parallel in the reference.\n";
    return;
  }

  // Check if the pragmas are equivalent
  if (!isEquivalent(getEquivalentAtTargetContext(refData->pragma_type, refData->offload),
      getEquivalentAtTargetContext(toolData->pragma_type, toolData->offload))) {
    cout << " - Directives are not equivalent\n";
    cout << "   - Reference pragma : " << refData->pragma_type << " Tool pragma : " << toolData->pragma_type << "\n";
    if (refData->offload != toolData->offload) {
      cout << "   - Reference offload context : ";
      cout << (refData->offload ? "true" : "false") << " ";
      cout << "Tool offload context : ";
      cout << (toolData->offload ? "true" : "false");
    }
  }

  // Check the ordered attribute: it need to be the same for both versions:
  if (refData->ordered != toolData->ordered) {
    cout << "Ordered clauses are different:\n";
    cout << "Reference ordered clause is " << (refData->ordered ? "true" : "false") << " ";
    cout << "Tool ordered clause is " << (toolData->ordered ? "true" : "false") << " ";
  }

  // We do not consider shared clause to validate the results: It is default.

  // Check if the private clauses are equivalent.
  // We need do consider valid if the tool mark as first or last private a
  // private variable.
  if (!equivalentVectors(refData->private_prag, toolData->private_prag)) {
    cout << "Private clauses are not equivalent. This report consider firstprivate and lastprivate\n";
    cout << "equivalent to private, to validade correctly unecessary copies:\n";
    printVectDiffs(refData->private_prag, toolData->private_prag);    
  }

  // Check if the first private clauses are equivalent.
  if (!equivalentVectors(refData->first_private_prag, toolData->first_private_prag)) {
    cout << "Firstprivate clauses are not equivalent:\n";
    printVectDiffs(refData->first_private_prag, toolData->first_private_prag);    
  }

  // Check if the last private clauses are equivalent.
  if (!equivalentVectors(refData->last_private_prag, toolData->last_private_prag)) {
    cout << "Lastprivate clauses are not equivalent:\n";
    printVectDiffs(refData->last_private_prag, toolData->last_private_prag);     
  }

  // Check if the linear private clauses are equivalent.
  if (!equivalentVectors(refData->linear_prag, toolData->linear_prag)) {
    cout << "Linear clauses are not equivalent:\n";
    printVectDiffs(refData->linear_prag, toolData->linear_prag);      
  }

  // Check if the reduction clauses are equivalent.
  if (!equivalentReductions(refData->reduction_prag, refData->reduction_prag_op, toolData->reduction_prag, toolData->reduction_prag_op)) {
    cout << "Reduction clauses are not equivalent:\n";
    printVectDiffs(refData->reduction_prag, refData->reduction_prag_op, toolData->reduction_prag, toolData->reduction_prag_op); 
  }

  // Check if the map:to clauses are equivalent.
  appendVector(toolData->map_to, toolData->map_tofrom);
  if (!equivalentVectors(refData->map_to, toolData->map_to)) {
    cout << "Map to clauses are not equivalent:\n";
    printVectDiffs(refData->map_to, toolData->map_to);

  }

  // Check if the map:from clauses are equivalent.
  appendVector(toolData->map_from, toolData->map_from);
  if (!equivalentVectors(refData->map_from, toolData->map_from)) {
    cout << "Map from clauses are not equivalent:\n";
    printVectDiffs(refData->map_from, toolData->map_from);
  }

  // Check if the map:tofrom clauses are equivalent.
  if (!equivalentVectors(refData->map_tofrom, toolData->map_tofrom)) {
    cout << "Map tofrom clauses are not equivalent:\n";
    printVectDiffs(refData->map_tofrom, toolData->map_tofrom);
  }

  // Check if the objects are equivalent
  if (!areObjectsEquivalent(refData->dependence_list, toolData->dependence_list)) {
    cout << "Dependence directives are not equivalent:\n";
    printVectDiffs(refData->map_tofrom, toolData->map_tofrom);
  }
}

void JSONParser::debug_classification() {
    for (std::map<std::pair<std::string,std::pair<std::string,int> >, parallel_loop>::iterator IT = reference.begin(), ITE = reference.end(); IT != ITE; IT++) {
    if (IT->first.first == std::string())
      continue;
    if (tool.count(IT->first) == 0) {
      cout << "N/A -> Loop not found (Please, make sure that optimizations did not remove the loop)!\n";
      continue;
    }
    classify(&reference[IT->first], &tool[IT->first]);
    debug_classification(&reference[IT->first], &tool[IT->first]);
    cout << "===============================================================================\n";
  }
}

std::string JSONParser::writeGenericObj(generic_obj *data, std::vector<std::string> & depList) {
  std::string obj = std::string();
  obj += "\"" + data->pragma_type + " " + std::to_string(++unique_obj_id) + "\":{\n";
  depList.push_back(data->pragma_type + " " + std::to_string(unique_obj_id));
  obj += "\"pragma type\":\"" + data->pragma_type + "\",\n";
  obj += "\"file\":\"" + data->filename + "\",\n";
  obj += "\"function\":\"" + data->function_name + "\",\n";
  obj += "\"loop id\":\"" + std::to_string(data->loop_id) + "\",\n";
  obj += "\"statement id\":\"" + std::to_string(data->instruction_id) + "\",\n";
  obj += "\"snippet line\":\"0\",\n";
  obj += "\"snippet column\":\"0\"\n";
  obj += "},\n"; 
  return obj;
}

std::string JSONParser::writeArrayObj(std::vector<std::string> vct, std::vector<std::string> vct_op) {
  std::string obj = std::string();
  for (int i = 0, ie = vct.size(); i != ie; i++) {
    if (vct_op[i] != "none")
      obj += "\"" + vct_op[i] + ":" + vct[i] + "\"";
    else 
      obj += "\"" + vct[i] + "\"";
    if (i != (ie - 1))
      obj += ",";
  }
  return obj;
}

std::string JSONParser::writeArrayObj(std::vector<std::string> vct) {
  std::string obj = std::string();
  for (int i = 0, ie = vct.size(); i != ie; i++) {
    if (vct[i] == "")
      continue;
    obj += "\"" + vct[i] + "\"";
    if (i != (ie - 1))
      obj += ",";
  }
  return obj;
}


std::string JSONParser::writeLoop(parallel_loop *data, bool reference, parallel_loop *data_ref) {
  std::string obj = std::string();
  std::vector<std::string> depList;
  for (int i = 0, ie = data->dependence_list.size(); i != ie; i++) {
    if (reference == true)
      obj += writeGenericObj(&reference_objs[data->dependence_list[i]], depList);
    else if (reference == false)
      obj += writeGenericObj(&tool_objs[data->dependence_list[i]], depList);
  }
  obj += "\"loop - object id : " + std::to_string(++unique_obj_id) + "\":{\n";
  obj += "\"file\":\"" + data->filename + "\",\n";
  obj += "\"function\":\"" + data->loop_function + "\",\n";
  obj += "\"loop id\":\"" + std::to_string(data->loop_id) + "\",\n";
  obj += "\"loop line\":\"" + std::to_string(data_ref->loop_line) + "\",\n";
  obj += "\"loop column\":\"" + std::to_string(data_ref->loop_column) + "\",\n";
  obj += "\"pragma type\":\"" +  data->pragma_type + "\",\n";
  obj += "\"ordered\":\"" + std::string(data->ordered == true ? "true" : "false") + "\",\n";
  obj += "\"offload\":\"" + std::string(data->offload == true ? "true" : "false") + "\",\n";
  obj += "\"multiversioned\":\"" + std::string(data->multiversioned == true ? "true" : "false") + "\"";

  if (data_ref->induction_variable != std::string()) {
    obj += ",\n\"induction variable\":\"" + data_ref->induction_variable + "\"";
    for (int i = 0, ie = data->first_private_prag.size();i != ie; i++)
      if (data->first_private_prag[i] == data_ref->induction_variable)
	data->first_private_prag[i] == "";
    for (int i = 0, ie = data->last_private_prag.size();i != ie; i++)
      if (data->last_private_prag[i] == data_ref->induction_variable)
	data->last_private_prag[i] == "";
  }
  if (data->shared.size() > 0)
    obj += ",\n\"shared\":[" + writeArrayObj(data->shared) + "]";
  if (data->private_prag.size() > 0)
    obj += ",\n\"private\":[" + writeArrayObj(data->private_prag) + "]";
  if (data->first_private_prag.size() > 0)
    obj += ",\n\"firstprivate\":[" + writeArrayObj(data->first_private_prag) + "]";
  if (data->last_private_prag.size() > 0)
    obj += ",\n\"lastprivate\":[" + writeArrayObj(data->last_private_prag) + "]";
  if (data->linear_prag.size() > 0)
    obj += ",\n\"linear\":[" + writeArrayObj(data->linear_prag) + "]";
  if (data->reduction_prag.size() > 0) {
    obj += ",\n\"reduction\":[" + writeArrayObj(data->reduction_prag,data->reduction_prag_op) + "]";
  }
  if (data->map_to.size())
    obj += ",\n\"map to\":[" + writeArrayObj(data->map_to) + "]";
  if (data->map_to.size() > 0)
    obj += ",\n\"map from\":[" + writeArrayObj(data->map_from) + "]";
  if (data->map_tofrom.size() > 0)
    obj += ",\n\"map tofrom\":[" + writeArrayObj(data->map_tofrom) + "]";
  if (depList.size() > 0)
    obj += ",\n\"dependence list\":[" + writeArrayObj(depList) + "]";

  obj += "\n},\n"; 
  return obj;
}

std::string JSONParser::joinJSONS(parallel_loop *refData, parallel_loop *toolData, bool existsToolVersion) {
  if ((refData->pragma_type == "NULL") && (existsToolVersion)) {
    return writeLoop(toolData, false, refData);
  }
  else {
    return writeLoop(refData, true, refData);
  }
}

void JSONParser::joinJSONS(std::string outputJSON) {
  unique_obj_id = 0;
  std::string obj = std::string();
  for (std::map<std::pair<std::string,std::pair<std::string,int> >, parallel_loop>::iterator IT = reference.begin(), ITE = reference.end(); IT != ITE; IT++) {
    if (IT->first.first == std::string())
      continue;
    obj += joinJSONS(&reference[IT->first], &tool[IT->first], tool.count(IT->first));
  }

  ofstream myfile;
  myfile.open (outputJSON);
  if (obj.size() > 1)
    obj.erase(obj.end() - 2, obj.end());
  myfile << "{\n" << obj << "\n}\n";
  myfile.close(); 
}

int main(int argc, char *argv[]) {
  if ((argc != 4) && (argc != 5)) {
    return 1;
  }
  std::string flag = argv[1];
  std::string refFile = argv[2];
  std::string toolFile = argv[3];
  std::string outputJSON = std::string();
  if (argc == 5)
    outputJSON = argv[4];

  JSONParser json(refFile, toolFile, outputJSON, flag);
  return 0;
}
