## What are empty (void) elements?
- Empty elements (also called void elements) are HTML elements that do not have any content and do not need a closing tag.
- They exist to perform a specific function, not to wrap content.

| Element    | Purpose            |
| ---------- | ------------------ |
| `<br>`     | Line break         |
| `<hr>`     | Horizontal rule    |
| `<img>`    | Image              |
| `<input>`  | Form input         |
| `<meta>`   | Metadata           |
| `<link>`   | External resources |
| `<source>` | Media source       |
| `<track>`  | Subtitles/captions |
| `<area>`   | Image map          |
| `<base>`   | Base URL           |

## 📄 What is <!DOCTYPE html>? (Simple + Interview-Perfect)
- <!DOCTYPE html> is a declaration, not an HTML tag.
- It tells the browser which version of HTML the page is written in and how to render it.

## non-semantic and semantic
- A non-semantic container is an HTML element that does not describe the meaning of its content — it’s used purely for grouping or styling.
    - <div></div>
    - <span></span>

## div vs span 
- <div> → block-level container
    - Starts on a new line
    - Takes full width
    - Can contain block + inline elements
    - Used for layout & structure
- <span> → inline container
    - Does not start a new line
    - Takes only required width
    - Can contain only inline content
    - Used for styling small text portions

## b vs strong 
| Feature                | `<b>` | `<strong>` |
| ---------------------- | ----- | ---------- |
| Visual bold            | ✅     | ✅          |
| Semantic meaning       | ❌     | ✅          |
| Screen reader emphasis | ❌     | ✅          |
| SEO value              | ❌     | ✅          |

## <meta> tag in HTML?
- The <meta> tag provides metadata about an HTML document.
- Metadata is information about the page, not content shown to users.

> ✅ UTF-8 is the default character encoding in HTML5.

## hr vs br
| Feature          | `<br>`          | `<hr>`            |
| ---------------- | --------------- | ----------------- |
| Type             | Line break      | Thematic break    |
| Semantic meaning | ❌ No            | ✅ Yes             |
| Visual output    | New line        | Horizontal line   |
| Used in          | Text formatting | Content structure |
| Screen readers   | Ignore mostly   | Announce break    |
| Styling          | Limited         | Fully styleable   |

- <br> → presentation
- <hr> → structure + meaning

