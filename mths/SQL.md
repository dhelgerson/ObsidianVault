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
- used w/ `SELECT` command
- `SELECT * FROM Customer` to display everything in table
### Filtering Data
- `WHERE` keyword
	`SELECT * FROM Customer WHERE CustomerID = "0001"`
	`SELECT * FROM Customer WHERE CustomerID = "0001" AND LastName = "Starkey"`	
- no difference between ' ' and " "
- some datatypes require ' ' or " "
### Wildcards
- you can approximate through "%"
	`SELECT * FROM Customer WHERE CustomerID LIKE "000%"`
### Viewing Unique columns
- you can select a specific column to return only unique values
- done through `DISTINCT`
	`SELECT DISTINCT CustomerID FROM Order`
### Viewing Ordered Data
- by default query is returned in order it exists in the database
- using keyword `ORDER`
	`SELECT * FROM Customer ORDER BY LastName, FirstName`
	or
	`SELECT * FROM Customer ORDER BY LastName, FirstName DESC`
- you can order by columns not in the query
## Inserting into a Table
- done by keyword `INSERT`
- Must have all the data being added upon query
	`INSERT INTO Customer (all colums you're inserting into) VALUES (all the values you're inserting)`
## Deleting from a table
- Uses keyword `DELETE`
- **NEEDS** a condition to delete only one record
	- should be a unique condition, like primary key
- can also delete 1 record
	`DELETE FROM Customer WHERE CustomerID = '0001'`
	`DELETE FROM Customer` **WILL DELETE ALL OF Customer**
## Updating Data
- done via `UPDATE` and `SET`
- can update multiple columns
	`UPDATE Customer SET FirstName='Dana', LastName='Shows' WHERE CustomerID='0001'`
## Deleting tables
- done w/ `DROP` keyword
	`DROP TABLE Customer` deletes table
	`TRUNCNATE TABLE Customer` deletes all rows in table
## Math in Queries
### Viewing Min and Max
- SQL allows you to return basic math items directly from a query
- use in conjunction w/ `SELECT`
	`SELECT MIN(Price) FROM Books`
	`SELECT MAX(Quantity) FROM Books WHERE Author="George Orwell"`
### Column Counts
- done through built-in SQL `COUNT` function
	`SELECT COUNT(ISBN) FROM Books`
	`SELECT COUNT(Au`
### Avg & Sum
	`SELECT SUM(Quantity) FROM Books`
	`SELECT AVG(Price FROM Books`
## Viewing Specific Data Expanded
- when using `WHERE` clause, you can use the `IN` keyword to compare column against multiple values
