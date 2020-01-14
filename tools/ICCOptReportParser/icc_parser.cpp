//******************************************************************************************************************//
// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
// and Federal University of Minas Gerais
// SPDX-License-Identifier: (BSD-3-Clause)
//*****************************************************************************************************************//
#include "icc_parser.h"

std::string ICCParser::replace_all(std::string str, std::string from, std::string to) {
  int pos = 0;
  while((pos = str.find(from, pos)) != std::string::npos) {
    str.replace(pos, from.length(), to);
    pos = pos + to.length();
  }
  return str;
}

std::string ICCParser::join_equal(std::string str, std::string target) {
  int pos = 0;
  std::string from = target + target;
  while((pos = str.find(from, 0)) != std::string::npos) {
    str.replace(pos, from.length(), target);
  }
  return str;
}

std::string ICCParser::copyAndRemove(std::string & str, int begin, int end) {
  std::string output = std::string();
  for(int i = begin, ie = end; i < ie; i++) {
    output += str[i];
  }
  str.erase(str.begin(), str.begin() + end);
  return output;
}

void ICCParser::copyUntil(std::string & src, std::string & dst, char end) {
  for (int i = 0, ie = src.size(); ((i < ie) && (src[i] != end)); i++) {
    dst += src[i];
  } 
}

bool ICCParser::isNumeric(std::string str) {
  for (int i = 0, ie = str.size(); i != ie; i++) {
    if ((str[i] > '0') && (str[i] < '9'))
      continue;
    if ((str[i] == '0') && (str[i] == '9'))
      continue;
    if (str[i] == '.')
      continue;
    return false;
  }
  return true;
}

void ICCParser::getVectorToClause(std::string & str, std::vector<std::string> & vect) {
  std::string substr = std::string();
  std::map<std::string, bool> mapped;
  for (int i = 0, ie = vect.size(); i != ie; i++)
    mapped[vect[i]] = true;
  if (str.size() > 0)
    str += ',';
  for (int i = 0, ie = str.size(); i < ie; i++) {
    if (str[i] != ',')
      substr += str[i];
    else {
      if (!isNumeric(substr)
	 && mapped.count(substr) == 0) {
        vect.push_back(substr);
	mapped[substr] = true;
      }
      substr = std::string();
    }
  }
}

void ICCParser::dump() {
  for (std::map<std::pair<int, std::string>,loop_node>::iterator I = nodes.begin(), IE = nodes.end(); I != IE; I++) {
    cout << "-------------------------------------------------------------------\n";
    cout << "---------------------- REPORT STARTS ------------------------------\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "FileName = " << I->second.filename << "\n";
    cout << "Loop ID = " << I->second.loop_id << "\n";
    cout << "Line = " << I->second.line << "\n";
    cout << "Column = " << I->second.column << "\n";
    cout << "Parallel = " << ((I->second.parallel) ? "T" : "F") << "\n";
    cout << "Simd = " << ((I->second.simd) ? "T" : "F") << "\n";

    for (int i = 0, ie = I->second.private_clause.size(); i < ie; i++)
      cout << "- Private Variable => " << I->second.private_clause[i] << "\n";

    for (int i = 0, ie = I->second.first_private_clause.size(); i < ie; i++)
      cout << "- First Private Variable => " << I->second.first_private_clause[i] << "\n";

    for (int i = 0, ie = I->second.last_private_clause.size(); i < ie; i++)
      cout << "- Last Private Variable => " << I->second.last_private_clause[i] << "\n";

    for (int i = 0, ie = I->second.shared_clause.size(); i < ie; i++)
      cout << "- Shared Variable => " << I->second.shared_clause[i] << "\n";

    for (int i = 0, ie = I->second.reduction_clause.size(); i < ie; i++)
      cout << "- Reduction Variable => " << I->second.reduction_clause[i] << "\n";
 
  }
}

void ICCParser::calculateIDs() {
  std::map<std::string, bool> visited;
  for (std::map<std::pair<int, std::string>,loop_node>::iterator I = nodes.begin(), IE = nodes.end(); I != IE; I++) {
    if (visited.count(I->second.filename) == 0) {
      calculateIDsToFile(I->second.filename);
      visited[I->second.filename] = true;
    }
  }
}

