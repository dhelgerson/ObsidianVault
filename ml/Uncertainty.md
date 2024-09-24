# basic probability theory
- concept of measuring how likely things are
- almost always represented in a range: 0<->1
$P(success)=\dfrac{num success}{total outcomes}$
## Bayesian rule
- $p(A|B)$ is the conditional probability that event a occurs given the event b has occurred
## Illness
HIV is a good example of conditional probabilities
False positives and false negatives in HIV testing are highly undesirable

given:
- true positive: P(elisa is positive|person tested has HIV)=0.93
- True negative: P(elisa is negative|person tested doesn't have HIVI)=0.99
- P(person tested has HIV)=0.00148
We know:
- False positive = 1 - true negative = .07
- False negative = 1 - true positive = .01
Bayes Theorem: $P(A|B) = P(B|A)*P(A)/P(B)$

Goal: $P(HIV|ELISA) = P(HIV\ and\ ELISA)/P(ELISA)$ 

$P(HIV\ and\ ELISA) = P(ELISA|HIV)*P(HIV) = .93 * .00148 = .0013764$
$P(A\ and\ B)=P(A|B)*P(B)$ -^

$P(A)=P(A|B)*P(B)+P(A|\ not\ B))