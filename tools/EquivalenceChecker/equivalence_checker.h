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

  // Flag to add line number afther classification, for each loop.
  bool detailed;
  //---------------------------------------------------------------------------
  //                       GLOBAL VARAIBLES
  //--------------------------------------------------------------------------- 
  
  // Map to loops in the reference json
  std::map<std::pair<std::string,std::pair<std::string,int> >, parallel_loop> reference;

  // Map to loops in the target tool json
  std::map<std::pair<std::string,std::pair<std::string,int> >, parallel_loop> tool;

  // Map to the generic objects in the reference json
  std::map<std::string, generic_obj> reference_objs;

  // Map to the generic objects in the target tool json
  std::map<std::string, generic_obj> tool_objs;

  // Map to equivalente pragmas
  // Map a OMP directive to its class.
  // <directive, class>
  std::map<std::string, std::string> equivalent_classes;

  int unique_obj_id;

  std::string flag;
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

  // Read and process the json file containing references for equivalent constructions
  // and populate the "equivalent_classes" map to classification.
  void readEquivalenceClasses(std::string filename);

  // Read the file named as "filename"
  // fileType attribute have two option:
  //   - true : This is the reference json file.
  //   - false : This is the target tool json file.
  void readFile(std::string filename, bool fileType);

  // Insert data of a string in a parallel loop data reference.
  void insertField(parallel_loop *data, std::string name, std::string obj);

  // Check equivalence between directivs in generic objects.
  bool representSameDirective(std::string & pragma_ref, std::string & pragma_tool);

  // Check if two generic objects are equivalent, using their names.
  bool areObjectsEquivalent(std::string & objRef, std::string & objTool);

  // Check if two lists containing generic objects are equivalent, using their names.
  bool areObjectsEquivalent(std::vector<std::string> & vectRef, std::vector<std::string> & vectTool);

  // Normalize the descripted C / C++ object. 
  // It transformes all "var +=" into "var = var +", and remove all spaces.
  // We can consider both the same agther this process.
  void normalizeCompoundAssignmentOperator(std::string op, std::string & desc) ;

  // Chech if the string contais one or more compound assignment operators
  bool containsCompoundAssignmentOperator(std::string & desc);

  // Normalize the expression.
  bool normalizeExpression(std::string & desc);

  // Denotate each atomic directive as reduction, the recovered expression is "operator:variable"
  // Ex: "+:sum"
  void denotateAtomicEquivalenttoReduction(std::vector<std::string> & dependence_list, std::vector<std::string> & reduction_prag, bool fileType);

  // Process a string that describes a generic loop object.
  void processGenericObject(std::string & objName, std::string & desc, bool fileType);

  // Process a string that describes a parallel loop object.
  void processParallelLoop(std::string & desc, bool fileType);

  // Copy all elements in "src" to "dest" vector.
  void appendVector(std::vector<std::string> & dest, std::vector<std::string> & src);

  // Check if the vector containing the results of a tool have at least the same attributes as the reference vector.
  // Note that "vectTool" vector containing more attributes are considered valid also.
  bool equivalentVectors(std::vector<std::string> & vectRef, std::vector<std::string> & vectTool);

  // Check if the reduction clauses are equivalent.
  bool equivalentReductions(std::vector<std::string> & vectRef, std::vector<std::string> & vectRef_ops, std::vector<std::string> & vectTool, std::vector<std::string> & vectTool_ops);

  // Normalize pragmas depending on the context (offload computation to other devices or not).
  std::string getEquivalentAtTargetContext(std::string prag, bool offload);

  // Classify the pragma depending ot it's type.
  bool isEquivalent(std::string prag1, std::string prag2);

  // Using the info of two loops (one reference and one target), classify them.
  void classify(parallel_loop *refData, parallel_loop *toolData); 

  // Classify each loop at both json files.
  void classify();

  // Print both vectors to debug the differences.
  void printVectDiffs(std::vector<std::string> refData, std::vector<std::string> toolData);
  void printVectDiffs(std::vector<std::string> refData, std::vector<std::string> refData_ops, std::vector<std::string> toolData, std::vector<std::string> toolData_ops);

  // Dump out the differences between two loop objects
  void debug_classification(parallel_loop *refData, parallel_loop *toolData);

  // Print the differences of each loop at both json files. 
  void debug_classification();

  // Generates a string that represents a generic object.
  std::string writeGenericObj(generic_obj *data, std::vector<std::string> & depList);

  // Generates strings to represent array objects.
  std::string writeArrayObj(std::vector<std::string> vct, std::vector<std::string> vct_op);
  std::string writeArrayObj(std::vector<std::string> vct);

  // Provide a JSON representation to the loop object.
  std::string writeLoop(parallel_loop *data, bool reference, parallel_loop *data_ref);

  // Join two JSON objects into one, using the following rule:
  //   - The references (first object) should be used if it is parallel.
  //   - The tool object should be used if the reference is not parallelized.
  //   - Then, if both loops are sequential, uses the reference version.
  // 
  std::string joinJSONS(parallel_loop *refData, parallel_loop *toolData, bool existsToolVersion);

  // Provide a JSON file with the name in the variable "outputJSON"
  void joinJSONS(std::string outputJSON);

  public:

  // Void to initilize the JSONParser class.
  JSONParser(std::string fileRef, std::string fileTool, std::string outputJSON, std::string flagUsed) { 
    flag = flagUsed;
    reference.erase(reference.begin(), reference.end());
    tool.erase(tool.begin(), tool.end());
    readEquivalenceClasses("equivalent_pragmas.json");
    readFile(fileRef, true);
    readFile(fileTool, false);
    detailed = false;
    if (flag == "-check-detailed") {
      detailed = true;
      classify();
    }
    if (flag == "-check")
      classify();
    if (flag == "-join")
      joinJSONS(outputJSON);
    if (flag == "-report-check")
      debug_classification();
  }

  JSONParser() { }

};
