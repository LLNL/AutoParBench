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
#include <algorithm>

using namespace std;

class JSONParser {

  private:

  //---------------------------------------------------------------------------
  //                       DATA SCTRUCTURES
  //---------------------------------------------------------------------------
  typedef struct parallel_loop {
    std::string filename; // Name of the file where the loop is inside. 
    int loop_id; // Loop unique id
    int loop_line; // Loop's line in source file
    int loop_column; // Loop's column in source file
    bool ordered; // Clause ordered
    std::string loop_function; // Name of the function where the loop is inside.
    bool offload; // Flag to assign if a directive is inside a target region or not.
    bool multiversioned; // Flag to check if the compiler can choose between
                         // sequential and parallel versions of the target loop
    std::string induction_variable; // Recover the induction variable associated with the
                                    // loop, if possible.
    std::string pragma_type; // Type of pragma, for example "parallel for"
    std::vector<std::string> shared; // List of shared variables
    std::vector<std::string> private_prag; // List of private variables
    std::vector<std::string> first_private_prag; // List of firstprivate variables
    std::vector<std::string> last_private_prag; // List of lastprivate variables
    std::vector<std::string> linear_prag; // List of linear variables
    std::vector<std::string> reduction_prag_op; // List of operators in the reduction field
    std::vector<std::string> reduction_prag; // List of variables marked as reduction
    std::vector<std::string> map_to; // List of variables assigned as map(to:...)
    std::vector<std::string> map_from; // List of variables assigned as map(from:...)
    std::vector<std::string> map_tofrom; // List of variables assigned as map(tofrom:...)
    std::vector<std::string> dependence_list; // List of directives this object depends.
  } parallel_loop;

  typedef struct generic_obj {
    std::string filename; // Name of the file where the instruction is inside.  
    std::string function_name; // Name of the function where the instruction is inside.   
    int loop_id; // Loop unique id
    int instruction_id; // Instruction unique id 
    std::string pragma_type; // Type of pragma, for example "ordered"
    std::vector<std::string> code_snippet; // The C representation of the target directive
    				 // Example: "a[i] += b[i];"
  } generic_obj; 

  //---------------------------------------------------------------------------
  //                       GLOBAL VARAIBLES
  //--------------------------------------------------------------------------- 
  
  // Map to loops in the reference json
  std::map<std::pair<std::string,std::pair<std::string,int> >, parallel_loop> json_loops;

  // Map to the generic objects in the reference json
  std::map<std::string, generic_obj> json_objs;

  //---------------------------------------------------------------------------
  //                         FUNCTIONS
  //--------------------------------------------------------------------------- 
 
  // Replace all  occurrences in the target string:
  //   - str : original string
  //   - from : substring to find
  //   - to : substring to replace
  std::string replace_all(std::string str, std::string from, std::string to);

  // Remove the brackets that define a json file.
  // Remove all occurrences of "\n"
  void cleanStr(std::string & desc);

  // A void to split the information of reduction clauses.
  void extractReductionOperator(std::string & clause, std::string & op);

  // Process the string, removing the next string object.
  void extractSTRINGObject(std::string & desc, std::string & str);

  // Process an array object, and return a vector containing the items.
  void createVectorToARRAYObj(std::string & desc, std::vector<std::string> & obj, bool recover_op,  std::vector<std::string> & ops);

  // Process the string, removing the next array object.
  void extractARRAYObject(std::string & desc, std::string & str);

  // Process the string, removing the next class object.
  void extractCLASSObject(std::string & desc, std::string & str);

  // Extract a object in the json file in new objects.
  void extractObject(std::string & desc, std::string & name, std::string & obj);

  // Read the file named as "filename"
  // fileType attribute have two option:
  //   - true : This is the reference json file.
  //   - false : This is the target tool json file.
  void readFile(std::string filename);

  // Insert data of a string in a parallel loop data reference.
  void insertField(parallel_loop *data, std::string name, std::string obj);

  // Process a string that describes a generic loop object.
  void processGenericObject(std::string & objName, std::string & desc);

  // Process a string that describes a parallel loop object.
  void processParallelLoop(std::string & desc);

  // Provide a C / C++ representation to a loop object.
  std::string generateOMPLoop(parallel_loop loop);

  // Provide a C / C++ representation to a generic object.
  std::string generateOMPDirective(generic_obj obj);

  // Recover a list of cluases in text format.
  std::string getListofClauses(std::vector<std::string> & clauses);

  // Recover a list of Clauses and operands, for reduction clauses.
  std::string getListofClauses(std::vector<std::string> & ops, std::vector<std::string> & clauses);

  public:

  // Map of abstract handles to OpenMP directives.
  std::map<std::string, std::string> directives;

  // Void to initilize the JSONParser class.
  JSONParser(std::string fileRef) { 
    json_loops.erase(json_loops.begin(), json_loops.end());
    readFile(fileRef);
  }

  JSONParser() { }

};
