//******************************************************************************************************************//
// Copyright (c) 2020, Lawrence Livermore National Security, LLC.
// and Federal University of Minas Gerais
// SPDX-License-Identifier: (BSD-3-Clause)
//*****************************************************************************************************************//

//===----------------------------ompwriterr.cpp-----------------------------===
//
//
//Author: Gleison Souza Diniz Mendonca
//  [gleison.mendonca at dcc.ufmg.br | gleison14051994 at gmail.com]
//
//===-----------------------------------------------------------------------===
//
//OMP Extractor is a small plugin developed for the Clang C compiler front-end.
//Its goal is to provide auxiliary source-code information extracting information
//of Openmp pragmas, to permits people to understand and compare different openmp
//pragmas for the same benchamrk.
//
//More specifically, it collects information about the synctatical pragma
//constructions and pragmas that exist within a C/C++ source-code file. It then
//builds a Json file, which is a representation of those pragma blocks in the source
//file, where each loop is a node block with information about parallelization using
//OpenMP syntax.
//
//For each input file, its reference nodes are outputted as a JSON format file, that
//represents the loops inside the source code.
//
//Since it is a small self-contained plugin (not meant to be included by other
//applications), all the code is kept within its own source file, for simplici-
//ty's sake.
//
//By default, the plugin is built alongside an LLVM+Clang build, and its shared
//library file (ompextractor.so) can be found its build.
//
//The plugin can be set to run during any Clang compilation command, using the
//following syntax:
//
//  clang -Xclang -load -Xclang $SCOPE -Xclang -add-plugin -Xclang -extract-omp
//
//  Where $SCOPE -> points to the ompextractor.so shared library file location 
//===-----------------------------------------------------------------------===

#include "clang/Driver/Options.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/Mangle.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include <stack>
#include <map>
#include <vector>
#include <fstream>

#include "jsonParser.h"

using namespace std;
using namespace clang;
using namespace llvm;

  //---------------------------------------------------------------------------
  //                       DATA SCTRUCTURES
  //---------------------------------------------------------------------------
  /*we can use this little baby to alter the original source code, if we ever feel
  like it*/
  Rewriter rewriter;

  /*POD struct that represents a meaningful node in the AST, with its unique name
  identifier and source location numbers*/
  typedef struct relative_loop_inst_id {
    string filename;
    string functionName;
    long long int functionLoopID;
    long long int loopInstructionID;
  } relative_loop_inst_id;

  /*POD struct that represents an input file in a Translation Unit (a single
  source/header file). Each input file will have its own stack of traversable
  nodes, and output file + associated information*/
  struct InputFile {
    string filename;
    map<Stmt*, bool> visited;
    // Mapping Stmts <-> Instructions.
    map<Stmt*, relative_loop_inst_id> mapStmtInstID;

    // Mapping strings to Stmt.
    // A index can be:
    //   - filename,functionName
    //   - filename,functionName,loopID
    //   - filename,functionName,loopID,instID
    map<string, Stmt*> mapInstIDStmt;
  };

  /*we need a stack of active input files, to know which constructs belong to
  which file*/
  stack <struct InputFile> FileStack;

  map <std::string, std::string> fileDir;
/*visitor class, inherits clang's ASTVisitor to traverse specific node types in
 the program's AST and retrieve useful information*/
class PragmaVisitor : public RecursiveASTVisitor<PragmaVisitor> {
private:
    ASTContext *astContext; //provides AST context info
    MangleContext *mangleContext;
    std::string json;
    JSONParser *jsonFile;

public:
    
    explicit PragmaVisitor(CompilerInstance *CI, std::string json) 
      : astContext(&(CI->getASTContext())) { // initialize private members
        rewriter.setSourceMgr(astContext->getSourceManager(),
        astContext->getLangOpts());
	this->json = json;
    }

