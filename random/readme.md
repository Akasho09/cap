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


