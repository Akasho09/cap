## NULL by default =>
- mysql> insert into teacher values (3 , "akash2" , NULL );

## if salary is NULL ==> NOT SHOWN
mysql> SELECT * FROM teacher WHERE salary>1000;           

## cant use * for GROUP BY
mysql> SELECT s_branch , *  FROM student GROUP BY s_branch ;


## how to apply column alias in sql?


## marks_should_be>0&&<100
ALTER TABLE student 
ADD CONSTRAINT marks_should_be>0&&<100 CHECK (marks BETWEEN 0 AND 100),
ADD CONSTRAINT chk_age CHECK (age >= 18),
ADD CONSTRAINT chk_gender CHECK (gender IN ('M','F','O'));


## Replicate table

## ➡️ SQL commands are NOT case-sensitive, but data and identifiers can be depending on context.

## “In SQL, every subquery in the FROM clause must have an alias.”
- When you write a subquery inside the FROM clause, SQL treats it like a temporary table.
- And every table must have a name — even temporary ones.
- That name is called an alias.


## Wildcards in SQL :
| Symbol        | Name                           | Meaning                                          |
| ------------- | ------------------------------ | ------------------------------------------------ |
| `%`           | Percent wildcard               | Matches **any number of characters** (0 or more) |
| `_`           | Underscore wildcard            | Matches **exactly one character**                |
| `[ ]`         | Character list *(DB specific)* | Matches any one character inside brackets        |
| `[^ ]` or `!` | Not in list *(DB specific)*    | Matches any character **not** in list            |

## A clause is a complete part of an SQL statement that performs a specific function.

## A keyword is a reserved word in SQL that has a special meaning and cannot be used as a variable or table name (unless escaped).

| Part               | Type    |
| ------------------ | ------- |
| `SELECT`           | Keyword |
| `FROM`             | Keyword |
| `WHERE`            | Keyword |
| `ORDER BY`         | Keyword |
| `SELECT name, age` | Clause  |
| `FROM students`    | Clause  |
| `WHERE age > 18`   | Clause  |
| `ORDER BY name`    | Clause  |



## 🔹 Optional: Link with Orders Table (Foreign Key)
- If you want to relate Orders → Shippers, you can do:

ALTER TABLE Orders
ADD ShipperID INT,
ADD CONSTRAINT fk_shipper
FOREIGN KEY (ShipperID) REFERENCES Shippers(ShipperID);

> , after INT .

## trigger
A trigger in SQL is a special stored program that automatically executes (fires) in response to a specific event on a table or view.

> A trigger is a database object that automatically executes when a specified DML event occurs on a table.


