## Normalization 
- in DBMS is the process of organizing data in a database to reduce redundancy and eliminate data anomalies such as insertion, deletion, and update anomalies.
- It involves dividing large tables into smaller, well-structured tables and defining relationships between them.
- The main normal forms are:
1. First Normal Form (1NF):
- A table is in 1NF if all attributes contain atomic (indivisible) values, and there are no repeating groups or multi-valued attributes.

2. Second Normal Form (2NF):
- A table is in 2NF if it is in 1NF and every non-key attribute is fully functionally dependent on the entire primary key (no partial dependency).

3. Third Normal Form (3NF):
- A table is in 3NF if it is in 2NF and there is no transitive dependency, meaning non-key attributes do not depend on other non-key attributes.

4. BCNF (Boyce–Codd Normal Form):
A stronger version of 3NF where every determinant is a candidate key.

- Normalization helps in improving data consistency, integrity, and efficient storage.


## 🔹 What is SQL?
- SQL (Structured Query Language) is a language used to:
    - Create databases
    - Store data
    - Retrieve data
    - Modify data
- It is a standard language, not software.
- 🔹 What SQL does:
        - CREATE tables
        - INSERT data
        - SELECT data
        - UPDATE / DELETE data.

## 🔹 What is MySQL?
- MySQL is a Database Management System (DBMS) that uses SQL to manage data.
- It is software that:
    - Stores data in tables
    - Executes SQL queries
    - Manages users, security, and transactions

| Feature      | SQL                    | MySQL               |
| ------------ | ---------------------- | ------------------- |
| Type         | Query language         | Database software   |
| Purpose      | Write database queries | Store & manage data |
| Developed by | ISO/ANSI               | Oracle Corporation  |
| Used for     | Communicating with DB  | Managing databases  |
| Dependency   | Independent            | Uses SQL            |

### 🔹 Other DBMS That Use SQL
- MySQL
- PostgreSQL
- Oracle
- SQL Server
- SQLite
- All use SQL but have different features.

## MYSQL VS POSTGRESQL
| Feature       | MySQL             | PostgreSQL                       |
| ------------- | ----------------- | -------------------------------- |
| Type          | Relational DBMS   | *Object-Relational* DBMS         |
| Developed by  | Oracle            | PostgreSQL Global Dev Group      |
| First Release | 1995              | 1996                             |
| License       | GPL (Open Source) | PostgreSQL License (Open Source) |

| Aspect                | MySQL    | PostgreSQL         |
| --------------------- | -------- | ------------------ |
| Read operations       | Faster   | Slightly slower    |
| Write-heavy workloads | Average  | Better             |
| Complex queries       | Limited  | Excellent          |
| Concurrency           | Moderate | Very strong (MVCC) |

- ✔ MySQL → better for simple, read-heavy applications
- ✔ PostgreSQL → better for complex queries & analytics

| Feature           | MySQL       | PostgreSQL       |
| ----------------- | ----------- | ---------------- |
| JSON support      | Yes (basic) | Advanced (JSONB) |
| Window functions  | Limited     | Excellent        |
| Full-text search  | Basic       | Advanced         |
| Custom data types | ❌           | ✅                |
| Stored procedures | Limited     | Powerful         |

## SQL DATA-TYPES :
| Data Type               | Storage Size | Signed Range                    | Unsigned Range                  | Common Use          |
| ----------------------- | ------------ | ------------------------------- | ------------------------------- | ------------------- |
| **TINYINT**             | 1 Byte       | -128 to 127                     | 0 to 255                        | Flags, status (0/1) |
| **SMALLINT**            | 2 Bytes      | -32,768 to 32,767               | 0 to 65,535                     | Small numbers       |
| **MEDIUMINT** *(MySQL)* | 3 Bytes      | -8,388,608 to 8,388,607         | 0 to 16,777,215                 | Rarely used         |
| **INT / INTEGER**       | 4 Bytes      | -2,147,483,648 to 2,147,483,647 | 0 to 4,294,967,295              | IDs, counters       |
| **BIGINT**              | 8 Bytes      | -9.22×10¹⁸ to +9.22×10¹⁸        | 0 to 18,446,744,073,709,551,615 | Large IDs           |

> column_name INT SIGNED;


## STORE AUDIO :

1. 🔹 Method 1: Store Audio as BLOB (Binary Large Object)
- 📌 What is BLOB?
- A BLOB stores binary data such as:
    - Audio
    - Images
    - Videos
    - PDFs
```sql
CREATE TABLE audio_files (
    id INT PRIMARY KEY AUTO_INCREMENT,
    file_name VARCHAR(255),
    audio_data BLOB
);
```
```SQL
INSERT INTO audio_files (file_name, audio_data)
VALUES ('song.mp3', LOAD_FILE('/path/song.mp3'));
```

## DELETE , DROP , TRUNCATE 
1. 🔹 1️⃣ DELETE
- Deletes specific rows from a table
- Can use WHERE clause
- Table structure remains
- Can be rolled back (if inside a transaction)
- 🔹 Features:
    - Row-by-row deletion
    - Slower than TRUNCATE
    - Can use WHERE condition
    - Triggers are activated

