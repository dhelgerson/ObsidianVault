# Evolutionary Computing
- "just another tool in the toolbox" -me
## Genetic Algorithm
- can be considered intelligence (Alan Turing's def)
- a set of rules enforced upon a population
- the population improves until the population is better than the prev.
- Population: set of possible answers. usually the best is chosen
- **Neo-Darwinism** is the name for this way of optimization through *mutation*.
- **Evolutionary Fitness** a measure of the organism's ability to anticipate changes in its environment. 
	- "how fit you are compared to the environment" -SR
	- in our algorithm, our fitness function is how we evaluate which units will "reproduce". 
- if you want to find solutions through generations, you need to first provide a representation of the solutions
- each artificial "chromosomes" consist of a number of "genes" which are represented in binary 
- the challenge of genetic algorithm is figuring out a way to represent the genes
steps for a genetic algorithm:
1. represent the problem variable domain as a chromosome of fixed length. chose population $N$, the crossover probability $p_c$ and the mutation probability $p_m$
	- $p_m$ - you flip a single gene - very rare
	- $p_c$ - you flip 2 genes - less rare
2.  define a fitness function to measure the performance of an individual chromosome in the problem domain. 
3. Randomly generate an initial population of size $N$
4. Calculate the fitness
5. prune
6. create pair of offspring chromosomes
7. place created offspring in new population
8. Repeast Step 5. until size of new chromosome propulation becomes eual to size of initial pop.
- GA represents an iterative process. each iteration is called a gen.. a typical number of generations for a simple GA can range from 50 to over 500. there's no way to know
- because GAs use a stochastic search method, the fitness of a pop. may remain stable for a number of generations before a superior chromosome appears
- common practice is to terminate a GA after a specified number of gen.s and then examine the best ind. in the pop. if no satisfactory solution is found, the GA is restarted.
### $EX$:
We want to find the max value for $(15x-x^2)$
**Fitness function**: $f(x)=(15x-x^2)$
- we encode a string of binary as an integer for the value of $x$
- randomly assign ind. to fill pop. $N$
- Follow above steps