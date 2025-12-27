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

