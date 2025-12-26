## Cache , RAM , ROM
| Memory Type     | Location        | Speed      | Volatile |
| --------------- | --------------- | ---------- | -------- |
| Cache           | Inside/near CPU | 🔥 Fastest | Yes      |
| RAM             | Motherboard     | Fast       | Yes      |
| ROM             | Motherboard     | Slow       | No       |
| Hard Disk / SSD | Storage device  | Slowest    | No       |

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