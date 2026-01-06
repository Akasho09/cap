## DriftPro – Project Description (Point-wise)
- DriftPro is a full-stack web application implemtation of digital wallet app like Paytm.
- **Turborepo for monorepo architecture** 
    - Turborepo is a build system optimized for JavaScript and TypeScript, written in Rust.
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
- few rate limiting techniques using redis.

## Projects
1. **College-Based Database Management System.**
- My first major project was a College-Based Database Management System.It Was a group Project of DBMS Curriculm subject in our 2nd year. Its is based on Non Relational DataBase MongodB and MERN Stack. 
>  This project demonstrates my understanding core concepts of database design, CRUD operations, and backend logic. 

2. **MediumPro** : [text](../../copper/MediumPro)
- I also built MediumPro – Clone of Medium Blogging App.
- Its written using React for Frontend and Hono + Prisma backend.
> Hono: A lightweight and feature-rich framework ideal for building web applications on Cloudflare Workers.
- Backend is deployed on Cloudflare Workers.
- it uses PostgreSQL DB and Prisma ORM for interaction with DB.
- TypeScript: The application is written entirely in TypeScript for type safety and to reduce runtime errors.
> This Project demonstrates my type-safe coding using TypeScript.

### Imps :
- One thing that i remeber rn about it is i tried hardcoe the text editor and not use any text editr library. 
- One thing I’d like to highlight is that I didn’t use any external text editor library. I implemented the editor functionality manually to better understand how text formatting and state handling work internally.

3. **Apple Scab Estimation Using CNN and Grad-CAM** .
- In our 7th sem we had to make a Minor Project based on Computer vision or Data Mining.
- It was a Group Project we made a Apple Scab Estimation Using CNN and Grad-CAM .
- It was more of Research Project than ...
- we Implemented a CNN model achieving 90% accuracy in detecting apple scab disease from leaf images.
- Used Grad-CAM visualization, data augmentation, and hyperparameter tuning for improved generalization.

### POINTS 
- A Convolutional Neural Network (CNN) is a type of deep learning model specially designed to process images and visual data.
- Grad-CAM is a visual explanation technique used to understand what part of the image a CNN is focusing on when making a prediction.
- Streamlit is an open-source Python framework used to build interactive web applications for data science, machine learning, and AI projects — without needing frontend skills like HTML, CSS, or JavaScript.

### My part :
- Plant Disease Detection and Localization using GRADCAM
- More of Research :
    - Reserch papers only on PLANT LEAFS not specifically on Apple Leaf.
    -  literature review
- problem-definition aspect and identifying gaps.
- dataset collection  , Plant Leaf Collection from Kaggle .
    - Specific leafs collection of Apple of 5k.
- Data Augmentation :
    - Data augmentation is done by applying controlled transformations like rotation, flipping, and brightness changes to training images to increase dataset diversity without altering labels.
> Ninad Shukla, Sushila Palwe, Shubham, Mohit Rajani, Aaryan Suri : Plant Disease Detection and Localization using GRADCAM
'''
My role was primarily focused on the research and problem-definition aspect of the project. I worked on reviewing existing literature, identifying gaps—especially around model explainability—and helped define the scope of using Grad-CAM along with CNNs. I also contributed to dataset collection, augmentation strategies, and interpretation of Grad-CAM heatmaps to validate the model’s predictions.
'''
### GOLDEN 
> That was outside my direct implementation, but conceptually…




### ✅ How to Describe Projects in an Interview (Golden Formula)
1. 1️⃣ One-line overview
What problem you solved and for whom.

2. 2️⃣ Tech stack
Mention key technologies confidently.

3. 3️⃣ Your role & responsibilities
What you actually did.

## Hono :
Hono is a modern backend framework similar to Express.js, but faster, smaller, and optimized for edge computing.

### 🔹 Key Features of  : 
✅ Extremely fast – built for edge environments
✅ Tiny bundle size (~12KB)
✅ TypeScript-first
✅ Works everywhere – Node.js, Bun, Deno, Cloudflare Workers
✅ Middleware support (like Express)
✅ Built-in routing & request handling

## Tell me something that’s not on your resume :
One thing that’s not explicitly mentioned on my resume is my front-end portfolio project, which I believe is a strong representation of my UI and performance optimization skills.

I focused heavily on web performance and user experience, and as a result, the Largest Contentful Paint (LCP) of the website is 1.27 seconds, which falls under the best performance category. The First Contentful Paint (FCP) is 0.94 seconds, and the Cumulative Layout Shift (CLS) is 0, indicating a stable and responsive layout.

I optimized these metrics through efficient asset loading, layout stability, and clean component design. This project reflects how I approach front-end development—not just visually, but also from a performance and user-centric perspective.


