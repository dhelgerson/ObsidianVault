// =============================================================================
//   ast.h 
// =============================================================================
// MSU CSE 4714/6714 Capstone Project (Spring 2026)
// Author: Derek Willis
// =============================================================================
#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#pragma region setup

// -----------------------------------------------------------------------------
// Pretty printer
// -----------------------------------------------------------------------------
inline void ast_line(ostream& os, string prefix, bool last, string label) {
  os << prefix << (last ? "└── " : "├── ") << label << "\n";
}

struct Statement {
  virtual ~Statement() = default;
  virtual void print_tree( ostream& os, string prefix, bool last) = 0 ;
  virtual void interpret( ostream& os ) = 0 ;
};

// TODO: Define and Implement structures to hold each data node!
// Tip: Build with the root of your tree as the lowest struct in this file
//      Implement each higher node in the tree HIGHER up in this file than its children
//      i.e. The root struct at the bottom of the file
//           The leaves of the tree toward the top of the file

#pragma endregion

// ----------------------------------------------------------------------------
// write → WRITE OPENPAREN STRINGLIT CLOSEPAREN
// ----------------------------------------------------------------------------
struct Write : Statement
{
  string strlit;
  void print_tree( ostream& os, string prefix, bool last ) {
    ast_line( os, prefix, false, "write" ) ;
    ast_line( os, prefix+"│   ", false, "WRITE" ) ;
    ast_line( os, prefix+"│   ", false, "OPENPAREN" ) ;
    ast_line( os, prefix+"│   ", false, "STRINGLIT("+strlit+")" ) ;
    ast_line( os, prefix+"│   ", true, "CLOSEPAREN" ) ;
  }

  void interpret( ostream& os ) {
    cout << strlit << endl ;
  }
};

// ----------------------------------------------------------------------------
// compound → TOK_BEGIN statement { SEMICOLON statement } END
// ----------------------------------------------------------------------------
struct Compound : Statement
{
  vector<unique_ptr<Statement>> statements;

  void print_tree( ostream& os, string prefix, bool last ){
    ast_line( os, prefix, last, "compound" ) ;
    string childPrefix = prefix + (last ? "    " : "│   ") ;
    ast_line( os, childPrefix, false, "TOK_BEGIN" ) ;
    for ( unique_ptr<Statement>& statement : statements ) {
      ast_line( os, childPrefix, false, "SEMICOLON" ) ;
      statement->print_tree( os, childPrefix, false ) ;
    }
    ast_line( os, childPrefix, true, "END" ) ;
  }
  
  void interpret( ostream& os ) {
    for ( unique_ptr<Statement>& statement : statements ) {
      statement->interpret(os) ;
    }
  }
};

// ----------------------------------------------------------------------------
// block → compound
// ----------------------------------------------------------------------------
struct Block : Statement
{
  // TODO: Declare Any Member Variables
  unique_ptr<Compound> compound;

  // Member Function to Print
  void print_tree(ostream& os, string prefix, bool last ){
    ast_line( os, prefix, true, "block" ) ;
    if (compound) compound->print_tree( os, prefix+"    ", true ) ;
  };

  // Member Function to Interpret
  void interpret( ostream& os ){
    // TODO: Finish this function
    if (compound) compound->interpret(os) ;
  };
};

// ----------------------------------------------------------------------------
// program → PROGRAM IDENT SEMICOLON block
// You do not need to edit this struct, but can if you choose
// ----------------------------------------------------------------------------
struct Program
{
  // Member Variables
  string name; 
  unique_ptr<Block> block;

  // Member Functions
  void print_tree(ostream& os)
  {
    cout << "program\n";
    ast_line(os, "", false, "NAME(" + name + ")");
    if (block) block->print_tree(os, "", true);
    else 
    { 
      ast_line(os, "", true, "Block"); 
      ast_line(os, "    ", true, "(empty)");
    }
  }

  void interpret(ostream& out) 
  { 
    if (block) block->interpret(out); 
  }
};