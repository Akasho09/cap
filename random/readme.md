## terminal :
command + j

## Stateless Authentication Mechanism — Meaning
A stateless authentication mechanism is an authentication approach where the server does not store any session information about the user.
Instead, all required authentication data is sent by the client with every request.
> In stateless authentication, each request is self-contained and the server does not remember the user between requests.
- User logs in → server issues a JWT
- Client stores the token (usually in Authorization header)
- Every request includes the token
- Server verifies the token, not a session
    - ✔ No session stored in database
    - ✔ No server-side memory of users

## Cookies 
- are small pieces of data stored in the user’s browser by a website to remember information across requests.
### 🔹 Why Cookies Are Needed
- HTTP is stateless → the server forgets everything after a response.
    - Cookies help maintain state.

### Cookies in Authentication
- Used in stateful authentication
- Server stores session → cookie stores session ID
- Example:
    - Login → server creates session
    - Cookie stores sessionId
    - Server checks session on each request

## DOM 
- is a tree representation of an HTML document.

## A JWT (JSON Web Token) 
- is a compact, self-contained, and secure token used to authenticate and authorize users in web applications.

> JWT is a token-based authentication mechanism where user information is securely transmitted as a JSON object between client and server.

### 🔁 How JWT Authentication Works
1. User logs in with credentials
2. Server verifies credentials
3. Server generates JWT and sends it to client
4. Client stores JWT (localStorage / cookies)
5. Client sends JWT in Authorization header
    - Authorization: Bearer <token>
6. Server verifies JWT and allows access

### ✅ Advantages of JWT
- Stateless authentication (no server-side session)
- Scales well (microservices)
- Fast & compact
- Works across domains

> JWT is a stateless, token-based authentication method that securely transfers user claims between client and server.

## API
- An API is a set of rules that allows one software to talk to another software.

## cloud service models
> IaaS → Infrastructure only
- 
    - Virtual machines
    - Storage
    - Networking
        - AWS EC2
        - Google Compute Engine
> PaaS → Platform to run your code
- 
    - You deploy code, platform handles the rest.
    - 🛠️ You manage
        - Application code
        - Data
    - Render
    - Vercel
> SaaS → Ready-to-use software
- 
    - Gmail
    - Google Docs

