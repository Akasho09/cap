## DriftPro – Project Description (Point-wise)
- DriftPro is a mini full-stack web application implemtation of digital wallet platforms like Paytm.
- **Turborepo monorepo architecture** 
    - Does not use RazorPay or Stripe , rather the bank is hard coded.
- It is built using **Next.js** for both frontend rendering and API handling.
- **TypeScript** is used across the project to ensure type safety and better code maintainability.
- **Tailwind CSS** is used for building a responsive and modern user interface.
- Authentication is implemented using **NextAuth**, supporting Google and GitHub OAuth login.
- **Express.js** is used as a backend service to handle payment-related webhooks.
- **Prisma ORM** is used for database interaction, providing type-safe queries.
- The application uses **PostgreSQL** as the relational database.
- **Upstash** (Redis) is integrated for caching and performance optimization.
    -  Rate Limiting : IP-based Rate Limiting using Upstash.
    - Mobile Based Rate Limiting.
- The entire application is **Dockerized** for consistent development and deployment.
- The frontend is deployed on **Vercel**, while backend services and webhooks are hosted on **Render**.
> The project demonstrates understanding of full-stack architecture, authentication flows, database design, caching, and deployment pipelines.


