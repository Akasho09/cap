## Process     vs       Thread

| Feature           | Process                                 | Thread                                      |
| ----------------- | --------------------------------------- | ------------------------------------------- |
| Definition        | Independent program in execution        | Smallest unit of execution within a process |
| Memory            | Has **separate memory space**           | Shares memory with other threads            |
| Creation Time     | Slow                                    | Fast                                        |
| Communication     | Expensive (IPC)                         | Easy (shared memory)                        |
| Isolation         | Strong isolation                        | Less isolation                              |
| Crash Impact      | One process crash doesn’t affect others | One thread crash can crash entire process   |
| Context Switching | Heavy                                   | Lightweight                                 |
| Example           | Chrome, VS Code                         | Tabs, background tasks in Chrome            |
- PCB(PID , Memory info) and TCB(PC, registers , Stack , Thread state)
- in c++ , Creation  fork()   , std::thread

### Process Context Switching Heavier than Thread Context Switching?
- 🔸 2️⃣ Context Information Size
| Component        | Process | Thread |
| ---------------- | ------- | ------ |
| Program Counter  | ✅       | ✅      |
| CPU Registers    | ✅       | ✅      |
| Stack Pointer    | ✅       | ✅      |
| Address Space    | ✅       | ❌      |
| Page Tables      | ✅       | ❌      |
| File Descriptors | ✅       | ❌      |
| TLB Flush        | ✅       | ❌      |

- 🔸 3️⃣ Involves Kernel Mode Switch
    - Process switch often requires switching kernel data structures
    - Thread switch (same process) may stay in user mode

- 4️⃣ Cache & TLB Flush Overhead
    - Process switch invalidates:
        - TLB (Translation Lookaside Buffer)
        - CPU caches
    - Thread switch mostly preserves cache locality

- 🔹 Simple Analogy
    - Process switch → Changing houses (move furniture, electricity, setup)
    - Thread switch → Changing rooms in the same house

## 🔹 1. Deadlock Prevention
➡ Prevent at least one of the four deadlock conditions so deadlock can never occur.
Methods:
Eliminate Mutual Exclusion → Not always possible (e.g., printers).
Eliminate Hold and Wait → Process must request all resources at once.

Eliminate No Preemption → OS forcibly takes resources back.

Eliminate Circular Wait → Impose ordering on resource allocation.

👉 Result: Deadlock never happens
👉 Drawback: Low system utilization

## 🔹 2. Deadlock Avoidance
- ➡ System dynamically checks whether granting a resource will lead to deadlock.

Uses safe state concept

Example: Banker’s Algorithm

👉 OS allows resource allocation only if system remains in a safe state.

## 🔹 3. Deadlock Detection & Recovery
- ➡ System allows deadlock to happen, then detects and recovers.

Recovery methods:

Kill one or more processes

Roll back processes

Preempt resources

## 🔹 4. Ostrich Algorithm (Important!)
- ➡ The OS **ignores** the deadlock completely

Used when deadlocks are rare

Cost of detection > cost of ignoring

Common in UNIX/Linux systems

👉 This is not prevention or avoidance, it’s “do nothing and hope it never happens.”


## “What is a race condition, and how can it be prevented?”
- A race condition occurs when two or more processes or threads access shared data at the same time, and the final result depends on the order of execution.
> ➡️ Since execution order is unpredictable, the output becomes incorrect or inconsistent.


