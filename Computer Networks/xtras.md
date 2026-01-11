## curl 
- is a command-line tool for getting or sending data, including files, using URL syntax

## Commands:
| **Command**    | **Purpose**                       | **Example**                            |
| -------------- | --------------------------------- | -------------------------------------- |
| `ifconfig`     | Show network interfaces & IP info | `ifconfig`                             |
| `ipconfig`     | Get interface IP / DHCP info      | `ipconfig getifaddr en0`               |
| `networksetup` | Configure network services        | `networksetup -listallnetworkservices` |
| `scutil`       | System network configuration      | `scutil --dns`                         |
| `ping`         | Check connectivity (ICMP)         | `ping google.com`                      |
| `traceroute`   | Show packet path                  | `traceroute google.com`                |
| `netstat`      | Network connections & routes      | `netstat -rn`                          |
| `route`        | View routing table                | `route -n get default`                 |
| `arp`          | View ARP cache (IP ↔ MAC)         | `arp -a`                               |
| `nslookup`     | DNS lookup                        | `nslookup google.com`                  |
| `dig`          | Advanced DNS queries              | `dig google.com`                       |
| `curl`         | HTTP/HTTPS testing                | `curl -I https://google.com`           |
| `tcpdump`      | Packet capture                    | `sudo tcpdump -i en0`                  |
| `lsof -i`      | Show ports in use                 | `lsof -i :8080`                        |
| `ssh`          | Secure remote login               | `ssh user@server_ip`                   |
| `sftp`         | Secure file transfer              | `sftp user@server_ip`                  |
| `ftp`          | File transfer (insecure)          | `ftp server_ip`                        |
| `hostname`     | Display system hostname           | `hostname`                             |
| `airport`      | Wi-Fi diagnostics (macOS only)    | `/System/Library/.../airport -I`       |

## Dynamic Host Configuration Protocol
- DHCP, or Dynamic Host Configuration Protocol, is a networking protocol used to automatically assign IP addresses to devices connected to a network.

When a device joins a network, it sends a broadcast request for an IP address. A DHCP server on the network responds by assigning an available IP address to the device, along with other network configuration details such as subnet mask, default gateway, and DNS server.

This eliminates the need for manual IP address configuration on each device, simplifying network management. DHCP also helps prevent IP address conflicts by tracking which addresses are in use.

DHCP is commonly used in networks with many devices, including home networks, small businesses, and large enterprises. It’s a widely adopted protocol supported by most devices, including computers, smartphones, and IoT devices.

## 8.8.8.8
- 8.8.8.8 is a public DNS server IP address provided by Google.

| Feature   | `nslookup google.com` | `8.8.8.8` in Chrome |
| --------- | --------------------- | ------------------- |
| Purpose   | DNS lookup            | Open website        |
| Uses DNS? | ✅ Yes                 | ❌ No                |
| Talks to  | DNS server            | Web server          |
| Protocol  | DNS                   | HTTP / HTTPS        |
| Port      | 53                    | 80 / 443            |
| Output    | IP address            | Webpage or error    |

> nslookup looks in DNS server for the IP of the url given while 8.8.8.8 tries to optn the url and shows the eroor of trying that and ip of the url.
- nslookup performs DNS resolution, whereas entering 8.8.8.8 in a browser initiates an HTTP/HTTPS request to a DNS server, which results in an error.