2. 🔹 2️⃣ TRUNCATE
- Removes ALL rows from a table
- Cannot use WHERE
- Faster than DELETE
- Resets auto-increment counter
> TRUNCATE TABLE employees;
- 🔹 Features:
    - Deletes all records instantly
    - Cannot be rolled back (in most DBs)
    - Table structure remains
    - No triggers fired

3. 🔹 3️⃣ DROP
- Deletes entire table structure
- Removes data + schema permanently
> DROP TABLE employees;
- 🔹 Features:
    - Table is completely removed
    - Cannot be rolled back
    - Table no longer exists

## CREATE DATABASE IF NOT EXISTS CAP;
- CREATE DATABASE IF NOT EXISTS creates a database only if it doesn’t already exist, preventing errors.


## A DUAL table 
- is a special one-row, one-column dummy table used mainly to execute expressions, functions, or calculations without needing a real table.
> DUAL is a dummy table used to evaluate expressions or functions when no actual table is required.
- Sometimes you want to:
    - Test a calculation
    - Call a function
    - Get system date/time
    - Evaluate expressions
- EXAMPLES:
    - SELECT CURRENT_DATE FROM DUAL;
    - SELECT NOW();          -- valid
    - SELECT LCASE("AKash");


## CASCADE 
- is a rule used with foreign keys that tells the database what to do with child records when a parent record is UPDATED or DELETED.
> CASCADE automatically applies changes made to a parent table to the related rows in the child table.

### 🔹 Where CASCADE is Used
- ON DELETE CASCADE : 
    - If a parent row is deleted
    - All related child rows are automatically deleted
- ON UPDATE CASCADE :
    - If a primary key value is updated
    - The foreign key values are updated automatically
- These are written while defining a foreign key.
- parent :
```sql
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50)
);
```
- child :
```sql
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    EmpName VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID)
    REFERENCES Department(DeptID)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
```
| Action          | Meaning                          |
| --------------- | -------------------------------- |
| **CASCADE**     | Apply changes to child rows      |
| **RESTRICT**    | Block the operation              |
| **NO ACTION**   | Same as RESTRICT                 |
| **SET NULL**    | Set foreign key to NULL          |
| **SET DEFAULT** | Set foreign key to default value |


## DISTINCT and GROUP BY 
- are used to remove duplicates, but they are not the same and are used for different purposes.
1. 1️⃣ DISTINCT
- Removes duplicate rows
- Works on selected columns
- Used for unique values only
- No aggregation

2. 🔹 2️⃣ GROUP BY
- Groups rows with same values
- Used with aggregate functions
- Performs summarization

| Feature            | DISTINCT      | GROUP BY           |
| ------------------ | ------------- | ------------------ |
| Removes duplicates | ✅             | ✅                  |
| Aggregation        | ❌             | ✅                  |
| Summarization      | ❌             | ✅                  |
| Performance        | Faster        | Slower             |
| Use case           | Unique values | Reports, analytics |
> DISTINCT removes duplicate rows, while GROUP BY groups rows to apply aggregate functions.

##  WHERE and HAVING 
- are used to filter data, but they work at different stages of query execution.

1. 🔹 1️⃣ WHERE Clause
- Filters rows
- Applied before GROUP BY
- Cannot use aggregate functions

2. 🔹 2️⃣ HAVING Clause
- Filters groups
- Applied after GROUP BY
- Used with aggregate functions

| Feature                | WHERE           | HAVING         |
| ---------------------- | --------------- | -------------- |
| Filters                | Rows            | Groups         |
| Used with aggregates   | ❌ No            | ✅ Yes          |
| Works without GROUP BY | ✅ Yes           | ❌ No (mostly)  |
| Execution stage        | Before grouping | After grouping |

### Can we use HAVING without GROUP BY?
❌ No, logically in standard SQL

### Think of it like this:
- WHERE → filter raw rows
- GROUP BY → make groups
- HAVING → filter groups

## EXECUTION OF PRECEDENCE 
- JOIN  
- WHERE
... SO ON


## 🔑 Core Rule (Remember This)
> ADD CONSTRAINT → table-level rules (relationships & uniqueness)
> MODIFY / ALTER COLUMN → column properties (datatype & nullability)
- ADD CONSTRAINT
| Constraint    | Why                   |
| ------------- | --------------------- |
| `PRIMARY KEY` | Uniqueness + NOT NULL |
| `FOREIGN KEY` | Referential integrity |
| `UNIQUE`      | Enforce uniqueness    |
| `CHECK`       | Custom conditions     |

- ✅ MODIFY / ALTER COLUMN — When to use
| Change                | Example                      |
| --------------------- | ---------------------------- |
| Datatype              | `INT → BIGINT`               |
| Size                  | `VARCHAR(50) → VARCHAR(100)` |
| Add/remove `NOT NULL` | enforce nullability          |
| Default value         | add/change default           |

