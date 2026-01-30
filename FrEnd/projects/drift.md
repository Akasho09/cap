## DriftPro 
- Developed a secure full-stack digital payment platform using Next.js, PostgreSQL, and Prisma…
- - **Turborepo for monorepo architecture**
- Built a modern, responsive frontend using **Next.js** (App Router) with reusable components and optimized routing.
- **TypeScript** is used across the project to ensure type safety and better code maintainability.
- - **Tailwind CSS** is used for building a responsive and modern user interface.
- Authentication is implemented using **NextAuth**, supporting Google and GitHub OAuth login.
- Input Validation using **Zod**
- The application uses **PostgreSQL** as the relational database.
- **Express.js** is used as a backend service to handle payment-related webhooks.
- **Prisma ORM** is used for database interaction, providing type-safe queries.
- **Upstash** (Redis) is integrated for caching and performance optimization.
    -  Rate Limiting : IP-based Rate Limiting using Upstash.
    - Mobile Based Rate Limiting.
- The frontend is deployed on **Vercel**, while backend services and webhooks are hosted on **Render**.
- The entire application is **Dockerized** for consistent development and deployment.

### useReveal — custom animation hook
- Animates sections when they enter the viewport
- Creates a smooth “scroll reveal” effect
- How it works (technical)
    - Uses IntersectionObserver (efficient browser API)
    - Watches when an element becomes visible
    - Adds/removes Tailwind classes to animate opacity & position


