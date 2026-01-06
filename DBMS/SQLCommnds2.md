## SQL LIKE 

### Examples: 
1. The following SQL statement selects all customers with a CustomerName that starts with "a" and are at least 3 characters in length:
```sql
SELECT * FROM customers WHERE ContactName LIKE "a___%";
```

2. The following SQL statement selects all customers with a CustomerName that does NOT start with "a":
```sql
SELECT * FROM customers WHERE ContactName NOT LIKE "a%";
```

## MySQL IN Operator
- The IN operator allows you to specify multiple values in a WHERE clause.
- The IN operator is a shorthand for multiple OR conditions.
```sql
SELECT column_name(s)
FROM table_name
WHERE column_name IN (value1, value2, ...);
```

### EXAMPLES:
1. The following SQL statement selects all customers that are located in "Germany", "France" or "UK":
```sql
mysql> SELECT * FROM customers WHERE City IN ("London" , "Kashmirr");
```

2. The following SQL statement selects all customers that are from the same countries as the suppliers:
```sql
SELECT * FROM Customers
WHERE Country IN (SELECT Country FROM Suppliers);
```

## MySQL BETWEEN Operator
- The BETWEEN operator selects values within a given range. The values can be numbers, text, or dates.
- The BETWEEN operator is inclusive: begin and end values are included.
```sql
SELECT column_name(s)
FROM table_name
WHERE column_name BETWEEN value1 AND value2;
```

1. The following SQL statement selects all products with a price between 10 and 20:
```sql
mysql> SELECT * FROM customers WHERE age BETWEEN 20 AND 30;
```

2. The following SQL statement selects all products with a price between 10 and 20. In addition; do not show products with a CategoryID of 1,2, or 3:
```sql
 SELECT * FROM customers WHERE age BETWEEN 20 AND 30 AND CustomerID NOT IN (1,2,3);
```

## MySQL Aliases
- Aliases are used to give a table, or a column in a table, a temporary name.
- Aliases are often used to make column names more readable.
- An alias only exists for the duration of that query.
- An alias is created with the AS keyword.
- Alias Column Syntax
```sql
SELECT column_name AS alias_name
FROM table_name;
```

1. mysql>  SELECT ContactName AS IDIOTS  FROM customers WHERE age BETWEEN 20 AND 30 AND CustomerID NOT IN (1,2,3);

2. SELECT CustomerName AS Customer, ContactName AS "Contact Person"
FROM Customers;

3. The following SQL statement creates an alias named "Address" that combine four columns (Address, PostalCode, City and Country):
```sql
mysql> SELECT ContactName AS Naav , CONCAT_WS(" ",Address , City , PostalCode , COUNTRY ) AS "FULL ADDRESS"  FROM customers;
```

4. The following SQL statement selects all the orders from the customer with CustomerID=4 (Around the Horn). We use the "Customers" and "Orders" tables, and give them the table aliases of "c" and "o" respectively (Here we use aliases to make the SQL shorter):
```sql
SELECT o.OrderID, o.OrderDate, c.CustomerName
FROM Customers AS c, Orders AS o
WHERE c.CustomerName='Around the Horn' AND c.CustomerID=o.CustomerID;
```

## MySQL Joins
- MySQL Joining Tables
    - A JOIN clause is used to combine rows from two or more tables, based on a related column between them.
    - Let's look at a selection from the "Orders" table:

| JOIN Type  | When to Use               | Example                            |
| ---------- | ------------------------- | ---------------------------------- |
| INNER JOIN | Only matching records     | Customers with orders              |
| LEFT JOIN  | Keep all from left table  | All customers, even without orders |
| RIGHT JOIN | Keep all from right table | All orders, even without customers |
| CROSS JOIN | All combinations          | Sizes × Colors                     |


## MySQL INNER JOIN Keyword

1. 
```sql
SELECT o.OrderID , o.CustomerID , o.OrderDate , c.CustomerName , c.ContactName FROM orders AS o INNER JOIN Customers as c ON c.CustomerID=o.CustomerID;
```

2. JOIN Three Tables
- The following SQL statement selects all orders with customer and shipper information:
```sql
SELECT o.OrderID , o.CustomerID , c.CustomerName , c.ContactName , c.Country , s.ShipperName , s.Phone FROM 
( 
(ORDERS AS o INNER JOIN customers AS c ON o.CustomerID=c.CustomerID) 
INNER JOIN Shippers AS s ON s.ShipperID=o.ShipperID
) ;
```

