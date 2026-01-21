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
    - Process switch → Changing houses (move furniture, electricity, setup).
    - Thread switch → Changing rooms in the same house.

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

## IPC :
- Inter-Process Communication (IPC) is a mechanism that allows different processes to communicate and share data with each other while executing concurrently.
### 🔹 Types of IPC Mechanisms
1. 1️⃣ Shared Memory
- Fastest IPC method
    - Multiple processes share a common memory region
    - 🔹 Needs synchronization tools (mutex/semaphore)
- 🔹 Used in high-performance applications
- ✔ Fast
- ❌ Risk of race conditions

2. 2️⃣ Pipes
    1. a) Unnamed Pipes
        - Used between parent and child processes
        - One-way communication

    2. b) Named Pipes (FIFOs)
        - Used between unrelated processes
        - Exist as files in the filesystem

3. 3️⃣ Message Queues
- Processes exchange messages instead of raw data
- OS maintains message queues
    - ✔ Structured communication
    - ✔ Safer than shared memory 
- ❌ Slower


4. 6️⃣ Signals
- Used to notify a process about events
- Simple and asynchronous
- Examples:
    - SIGKILL, SIGINT, SIGTERM

| IPC Mechanism | Speed   | Communication Type | Use Case              |
| ------------- | ------- | ------------------ | --------------------- |
| Shared Memory | Fastest | Data sharing       | High performance apps |
| Pipes         | Medium  | One-way            | Parent-child          |
| Message Queue | Medium  | Message based      | Process messaging     |
| Semaphores    | Fast    | Synchronization    | Resource control      |
| Sockets       | Slower  | Network            | Client-server         |
| Signals       | Fast    | Event notification | Control signals       |


## 🔹 What is Contention?
- Contention occurs when two or more processes or threads compete for the same limited resource (CPU, memory, lock, I/O device, etc.) at the same time.
- ➡️ Because the resource cannot be used simultaneously, some processes must wait, leading to delay or performance degradation.
> Contention is the competition between processes for shared resources.

### 🔹 Common Types of Contention
1. 1️⃣ CPU Contention
- Multiple processes want CPU time.
- Handled by the CPU scheduler.
🧠 Example:
> Many running programs competing for CPU cores.

2. 2️⃣ Memory Contention
- Multiple processes try to access or allocate memory simultaneously.

🧠 Example:
- Multiple apps requesting RAM → paging or thrashing.

3. 3️⃣ Lock Contention
- Multiple threads try to acquire the same lock/mutex.


## Compaction 
- is a memory management technique used to reduce or eliminate external fragmentation by moving processes in memory so that all free memory becomes one large contiguous block.

## 🔹 Internal Fragmentation
- Internal fragmentation occurs when allocated memory is larger than the requested memory, and the extra unused space inside the allocated block is wasted.

## External fragmentation 
- occurs when free memory is split into small scattered blocks, making it impossible to allocate a large contiguous block even though total free memory is sufficient.

| Feature         | Internal Fragmentation    | External Fragmentation   |
| --------------- | ------------------------- | ------------------------ |
| Where it occurs | Inside allocated memory   | Between allocated blocks |
| Cause           | Fixed-size allocation     | Variable-size allocation |
| Wasted memory   | Inside allocated block    | Outside allocated blocks |
| Avoided by      | Using smaller blocks      | Compaction / paging      |
| Example         | 8 KB allocated, 6 KB used | Many small free holes    |

## Paging Drawbacks :
| Drawback               | Explanation                         |
| ---------------------- | ----------------------------------- |
| Internal fragmentation | Wasted memory inside pages          |
| Memory overhead        | Page tables consume space           |
| Slower access          | Two memory accesses per instruction |
| Hardware dependency    | Requires MMU support                |
| Page faults            | Can slow system significantly       |


