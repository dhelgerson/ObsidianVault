## Design Phase
- bridges the gap between requirements and implementation
- make a plan for the implementation
	- object-oriented
	- procedural
- identify the structs that underline the problem to be solved
### discover classes
- they correlate with nouns
- their functions correlate to functions(methods)
- identify their:
	- responsibilities
	- relationships
- determine required output
### what makes a bad class:
- if you can't tell from the name what the object is supposed to detail, you're probably not on the right track
- don't turn an action into a class e.g.
	- 'checkout' class
### cohesion
- all of your functions and data attributes within a class should be cohesive
	- all the features should be directly related to the concept that the class represents
- if the class covers mult. concepts, it should likely be separate classes
### coupling
- a class depends on another class or its functions uses the other class
- coupling should be low (ig)