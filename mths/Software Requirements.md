# software life-cycle
- set of activities that take place between the time the software programs conceived and the time is finally retired
- many engineers break the development process down into the following phases
	- requirement
	- design
	- implementation
	- testing
	- deployment/maintenance
- typically these all happen discretely
## requirements:
- decides what the project is supposed to accomplish
- the only output of this phase is documentation
### Types:
- functional requirements
	- services system provides
		- be as clear as possible
	- how it reacts
	- ex:
		- add thing
		- remove thing
		- login
		- **NOT** *"add/remove"*
	- counter-examples:
		- *having* a homepage
		- *Be able to* this or that
			- be aware of the verb. state of being verbs
		- overly easy things that are probably handled by the framework e.g. "clicking a link"
- non-functional requirements
	- constraints
	- features
	- ex:
		- data integrity
		- efficiency given an amt of users
		- accessibility
		- maintainability
		- portability
		- file size restraints
		- speed
		- etc.
- domain requirements
	- runtime environment
	- etc
- requirements should be:
	- correct/verifieable
	- unambiguous
	- complete
	- consistent
	- prioritized
	- modifiable
	- traceable
	- feasible
	- design independent
	- **non-redundant**
	- **properly prioritized**
### requirement gathering
- who are the stakeholders?
	- people who are monetarily invested as well as those who are using the product
- what documentation is required
- determine functionality required vs. optional
### documentation
- use cases
	- description of how the user interacts
- use case diagrams
	- shows the actors on the left and their interactions on the system
		- a visual representation of the system
	- any external systems on the right (if necessary)
### scenarios
- each scenario will be a single requirement with a unique name and priority
	- high,med,low
	- identifies actors
	- step-by-step walk-through of the system
		- necessary validity checks
		- exact sequences