    /*Recover C code */
    std::string getSourceSnippet(SourceRange sourceRange, bool allTokens, bool jsonForm) {
      if (!sourceRange.isValid())
	return std::string();

      SourceLocation bLoc(sourceRange.getBegin());
      SourceLocation eLoc(sourceRange.getEnd());
	   
      const SourceManager& mng = astContext->getSourceManager();
      std::pair<FileID, unsigned> bLocInfo = mng.getDecomposedLoc(bLoc);
      std::pair<FileID, unsigned> eLocInfo = mng.getDecomposedLoc(eLoc);
      FileID FID = bLocInfo.first;
      unsigned bFileOffset = bLocInfo.second;
      unsigned eFileOffset = eLocInfo.second;
      int length = eFileOffset - bFileOffset;

      if (length <= 0)
	return std::string();

      bool Invalid = false;
      const char *BufStart = mng.getBufferData(FID, &Invalid).data();
      if (Invalid)
        return std::string();

      if (allTokens == true) {
	while (true) {
	  if (BufStart[(bFileOffset + length)] == ';')
            break;
	  if (BufStart[(bFileOffset + length)] == '}')
	    break;
	  if (length == eFileOffset)
            break;
          length++;
	}
      }

      if (length != eFileOffset)
        length++;

      std::string snippet = StringRef(BufStart + bFileOffset, length).trim().str();
      snippet = replace_all(snippet, "\\", "\\\\");
      snippet = replace_all(snippet, "\"", "\\\"");

      if (jsonForm == true)
	snippet = "\"" + replace_all(snippet, "\n", "\",\n\"") + "\"";

      return snippet;
    }

    /*Replace all  occurrences in the target string*/
    std::string replace_all(std::string str, std::string from, std::string to) {
      int pos = 0;
      while((pos = str.find(from, pos)) != std::string::npos) {
	str.replace(pos, from.length(), to);
	pos = pos + to.length();
      }
      return str;
    }

    /*visit each node walking in the sub-ast and provide a list stored as "nodes_list"*/
    void visitNodes(Stmt *st, vector<Stmt*> & nodes_list) {
      if (!st)
	return;
      nodes_list.push_back(st);
      if (CapturedStmt *CPTSt = dyn_cast<CapturedStmt>(st)) {
        visitNodes(CPTSt->getCapturedStmt(), nodes_list);
	return;
      }
      for (auto I = st->child_begin(), IE = st->child_end(); I != IE; I++) {
       visitNodes((*I)->IgnoreContainers(true), nodes_list);
      }
    }

    /*Populate a map with the defined lines, to do that, we consider everything inside a statment as
     * a vector of characters, then we define new ids whenever we find the token ";".
     * The goal is be able to recover relative positions to statments when necessary, for example,
     * instructions inside a loop */
    void recoverCodeSnippetsID(Stmt *st, std::string functionName, long long int loopID) {
      if (!st)
	return;
      
      map<Stmt*, long long int> mapped_statments;
      string snippet = getSourceSnippet(st->getSourceRange(), true, false);
      // The separator ref vector have the following format:
      // <line, column>, where that is the position of the character ';' in the source code
      // and the position of the vector is the relative id;
      vector<pair<int, int> > separator_ref;
      int line = 0;
      int column = 0;
      for (int i = 0, ie = snippet.size(); i < ie; i++) {
	// Store the positions with the character ';'
        if (snippet[i] == ';')
	  separator_ref.push_back(make_pair(line, column));
	column++;
	if (snippet[i] == '\n') {
	  line++;
	  column = 0;
	}
      }

      if (snippet[(snippet.size() - 1)] != ';')
        separator_ref.push_back(make_pair(line, column));

      vector<Stmt*> nodes_list;
      visitNodes(st, nodes_list);
      for (int i = 0, ie = nodes_list.size(); i != ie; i++) {
        FullSourceLoc StartLocation = astContext->getFullLoc(nodes_list[i]->getBeginLoc());
        FullSourceLoc EndLocation = astContext->getFullLoc(nodes_list[i]->getEndLoc());
	if (!StartLocation.isValid() || !EndLocation.isValid()) 
	  continue;

	int line  = EndLocation.getSpellingLineNumber();
        int column = EndLocation.getSpellingColumnNumber();

	mapped_statments[nodes_list[i]] = -1;
	for (int j = 0, je = separator_ref.size(); j != je; j++) {
          if (separator_ref[i].first == line) {
            if (separator_ref[i].second >= column) {
              mapped_statments[nodes_list[i]] = j + 1;
	      break;
	    }
	  }
	  else if (separator_ref[i].first > line) {
            mapped_statments[nodes_list[i]] = j + 1;
	    break;
	  }
	}
	if (mapped_statments[nodes_list[i]] == -1)
	  mapped_statments[nodes_list[i]] = separator_ref.size();

	// Associate the statment with a relative position. Provides facilities to recover the relative position
	// after this process
	struct InputFile& currFile = FileStack.top();
	
	currFile.mapStmtInstID[nodes_list[i]].filename = currFile.filename;
	currFile.mapStmtInstID[nodes_list[i]].functionName = functionName;
	currFile.mapStmtInstID[nodes_list[i]].functionLoopID = loopID;
	currFile.mapStmtInstID[nodes_list[i]].loopInstructionID = mapped_statments[nodes_list[i]];

	std::string index = std::string();
	index += currFile.filename + "," + functionName + ",";
        index += std::to_string(loopID) + "," + std::to_string(mapped_statments[nodes_list[i]]);

	if (currFile.mapInstIDStmt.count(index) == 0) {
          currFile.mapInstIDStmt[index] = nodes_list[i];
          if (jsonFile->directives.count(index) > 0) {
            rewriter.InsertText(st->getBeginLoc(),jsonFile->directives[index], true, true);
            rewriter.overwriteChangedFiles();
          }
        }

	currFile.mapInstIDStmt[index] = nodes_list[i];
      }
    }