## 🧠 What is PL/SQL?
- PL/SQL stands for Procedural Language / SQL.
- It is Oracle’s procedural extension of SQL, used to write blocks of executable code that combine SQL with programming features like loops, conditions, and variables.
- It is tightly integrated with the Oracle Database.
> PL/SQL is a block-structured, procedural language that extends SQL by adding programming constructs such as loops, conditions, variables, and exception handling.
```sql
DECLARE
    -- Variable declarations
BEGIN
    -- Executable SQL + logic
EXCEPTION
    -- Error handling
END;
/
```

## SQL Error Codes?
- SQL error codes are numeric or symbolic identifiers generated by the database when an error occurs during SQL execution.

## 1️⃣ What is a User?
- A User is an account created in the database system that:
    - Can log in to the database
    - Has authentication credentials (username/password)
    - Is granted privileges (CREATE, SELECT, INSERT, etc.)
- Example
> CREATE USER akash IDENTIFIED BY password123;
✔ User can connect to the database
✔ User may or may not own objects

## 2️⃣ What is a Schema?
- A Schema is a logical container (namespace) that holds database objects such as:
- Tables
- Views
- Indexes
- Procedures
- Triggers

## What is a View?
- A view is a virtual table created using a SQL query.
- It does not store data itself — it stores the query definition.
> A view is a logical table based on a SELECT query that presents data from one or more tables.
```SQL
CREATE VIEW high_salary_employees AS
SELECT id, name, salary
FROM employee
WHERE salary > 50000;
```
### Can We Update a View?
- ✅ Yes, if:
    - Single table
    - No GROUP BY, DISTINCT, JOIN
    - No aggregate functions
```SQL
UPDATE Emp_Public
SET department = 'HR'
WHERE emp_id = 5;
```
- ❌ No, if:
    - View uses joins
    - Aggregates present

## What is a Cursor?
- A cursor is a pointer that allows row-by-row processing of query results.
- SQL normally works on sets, but cursors allow procedural, row-wise processing.
> A cursor is a database object used to retrieve, process, and manipulate query results one row at a time.

## What is a Trigger?
- A trigger is a stored program that automatically executes when a specific database event occurs.
> A trigger is a database object that is automatically fired in response to INSERT, UPDATE, or DELETE events.
```sql
CREATE TRIGGER salary_check
BEFORE INSERT ON employee
FOR EACH ROW
BEGIN
    IF :NEW.salary < 0 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Salary cannot be negative');
    END IF;
END;
/
```
| Type               | Description              |
| ------------------ | ------------------------ |
| BEFORE Trigger     | Executes before DML      |
| AFTER Trigger      | Executes after DML       |
| INSTEAD OF Trigger | Used on views            |
| ROW-level          | Fires per row            |
| STATEMENT-level    | Fires once per statement |

### Why Triggers Are Used
- Automatic validation
- Enforcing business rules
- Preventing invalid operations
- Auditing (logging changes)
    - EXAMPLE : 
```sql
CREATE OR REPLACE TRIGGER employee_salary_audit
BEFORE UPDATE OF salary ON employee
FOR EACH ROW
BEGIN
    INSERT INTO employee_audit (
        emp_id,
        old_salary,
        new_salary,
        action_type,
        changed_by,
        changed_on
    )
    VALUES (
        :OLD.id,
        :OLD.salary,
        :NEW.salary,
        'UPDATE',
        USER,
        SYSDATE
    );
END;
/
```

> Rollbacks are achieved using transaction logs and write-ahead logging, not by triggers.

## SQL vs  MongoDB  
| Feature        | SQL (MySQL / PostgreSQL) | MongoDB                          |
| -------------- | ------------------------ | -------------------------------- |
| Type           | Relational DB            | NoSQL (Document DB)              |
| Data format    | Tables (rows & columns)  | JSON-like documents (BSON)       |
| Schema         | Fixed schema             | Schema-less (flexible)           |
| Joins          | ✅ Supported              | ❌ Limited (lookup)               |
| Relationships  | Strong (FK, PK)          | Weak / embedded                  |
| Scalability    | Vertical (scale up)      | Horizontal (scale out)           |
| Transactions   | ✅ ACID                   | ✅ ACID (multi-doc supported now) |
| Query language | SQL                      | MongoDB Query Language           |
| Performance    | Complex queries          | High read/write                  |
| Use case       | Structured data          | Rapidly changing data            |


## two tables Employee and Dept and asked me to find dept wise max Salary. 
- ✅ Requirement
    -  Find department-wise maximum salary
- ✅ Correct SQL Query
```sql
SELECT 
    d.dept_name,
    MAX(e.salary) AS max_salary
FROM Employee e
JOIN Dept d
ON e.dept_id = d.dept_id
GROUP BY d.dept_name;
```
- Show Employee Name Also
```sql
SELECT 
    d.dept_name,
    e.emp_name,
    e.salary
FROM Employee e
JOIN Dept d ON e.dept_id = d.dept_id
WHERE (e.dept_id, e.salary) IN (
    SELECT dept_id, MAX(salary)
    FROM Employee
    GROUP BY dept_id
);
```

