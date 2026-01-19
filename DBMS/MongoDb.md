## MongoDB
- MongoDB is a NoSQL, document-oriented database designed for high scalability, flexibility, and performance.

| SQL Concept | MongoDB Equivalent |
| ----------- | ------------------ |
| Database    | Database           |
| Table       | Collection         |
| Row         | Document           |
| Column      | Field              |
| Primary Key | `_id`              |

### 📄 Data Format (BSON Documents)
- MongoDB stores data in BSON (Binary JSON).
```json
{
  "_id": ObjectId("65a9..."),
  "name": "Akash",
  "email": "akash@gmail.com",
  "skills": ["React", "Node", "MongoDB"],
  "active": true
}
```
- ✔ Flexible fields
- ✔ Nested objects
- ✔ Arrays supported

### ⚙️ Key Features
1. ✅ Schema Flexibility
- No fixed schema
- Fields can vary per document

2. ✅ High Performance
- Fast reads/writes
- Indexing support

3. ✅ Horizontal Scalability
- Built-in sharding
- Handles big data easily

4. ✅ Rich Query Language
db.users.find({ age: { $gt: 18 } })

### 🧠 How $lookup Works Internally
- Reads documents from source collection
- Matches documents in foreign collection
- Embeds matching results as an array
- Outputs combined document
> ➡️ Acts like a LEFT OUTER JOIN

### Queries
find → read
insert → create
update → modify
delete → remove
aggregate → analyze
