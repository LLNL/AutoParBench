//******************************************************************************************************************//
// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
// and Federal University of Minas Gerais
// SPDX-License-Identifier: (BSD-3-Clause)
//*****************************************************************************************************************//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

std::string replace_all(std::string str, std::string from, std::string to) {
  int pos = 0;
  while((pos = str.find(from, pos)) != std::string::npos) {
    str.replace(pos, from.length(), to);
    pos = pos + to.length();
  }
  return str;
}

void processFile(std::string filename, std::string & output) {
  string line, lineNormalized;
  ifstream file (filename);
  bool brokenDirective = false;
  if (file.is_open()) {
    while (getline(file,line)) {
      lineNormalized = replace_all(line, "\t", "");
      lineNormalized = replace_all(lineNormalized, " ", "");
      std::string lineNormalizedToP = lineNormalized;
      lineNormalized = std::string();
      for (int i = 0, ie = lineNormalizedToP.size(); i < ie; i++) {
	if ((lineNormalizedToP[i] < ' '))
	  continue;
        lineNormalized += lineNormalizedToP[i];
      }
      if (lineNormalized.find("#pragma",0) == 0) {
        if (lineNormalized[(lineNormalized.size() - 1)] == '\\')
          brokenDirective = true;
        continue;
   	
      }
      if (brokenDirective == true) {
	brokenDirective = false;
        if (lineNormalized[(lineNormalized.size() - 1)] == '\\')
          brokenDirective = true;
 
        continue;
      }
      output += line + "\n";
    }
    file.close();
  }
}

void printNewFile (std::string filename, std::string & output) {
  ofstream file (filename);
  if (file.is_open()) {
    file << output;
    file.close();
  }
}

int main(int argc, char *argv[]) {
  std::string filename = argv[1];
  std::string fileinfo;
  processFile(filename, fileinfo);
  printNewFile(filename, fileinfo);
  return 0;
}

