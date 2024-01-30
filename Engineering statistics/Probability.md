# recap:
## sample space
## counting techniques
## probability
- looks like this: $C_1^6$ 
	Ex 1: 
		A: get a number 2 when rolling a die
		B: get an even number
		$P(A) = \dfrac{1}{6}$
		$P(B) = \dfrac{3}{6}$ 
		P(A|B) = 100%
		$P(B \vee A) = \dfrac{1}{6}$
	Ex 2:
		roll 2 die, $X_1$ $X_2$:
		A: $X_1$ is 2
		B: $X_1 + X_2 > 5$ 
		$P(A|B) = \dfrac{P(B\wedge A)}{P(A)} = \dfrac{\dfrac{B\wedge A}{n}}{\dfrac{A}{n}} = \dfrac{B\wedge A}{A} = \dfrac{3}{6}$ 
		$P(B\wedge A) = \dfrac{3}{6}$ 
	**General Rule:** $P(A|B) = \dfrac{P(B\wedge A)}{P(B/A)}$  
## conditional probability
- **Mean:** is a measure of the center or middle of the probability distribution
	- $mean \equiv \mu = E(X) = \sum _x xf(x) = \sum _x x * P(X = x)$ 
- **Variance:** is a measure of ht dispersion, or variability of a distribution
	- $variance \equiv \overline{z}(X_2 - \mu)$ 
- $V(X)=E(x^2) - E(x)^2 = E(x^2)- \mu^2$ 
- $\sigma^2 = V(x) = E((x-\mu)^2)$
- $= \sum_{i=1}^n (x_i - \mu)^2 + x_2^i)$
- $=\sum_{i=1}^n x_i^2 + x_i - 2\mu x_i + x_i + \mu^2 + x_i$
- $=\sum_{i=1}^n x_i^2 + x_i - 2\mu \sum_{i=1}^n x_i + x_i + \mu^2 \sum_{i=1}^n + x_0$
- $=E(x^2) - \mu^2$
$Ex:$
	there's a chance that a bit transmitted through a digital transmission channel is recieved in error. let $X$ equal the number of bits in the error that the next four bits transmitted. the possible values for $X$ are ${0,1,2,3,4}$. suppose that the probabilities are
## Bayes' theorem
## discrete random variable
## probability mass function
## cumulative distribution functions