void ICCParser::calculateIDsToFile(std::string filename) {
  std::vector<int> ids;
  std::map<std::string, int> ids_functions;
  for (std::map<std::pair<int, std::string>,loop_node>::iterator I = nodes.begin(), IE = nodes.end(); I != IE; I++) {
     if (I->second.filename == filename) {
       ids.push_back(I->second.line);
       ids_functions[I->second.functionName] = 1;
     }
  }
  std::sort(ids.begin(), ids.end());
  for (int i = 0, ie = ids.size(); i != ie; i++) {
    std::pair<int, std::string> index = std::make_pair(ids[i], filename);
    nodes[index].loop_id = (ids_functions[nodes[index].functionName]++);
  }
}

void ICCParser::processNode(std::string & str, loop_node * info) {
  info->clauses = str;
  if (str.find("shared={", 0) == 0) {
     str.erase(str.begin(), str.begin() + 8);
     std::string clause = std::string();
     copyUntil(str, clause, '}');
     getVectorToClause(clause, info->shared_clause);
     str.erase(str.begin(), str.begin() + (str.find("}") + 1));
  }
  if (str.find("private={", 0) == 0) {
     str.erase(str.begin(), str.begin() + 9);
     std::string clause = std::string();
     copyUntil(str, clause, '}');
     getVectorToClause(clause, info->private_clause);
     str.erase(str.begin(), str.begin() + (str.find("}") + 1));
  }
  if (str.find("firstprivate={", 0) == 0) {
     str.erase(str.begin(), str.begin() + 14);
     std::string clause = std::string();
     copyUntil(str, clause, '}');
     getVectorToClause(clause, info->first_private_clause);
     str.erase(str.begin(), str.begin() + (str.find("}") + 1));
  }
  if (str.find("lastprivate={", 0) == 0) {
     str.erase(str.begin(), str.begin() + 13);
     std::string clause = std::string();
     copyUntil(str, clause, '}');
     getVectorToClause(clause, info->last_private_clause);
     str.erase(str.begin(), str.begin() + (str.find("}") + 1));
  }
  if (str.find("firstlastprivate={", 0) == 0) {
     str.erase(str.begin(), str.begin() + 18);
     std::string clause = std::string();
     copyUntil(str, clause, '}');
     std::string clausecpy = clause;
     getVectorToClause(clause, info->first_private_clause);
     getVectorToClause(clausecpy, info->last_private_clause);
     str.erase(str.begin(), str.begin() + (str.find("}") + 1));
  }
  if (str.find("reduction={", 0) == 0) {
     str.erase(str.begin(), str.begin() + 11);
     std::string clause = std::string();
     copyUntil(str, clause, '}');
     getVectorToClause(clause, info->reduction_clause);
     str.erase(str.begin(), str.begin() + (str.find("}") + 1));
  }
}

void ICCParser::createNode(std::string str, std::string & functionName) {
 if (str.find("inlinedinto",0) != std::string::npos)
    return;

  str = replace_all(str," at ","");
  str = replace_all(str," ","");

  int pos = str.find("(", 0);
  std::string filename = copyAndRemove(str, 0, pos);

  pos = str.find(",", 0);
  int line = std::stoi(copyAndRemove(str, 1, pos));

  pos = str.find(")", 0);
  int column = std::stoi(copyAndRemove(str, 1, pos));

  std::pair<int, std::string> index = std::make_pair(line, filename);
  if (nodes.count(index) == 0) {
    loop_node info;
    info.filename = filename;
    info.functionName = functionName;
    info.line = line;
    info.column = column;
    info.parallel = false;
    info.multiversioned = false;
    info.simd = false;
    info.coallesced = false;
    nodes[index] = info;
  } 

  if (str.find("LOOPWASAUTO-PARALLELIZED", 0) != std::string::npos) {
    str.erase(str.begin(), str.begin() + str.find("parallelloop", 0) + 12);
    str.erase(str.begin() + str.find("remark", 0), str.end());
    processNode(str, &nodes[index]);
    nodes[index].parallel = true;
  }

  if (str.find("Multiversionedv2", 0) != std::string::npos) {
    nodes[index].multiversioned = true;
  }

  if (str.find("LOOPWASVECTORIZED", 0) != std::string::npos) {
    nodes[index].simd = true;
  }

  if ((str.find("LoopeliminatedinCollapsing", 0) != std::string::npos) ||
      (str.find("loopwasnotparallelized:innerloop") != std::string::npos)) {
    nodes[index].coallesced = true;
  }
}

