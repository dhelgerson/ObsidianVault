# Intro to prog lang
##  domains of langs
- scientific: e.g fortran
- business: e.g. cobol
- AI: e.g. lisp
- web: e.g. html
## lang evaluation
- readability
- writability
- reliability
- cost
## lang categories
- imperative: e.g. c
- functional: e.g. lisp
- logical: prolog
- markup: markdown
# Finite-state Automata
abstract of a computer. accepts regular language. has: input, control, output
## DFA
- Exactly one transition per symbol
- no empty string transitions
- can have multiple accept states
- unambiguous
## NFA
- paths not provided are assumed thrown away
- can also have multiple accept states
- the same input can have multiple paths
- can accept the empty string
## Comparison
- NFA's don't have to account for every path
- NFA's can accept the empty string, leading to a different path altogether
## Example conversion
![[Screenshot from 2026-03-04 14-11-57.png]]
Start from the beginning. chart through until everything is accounted for. Make sure every state has a transition for every symbol.
# Grammars
## BNF
```
<expression> -> <thing> TOKEN | <thing> OTHERTOKEN
<expression> -> <expression> thing | thing
```
- no optional tokens
- no list of options
## EBNF
- adds optional parts `[]` for one and `{}` for many
```
<expression> -> <thing> (TOKEN | OTHERTOKEN)
<expression> -> {<expression>} thing
```
