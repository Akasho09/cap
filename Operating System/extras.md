##  Program        | Process            
| Program           | Process                        |
| ----------------- | ------------------------------ |
| Passive entity    | Active entity                  |
| Stored on disk    | Loaded in memory               |
| Static            | Dynamic                        |
| Just instructions | Instructions + execution state |

## Playing a Music File (User Mode vs Kernel Mode)
| Step            | Mode   | What Happens       |
| --------------- | ------ | ------------------ |
| Click play      | User   | App receives input |
| Open file       | Kernel | Disk access        |
| Decode audio    | User   | CPU computation    |
| Send to speaker | Kernel | Hardware I/O       |
| Play sound      | Kernel | Device operation   |

## How ls Command Works (User Mode ↔ Kernel Mode Flow)
User types "ls"
     ↓
Shell (User Mode)
     ↓ fork()
Kernel creates process
     ↓ exec()
Kernel loads ls
     ↓
ls runs (User Mode)
     ↓
System calls (open, read, write)
     ↓
Kernel accesses filesystem
     ↓
Output shown
     ↓
Process exits

## EXAMPLE OF A PROCESS WHICH RUNS IN USER MODE ONLY
1. A Calculator App (or simple text editor)

## Cache , RAM , ROM
| Memory Type           | Location          | Speed                              | Volatile |
| --------------------- | ----------------- | ---------------------------------- | -------- |
| **TLB**               | Inside CPU (MMU)  | 🚀 **Fastest**(1-128kb)            | Yes      |
| **Cache (L1/L2/L3)**  | Inside / near CPU | 🔥 Very Fast                       | Yes      |
| **RAM (Main Memory)** | Motherboard       | ⚡ Fast                             | Yes      |
| **ROM**               | Motherboard       | 🐢 Slow                            | No       |
| **Hard Disk / SSD**   | Storage Device    | 🐌 Slowest *(SSD faster than HDD)* | No       |

- in MAC's
| Component | Size Range    | Location                 |
| --------- | ------------- | ------------------------ |
| Cache     | ~20–30 MB     | Inside CPU               |
| RAM       | 8–16 GB       | On-chip (Unified Memory) |
| ROM       | ~16–32 MB     | On motherboard           |
| SSD       | 256 GB – 2 TB | Internal storage         |

## MultiLevel Cache :
| Cache Level | Speed   | Size       | Location        | Shared?   |
| ----------- | ------- | ---------- | --------------- | --------- |
| L1          | Fastest | Very Small | Inside CPU core | ❌         |
| L2          | Fast    | Medium     | Inside CPU      | Sometimes |
| L3          | Slower  | Large      | Shared on chip  | ✅         |


## Buffering 
- is a technique used by the operating system to temporarily store data in memory (buffer) while it is being transferred between two devices or processes that operate at different speeds.


## Spooling (Simultaneous Peripheral Operations On-Line)
Spooling is a technique used by the operating system to store I/O data temporarily on disk so that slow I/O devices (like printers) can work independently of faster processes (like the CPU).

| Feature          | Spooling         | Buffering      |
| ---------------- | ---------------- | -------------- |
| Storage location | Disk             | Memory (RAM)   |
| Used for         | Slow I/O devices | Speed mismatch |
| Example          | Printer queue    | Keyboard input |
| Data size        | Large            | Small          |

## 🔁 IPC – Inter-Process Communication
- Inter-Process Communication (IPC) is a mechanism that allows processes to communicate and share data with each other while executing concurrently in an operating system.
- EXAMPLE :
1. Shared Memory:
    - A .jpg to tiff converter (p1) is in kernel mode and p2, which will send the address of the image to p1 is in user mode.
    - to solve this we use shared memory ipc .
    - p2 writes the string addreess to shared space , with some $(for example) to shared space and then p1 reads from it.(idk yehi hai)

2. Message Passing:
    - Processes communicate via message passing
    - Messages stored in a queue with type and data

### 🧠 Why IPC is Needed
- Processes run in separate memory spaces
- They cannot directly access each other’s data
- IPC enables:
    - Data sharing
    - Synchronization
    - Coordination between processes

## Virtualization
Virtualization is a technology that allows one physical machine to run multiple virtual machines (VMs), each behaving like an independent computer with its own OS, memory, and CPU.

## TO COVER 
 spin locking  , live locking , busy waiting , best process scheduling algo , 


## Cache hit 
- occurs when the data requested by the CPU is found in the cache memory, so it can be accessed quickly without going to main memory (RAM).
- In simple terms:
- 👉 Requested data = already in cache → Cache Hit
- Why it matters:
    - Much faster access (nanoseconds vs milliseconds)
    - Improves system performance
    - Reduces CPU waiting time
- Example:
- If the CPU needs variable x and it's already stored in cache → cache hit
- If not found and it must fetch from RAM → cache miss
- Types of Cache Hits:
    - L1 Cache Hit – fastest
    - L2 Cache Hit
    - L3 Cache Hit – slower than L1/L2 but faster than RAM
- Cache Hit Ratio:
Hit Ratio = Number of cache hits / Total memory accesses
- Higher hit ratio = better performance ✅

## 🧠 What is TLB (Translation Lookaside Buffer)?
- TLB (Translation Lookaside Buffer) is a small, **fast cache** inside the CPU that stores recently used page table entries to speed up virtual-to-physical address translation.

### 🔍 Why TLB is Needed
- When a program accesses memory:
    - CPU generates a virtual address
    - OS must translate it to a physical address using the page table
    - Accessing page table in RAM is slow
- ➡️ TLB solves this by storing recent translations so the CPU can skip accessing the page table.

## Livelock
- A livelock occurs when two or more processes keep responding to each other but make no actual progress.
- EXAMPLE : 
- IN DINING PHILOSPHER PROB :
    - assume 2 philospher only .
    - IF A PHILOSPHER1 IS USING FORK1 n needs fork2 also n p2 is using fork2 needs f1 . we have used a policy that philospher will use fork only if both are free. so p1 will free f1 and p2 will free p2 . now p1 will take f2 and p2 will take f1 and LOOPP WILL OCCOUR.

