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

