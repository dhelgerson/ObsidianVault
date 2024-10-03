## Using:
to build an app, you need 3 things:
- Relational Database Management Systems
	- mariadb, mysql, sqlite
- server-side scripting language (php or asp)
- SQL queries
## DB and table basics
- tables contain data you pull from
- columns are attributes
- rows are tuples
- primary keys are unique values per entry used to identify each row
- foreign keys are primary keys or other tables used for referencing between tables(relations)
## Entries
- each column has a datatype
	- types can range from strings to timestamps, etc
	- can specify max length
	- each field must adhere to the rules of the column
- columns can also choose to allow NULL values or not
	- sending a query to add a new row with values that don't match the criteria will not complete correctly
## Queries
- typically follow rules where keywords are in all caps
- table names are case sensitive
- database column names are case sensitive
- must specify the table name "FROM table_name"
- if multiple queries are used, semicolons can be used to separate.
### Creating Tables
- keyword CREATE TABLE
- specifies name, columns, column data types, primary/foreign keys, and null acceptance
	- cannot have spaces in table name
### Viewing Data
- ''