/*****************************************************************************
 *   rules.l - Flex Rules for TIPS Language Subset
 *   MSU CSE 4714/6714 Capstone Project (Fall 2025)
 *   Author: Derek Willis
*****************************************************************************/
%option noyywrap nodefault nounput
%option yylineno

%{
#include "lexer.h"
%}

%%
 /* DEFINE YOUR RULES STARTING HERE */

 /* Ignore Whitespace */
[ \t\r\n]+ {}

 /* keywords */
PROGRAM { return PROGRAM; }
BEGIN { return TOK_BEGIN; }
END { return END; }
WRITE { return WRITE; }

 /* punctuation */
\; { return SEMICOLON; }
\( { return OPENPAREN; }
\) { return CLOSEPAREN; }

 /* IDENT */
[A-Z][A-Z0-9]{0,7} { return IDENT; }

 /* STRINGLIT */
\'[^\n\']{0,80}\' { return STRINGLIT; }

 /* catch all */
. { return UNKNOWN; }

 /* EOF */
<<EOF>> { return TOK_EOF; }

%%