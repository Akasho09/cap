## React Router 
- is a client-side routing library for React that allows you to build Single Page Applications (SPAs) with multiple pages/views without reloading the browser.

### 🔹 Why Do We Need React Router?
- In a normal website:
    - Clicking a link → browser reloads the page → server responds with new HTML.
- In a React app:
    - We want fast navigation without page reloads
    - React Router changes the URL and component without refreshing the page.

### STEPS:
- npm install react-router-dom
```js
import { BrowserRouter, Routes, Route } from "react-router-dom";
import Home from "./Home";
import About from "./About";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/about" element={<About />} />
      </Routes>
    </BrowserRouter>
  );
}
export default App;
```
> ➡️ No page reload
> ➡️ Fast navigation

| Component       | Purpose                           |
| --------------- | --------------------------------- |
| `BrowserRouter` | Wraps entire app, enables routing |
| `Routes`        | Container for all routes          |
| `Route`         | Maps URL → Component              |
| `Link`          | Navigation link                   |
| `NavLink`       | Like Link + active styling        |
| `useParams()`   | Access URL parameters             |
| `useNavigate()` | Programmatic navigation           |
| `Outlet`        | Render child routes               |

## Dynamic Routes
- Dynamic Routes are pages that allow you to add custom params to your URLs.
```jsx
<Route path="/user/:id" element={<User />} />
```
```jsx
import { useParams } from "react-router-dom";

function User() {
  const { id } = useParams();
  return <h1>User ID: {id}</h1>;
}
```

## 🔹 Programmatic Navigation
```jsx
import { useNavigate } from "react-router-dom";

const navigate = useNavigate();

<button onClick={() => navigate("/login")}>
  Login
</button>
```
## 🔹 Nested Routes
```jsx
<Route path="/dashboard" element={<Dashboard />}>
  <Route path="profile" element={<Profile />} />
  <Route path="settings" element={<Settings />} />
</Route>
```


