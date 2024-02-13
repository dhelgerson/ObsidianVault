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
	- $mean \equiv \mu = E(X) = \sum\limits _x xf(x) = \sum\limits _x x * P(X = x)$ 
- **Variance:** is a measure of ht dispersion, or variability of a distribution
	- $variance \equiv \overline{z}(X_2 - \mu)$ 
	$V(X)=E(x^2) - E(x)^2 = E(x^2)- \mu^2$ 
	$\sigma^2 = V(x) = E((x-\mu)^2)$
	$= \sum\limits_{i=1}^n (x_i - \mu)^2 + x_2^i)$
	$=\sum\limits_{i=1}^n x_i^2 + x_i - 2\mu x_i + x_i + \mu^2 + x_i$
	$=\sum\limits_{i=1}^n x_i^2 + x_i - 2\mu \sum\limits_{i=1}^n x_i + x_i + \mu^2 \sum\limits_{i=1}^n + x_0$
	$=E(x^2) - \mu^2$
$Ex:$
	there's a chance that a bit transmitted through a digital transmission channel is received in error. let $X$ equal the number of bits in the error that the next four bits transmitted. the possible values for $X$ are ${0,1,2,3,4}$. suppose that the probabilities are
## Bayes' theorem
## Discrete random variable
mean value/expected value
	$\mu = E(x)=\sum\limits_{i=1}^{n} x: f(\mu_i)$ 
variance
	$\sigma^2=V(x)=E(x-\mu)^2=\sum\limits_{i=1}^n(x_i-\mu)^2+x_i=E(x^2)-\,u^2$ 
$Ex$: let x be the change be the number of incorrect bits in the next 4
suppose:
	$\mu = E(X)=0f(0)+1f(1)+2f(2)+3f(3)+4f(4)=.4$ 
	$\sigma^2=V(x)=\sum\limits_{i=1}^n(x_i-\mu)^2=0.36$ 
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
	
	$\mu=\sum\limits_{k=a}^b(\dfrac{k}{b-a+1})=\dfrac{a+b}{2}$
	
	$\sigma^2=\dfrac{(b-a+1)^2-1}{12}$
$Ex$: binomial distribution
	$f(x)=(^n_x)p^x(1-p)^{n-x}x=0,1,...,n$ 
	$\mu=E(X)=np$
	$\sigma^2=V(X)=np(1-p)$ 
$Example$ -> the chance that a bit transmitted is in error is 0.1. also, assume that the transmission trials are independent.
	$X =$ the number of bits in error in the next 4 bits.
	Determine $P(X=2)$
	$E=error, O=okay$
	6 outcomes where $X=2$: $\{EEOO,EOEO,EOOE,OEOE,OEEO,OOEE\}$ 
	$P(EEOO)=.1*.1*(1-.1)*(1-.1)$
	$P(EEOO)=.1^2*.9^2$
	$P(EEOO)=0.0081$ 
	this is true for all $P(X=2)$ 
$Ex$: Poisson Distribution
	$Po(\lambda)$ 
	Poisson charts how likely an event will happen in a standard time interval
	$P(Y)=\dfrac{\lambda^ye^{-\lambda}}{y!}$  
	$(^n_x)(\dfrac{\lambda T}{n})\rightarrow\dfrac{(\lambda T)^x}{x!}(1-\dfrac{\lambda T}{n})^{-x}\rightarrow1(1-\dfrac{\lambda T}{n})^n\rightarrow e^{-\lambda T}$ 
$Ex$: Cumulative Distribution
	$F(x)=P(X\leq x)=\int\limits_{-\infty}^xf(u)du\ for\ -\infty<x<\infty$ 
	- remember you can always break up integrals by summing different segments of the domain
	$\mu=E(X)=\int\limits_{-\infty}^{\infty}xf(x)dx$ 
	$\sigma^2=V(X)=\int\limits_{-\infty}^{\infty}(x-\mu)^2f(x)dx=\int\limits_{-\infty}^{\infty}x^2f(x)dx-\mu^2$ 
$P(x<4.95)=F(4.95)=5*4.95-24.5$ 
	probability at any point in a CDF is 0 since $\int\limits_a^b(u)du$ where $b=a$ is just $\int\limits^a_a(u)du=u(a-a)=0$ 
## probability mass function
## cumulative distribution functions 