## IP-Address : 
- An IP Address (Internet Protocol Address) is a unique numerical identifier assigned to every device connected to a network.
- It helps in identifying and locating devices so data can be sent and received correctly.
> An IP address is the digital address of a device on a network.

### 📌 It helps in:
- Identifying a device
- Locating a device on a network
- Sending and receiving data

### 🔹 Why IP Address is Needed?
- Without an IP address:
    - Devices cannot identify each other
    - Data cannot reach the correct destination
    - Internet communication becomes impossible
    - Just like a home address helps deliver letters, an IP address helps deliver data packets.

### 🔹 So, Is Your IP Same Every Time?
| Connection Type          | IP Behavior               |
| ------------------------ | ------------------------- |
| Home Wi-Fi (normal plan) | ❌ Changes sometimes       |
| Mobile Data (4G/5G)      | ❌ Changes very frequently |
| Office/Server Network    | ✅ Usually static          |
| VPN                      | ❌ Changes every time      |

### 🔹 Public IP vs Private IP
1. 🌐 Public IP
- Assigned by ISP
- Visible on the internet
- Can change

2. 🏠 Private IP
- Used inside your home network
- Example: 192.168.1.5
- Almost always same unless router resets

### 🔹 How to Check Your IP
1. Public IP: type "what is my IP" in Google
- curl ifconfig.me
> 136.232.148.166
2. Private IP:
- ipconfig getifaddr en0
> 10.71.2.232
3. MAC Address :
- ifconfig en0 | grep ether
> 	ether ee:e0:fe:93:..:..

### 🔹 How IP Works (Step-by-Step)
- Device connects to network
- Router assigns IP (via DHCP) ,Private IP.
- Device sends data with destination IP
- Routers forward packets using IP routing
- Destination device receives data

### 🔹 Advantages of IP Addressing
- Global identification
- Enables routing
- Supports internet scalability
- Device-to-device communication

### 🔹 Disadvantages
- IPv4 exhaustion
- Security issues if not protected
- IP spoofing possible :
    - 1️⃣ DDoS Attacks
        - Attackers flood a server with spoofed IP packets
        - Hard to trace real attacker
    
##  🔹 Structure of an IP Address
1. IPv4 Format
- 192.168.1.1
- 32-bit address
- Divided into 4 octets
- Each octet = 8 bits (0–255)
- Binary example:
```yml
192 → 11000000
168 → 10101000
1   → 00000001
1   → 00000001
```

## 🔹 Types of IP Addresses
1. 1️⃣ IPv4 (32-bit)
- Format: x.x.x.x
- Total addresses: ~4.3 billion
- Example: 192.168.0.1

2. 2️⃣ IPv6 (128-bit)
- Created due to IPv4 exhaustion
- Format:
> 2001:0db8:85a3:0000:0000:8a2e:0370:7334
> Supports ~340 undecillion addresses
- Each block:
    - 16 bits (4 hex digits)
    - Total = 8 blocks = 128 bits

## 🔹 Classes of IP Addresses (IPv4)

| Class | Range                       | Default Mask  | Use             |
| ----- | --------------------------- | ------------- | --------------- |
| A     | 1.0.0.0 – 126.255.255.255   | 255.0.0.0     | Large networks  |
| B     | 128.0.0.0 – 191.255.255.255 | 255.255.0.0   | Medium networks |
| C     | 192.0.0.0 – 223.255.255.255 | 255.255.255.0 | Small networks  |
| D     | 224.0.0.0 – 239.255.255.255 | Multicast     |                 |
| E     | 240.0.0.0 – 255.255.255.255 | Reserved      |                 |

| **Class**   | **First Octet Range** | **Network Bits** | **Number of Networks** | **Hosts per Network** |
| ----------- | --------------------- | ---------------- | ---------------------- | --------------------- |
| **Class A** | 1 – 126               | 7 bits           | **126 networks**       | 16,777,214            |
| **Class B** | 128 – 191             | 14 bits          | **16,384 networks**    | 65,534                |
| **Class C** | 192 – 223             | 21 bits          | **2,097,152 networks** | 254                   |
| **Class D** | 224 – 239             | —                | Multicast              | —                     |
| **Class E** | 240 – 255             | —                | Experimental           | —                     |

