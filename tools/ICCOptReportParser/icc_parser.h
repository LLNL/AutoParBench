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

using namespace std;

class ICCParser {

private:	

  //---------------------------------------------------------------------------
  //                       GLOBAL VARAIBLES
  //--------------------------------------------------------------------------- 

  // Structure to store the information present in the loops:
  typedef struct loop_node {
    std::string filename;
    std::string reference_str;
    int loop_id;
    std::string functionName;
    int line;
    int column;
    bool parallel;
    bool multiversioned;
    bool simd;
    bool coallesced;
    std::string clauses;

    std::vector<std::string> private_clause;
    std::vector<std::string> first_private_clause;
    std::vector<std::string> last_private_clause;
    std::vector<std::string> shared_clause;
    std::vector<std::string> reduction_clause;
  } loop_node;

  //---------------------------------------------------------------------------
  //                       GLOBAL VARAIBLES
  //--------------------------------------------------------------------------- 

  // Store all information about loops.
  // The key is a pair:
  //  - line
  //  - file name
  std::map<std::pair<int, std::string>, loop_node> nodes;

  //---------------------------------------------------------------------------
  //                         FUNCTIONS
  //--------------------------------------------------------------------------- 

  // Replace all occurrences in the target string:
  //   - str : original string
  //   - from : substring to find
  //   - to : substring to replace
  std::string replace_all(std::string str, std::string from, std::string to);

  // Replace all occurrences of the "target" string concatenated with itself, then remove
  // redundant compies :
  //   - str : original string
  //   - target : substring to find and reduce the duplicate
  std::string join_equal(std::string str, std::string target);

  // Create a copy of a string starting on "begin" and finishing on "end" position. Then delete this substring:
  //   - str : original string
  //   - begin : position of "str" to start the copy.
  //   - end : position of "str" to finish the copy.
  std::string copyAndRemove(std::string & str, int begin, int end);

  // Copy the characters of the string "str" to "dst" until the position "end".
  //   - src : original string
  //   - dst : string to receive the copy
  //   - end last position to be copied
  void copyUntil(std::string & src, std::string & dst, char end);

  // Generates a vector containing the caluse described in str
  //   - str : string containing the OMP clause description
  //   - vect : vector to insert each variable present in the clause 
  void getVectorToClause(std::string & str, std::vector<std::string> & vect);

  // Calculate and provide a loop ID to each loop in each file
  void calculateIDs();

  // Calculate and provide a loop ID to each loop in the file with the name "filename"
  //   - filename : name of the target file
  void calculateIDsToFile(std::string filename);

  // Process the string "str", organize and store the information in "info":
  //   - str : string with the description of a node
  //   - info : node to store the information
  void processNode(std::string & str, loop_node * info);
  
  // Process the string "str", organize and update the name of the function in "name":
  //   - str : string with the description of a node
  //   - name : string to store the name of the function
  void updateFunctionName(std::string & str, std::string & name);

  // Updated the loop with the index with the same info as its outmoster loop. 
  void updateCoallesedLoop(std::pair<int, std::string> index);

  // Updated the coallesed loops with the outmoster loop information.
  void updateCoallesedLoops();

  // Create a node using the string "str". If a node describing this loop existis, update it.
  //   - str : description of a node
  //   This function uses the key <line number, file name> to find and associate information.
  void createNode(std::string str, std::string & functionName);

  // Parser a clause description, changing the spaces to comas (a kind of small csv) 
  void parserClauses(std::string & str);

  // Check if a value is just a number or not:
  bool isNumeric(std::string str);

  // Parser a file description to devide information into small nodes, each node is associated with one loop.
  // One loop can have more than one description.
  void collectLoops(std::string & str); 

  // Format the input to be parser, then call "collectLoops" to collect loops
  void formatInput(std::string & str);

  // Write and save the JSON file using the collected information.
  //   - filename : Reference name to be used to save the info.
  void writeJSON(std::string filename);

  // Read the ".optptr"  file to be parser
  void readFile(std::string filename);

public:

  // Print the analysis results on standart output
  void dump();

  // Void to initialize ICC parser
  ICCParser(std::string file) {   
    readFile(file);
    calculateIDs();
    writeJSON(file);
  }
};
