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