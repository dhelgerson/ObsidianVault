## background
- aren't tabular, store things differently than relational databases
	- idea has existed since 1960s
	- the term didn't emerge 'til 21st century
- commonly used in big data and real-time web applications
- sometimes referred to not-only-sql 'cause some have sql like commands
- term first used in 1998
	- though he made a relational database :(
- widely used method was made in 2009
## data storage
items are stored in 4 main categories:
- [[#wide-column store]]
- [[#document store]]
- [[#key-value store]]
- graph
## key-value store
- uses an associaitive array as a basis for storing info
	- similar to python dicts,maps, hash tablels
	- hopefully more performance with larger datasets
- involves having a collection of data
	- each field is associated w/ a key
- there's no basis for how they interact w/ the key-value store
### wide-column store
- also knows as extensible record store
- uses tables, rows, and columns
	- name an dformat of each column can vary from row to row
	- this is the opposite of relational databases
- often interpreted as a 2-dimensional key-value store
- also no benchmark for how you access data
### document store
- central idea here, literally that of a document
- documents are referenced by unique keys in a database
- access data by parsing the given document
### graph database
- only really usable by certain data
## examples:
- mongodb
- asure cosmosdb
- marklogic
- aerospike
- couchbase
- couchhdb