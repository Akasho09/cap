## 🔹 CSS (Cascading Style Sheets)
1. 1️⃣ CSS Box Model ⭐⭐⭐
> content → padding → border → margin

2. 3️⃣ Flexbox (MUST KNOW)
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
- 
    - Key properties:
    - justify-content
    - align-items
    - flex-direction
    - gap
- 👉 Interview Q:
Center a div horizontally & vertically
→ Flexbox answer expected

3. Flexbox vs Grid:
- Flex → 1D layout
- Grid → 2D layout

4. 5️⃣ Positioning
- CSS positioning controls where an element lives on the page and how it moves when you scroll or interact.
> position: static | relative | absolute | fixed | sticky;

1. static
- Default for all elements
- Follows normal document flow
- top / left / right / bottom ❌ don’t work

2. relative
- Positioned relative to itself
- Original space is preserved
- Used as parent for absolute

3. absolute
- Positioned relative to nearest positioned ancestor
- Removed from document flow
- If no ancestor → relative to viewport

4. fixed
- Positioned relative to viewport
- Doesn’t move on scroll

5. sticky
- Acts like relative → until scroll
- Then behaves like fixed

| Position | In Flow | Reference | Scroll  |
| -------- | ------- | --------- | ------- |
| static   | ✅       | normal    | moves   |
| relative | ✅       | itself    | moves   |
| absolute | ❌       | ancestor  | moves   |
| fixed    | ❌       | viewport  | ❌       |
| sticky   | ✅       | parent    | partial |

- ❓ Why absolute not working?
➡️ Parent isn’t positioned (relative missing)

- ❓ Why z-index not working?
➡️ Element has position: static

- ❓ Sticky not sticking?
➡️ Parent has overflow: hidden

- 🔹 When to Use What?
    - relative → anchor for children
    - absolute → UI components inside container
    - fixed → global UI
    - sticky → section headers
    - static → default layout

6. 6️⃣ Responsive Design
- Responsive Design means building websites that adapt smoothly to all screen sizes — mobile, tablet, laptop, desktop — without breaking UI.
- Media Queries
@media (max-width: 768px) {
  body { font-size: 14px; }
}
- Units:
    - %
    - em, rem
    - vh, vw

## 🔹 The Cascade (C in CSS)
- Cascade decides which CSS rule wins when multiple rules target the same element.
- Order of decision 👇
1. 1️⃣ Importance (!important)
    - Overrides almost everything
2. 2️⃣ Specificity
3. 3️⃣ Source order (last one wins)

### Specificity
- Specificity decides which selector is more “powerful”.
- More specific selector = higher priority

| Selector Type        | Example          | Score |
| -------------------- | ---------------- | ----- |
| Universal            | `*`              | 0     |
| Element              | `div`            | 1     |
| Class / Pseudo-class | `.box`, `:hover` | 10    |
| ID                   | `#header`        | 100   |
| Inline style         | `style=""`       | 1000  |
| `!important`         | 🔥               | Wins  |