    /*Initializes a new input file and pushes it to the top of the file stack*/
    void NewInputFile(string filename) {
      struct InputFile newfile;
      
      filename.erase(filename.begin(), filename.begin() + filename.rfind("/") + 1);
      newfile.filename = filename;
      FileStack.push(newfile);

    }

    /*visits all nodes of type decl*/
    virtual bool VisitDecl(Decl *D) {
	if (FunctionDecl *FD = dyn_cast<FunctionDecl>(D)) {
      	  if (FD->doesThisDeclarationHaveABody()) {
	    const SourceManager& mng = astContext->getSourceManager();
            if (astContext->getSourceManager().isInSystemHeader(D->getLocation())) {
              return true;
            }

	    string dirname = mng.getFilename(D->getBeginLoc());

	    if (dirname.rfind("/") == std::string::npos)
              return true;
	    dirname.erase(dirname.begin() + dirname.rfind("/"), dirname.end());
        
	    if ((this->json != std::string()) && (dirname != std::string())) {
              string jsonName = dirname + "/" + this->json;
      	      jsonFile = new JSONParser(jsonName);
            }

	    string filename = mng.getFilename(D->getBeginLoc());
	    if (FileStack.empty() || FileStack.top().filename != filename) {
      	       NewInputFile(filename);
            }

	    struct InputFile& currFile = FileStack.top();
	    vector<Stmt*> nodes_list;
            visitNodes(FD->getBody(), nodes_list);
	    string functionName = FD->getNameInfo().getName().getAsString();

            // Create information about the function, and associate it with the statment
	    currFile.mapStmtInstID[FD->getBody()].filename = currFile.filename;
            currFile.mapStmtInstID[FD->getBody()].functionName = functionName;
            currFile.mapStmtInstID[FD->getBody()].functionLoopID = -1;
            currFile.mapStmtInstID[FD->getBody()].loopInstructionID = -1;

	    // Associate index with statmtnt
            std::string index = std::string();
            index += currFile.filename + "," + functionName;
            currFile.mapInstIDStmt[index] = FD->getBody();

	    // Map loops correctly, to assing the identifier
	    map<int, Stmt*> loops;
	    for (int i = 0, ie = nodes_list.size(); i != ie; i++) {
              if (isa<DoStmt>(nodes_list[i]) || isa<ForStmt>(nodes_list[i]) || isa<WhileStmt>(nodes_list[i])) {
                FullSourceLoc StartLocation = astContext->getFullLoc(nodes_list[i]->getBeginLoc());
                FullSourceLoc EndLocation = astContext->getFullLoc(nodes_list[i]->getEndLoc());
	        if (!StartLocation.isValid() || !EndLocation.isValid()) 
		  continue;

	        int line  = StartLocation.getSpellingLineNumber();
                loops[line] = nodes_list[i];
	      }
	    }
	    
	    // For each loop, assign the correct id the the statment 
	    int id = 0;
	    for (map<int, Stmt*>::iterator I = loops.begin(), IE = loops.end(); I != IE; I++) {
              id++;

	      Stmt *st = nullptr;
	      if (ForStmt *forst = dyn_cast<ForStmt>(I->second))
		st = forst;
	      if (DoStmt *dost = dyn_cast<DoStmt>(I->second))
		st = dost;
	      if (WhileStmt *whst = dyn_cast<WhileStmt>(I->second))
		st = whst;
	
              // Create information about the function, and associate it with the statment
              currFile.mapStmtInstID[st].filename = currFile.filename;
              currFile.mapStmtInstID[st].functionName = functionName;
              currFile.mapStmtInstID[st].functionLoopID = id;
              currFile.mapStmtInstID[st].loopInstructionID = -1;

              // Associate index with statmtnt
              std::string index = std::string();
              index += currFile.filename + "," + functionName + "," + std::to_string(id);
              if (currFile.mapInstIDStmt.count(index) == 0) {
	        currFile.mapInstIDStmt[index] = I->second;
		if (jsonFile->directives.count(index) > 0) {
		  rewriter.InsertText(st->getBeginLoc(),jsonFile->directives[index], true, true);
		  rewriter.overwriteChangedFiles();
		}
	      }
	
	      if (ForStmt *forst = dyn_cast<ForStmt>(I->second))
		st = forst->getBody();
	      if (DoStmt *dost = dyn_cast<DoStmt>(I->second))
		st = dost->getBody();
	      if (WhileStmt *whst = dyn_cast<WhileStmt>(I->second))
		st = whst->getBody();

	      if (CompoundStmt *cmps = dyn_cast<CompoundStmt>(st))
		st = cmps->body_front();

	      recoverCodeSnippetsID(st, functionName, id);
	    }
	  }
	}
      return true;
    }