void ICCParser::updateFunctionName(std::string & str, std::string & name) {
  int posNextName = str.find("Beginoptimizationreportfor", 0);
  int posBegin = str.find("LOOPBEGIN", 0);
  if ((posNextName == std::string::npos) ||
      (posBegin == std::string::npos) ||
      (posNextName > posBegin))
    return;

  bool isvalid = true;
  while(isvalid) { 
    int tmpNextName = str.find("Beginoptimizationreportfor", posNextName + 1);
    if ((tmpNextName != std::string::npos) && (tmpNextName < posBegin))
      posNextName = tmpNextName;
    else
      isvalid = false;
  }

  int posEndName = str.find("(", posNextName);
  name = std::string();
  for (int i = posNextName + 27, ie = posEndName; i != ie; i++) {
    name += str[i];
  }
  if (name.find("..0",0) != std::string::npos)
    name.erase(name.begin() + name.find("..0",0), name.begin() + name.find("..0",0) + 3);
}

void ICCParser::updateCoallesedLoop(std::pair<int, std::string> index) {
  std::map<std::pair<int, std::string>,loop_node>::iterator selected = nodes.begin();

  for (std::map<std::pair<int, std::string>,loop_node>::iterator I = nodes.begin(), IE = nodes.end(); I != IE; I++) {
    if ((selected->second.line < I->first.first) &&
        (I->first.first < nodes[index].line))
   selected = I;
  }

  // After select the correct outmoster loop, copy the attributes.
  nodes[index].parallel = selected->second.parallel;
  nodes[index].multiversioned = selected->second.multiversioned;
  nodes[index].simd |= selected->second.simd;
  if (selected->second.simd == true) {
    selected->second.simd = false;
  }
  nodes[index].clauses = selected->second.clauses;
  std::string clauses = selected->second.clauses;
  processNode(clauses, &nodes[index]);
}

void ICCParser::updateCoallesedLoops() {
  for (std::map<std::pair<int, std::string>,loop_node>::iterator I = nodes.begin(), IE = nodes.end(); I != IE; I++) {
    if (I->second.coallesced == true) {
      updateCoallesedLoop(I->first); 
    }
  }
}

void ICCParser::collectLoops(std::string & str) {
  // Process the loop to generate each node:
  int posBegin = 0, posEnd = 0, posNextBegin = 0;
  std::string nodeStr = std::string();
  std::string functionName = std::string();
  updateFunctionName(str, functionName);

  posBegin = str.find("LOOPBEGIN", 0);
  str.erase(str.begin(), str.begin() + posBegin);
  posEnd = str.rfind("LOOPEND");
  str.erase(str.begin() + posEnd + 7, str.end());

  str = join_equal(str,"LOOPEND");

  while((!str.empty()) && 
    ((posBegin = str.find("LOOPBEGIN", 0)) != std::string::npos)) {
    posNextBegin = str.find("LOOPBEGIN", posBegin + 9);
    posEnd = str.find("LOOPEND", 0);

    if (posNextBegin != std::string::npos)
      posEnd = std::min(posNextBegin, posEnd);
    nodeStr = std::string();
    for (int i = posBegin + 9; i < posEnd; i++) {
       nodeStr += str[i];
    }

    updateFunctionName(str, functionName);
    createNode(nodeStr, functionName);
	
    str.erase(str.begin(), str.begin() + posEnd);
    if (str.find("LOOPEND", 0) == 0)
      str.erase(str.begin(), str.begin() + 7);
  }
  updateCoallesedLoops();
}

void ICCParser::parserClauses(std::string & str) {
  bool in_brackts = false;
  for (int i = 0, ie = str.size(); i < ie; i++) {
    if (str[i] == '{') {
      for (int j = i, je = str.find("}", i); j < je; j++) {
        if (str[j] == ' ') {
          str[j] = ','; 
	}
	i = je;
      }
    }
  }
}

void ICCParser::formatInput(std::string & str) {
  std::string nodeStr = std::string();
  int posBegin = 0, posEnd = 0;
  str = replace_all(str," at ","");
  str = replace_all(str,"{ ","{");
  str = replace_all(str," }","}");
  parserClauses(str);
  str = replace_all(str," ","");
  
  collectLoops(str);
}

