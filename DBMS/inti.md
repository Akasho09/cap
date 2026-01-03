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

BCNF (Boyce–Codd Normal Form):
A stronger version of 3NF where every determinant is a candidate key.

Normalization helps in improving data consistency, integrity, and efficient storage.


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
        - UPDATE / DELETE data

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
| Type          | Relational DBMS   | Object-Relational DBMS           |
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
- JOINT  
- WHERE
... SO ON