## 26. Find 2nd highest salary
1. ✅ Method 1: Using ORDER BY + LIMIT (MySQL / PostgreSQL)
```sql
SELECT salary
FROM employees
ORDER BY salary DESC
LIMIT 1 OFFSET 1;
```
> SELECT CustomerID FROM CUSTOMERS ORDER BY CustomerID DESC LIMIT 1 OFFSET 1;
- 
### ✔ Useful when multiple employees have the same highest salary.
```sql
SELECT DISTINCT salary
FROM employees
ORDER BY salary DESC
LIMIT 1 OFFSET 1;
```

2. ✅ Method 3: Using Subquery with MAX()
```sql
SELECT MAX(salary)
FROM employee
WHERE salary < (SELECT MAX(salary) FROM employee);
```
- mysql> SELECT MAX(CustomerID) FROM CUSTOMERS WHERE CustomerID < (SELECT MAX(CustomerID) FROM CUSTOMERS) ;

3. DENSE_RANK
```sql
SELECT salary
FROM (
    SELECT salary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM employees
) t
WHERE rnk = 2;
```

SELECT SALARY FROM ( SELECT SALARY , DENSE_RANK() OVER ( ORDER BY SALARY DESC ) AS rnk FROM employees ) WHERE rnk=2;

4.
```sql
SELECT SALARY FROM employees e1 WHERE 1 = ( SELECT COUNT(DISTINCT SALARY) FROM employees e2  WHERE e2.SALARY > e1.SALARY );
```

- HIGHEST ==> ALL AT HIGHEST
SELECT SALARY FROM employees e1 WHERE 0 = ( SELECT COUNT(DISTINCT SALARY) FROM employees e2  WHERE e2.SALARY > e1.SALARY );
+--------+
| SALARY |
+--------+
|  90000 |
|  90000 |
+--------+
2 rows in set (0.002 sec)

SELECT DISTINCT     SALARY FROM employees e1 WHERE 0 = ( SELECT COUNT(DISTINCT SALARY) FROM employees e2  WHERE e2.SALARY > e1.SALARY );
