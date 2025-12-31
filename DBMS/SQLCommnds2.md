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

