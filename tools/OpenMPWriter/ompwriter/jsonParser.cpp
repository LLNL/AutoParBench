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

#include "jsonParser.h"

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

void JSONParser::extractReductionOperator(std::string & clause, std::string & op) {
  op = "none";
  if (clause.find(":") != std::string::npos) {
    op = clause[0];
    clause.erase(clause.begin(), clause.begin() + 2);
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

void JSONParser::processGenericObject(std::string & objName, std::string & desc) {
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

  data.filename.erase(data.filename.begin(), data.filename.begin() + data.filename.rfind("/") + 1);

  json_objs[objName] = data;

  std::string index = data.filename + "," + data.function_name + ",";
  index += std::to_string(data.loop_id) + "," + std::to_string(data.instruction_id);

  directives[index] = generateOMPDirective(data);
}

void JSONParser::processParallelLoop(std::string & desc) {
  parallel_loop data;
  data.induction_variable = std::string();
  std::string name = std::string();
  std::string obj = std::string();

  for (extractObject(desc, name, obj); (name != std::string()); extractObject(desc, name, obj)) {
    insertField(&data, name, obj);
    name = std::string();
    obj = std::string();
  }
  if (data.filename == std::string()) {
    cout << "BUG THERE!\n";
  }

  data.filename.erase(data.filename.begin(), data.filename.begin() + data.filename.rfind("/") + 1);

  json_loops[std::make_pair(data.filename, std::make_pair(data.loop_function,data.loop_id))] = data;
  
  std::string index = data.filename + "," + data.loop_function + "," + std::to_string(data.loop_id);
  directives[index] = generateOMPLoop(data);
}

void JSONParser::readFile(std::string filename) {
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
      processParallelLoop(obj);
    else
      processGenericObject(name, obj);
    name = std::string();
    obj = std::string();
  }
}

std::string JSONParser::getListofClauses(std::vector<std::string> & clauses) {
  std::string output = std::string();
  for (int i = 0, ie = clauses.size(); i != ie; i++) {
    output += clauses[i] + " ";
    if (i != (ie - 1))
      output += ",";
  }
  return output;
}

std::string JSONParser::getListofClauses(std::vector<std::string> & ops,
		                         std::vector<std::string> & clauses) {
  std::string output = std::string();
  for (int i = 0, ie = clauses.size(); i != ie; i++) {
    std::string op = ops[i];
    if (op == "none")
      op = "+";
    output += "reduction(" + op + ":" + clauses[i] + ") ";
  }
  return output;
}

std::string JSONParser::generateOMPLoop(parallel_loop loop) {
  if (loop.pragma_type == "NULL") {
    return std::string();
  }
  std::string directive = "#pragma omp ";
  directive += loop.pragma_type + " ";
  if (loop.private_prag.size() > 0)
    directive += "private(" + getListofClauses(loop.private_prag) + ") ";
  if (loop.shared.size() > 0)
    directive += "share(" + getListofClauses(loop.shared) + ") ";
  if (loop.first_private_prag.size() > 0)
    directive += "firstprivate(" + getListofClauses(loop.first_private_prag) + ") ";
  if (loop.last_private_prag.size() > 0)
    directive += "lastprivate(" + getListofClauses(loop.last_private_prag) + ") ";
  if (loop.linear_prag.size() > 0)
    directive += "linear(" + getListofClauses(loop.linear_prag) + ") ";
  if (loop.reduction_prag.size() > 0)
    directive += getListofClauses(loop.reduction_prag_op, loop.reduction_prag);
  if (loop.map_to.size() > 0)
    directive += "map(to:" + getListofClauses(loop.map_to) + ") ";
  if (loop.map_from.size() > 0)
    directive += "map(from:" + getListofClauses(loop.map_from) + ") ";
  if (loop.map_tofrom.size() > 0)
    directive += "map(tofrom:" + getListofClauses(loop.map_tofrom) + ") ";
  if (loop.ordered)
    directive += "ordered ";
  directive += "\n";
  return directive;
}

std::string JSONParser::generateOMPDirective(generic_obj obj) {
  std::string directive = "#pragma omp ";
  directive += obj.pragma_type + "\n";
  return directive;
}
