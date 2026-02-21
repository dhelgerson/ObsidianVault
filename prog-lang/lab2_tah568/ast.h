#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------
// Forward declarations
// -----------------------------------------------------------------------------
struct Node;
struct AdjectivePhrase;
struct NounPhrase;
struct VerbPhrase;
struct Sentence;

// -----------------------------------------------------------------------------
// Grammar 
// -----------------------------------------------------------------------------
// <sentence>         -> <noun phrase> <verb phrase> <noun phrase>
// <noun phrase>      -> <adjective phrase> NOUN
// <adjective phrase> -> (ARTICLE | POSSESSIVE) ADJECTIVE
// <verb phrase>      -> VERB | ADVERB <verb phrase>
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Pretty printer (tree-style)
// -----------------------------------------------------------------------------
inline void ast_line(ostream& os, string prefix, bool last, string label)
{
    os << prefix << (last ? "+-- " : "|-- ") << label << "\n";
}

// -----------------------------------------------------------------------------
// Base AST node
// -----------------------------------------------------------------------------
struct Node {
    virtual ~Node() = default;
    virtual void print_tree(ostream& os, string prefix, bool last) = 0;
};

// -----------------------------------------------------------------------------
// Student AST design area
// -----------------------------------------------------------------------------
// TODO (Lab 2): Design your AST structs.
//
// Requirements:
//  1) There must be ONE AST node per nonterminal in the grammar above.
//  2) Store lexeme strings from yytext (e.g., "the", "my", "big", "dog", ...).
//  3) Every node must implement print_tree(...) using ast_line(...).
//  4) Keep the file in "top-down" order if you want (Sentence first), but if you
//     do that you may need out-of-line print_tree definitions to avoid
//     incomplete-type errors.
//
// Suggested (not required) node names:
//   Sentence, NounPhrase, VerbPhrase, AdjectivePhrase
//
// Tip: VerbPhrase can be represented as (ADVERB)* VERB in your AST.
//

// --- Put your structs below this line ----------------------------------------

// -----------------------------------------------------------------------------
// <sentence>         -> <noun phrase> <verb phrase> <noun phrase>
// -----------------------------------------------------------------------------
struct Sentence : Node 
{
    unique_ptr<NounPhrase> firstNoun ;
    unique_ptr<VerbPhrase> verb ;
    unique_ptr<NounPhrase> scndNound ;
};
// -----------------------------------------------------------------------------
// <noun phrase>      -> <adjective phrase> NOUN
// -----------------------------------------------------------------------------
struct NounPhrase : Node 
{
    unique_ptr<AdjectivePhrase> adj ;
    string noun ;
};
// -----------------------------------------------------------------------------
// <adjective phrase> -> (ARTICLE | POSSESSIVE) ADJECTIVE
// -----------------------------------------------------------------------------
struct AdjectivePhrase : Node
{
    string qual ;
    string adj ;
};
// -----------------------------------------------------------------------------
// <verb phrase>      -> VERB | ADVERB <verb phrase>
// -----------------------------------------------------------------------------
struct VerbPhrase : Node
{
    string adverb ;
    unique_ptr<VerbPhrase> verb ;
};