## MySQL LEFT JOIN Keyword
```sql
SELECT c.CustomerName , c.ContactName , o.OrderID , o.CustomerID , o.OrderDate FROM Customers AS c LEFT JOIN Orders as o ON c.CustomerID=o.CustomerID;
```
> ALL customers with or without orders

## CROSS JOIN :
1. SELECT Customers.CustomerName, Orders.OrderID
    -> FROM Customers
    -> CROSS JOIN Orders;
> ALL C*O;

2. SELECT Customers.CustomerName, Orders.OrderID
    -> FROM Customers
    -> CROSS JOIN Orders
    -> WHERE Customers.CustomerID=Orders.CustomerID;
> INNER JOIN.
> If you add a WHERE clause (if table1 and table2 has a relationship), the CROSS JOIN will produce the same result as the INNER JOIN clause:


## MySQL Self Join
- A self join is a regular join, but the table is joined with itself.
```sql
 SELECT A.CustomerName , B.CustomerName , A.Country FROM customers A , customers B WHERE A.CustomerID<>B.CustomerID AND A.Country=B.Country;
```

## MySQL UNION Operator
- The UNION operator is used to combine the result-set of two or more SELECT statements.
- The UNION operator automatically removes duplicate rows from the result set.

### EXAMPLES:
1. ALL THE NAMES OF SHIPPERS AND customers ; 
```sql
SELECT ShipperName FROM Shippers UNION SELECT ContactName FROM customers;
```

2. The following SQL statement returns the German cities (only distinct values) from both the "Customers" and the "Suppliers" table:
```sql
SELECT City, Country FROM Customers
WHERE Country='Germany'
UNION
SELECT City, Country FROM Suppliers
WHERE Country='Germany'
ORDER BY City;
```

3. 
```sql
SELECT 'Customer' AS Type, ContactName AS People , Country AS "Country OR Phone"
FROM Customers
UNION
SELECT 'Shippers', ShipperName, Phone
FROM Shippers;

+----------+------------------+------------------+
| Type     | People           | Country OR Phone |
+----------+------------------+------------------+
| Customer | Maria Anders     | Germany          |
| Customer | Ana Trujillo     | Mexico           |
| Customer | Antonio Moreno   | Mexico           |
| Customer | Sample Contact   | USA              |
| Shippers | Speedy Express   | 123-456-7890     |
| Shippers | United Package   | 987-654-3210     |
| Shippers | Federal Shipping | 555-789-4561     |
+----------+------------------+------------------+

```


## The MySQL UNION ALL Operator
- The UNION ALL operator is used to combine the result-set of two or more SELECT statements.
- The UNION ALL operator includes all rows from each statement, including any **duplicates**.
- Requirements for UNION ALL: 
    - Every SELECT statement within UNION must have the same number of columns
    - The columns must also have similar data types
    - The columns in every SELECT statement must also be in the same order


## MySQL GROUP BY Statement


### EXAMPLE
1. The following SQL statement lists the number of customers in each country:
```sql
SELECT COUNTRY , COUNT(CustomerID)  FROM CUSTOMERS GROUP BY COUNTRY;
```

2. from desending numbera;
ORDER BY COUNT(CustomerID) DESC;

3. The following SQL statement lists the number of orders sent by each shipper:
```sql
SELECT C.ContactName , COUNT(O.OrderID) AS NumberOfOrders FROM CUSTOMERS AS C LEFT JOIN ORDERS AS O  ON O.CustomerID=C.CustomerID  GROUP BY C.CustomerID;
```

## The MySQL HAVING Clause
- The HAVING clause was added to SQL because the WHERE keyword cannot be used with aggregate functions.


### EXAMPES:
1. The following SQL statement lists the number of customers in each country. Only include countries with more than 5 customers:
```sql
SELECT COUNTRY , COUNT(COUNTRY)  FROM CUSTOMERS GROUP BY COUNTRY HAVING COUNT(COUNTRY)>1;
```


## A VIEW in SQL 
- is a virtual table created using a SELECT query.
- It does not store data physically; it stores only the query.
> A VIEW is a named SQL query that behaves like a table but contains no data of its own.
> A view in SQL is a virtual table created from a SELECT query that provides abstraction and security without storing data.

### Updatable and Non-updatacble
- A non-updatable view is a view where INSERT, UPDATE, or DELETE is not allowed because SQL cannot map the changes back to the base table clearly.
- An updatable view is a view on which you can perform INSERT, UPDATE, and DELETE operations, and those changes reflect in the base table.

