### Propositions:
- a statement that can be evaluated to true false
	- ex:

| proposition | is prop |
| - | - |
| zero is an even number | y |
| it is raining | y |
| is it raining? | n |
| do your homework | n |
|24 divided by 12 is 6 | y |
| did you do your homework? | n |
### Truth Values:
- one plus one is 2
## Propositional variables:
- variables that can be used to denote arbitrary propositions
	- such as i or j when counting loops
	**Ex:**	
 - p is true and q is false
- **compound propositions**: evaluating propositional variables together
- #### Compound propositions:
	- **Conjunction:** or 'and'
		- denoted by `^`
	- **Disjunction:** or 'or'
		- denoted by `v`
	- **Exclusive Or**:
		- denoted by a circle w/ a plus
	- **Negation**: or 'not'
		- denoted by a little carrot

## order of operations:
## `PNCD`
- parenthesis, not, conjunction disconjunction

### conditional operation
- denoted by an arrow
- read as `if _ then _`

| p | q | p -> q |
| ---- | ---- | ---- |
| t | t | t |
| f | t | f |
| t | f | t |
| f | f | t |

- it's weird

| base | p -> q |
| ---- | ---- |
| converse | q -> p |
| contrapositive | !q -> !p |
| Inverse | !p -> !q |
### Biconditional:
- read `if and only if`

| p | q | p <-> q |
| ---- | ---- | ---- |
| T | T | T |
| T | F | F |
| F | T | F |
| F | F | T |
## Tautology & Contradiction
- tautology - a proposition that only results in true values
- contradiction - proposition that d results in false values

| p | !p | p v !p | p ^ !p |
| ---- | ---- | ---- | ---- |
| T | F | T | F |
| F | T | T | F |
## Logical equivalency:
- propositions that have the same truth value regardless of the truth values of their individual propositions.
- denoted as a triple equal sign
### Propositional Logic Proof:
- see slides on canvas for equivalency laws
### Predicates and modifiers
- mathematical statements generally contain variables
	- x is an odd number
### Predicates:
- **Anything w/ free variables is a predicate, anything w/out is a proposition**
- any logical statement who's truth value is a function of one or more variables is knows as a predicate
- $Q(x,y):x^2=y$
- $Q(5,25)$ is true because $5^2 =25$
### Domain
- set of all possible values
	- typically specified
	- can drastically change the outcome of predicates
- $P(x):x$ is a prime number
	- $P(7)$ True?
### Quantifiers
- predicate has all unknown variables accounted for, it becomes a proposition
- quantifiers let us do this
- $\forall x P(x)$ reads "for all x, p of x" 
	- $\forall$ is a universal modifier
	- $\forall x P(x)$ is true if an only if $P(n)$ is true for every n in the domain of x
- **arbitrary element:**
- $\forall x(\dfrac{1}{x+1} < 1)$
	- the domain is all positive integers: $0<x$
	Proof:
		$0 < x$
		$1 < x+1$
		$\dfrac{1}{x+1} < 1$
- **Counterexample:** an element withing a domain for which a predicate is false
- **Existential modifier:**
	- $\exists x:P(x)$ is true if and only if $P(n)$ is true for at least one value of n in the domain
	- $\exists x:(x + 1 < x)$
- **Quantified Statements:** universally and existentially quantified statements can also be constructed from logical operations
	- domain of all positive integers
		- $P(x):x$ is prime
		- $O(x):x$ is odd
### logical equivalents:
- English statements can be logically equivalent to logical statements
	- "everyone was not sick" $\equiv \forall x:\neg P(x)$ 
- **Demorgans law:**
	- $\neg \forall x:P(x) \equiv \forall x: \neg P(x)$ 

| proposition | truth |
| ---- | ---- |
| $\forall x \forall y:x*y=1$ | false |
| $\exists x\exists y:(x*y=0)$ | true |
| $\exists x \exists y:((x+y=x)\wedge(y\not=0))$ | false |
| $\forall x\exists y:(x*y=1)$ | false |
| $\exists x\forall y:(x*y=1)$ | false |
| $\exists x\forall y:(x*y=y)$ | true |
