# Module 3

## LAN vs WAN

A LAN (Local Area Network) connects devices within a small, private area like a home or office, offering high speeds and low cost. A WAN (Wide Area Network) spans large geographical distances connecting multiple LANs using public or leased infrastructure (like the Internet), making it slower and more expensive.

## 2.4GHz in Estonia

The 2.4 GHz Wi-Fi band is a frequency range used by Wi-Fi networks for wireless communication. In Europe, it follows ETSI standards, which define which frequencies and power levels are allowed.

Wi-Fi channels are smaller frequency ranges inside the 2.4 GHz band. In this band, channels overlap with each other, so if many nearby routers use the same or overlapping channels, interference happens and internet speed becomes worse.

That is why it is important to choose a less busy channel. Usually channels 1, 6, and 11 are preferred because they overlap less.

In Estonia, all channels from 1 to 13 can be used because Estonia follows European ETSI rules. Channel 14 is not allowed.

One usual home router it is 1 in 6 - switch, router, wifi access point, DNSmasq, DHCP server, ISP modem

## Small Tutorial: Setting Up an IoT Network with Mango Router

First, we connected the GL.iNet GL-MT300N-V2 Mango Mango router to a computer and opened its web interface in the browser. Through the router settings, we configured the local network so that the router became the main gateway for our IoT system.

After that, we created our own Wi-Fi network for the team. We selected a unique SSID, set the password to iotempire, enabled WPA2-PSK security, and chose a less busy 2.4 GHz channel to reduce interference from nearby networks.

Next, we connected the router to the internet through the WAN port so that additional software could be installed. Using the OpenWRT package manager, we installed the MQTT broker packages:

Mosquitto

luci-app-mosquitto

luci-app-commands

Then we configured the MQTT broker inside the router:

anonymous connections enabled

listener created on port 1883

MQTT protocol selected

When the broker was running, we connected phones and computers to our new Wi-Fi network and used MQTT client applications to test communication.

Finally, we used MQTT Explorer on the computer to subscribe to all topics with wildcard #, which allowed us to see all published messages in the network.

## How to start USB Tethering on Mango router

We couldn't do it because our power supply was too weak, and when we connected a phone, it consumed too much power, so the router kept rebooting.

**But here is consice instructions:**

We installed the kmod-usb-net-rndis package on the router so that it could recognize USB tethering. Then we connected a phone to the Mango router via USB and enabled USB tethering on the phone.

After that, in the router configuration interface, we added a new network interface for the USB connection, assigned it to the WAN firewall zone, and applied the settings. Once configured, the phone shared its internet connection with the router, which provided internet access to both the laptop and the Wi-Fi network.

## Some personal notes

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