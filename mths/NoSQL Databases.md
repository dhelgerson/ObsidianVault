## Background
- aren't tabular, store things differently than relational databases
	- idea has existed since 1960s
	- the term didn't emerge 'til 21st century
- commonly used in big data and real-time web applications
- sometimes referred to not-only-sql 'cause some have sql like commands
- term first used in 1998
	- though he made a relational database :(
- widely used method was made in 2009
## Data storage
items are stored in 4 main categories:
- [[#Wide-column store]]
- [[#Document store]]
- [[#Key-value store]]
- [[#Graph database]]
### Key-value store
- uses an associaitive array as a basis for storing info
	- similar to python dicts,maps, hash tablels
	- hopefully more performance with larger datasets
- involves having a collection of data
	- each field is associated w/ a key
- there's no basis for how they interact w/ the key-value store
### Wide-column store
- also knows as extensible record store
- uses tables, rows, and columns
	- name and format of each column can vary from row to row
	- this is the opposite of relational databases
- often interpreted as a 2-dimensional key-value store
- also no benchmark for how you access data
### Document store
- central idea here, literally that of a document
- documents are referenced by unique keys in a database
- access data by parsing the given document
### Graph database
- only really usable by certain data
	- must be represented by a graph
	- social relations, public transportation, road maps, etc
- uses graph theory to access data
	- different graphs have different ins-and-outs for querying
## Comparison:
### NoSql
- better at horizontal scaling
- no object-relational impedance mismatch
- no rigid structure
- low latency calls
- must have an access pattern
- not all have ACID transactions
	- mainly 'cause of their age
### SQL-like
- performs well with structured data
- calls tend to take a bit longer
- access patterns aren't needed
- best form to use when attributes are constrained
- more flexible queries
	- many ways to access data
- more guaranteed to have ACID transactions
	- concerned w/ data integrity and making changes ASAP

## Examples:
- *mongodb* ([[#Key-value store]])
- *asure cosmosdb*
- *marklogic*
- *aerospike*
- *couchbase*
- *couchhdb*