    /*Recover lines using abstract handles.*/
    int getLineForAbstractHandle(std::string index) {
      struct InputFile& currFile = FileStack.top();
      FullSourceLoc StartLocation = astContext->getFullLoc(currFile.mapInstIDStmt[index]->getBeginLoc());
      FullSourceLoc EndLocation = astContext->getFullLoc(currFile.mapInstIDStmt[index]->getEndLoc());
      return StartLocation.getSpellingLineNumber();
    }
};

class PragmaASTConsumer : public ASTConsumer {
private:
    PragmaVisitor *visitor; // doesn't have to be private

public:
    /*override the constructor in order to pass CI*/
    explicit PragmaASTConsumer(CompilerInstance *CI, std::string json)
        : visitor(new PragmaVisitor(CI, json)) // initialize the visitor
    { }

    /*we override HandleTranslationUnit so it calls our visitor
    after parsing each entire input file*/
    virtual void HandleTranslationUnit(ASTContext &Context) {
        /*traverse the AST*/
        visitor->TraverseDecl(Context.getTranslationUnitDecl());

    }
};

class PragmaPluginAction : public PluginASTAction {
protected:
    std::string json = std::string();

    /*This gets called by Clang when it invokes our Plugin.
    Has to be unique pointer (this bit was a bitch to figure out*/
    unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, 
                                              StringRef file) {
        return make_unique<PragmaASTConsumer>(&CI, this->json);
    }

    /*leaving this here as a placeholder for now, we can implement a function
    here to evaluate and handle input arguments, if ever necessary*/
    bool ParseArgs(const CompilerInstance &CI, const vector<string> &args) {
      	for (unsigned i = 0, e = args.size(); i != e; ++i) {
      	if (args[i].find("-write-json=") == 0) {
          this->json = args[i];
	  this->json.erase(this->json.begin(), this->json.begin() + 12);
        }
      }
      return true;
    }
};

/*register the plugin and its invocation command in the compilation pipeline*/
static FrontendPluginRegistry::Add<PragmaPluginAction> X
                                               ("-write-omp", "OMP Writer");
