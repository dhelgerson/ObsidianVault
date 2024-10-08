up through the fuzzy expert systems. 
history won't be on the exam
review lectures 2-4
some of the questions will reflect the quiz. others are more in depth
Look over inference engine cycle (starting w/ conflation)
![[Pasted image 20241008084802.png]]
![[Pasted image 20241008082247.png]]
quiz serves to emphasize what WILL be on the exam. questions not verbatim

1 question will require a simple clips program to be written
- not picky about syntax but has to look like clips
review clips control models
at least 1 probability/Bayesian theory problem
examples on phase/salience at the end of slide-set
### Questions from quiz 1:
1. What are the main components of an expert system? Briefly describe each one.
	- the rule base - a list of antecedent-rule pairs for inferencing
	- the fact base - a list of facts to be considered at this inference time
	- the inference engine - the system that goes through the rules w/ the given facts and evaluates them
	- the user interaction - a method for the user to interact w/ the expert system (terminal in most cases(clips))
2. Describe the inference engine cycle in detail.
	- Conflict Resolution - engine checks the agenda and fires the highest matching priority
	- execution - perform the actions defined in the rule-base
	- match - update the agenda, adding and removing necessary rules in the agenda
3. Describe forward and backward chaining. provide an example for each. 
	- forward chaining is the standard arrangement of expert systems, you have facts, and you want to know what they mean.
	- backward chaining is when you already believe you know what the facts mean and you want to double-check yourself.
4. What are the limitations of expert systems?
	- expert systems are limited by their very specific domain. they cannot answer questions outside of it. 
	- they also cannot answer questions they have not already been a rule for.
5. What is the difference between Post Production method and Markov algorithm? What are the pros and cons of Markov's algorithm?
	- post production will fire any and all rules who's antecedent matches the given scenario. Markov's algorithm will start at the top and work its way down until it can fire a rule, then it'll return back to the top for another go.