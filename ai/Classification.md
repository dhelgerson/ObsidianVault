# Inductive Bias
- most people, about 2/3, think class A(see slides) is birds and class B is mammals
- Others, about 1/3, think Class A is animals that fly and class B is animals that don't
- The test examples are classified differently depending on how the training data is generalized
- the difference in whether we generalize the training data one way or the other is not based on anything in the data! it reflects our "inductive bias"
Inductive bias is necessary because learning in an ill-posed problem; the training data is not sufficient to find a unique solution
any time we have more possible outputs than given outputs, there's more than one answer that will satisfy the constraints. this is where inductive bias' come in to play. 
## Dec tree
when the decision tree learning algorithm uses the information gain heuristic to select the next attribute to test, it tends to find smaller decision tress
this is an example of inductive bias because there is nothing in the training data that indicates smaller trees are better. 

## Key principle of machine learning
given feature/target pairs $(X_1, y_1)$, ... ,$(X_n,y_n)$:
if $X_i$ is similar to $X_j$, then $y_i$ is probably similar to $y_j$

# Nearest neighbor classification
Simple idea:
- store all the training examples
- classify new examples based on most similar training example
	some math is involved in finding where they should be placed (different distance formulas)
problem with this is you have to fine-tune how many nearest neighbors you consider.
Disadvantes of k-nearest neighbor
- sensitive to irrelevant features
- doesn't produce an understandable model
Inductive bias of k-nearest neighbor
- assumes the classification of an instance x will be most similar to the classification of other instances that are nearby in Euclidean distance
