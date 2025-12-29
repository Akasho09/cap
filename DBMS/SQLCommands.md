## Some of The Most Important SQL Commands
- SELECT - extracts data from a database
- UPDATE - updates data in a database
- DELETE - deletes data from a database
- INSERT INTO - inserts new data into a database
- CREATE DATABASE - creates a new database
- ALTER DATABASE - modifies a database
- CREATE TABLE - creates a new table
- ALTER TABLE - modifies a table
- DROP TABLE - deletes a table
- CREATE INDEX - creates an index (search key)
- DROP INDEX - deletes an index
- **DESC** : ;

## SELECT 
- Syntax : 
```sql
SELECT column1, column2, ...
FROM table_name;
```

1. Select ALL columns
```sql
SELECT * FROM Customers;
```

## SELECT DISTINCT 
The SELECT DISTINCT statement is used to return only distinct (different) values.

1. SELECT DISTINCT Country FROM Customers;
- Syntax : 
```sql
SELECT DISTINCT column1, column2, ...
FROM table_name;
```
- Select all the different countries from the "Customers" table:
```sql
mysql> SELECT DISTINCT Country FROM Customers;
+---------+
| Country |
+---------+
| Germany |
| Mexico  |
| UK      |
| Sweden  |
+---------+
```

2. GET COUNT OF DISTINCT Countrys in DB
```sql
SELECT count(DISTINCT Country) FROM Customers;
```

```sql
SELECT Count(*) AS DistinctCountries
FROM (SELECT DISTINCT Country FROM Customers);
```

## WHERE Clause
- The WHERE clause is used to filter records.
> It is used to extract only those records that fulfill a specified condition.
- SYNTAX : 
    ```sql
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition;
    ```
- Select all customers from Mexico:
    ```sql
    SELECT * FROM Customers
    WHERE Country='Mexico';
    ```
> Note: The WHERE clause is not only used in SELECT statements, it is also used in UPDATE, DELETE, etc.!
### OTHER EXAMPLES :
1. 
    ```sql
    SELECT * FROM Customers
    WHERE CustomerID > 80;
    ```
Select all customers with a CustomerID greater than 80:

2. BETWEEN => BETWEEN AND INCLUDING BOTH.
```sql
SELECT * FROM CUSTOMERS WHERE AGE BETWEEN 30 AND 45;
```
Select all customers with a AGE **>=30 and <=45:**

3. LIKE => pattern 
```sql
SELECT * FROM CUSTOMERS WHERE CustomerName LIKE "A%";
```
Select all customers with  CustomerName starting with "a"

4. LIKE :
```sql
SELECT * FROM CUSTOMERS WHERE Country IN ('Mexico' , 'Germany');
```
- Select all customers with Country is either  Mexico or Germany.

5. LIKE , OR , IN .
```sql
SELECT * 
FROM Customers
WHERE City LIKE 'México%'
   OR City IN ('London' , 'Berlin') ;
```

### The following operators can be used in the WHERE clause:
- =	Equal	
    - >	    Greater than	
    - <	    Less than	
    - >=	Greater than or equal	
    - <=	Less than or equal	
    - <>	Not equal. Note: In some versions of SQL this operator may be written as !=	
    - BETWEEN	Between a certain range	
    - LIKE	    Search for a pattern	
    - IN	    To specify multiple possible values for a column	

## SQL ORDER BY Keyword
- The ORDER BY keyword is used to sort the result-set in ascending or descending order
- Syntax: 
```sql
SELECT column1, column2, ...
FROM table_name
ORDER BY column1, column2, ... ASC|DESC;
```
### EXAMPLES:
```sql
SELECT * FROM Customers
ORDER BY Country ASC, CustomerName DESC;
```
- The following SQL statement selects all customers from the "Customers" table, sorted ascending by the "Country" and descending by the "CustomerName" column:


## The SQL AND Operator
- The WHERE clause can contain one or many AND operators.
- The AND operator is used to filter records based on more than one condition, like if you want to return all customers from Spain that starts with the letter 'G':
```sql
SELECT *
FROM Customers
WHERE Country = 'Spain' AND CustomerName LIKE 'G%';
```
- Syntax : 
```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition1 AND condition2 AND condition3 ...;
```
- The AND operator displays a record if all the conditions are TRUE.
- The OR operator displays a record if any of the conditions are TRUE.

### Examples:
1. Combining AND and OR
```sql
SELECT * FROM CUSTOMERS WHERE Country="Mexico" AND (CustomerName LIKE "A%" OR CustomerName LIKE "B%");
```

## The NOT Operator
- The NOT operator is used in combination with other operators to give the opposite result, also called the *negative result*.
- SYNTAX:
```sql
SELECT column1, column2, ...
FROM table_name
WHERE NOT condition;
```
### Examples:
1. Select only the customers that are NOT from Spain:
```sql
SELECT * FROM Customers
WHERE NOT Country = 'Spain';
```
2. Select only the customers that are NOT from Mexico:
```sql
SELECT * FROM CUSTOMERS WHERE COUNTRY NOT IN ("Mexico");
```

