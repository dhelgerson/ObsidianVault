# Answers
1. Return contacts with the first name “John”
    
    `SELECT * FROM Contacts WHERE name = "John%"`
2. Return the name and age of contacts ordered by age (oldest to youngest)
    
    `SLECT name, age FROM Contacts ORDER BY age DESC`
3. Return all the contacts
    
    `SELECT * FROM Contacts`
4. Return contacts with the last name “Brinkley”
    
    `SELECT * FROM Contacts WHERE name = "%Brinkley"`
5. Return contacts between the ages of 20 and 30 (inclusive)
    
    `SELECT * FROM Contacts WHERE age BETWEEN 20 AND 30`
6. Return the name of the contacts that have the zip code of 39759
    
    `SELECT name FROM Contacts WHERE zip = "39759"`
7. Update Corrissa Farm’s age to 27
    
    `UPDATE Customer SET age = "27" WHERE name = "Corrissa Farms"`
8. Insert another contact into the table (values are up to you)
    
    `INSERT INTO Contacts name, phone, address, zip, age VALUES "Kortni Neal", "555-5555","666 Bardwell Rd","39759","31"`
9. Delete any contacts that live on a street containing “Poplar” anywhere in the address
    
    `DELETE FROM Contacts WHERE address = "%Poplar%"`
10. Return a list of unique zip codes contained in the table
    
    `SELECT DISTINCT zip FROM Contacts`