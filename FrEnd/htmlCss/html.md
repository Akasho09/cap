## HTML (HyperText Markup Language) – Interview Essentials
- → Markup language used to structure web pages.
- HTML5 features:
    - Semantic tags
    - Audio / Video
    - Local storage
    - Canvas, SVG

## 2️⃣ Semantic Tags (VERY IMPORTANT)
- <header> 
- <nav> 
- <main> 
- <section> 
- <article>
- <aside> 
- <footer>

### Why use them?
- Better SEO
- Better accessibility
- Cleaner code

- 👉 Interview Q:
1. Difference between <div> and <section>?
- <div> → generic container
- <section> → meaningful block of content

| Block            | Inline              |
| ---------------- | ------------------- |
| div, p, h1       | span, a, img        |
| Takes full width | Takes content width |

## 4️⃣ Forms & Inputs
- An HTML form is used to collect user input and send it to a server (or handle it via JavaScript).
```html
<form>
  <input type="text">
  <input type="email">
  <input type="password">
  <button>Submit</button>
</form>
```

### Input types:
- Text Input
- Password
- Email
- Number
    - <input type="number" min="1" max="100" />
- Date
    - <input type="date" />
- Checkbox
    - <input type="checkbox" /> I agree
- Radio Button
    <input type="radio" name="gender" /> Male
    <input type="radio" name="gender" /> Female
- File Upload
    - <input type="file" />
- Textarea
    - <textarea rows="4" cols="30"></textarea>
- Select / Dropdown
<select>
  <option>India</option>
  <option>USA</option>
  <option>UK</option>
</select>
- Buttons
<button type="submit">Submit</button>
<button type="reset">Reset</button>
<button type="button">Click</button>

### Common Form Validation attributes:
- required
- minlength
- maxlength
- pattern
- readonly
- disabled

### 🔹 Name Attribute (VERY IMPORTANT ⚠️)
<input type="text" name="username" />
- 👉 Without name, data will NOT be sent to backend.

| Method | Use case                      |
| ------ | ----------------------------- |
| GET    | Search, filters               |
| POST   | Login, signup, sensitive data |

- 🔹 Sample Complete Form (Real-World)
<form action="/register" method="POST">
  <label>Name</label>
  <input type="text" name="name" required />

  <label>Email</label>
  <input type="email" name="email" required />

  <label>Password</label>
  <input type="password" name="password" required />

  <button type="submit">Register</button>
</form>

## 5️⃣ HTML Attributes (Simple + Exam-Ready)
- HTML attributes give extra information about an element.
- They control behavior, appearance, identity, and accessibility.

- 🔹 Basic Syntax
<tag attribute="value">Content</tag>
- Example:
- <input type="text" placeholder="Enter name" />

1. 1️⃣ id
- Unique identifier
- Used in CSS & JavaScript
<div id="header"></div>
> ⚠️ One id = one element only

2. 2️⃣ class
- Used for grouping elements
- Can be reused
<p class="text-red bold"></p>

3. 3️⃣ style
- Inline CSS (not recommended for large projects)
<h1 style="color:red;">Hello</h1>

4. 4️⃣ title
- Tooltip text
<button title="Click me">Hover</button>

5. 5️⃣ href (Hypertext Reference)
- 👉 Creates a link to another resource
- 👉 The browser does NOT automatically load it (except for CSS)
- Used with <a> tag
- What happens?
- Clicking <a> → navigates to the URL
    - <link href="style.css"> → tells browser where CSS is, browser loads it
    - <a href="https://google.com">Google</a>

6. 6️⃣ src ((source)) (it defines the location of external resources.)
- 👉 Embeds a resource into the page
- 👉 Browser automatically downloads and executes/displays it
- Commonly used with:
<img src="image.png" />
<script src="app.js"></script>
<video>
<audio>
<iframe>
- What happens?
    - Image is fetched and displayed
    - JS file is fetched and executed immediately

7. 7️⃣ alt (Very Important ⭐)
- Shown if image fails
- Helps SEO & accessibility
<img src="logo.png" alt="Company logo" />

### 🔹 Input-Specific Attributes (VERY IMPORTANT)
8. 8️⃣ type
<input type="password" />

9. 9️⃣ name
- 👉 Required to send data to backend
<input type="text" name="username" />

10. 🔟 value
<input type="text" value="Akash" />

11. 1️⃣1️⃣ placeholder
<input type="email" placeholder="Enter email" />

12. 1️⃣2️⃣ required
(Boolean attribute)
<input type="text" required />

13. 1️⃣3️⃣ readonly
<input type="text" value="Admin" readonly />

14. 1️⃣4️⃣ disabled
<input type="text" disabled />

- Difference:
    - readonly → value is sent
    - disabled → value NOT sent

| Attribute | Purpose           |
| --------- | ----------------- |
| `id`      | Unique identifier |
| `class`   | Group styling     |
| `style`   | Inline CSS        |
| `title`   | Tooltip           |
| `hidden`  | Hide element      |
| `data-*`  | Custom data       |

| Feature           | `href`                  | `src`                     |
| ----------------- | ----------------------- | ------------------------- |
| Purpose           | Links to a resource     | Embeds a resource         |
| Auto-load         | ❌ No (except CSS)       | ✅ Yes                     |
| Page behavior     | Navigation or reference | Becomes part of page      |
| Affects rendering | Usually no              | Yes (can block rendering) |

## ♿ Accessibility (A11y) — HTML & Frontend (Clear + Practical)
- Accessibility (A11y) means building websites so everyone can use them — including people using screen readers, keyboard-only navigation, or with visual, hearing, or motor impairments.
> 🔑 Good A11y = better UX + better SEO + interview brownie points.
- 🔹 Why Accessibility Matters
    - 🌍 Inclusive for all users
    - ⚖️ Required by law in many countries
    - 🔍 Improves SEO
    - 💼 Big companies care a LOT (Google, Microsoft, Amazon)
