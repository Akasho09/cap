## DriftPro – Project Description (Point-wise)
- DriftPro is a full-stack web application implemtation of digital wallet app like Paytm.
- **Turborepo monorepo architecture** 
    - Does not use RazorPay or Stripe , rather the bank is hard coded.
- It is built using **Next.js** for both frontend rendering and API handling.
- **TypeScript** is used across the project to ensure type safety and better code maintainability.
- **Tailwind CSS** is used for building a responsive and modern user interface.
- Authentication is implemented using **NextAuth**, supporting Google and GitHub OAuth login.
- **Express.js** is used as a backend service to handle payment-related webhooks.
- **Prisma ORM** is used for database interaction, providing type-safe queries.
- The application uses **PostgreSQL** as the relational database.
- Input Validation using **Zod**
- **Upstash** (Redis) is integrated for caching and performance optimization.
    -  Rate Limiting : IP-based Rate Limiting using Upstash.
    - Mobile Based Rate Limiting.
- The entire application is **Dockerized** for consistent development and deployment.
- The frontend is deployed on **Vercel**, while backend services and webhooks are hosted on **Render**.
> The project demonstrates understanding of full-stack architecture, authentication flows, database design, caching, and deployment.

## Projects
1. College-Based Database Management System.
- My first major project was a College-Based Database Management System.It Was a group Project of DBMS Curriculm subject in our 2nd year. Its is based on Non Relational DataBase MongodB and MERN Stack. 
>  This project demonstrates my understanding core concepts of database design, CRUD operations, and backend logic. 

2. MediumPro
- I also built MediumPro – Clone of Medium Blogging App.
- Its written using React for Frontend and Hono + Prisma backend.
> Hono: A lightweight and feature-rich framework ideal for building web applications on Cloudflare Workers.
- Backend is deployed on Cloudflare Workers.
- it uses PostgreSQL DB and Prisma ORM for interaction with DB.
- TypeScript: The application is written entirely in TypeScript for type safety and to reduce runtime errors.
> This Project demonstrates my type-safe coding using TypeScript.

3. Apple Scab Estimation Using CNN and Grad-CAM .
- In our 7th sem we had to make a Minor Project based on Computer vision or Data Mining.
- It was a Group Project we made a Apple Scab Estimation Using CNN and Grad-CAM .
- It was more of Research Project than ...
- we Implemented a CNN model achieving 90% accuracy in detecting apple scab disease from leaf images.
- Used Grad-CAM visualization, data augmentation, and hyperparameter tuning for improved generalization.

4. DriftPro – Paytm for Desktop