void ICCParser::writeJSON(std::string filename) {
  std::map<std::string, std::string> files;
  int unique_id = 1;
  for (std::map<std::pair<int, std::string>,loop_node>::iterator I = nodes.begin(), IE = nodes.end(); I != IE; I++) {
    if (files.count(I->second.filename) == 0)
      files[I->second.filename] = std::string();

    files[I->second.filename] += "\"loop - object id : " + std::to_string(unique_id++) + "\":{\n";
    files[I->second.filename] += "\"file\":\"" + I->second.filename + "\",\n";
    files[I->second.filename] += "\"function\":\"" + I->second.functionName + "\",\n"; 
    files[I->second.filename] += "\"loop id\":\"" + std::to_string(I->second.loop_id) + "\",\n";
    files[I->second.filename] += "\"loop line\":\"" + std::to_string(I->second.line) + "\",\n";
    files[I->second.filename] += "\"loop column\":\"" + std::to_string(I->second.column) + "\",\n";


    std::string pragmaType = ((I->second.parallel && !I->second.simd) ? "parallel for" : "");
    pragmaType = ((!I->second.parallel && I->second.simd) ? "simd" : pragmaType);
    pragmaType = ((I->second.parallel && I->second.simd) ? "parallel for simd" : pragmaType);
    pragmaType = ((!I->second.parallel && !I->second.simd) ? "NULL" : pragmaType);
    files[I->second.filename] += "\"pragma type\":\"" + pragmaType + "\",\n";
    files[I->second.filename] += "\"ordered\":\"false\",\n";
    files[I->second.filename] += "\"offload\":\"false\",\n";
    std::string multiversioned = ((I->second.multiversioned == true) ? "true" : "false");
    files[I->second.filename] += "\"multiversioned\":\"" + multiversioned + "\"";

    if (I->second.shared_clause.size() > 0) {
      files[I->second.filename] += ",\n\"shared\":[";
      for (int i = 0, ie = I->second.shared_clause.size(); i < ie; i++)
        files[I->second.filename] += "\"" + I->second.shared_clause[i] + "\"" + (((i+1) < ie) ? "," : "");
      files[I->second.filename] += "]";
    }

    if (I->second.private_clause.size() > 0) {
      files[I->second.filename] += ",\n\"private\":[";
      for (int i = 0, ie = I->second.private_clause.size(); i < ie; i++)
        files[I->second.filename] += "\"" + I->second.private_clause[i] + "\"" + (((i+1) < ie) ? "," : "");
      files[I->second.filename] += "]";
    }

    if (I->second.first_private_clause.size() > 0) {
      files[I->second.filename] += ",\n\"firstprivate\":[";
      for (int i = 0, ie = I->second.first_private_clause.size(); i < ie; i++)
        files[I->second.filename] += "\"" + I->second.first_private_clause[i] + "\"" + (((i+1) < ie) ? "," : "");
      files[I->second.filename] += "]";
    }
    
    if (I->second.last_private_clause.size() > 0) {
      files[I->second.filename] += ",\n\"lastprivate\":[";
      for (int i = 0, ie = I->second.last_private_clause.size(); i < ie; i++)
        files[I->second.filename] += "\"" + I->second.last_private_clause[i] + "\"" + (((i+1) < ie) ? "," : "");
      files[I->second.filename] += "]";
    }

    if (I->second.reduction_clause.size() > 0) {
      files[I->second.filename] += ",\n\"reduction\":[";
      for (int i = 0, ie = I->second.reduction_clause.size(); i < ie; i++)
        files[I->second.filename] += "\"" + I->second.reduction_clause[i] + "\"" + (((i+1) < ie) ? "," : "");
      files[I->second.filename] += "]";
    }

    files[I->second.filename] += "\n},\n";
  }

  for (std::map<std::string,std::string>::iterator I = files.begin(), IE = files.end(); I != IE; I++) {
    std::string name = filename + ".json";
    std::ofstream ofs(name, std::ofstream::out);
    I->second.erase(I->second.end() - 2, I->second.end() - 1);
    ofs << "{\n" << I->second << "}";
    ofs.close();
  }
}

void ICCParser::readFile(std::string filename) {
  std::string line = std::string();
  std::string info = std::string();
  std::ifstream file(filename);
  if (file.is_open()) {
    while (getline(file, line)) {
      info = info + line;
    }
    file.close();
  }
  formatInput(info);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return 1;
  }
  std::string file = argv[1];
  ICCParser icc(file);
  return 0;
}
