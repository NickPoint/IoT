One usual home router it is 1 in 6 - switch, router, wifi access point, DNSmasq, DHCP server, ISP modem

Mango router (GL-MT300N-V2) has:
- max 300mbps wifi speed
- 128mb of ram
- 4 GPIOs and UART
- OpenVPN encryprion
- Dual Ethernet ports
- Only 2.4GHz

A router connects different networks together (e.g., your home network to the internet) and manages traffic between them using IP addresses. A switch connects multiple devices (computers, printers) within a single local network (LAN) to share resources, using MAC addresses. Routers are for external connectivity, switches for internal connectivity.

Dnsmasq is a lightweight, easy-to-configure network infrastructure tool designed for small networks, acting as a DNS forwarder, DHCP server, and TFTP server. It enhances network performance through DNS caching and supports local hostname resolution. It is commonly used in routers, firewalls, and small-scale environments, supporting IPv6 and PXE netbooting.

DHCP server automically assigns IP in given range to devices and memorizes devices by MAC address.

A TFTP (Trivial File Transfer Protocol) server is a lightweight software tool used for transferring files, such as firmware updates and configuration files, to network devices (routers, switches, IP phones) over UDP port 69. It lacks advanced security, making it ideal for fast, local network operations.

OpenWrt is an open-source Linux operating system which runs on embedded devices/ routers. It offers more features, performance and security than a traditional router. It has a filesystem that’s fully writable and includes a package management system. You can make use of these packages to suit your applications in various ways.

By using OpenWrt you can have various features such as:

    Increase overall network performance when multiple devices are connected
    Share files between devices via an external storage drive connected directly to the router
    Increase network security
    Run a BitTorrent client from the router
    Connect a printer directly to the router to create a networked printer
    Limit bandwidth usage of a particular device in the network
    Active queue management
    Real time network monitoring
    Create Dynamic DNS
    Set Up a VPN client or server

MQTT is a standards-based messaging protocol, or set of rules, used for machine-to-machine communication. Smart sensors, wearables, and other Internet of Things (IoT) devices typically have to transmit and receive data over a resource-constrained network with limited bandwidth. These IoT devices use MQTT for data transmission, as it is easy to implement and can communicate IoT data efficiently. MQTT supports messaging between devices to the cloud and the cloud to the device.

Why to use it?
- Lightweight and efficient. MQTT implementation on the IoT device requires minimal resources, so it can even be used on small microcontrollers. For example, a minimal MQTT control message can be as little as two data bytes. MQTT message headers are also small so that you can optimize network bandwidth.
- Scalable. MQTT implementation requires a minimal amount of code that consumes very little power in operations. The protocol also has built-in features to support communication with a large number of IoT devices. Hence, you can implement the MQTT protocol to connect with millions of these devices.
- Reliable. Many IoT devices connect over unreliable cellular networks with low bandwidth and high latency. MQTT has built-in features that reduce the time the IoT device takes to reconnect with the cloud. It also defines three different quality-of-service levels to ensure reliability for IoT use cases— at most once (0), at least once (1), and exactly once (2).
- Secure. MQTT makes it easy for developers to encrypt messages and authenticate devices and users using modern authentication protocols, such as OAuth, TLS1.3, Customer Managed Certificates, and more.