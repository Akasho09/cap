## DriftPRo 

### real-world payment gateway like Razorpay
- “I intentionally did not use a real-world payment gateway like Razorpay because the primary objective of this project was to understand and implement the complete payment flow internally rather than abstracting it behind a third-party service.”

## “Another challenge was ensuring wallet consistency when multiple transactions occur concurrently.”
- Used database transactions
- and SQL's Row level Locking.

## another imp challenge was to ensure timely update when add money transactions go through bank web-hook for payment verification. 
- Maintained transaction states such as PENDING, SUCCESS, and FAILED using enums 

## adding redis cache and backup if redis limit occours 
- Designed a fallback mechanism to gracefully handle Redis rate-limit exhaustion

### Others 
Idempotency
