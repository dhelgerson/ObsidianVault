## Inference Chaining

### Propositional Logic
- statements are concrete
- they're either true or false. nowhere inbetween
- llm's don't do reasoning

### How CLIPS Works
- you have a fact base
- you have an agenda ( a list of things that you want to do but it may not happen)
    - the agenda should have a priority rank. this is so that if you have a conflict with your agenda, you can logically conclude the correct solution
- you should check your agenda before you evaluate any proposition

### forward vs. backward chaining
- forward chaining - regular conclusion
- backward chaining - you already have an assumption and you need to go through your logic to prove that your assumption is correct

## Markov agorithm
- ordered group of production applied in order of priority to an input string
- inefficent algorithm
- termination on last production or if the rule has a period
* see notes

## Rete's algorithm
- 

## Methods used for conflict resolution
- in simple systems,priority can be established by the position in the list
- in clips?, fire the rules that uses the most recently entered data 

## Advantages and Disadvantages of rule-based systems
- inability to learn
    - this has been circumvented with clever logic
## Metarules
1. rules supplied by an expert have higher priorities than rules supplied by novice
2. rules governing the rescue of human lives have higher priorities than rules concerned with clearing