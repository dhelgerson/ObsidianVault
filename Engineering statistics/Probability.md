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
		$P(B \cup A) = \dfrac{1}{6}$
	Ex 2:
		roll 2 die, $X_1$ $X_2$:
		A: $X_1$ is 2
		B: $X_1 + X_2 > 5$ 
		$P(A|B) = \dfrac{P(B\cap A)}{P(A)} = \dfrac{\dfrac{B\cap A}{n}}{\dfrac{A}{n}} = \dfrac{B\cap A}{A} = \dfrac{3}{6}$ 
		$P(B\cap A) = \dfrac{3}{6}$ 
	**General Rule:** $P(A|B) = \dfrac{P(B\cap A)}{P(B/A)}$  
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
	there's a chance that a bit transmitted through a digital transmission channel is received in error. let $X$ equal the number of bits in the error that the next four bits transmitted. the possible values for $X$ are ${0,1,2,3,4}$. suppose that the probabilities are
## Bayes' theorem
## discrete random variable
mean value/expected value
$\mu = E(x)=\sum x: f(\mu_i)$ 
variance
$\sigma^2=V(x)=E(x-\mu)^2=\sum_{i=1}^n(x_i-\mu)^2+x_i=E(x^2)-\,u^2$ 
$Ex:$
let x be the change be the number of incorrect bits in the next 4
suppose:
$\mu = E(X)=0f(0)+1f(1)+2f(2)+3f(3)+4f(4)=.4$ 
$\sigma^2=V(x)=\sum_{i=1}^n(x_i-\mu)^2=0.36$ 
	both are taken from empirical values I didn't write down
Alternative formula for variance:
$V(x)=E(x^2)-\mu^2$ 
### Discrete uniform distribution:
- simplest discrete random variable
- finite number of possible values, each w/ equal probability
$f(x_i)=\dfrac{1}{n}$ 
$Ex$: you roll a die:
	$f(x_i)=\dfrac{result}{sides}=\dfrac{1}{6}$ 
$Ex$: all integers from a to b:
	$f(x_i)=\dfrac{1}{b-a+1}$ 
	
	$\mu=\sum_{k=a}^b(\dfrac{k}{b-a+1})=\dfrac{a+b}{2}$
	
	$\sigma^2=\dfrac{(b-a+1)^2-1}{12}$ 
## probability mass function
## cumulative distribution functions 