1. A:
> 1.0.0.0 – 126.255.255.255
- First bit: 0
- 8 bits for network => 2^7(0 fixed ) => 126 networks(cz 0 resrved and 127 broadcasting )
- 24 bits for hosts => 2^24 ~16 million hosts per network
- 🔸 Usage:
    - Large organizations
    - ISPs
- 
    - 0.0.0.0 (reserved)
    - 127.0.0.0 (loopback)


2. 🔹 Class B
- First two bits: 10
- 16 bits for network
- 16 bits for hosts
- Supports 65,534 hosts per network



## Special IP Adrresses : 
| Address         | Purpose              |
| --------------- | -------------------- |
| 127.0.0.1       | Loopback (localhost) |
| 0.0.0.0         | Default route        |
| 255.255.255.255 | Broadcast            |


## 🔹 What is NAT?
- NAT (Network Address Translation) is a networking technique used to translate private (internal) IP addresses into public IP addresses and vice versa.
- 👉 It allows multiple devices in a private network to share a single public IP address to access the internet.

### 🔹 Why NAT is Needed
- Problems NAT Solves:
1. IPv4 address shortage
2. Security (internal IPs are hidden)
3. Cost saving (one public IP for many devices)
4. Network independence (internal IPs can change freely)

### 🔹 How NAT Works (Simple Flow)
- A device in a private network (e.g., 192.168.1.10) sends a request to the internet.
- Router replaces the private IP with its public IP.
- Router keeps a NAT table to remember which internal device made the request.
- When the response comes back, router forwards it to the correct internal device.

### 🔹 Types of NAT
1. 1️⃣ Static NAT
- One private IP ↔ One public IP
- Fixed mapping
- 📌 Used for:
    - Servers
    - Hosting services

2. 2️⃣ Dynamic NAT
- Private IP mapped to a pool of public IPs
- Mapping changes dynamically
- 📌 Used in medium networks

3. 3️⃣ PAT (Port Address Translation) — Most Common
- Multiple private IPs share one public IP
- Uses port numbers to differentiate connections
- 📌 Also called NAT Overload

### 🔹 Advantages of NAT
✔ Conserves IPv4 addresses
✔ Improves security (internal IPs hidden)
✔ Allows private networking
✔ Reduces ISP IP usage

### 🔹 Disadvantages of NAT
❌ Breaks end-to-end connectivity
❌ Causes issues with some protocols (VoIP, FTP)
❌ Adds processing overhead
❌ Complicates peer-to-peer communication

## PORT 
A port is a logical communication endpoint used by computers to identify specific services or applications running on a device.
- 👉 While an IP address identifies a device,
- 👉 a port number identifies a specific application or service on that device.

### 🔹 Why Do We Need Ports?
- A computer can run many network applications at the same time:
    - Web browser
    - Email
    - File transfer
    - Streaming apps
- Ports ensure data reaches the correct application.
- 📌 Example:
    - IP → identifies which computer
    - Port → identifies which application

### 🔹 Port Number Range :  2^16.
| Range             | Type                | Description                  |
| ----------------- | ------------------- | ---------------------------- |
| **0 – 1023**      | Well-known ports    | Reserved for system services |
| **1024 – 49151**  | Registered ports    | Assigned to applications     |
| **49152 – 65535** | Dynamic / Ephemeral | Temporary client ports       |

> Ephemeral ports are temporary, automatically assigned port numbers used by client devices to establish outgoing network connections.

### 🔹 Common Port Numbers
| Port    | Protocol   | Service            |
| ------- | ---------- | ------------------ |
| 20 / 21 | FTP        | File Transfer      |
| 22      | SSH        | Secure login       |
| 23      | Telnet     | Remote login       |
| 25      | SMTP       | Sending email      |
| 53      | DNS        | Domain name lookup |
| 80      | HTTP       | Web traffic        |
| 443     | HTTPS      | Secure web         |
| 3306    | MySQL      | Database           |
| 5432    | PostgreSQL | Database           |

### 🔹 Types of Ports
1. 1️⃣ Physical Ports
- USB
- HDMI
- Ethernet

2. 2️⃣ Logical (Network) Ports
- Software-based
- Used by TCP/UDP

### 🔹 TCP vs UDP Ports
| Feature     | TCP                 | UDP               |
| ----------- | ------------------- | ----------------- |
| Connection  | Connection-oriented | Connectionless    |
| Reliability | Guaranteed          | Not guaranteed    |
| Speed       | Slower              | Faster            |
| Use Case    | Web, Email          | Streaming, Gaming |

