#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

#include "lexer.h"
#include "ast.h"
#include "debug.h"

using namespace std;
using Token = int;

// -----------------------------------------------------------------------------
//   <sentence>         -> <noun phrase> <verb phrase> <noun phrase>
//   <noun phrase>      -> <adjective phrase> NOUN
//   <adjective phrase> -> (ARTICLE | POSSESSIVE) ADJECTIVE
//   <verb phrase>      -> VERB | ADVERB <verb phrase>
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// One-token lookahead
// -----------------------------------------------------------------------------
bool   havePeek = false;
Token  peekTok  = 0;
string peekLex;

inline const char* tname(Token t) { return tokName(t); }

Token peek()
{
  if (!havePeek) {
    peekTok = yylex();
    if (peekTok == 0) { peekTok = EOF; peekLex.clear(); }
    else              { peekLex = yytext ? string(yytext) : string(); }
    dbg::line(string("peek: ") + tname(peekTok) + (peekLex.empty() ? "" : " ["+peekLex+"]")
              + " @ line " + to_string(yylineno));
    havePeek = true;
  }
  return peekTok;
}

Token nextTok()
{
  Token t = peek();
  dbg::line(string("consume: ") + tname(t));
  havePeek = false;
  return t;
}

Token expect(Token want, const char* msg)
{
  Token got = nextTok();
  if (got != want) {
    dbg::line(string("expect FAIL: wanted ") + tname(want) + ", got " + tname(got));
    ostringstream oss;
    oss << "Parse error (line " << yylineno << "): expected "
        << tname(want) << " — " << msg << ", got " << tname(got)
        << " [" << (yytext ? yytext : "") << "]";
    throw runtime_error(oss.str());
  }
  return got;
}

// -----------------------------------------------------------------------------
// Forward declarations
// -----------------------------------------------------------------------------
unique_ptr<Sentence> parse_sentence();
unique_ptr<NounPhrase> parse_noun_phrase();
unique_ptr<AdjectivePhrase> parse_adjective_phrase();
unique_ptr<VerbPhrase> parse_verb_phrase();

// -----------------------------------------------------------------------------
// <adjective phrase> -> (ARTICLE | POSSESSIVE) ADJECTIVE
// -----------------------------------------------------------------------------
unique_ptr<AdjectivePhrase> parse_adjective_phrase()
{
    // TODO (Lab 2): implement
    // - read ARTICLE or POSSESSIVE into ap->determiner
    auto ap = make_unique<AdjectivePhrase>() ;
    if ( peek() == ARTICLE ) {
      expect(ARTICLE, "Article before adjective") ;
      ap->article = peekLex ;
    } else if ( peek() == POSSESSIVE ) {
      expect(POSSESSIVE, "Posessive before adjective") ;
      ap->possessive = peekLex ;
    }
    // - read ADJECTIVE into ap->adjective
    expect(ADJECTIVE, "Adjective after article|posessive") ;
    ap->adjective = peekLex ;
    // - return the node
    return ap ;
}


// -----------------------------------------------------------------------------
// <noun phrase> -> <adjective phrase> NOUN
// -----------------------------------------------------------------------------
unique_ptr<NounPhrase> parse_noun_phrase()
{
    // TODO (Lab 2): implement
    // - build noun phrase
    auto np = make_unique<NounPhrase>() ;
    // - parse adjective phrase
    np->adj = parse_adjective_phrase() ;
    // - expect NOUN
    expect(NOUN, "Noun After <adjective phrase>") ;
    np->noun = peekLex ;

    return np ;
}


// -----------------------------------------------------------------------------
// <verb phrase> -> VERB | ADVERB <verb phrase>
// Equivalent to: (ADVERB)* VERB
// -----------------------------------------------------------------------------
unique_ptr<VerbPhrase> parse_verb_phrase()
{
    // TODO (Lab 2): implement
    auto vp = make_unique<VerbPhrase>() ;
    // - consume 0+ ADVERB into vp->adverbs
    if ( peek() == ADVERB ) {
      expect(ADVERB, "Adverb before <Verb Phrase>") ;
      vp->adverb = peekLex ;
      if ( peek() == ADVERB ) {
        vp->verbPhrase = parse_verb_phrase() ;
      } else {
        expect(VERB, "<Verb Phrase> after adverb" ) ;
        vp->verb = peekLex ;
      }
    }

    return vp ;
}


// -----------------------------------------------------------------------------
// <sentence> -> <noun phrase> <verb phrase> <noun phrase>
// -----------------------------------------------------------------------------
unique_ptr<Sentence> parse_sentence()
{
    // TODO (Lab 2): implement
    auto s = make_unique<Sentence>() ;
    // - subject noun phrase
    s->firstNounPhrase = parse_noun_phrase() ;
    // - verb phrase
    s->verbPhrase = parse_verb_phrase() ;
    // - object noun phrase
    s->scndNoundPhrase = parse_noun_phrase() ;

    return s ;
}


// -----------------------------------------------------------------------------
// parse(): entry point called by driver.cpp
// -----------------------------------------------------------------------------
unique_ptr<Sentence> parse()
{
    // Reset lookahead state for a fresh parse
    havePeek = false;
    peekTok = 0;
    peekLex.clear();

    auto root = parse_sentence() ;

    // TODO (Lab 2): parse a sentence and ensure EOF after it
    if (peek() != EOF) {
      ostringstream oss;
      oss << "Parse error (line " << yylineno << "): extra tokens after <sentense>, got " << tname(peekTok) << " [ " << (yytext ? yytext : "") << "]" ;
      throw runtime_error(oss.str()) ;
    }
    return root;
}
