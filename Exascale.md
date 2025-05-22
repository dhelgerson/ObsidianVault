### Types
- GPU - Massively parallel, weak for single-threaded - 1 power and cooling per rack
- CPU - All-rounder (Basic type)
- TPU - Not much support, Extremely good at it's battles
- Storage - Allows a single job to be stored, decreases a cluster's job runtime by 1 for each rack of storage
### Facility Resources
each facility has a fixed amount of resources, each cluster needs networking
- Power 
- Cooling
- Networking
### Trainers: Support Staff/Students
staff prevent issues, students buff performance. Staff remain throughout play, Trainers are required for cluster operations. each trainer has a perk that will aid in a specific operational circumstance (detailed later)
- Vince (staff) - reduce cluster standups and upgrades by 1 turn - "There is no further escalation"
- Oliver (student) - Code optimization: jobs require 1 less turn to complete - "A scalable code is a slow code"
- Joey (staff) - prevent job failures - "Fix your slurm allocation"
- John (staff) - if administering a storage cluster, datacenter is immune to 1 power outage - "RAID is not a backup"
- Huston (staff) - prevent hardware failures - "This wouldn't happen if we just remove electricity from rock"
- Mike (staff) - increase reward of completed job by 1
- Dawn (staff) - add 1 networking to resource pool
- Drew (student)  - negate 1 security breach - "We already found that one chief"
- Tess (student) - protects against 1 ticket submission 
- Isha (student) - Allow 2 research jobs to be performed by the same cluster. - "proper management is the key to efficiency"
- Soyab (student) - decrease ML job runtime by 1 turn
### Jobs
each job will have base runtime per cluster type. each additional rack in a cluster will decrease runtime by 1 turn.
- ICON - 8cpu, 10gpu, 10tpu, +2
- NAMD - 8cpu, 4gpu, 10tpu, +2
- Training - 16cpu, 6gpu, 3tpu, +3
- Inferencing - 4cpu, 2gpu, 1tpu, +1
- Quantum SIM - 12cpu, 8gpu, 16tpu, +3
- Research - 4cpu, 4gpu, 4tpu, +1
- JtR - 16cpu, 8gpu, 12tpu, +3
- Cloud Serving - read details
	- uses 1 cluster, storage, and 1 extra networking
	- gain +1 for every turn job is run
	- once stopped, job goes back out for bid
	- only 1 cloud card per game
### Commander Cards: Facilities
each deck will have 1 commander. it gives perks and weaknesses. it also determines the amount of resources available based on the turn.
- HPC$^2$ - less resources, but the tight-knit support staff offers some advantages
- New Datacenter - LOTS of space and power
- ORNL - many resources, things take longer to stand up due to red tape, etc.
### Trap Cards:
Issues always arise in cluster administration. trap cards are these issues. different staff members can guard against certain issues
- power outage - all jobs must be restarted
- heat wave - all jobs require 2 more turn to complete
- data breach - Disable use of storage cluster, turning jobs over to bid
- job failure - a single job restarts (roll a die if multiple clusters)
- hardware failure - remove a rack from the cluster (decided upon die roll) and return it to your deck
- Ticket Submission - job takes 1 more turn to complete
### Turn Flow:
- Clusters take multiple Turns to "Stand Up"
- Players compete to complete different "jobs" before other players, playing to cluster strengs and weaknesses
- "trap cards" such as downtime, security breach
- players will have their own decks to with which they'll build out their clusters. 
- the game will also have a global deck which players will draw from
- the global deck will have either jobs, or trap cards. 
- each cluster built can be allocated a job, their types and sizes will determine how long jobs take to complete
- mutually exclusive to jobs, clusters can be upgraded. if a cluster working on a job is upgraded, the job is paused. 
- 
