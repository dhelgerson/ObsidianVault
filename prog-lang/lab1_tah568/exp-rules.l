 /*********************************************************************
  Name: Drew Helgerson             NetID: tah568
  Course: CSE 4714              
  Lab: 01 - Lexical Analyzer 
  Purpose of File: Contains the ....


 This is the file that you should modify for Lab 1.
 **********************************************************************/

 /*=====================================================================
  Lab 1 - exp-rules.l  (Starter Skeleton)

  Edit this file to complete the Lab 1 assignment.
  Only Sections B (Definitions) and C (Rules) need changes.
 =====================================================================*/

 /*------------------------------
  Section A: Options & Includes
  (Leave this alone)
 ------------------------------*/
%option noyywrap      
%option nounput       
%option noinput       

%{
  #include <stdio.h>
  #include "lexer.h"

  int line_number = 1;   /* Driver uses this */
%}

 /*------------------------------
  Section B: Definitions (Macros)
  Add more macros if helpful.
 ------------------------------*/
DIG    [0-9]
YEAR   {DIG}{DIG}{DIG}{DIG}

 /*------------------------------
  Section C: Rules
  Each regex → return TOKEN.
  Examples are given; fill in the rest.
 ------------------------------*/
%%
[ \t\r]+        { /* skip spaces" ", tabs"\t", OR carriage returns "\r"... which appear one or more times "+" */ }

 /* TODO: Increment line_number whenever there is a newline character */
"\n"            { ++line_number; }

 /* Example: punctuation */
,             { return SEPARATOR; }

 /* Example: simple words (case-insensitive first letter) */
[Yy]es          { return YES; }
[Nn]o           { return NO; }

 /* TODO: Add rule for Date */
[0-9]{4}\/[0-9]{2}\/[0-9]{2} { return DATE; }

 /* TODO: Add rule for "Unknown" → UNKNOWN_VALUE */
[Uu]"nknown" { return UNKNOWN_VALUE; }

 /* TODO: Add rule for "Missing" → MISSING */
[Mm]"issing" {return MISSING; }

 /* TODO: Add rules for Case Status (Laboratory-confirmed, Probable) */
[Ll]"aboratory-confirmed "[Cc]"ase" { return LABORATORY; }
[Pp]"robable "[Cc]"ase" {return PROBABLE; }

 /* TODO: Add rules for Gender (Male, Female, Other) */
[Ff]"emale" { return FEMALE; }
[Mm]"ale" { return MALE; }
[Oo]"ther" { return OTHER; }

 /* TODO: Add rules for Age buckets (0-9 Years ... 80+ Years) */
"0 - "[0-9]+" "[Yy]"ears"   { return AGE_0X; }
"10 - 19 "[Yy]"ears" { return AGE_1X; }
"20 - 39 "[Yy]"ears" { return AGE_2X; }
"40 - 49 "[Yy]"ears" { return AGE_4X; }
"50 - 59 "[Yy]"ears" { return AGE_5X; }
"60 - 69 "[Yy]"ears" { return AGE_6X; }
"70 - 79 "[Yy]"ears" { return AGE_7X; }
"80+ "[Yy]"ears" { return AGE_8X; }

 /* TODO: Add rules for quoted ethnicity/race phrases */
\"[^\"]*[Aa]sian[^\"]*\" { return ASIAN; }
\"[^\"]*[Bb]lack[^\"]*\" { return BLACK; }
\"[^\"]*[Pp]acific[ -][Ii]slander[^\"]*\" { return PACIFIC_ISLANDER; }
\"[^\"]*[Ww]hite[^\"]*\" { return WHITE; }
\"[^\"]*[Mm]ultiple\/[Oo]ther[^\"]*\" { return MULTIPLE_OTHER; }
\"[^\"]*[Aa]merican[ .][Ii]ndian\ [^\"]*\" { return NATIVE_AMERICAN; }
\"[^\"]*[Nn]ative[ .][Aa]merican[^\"]*\" { return NATIVE_AMERICAN; }
\"[^\"]*[Hh]ispanic\/[Ll]atino[^\"]*\" { return HISPANIC; }
 /* Not sure if I was supposed match just the first so */
 /* these match it as long as it's in the quotes */

 /* End-of-file */
<<EOF>>         { return EOF_TOKEN; }

 /* Anything else → unknown */
.               { return UNKNOWN_TOKEN; }

%%