3. Select customers that does not start with the letter 'A':
```sql
SELECT * FROM CUSTOMERS WHERE CustomerName NOT LIKE "A%";
```

4. Select customers with a customerID not between 10 and 60:
```sql
SELECT * FROM Customers
WHERE CustomerID NOT BETWEEN 10 AND 60;
```

5. Select customers that are not from Paris or London:
SELECT * FROM Customers
WHERE City NOT IN ('Paris', 'London');

## SQL INSERT INTO Statement
1. Specify both the column names and the values to be inserted:
2. If you are adding values for all the columns of the table, you do not need to specify the column names in the SQL query. However, make sure the order of the values is in the same order as the columns in the table. Here, the INSERT INTO syntax would be as follows:

### Examples:
- It is also possible to only insert data in specific columns.
mysql> INSERT INTO Customers (CustomerID , CustomerName, City, Country) VALUES (9 , 'Cardinal', 'Stavanger', 'Norway');

- Multiple Rows: 
```sql
INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
VALUES
('Cardinal', 'Tom B. Erichsen', 'Skagen 21', 'Stavanger', '4006', 'Norway'),
('Greasy Burger', 'Per Olsen', 'Gateveien 15', 'Sandnes', '4306', 'Norway'),
('Tasty Tee', 'Finn Egan', 'Streetroad 19B', 'Liverpool', 'L1 0AA', 'UK');
```

## SQL NULL Values
- A field with a NULL value is a field with no value.
- If a field in a table is optional, it is possible to insert a new record or update a record without adding a value to this field. Then, the field will be saved with a NULL value.
> Note: A NULL value is different from a zero value or a field that contains spaces. A field with a NULL value is one that has been left blank during record creation!

### How to Test for NULL Values?
- It is not possible to test for NULL values with comparison operators, such as =, <, or <>.
- We will have to use the IS NULL and IS NOT NULL operators instead
> mysql> SELECT * FROM CUSTOMERS WHERE Address IS NULL;
- mysql> SELECT * FROM CUSTOMERS WHERE Address IS NOT NULL;

## The SQL UPDATE Statement
- The UPDATE statement is used to modify the existing records in a table.
```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```
> Note: Be careful when updating records in a table! Notice the WHERE clause in the UPDATE statement. The WHERE clause specifies which record(s) that should be updated. If you omit the WHERE clause, **all** records in the table will be updated!

### examples:
- mysql> UPDATE CUSTOMERS SET CustomerName="Akash3" WHERE CustomerID=11;
> mysql> UPDATE CUSTOMERS SET CustomerName="Akash4" ; SETS ALL ROWS AS AKASH4.

## The SQL DELETE Statement
- The DELETE statement is used to delete existing records in a table.
```sql
DELETE FROM table_name WHERE condition;
```

> Note: Be careful when deleting records in a table! Notice the WHERE clause in the DELETE statement. The WHERE clause specifies which record(s) should be deleted. If you omit the WHERE clause, all records in the table will be deleted!

### examples:
1. Delete All Records
- It is possible to delete all rows in a table without deleting the table. This means that the table structure, attributes, and indexes will be intact:
```sql
DELETE FROM table_name
```

2. To delete the table completely, use the DROP TABLE statement:
```sql
DROP TABLE Customers;
```

## SQL TOP, LIMIT, FETCH FIRST or ROWNUM Clause
1. LIMIT in MYSQL

> Note: Not all database systems support the SELECT TOP clause. MySQL supports the LIMIT clause to select a limited number of records, while Oracle uses FETCH FIRST n ROWS ONLY and ROWNUM.

- MYSQL:
mysql> SELECT * FROM CUSTOMERS LIMIT 5;

## ORDER BY
- mysql> SELECT * FROM Customers ORDER BY Address;
- 
SELECT * FROM Customers
ORDER BY CustomerName DESC
LIMIT 3;

## SQL Aggregate Functions
- An aggregate function is a function that performs a calculation on a set of values, and returns a single value.
- Aggregate functions are often used with the GROUP BY clause of the SELECT statement. The GROUP BY clause splits the result-set into groups of values and the aggregate function can be used to return a single value for each group.
- The most commonly used SQL aggregate functions are:
- 
MIN() - returns the smallest value within the selected column
MAX() - returns the largest value within the selected column
COUNT() - returns the number of rows in a set
SUM() - returns the total sum of a numerical column
AVG() - returns the average value of a numerical column

- Aggregate functions ignore null values (except for COUNT(*)).

### EXAMPLES:
1. mysql> SELECT MIN(age) AS `youngest buddy`
FROM Customers;
- youngest_budddy is Alias.

2. Find the number of products where the ProductName is not null:
```sql
SELECT COUNT(ProductName)
FROM Products;
```

3. You can ignore duplicates by using the DISTINCT keyword in the COUNT() function.
```sql
mysql> SELECT COUNT(DISTINCT CustomerName) FROM Customers;
```

4. Give the counted column a name by using the AS keyword.




