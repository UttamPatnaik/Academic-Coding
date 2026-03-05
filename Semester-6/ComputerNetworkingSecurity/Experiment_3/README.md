# Router Configuration and Access Control Lists (ACL) – Lab Documentation

## Objective

* Construct a simple network topology.
* Assign IP addresses to router interfaces.
* Configure the router.
* Verify connectivity.
* Implement **Standard Access Control Lists (ACLs)**.
* Test ACL functionality.
* Implement **Extended Access Control Lists (ACLs)**.

---

# Step 1: Construct Network

Create a network topology consisting of:

* PCs in **Network 1**
* A **Router**
* A **Server in Network 2**

Example networks used in this lab:

* **Network 1:** 192.168.1.0 /24
* **Network 2:** 192.168.2.0 /24

---

# Step 2: Assign IP Addresses

Example configuration:

| Device | Interface | IP Address    | Subnet Mask   |
| ------ | --------- | ------------- | ------------- |
| Router | G0/0      | 192.168.1.1   | 255.255.255.0 |
| Router | G0/1      | 192.168.2.1   | 255.255.255.0 |
| PC0    | -         | 192.168.1.10  | 255.255.255.0 |
| PC1    | -         | 192.168.1.20  | 255.255.255.0 |
| Server | -         | 192.168.2.100 | 255.255.255.0 |

Default gateway for PCs: **192.168.1.1**
Default gateway for Server: **192.168.2.1**

---

# Step 3: Configure Router

Enter privileged mode and global configuration mode.

```
Router#enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
```

### Configure interface GigabitEthernet0/0

```
Router(config)#interface g0/0
Router(config-if)#ip address 192.168.1.1 255.255.255.0
Router(config-if)#no shutdown
Router(config-if)#exit
```

### Configure interface GigabitEthernet0/1

```
Router(config)#interface g0/1
Router(config-if)#ip address 192.168.2.1 255.255.255.0
Router(config-if)#no shutdown
Router(config-if)#exit
```

---

# Step 4: Check Connectivity

Verify communication between devices using **ping**.

Example tests:

* PC0 → Server
* PC1 → Server

If configuration is correct, both should be **reachable**.

---

# Step 5: Standard Access Control Lists (ACL)

Display ACL configuration options.

```
Router(config)#access-list?
access-list
```

```
Router(config)#access-list ?
  <1-99>     IP standard access list
  <100-199>  IP extended access list
```

```
Router(config)#access-list 10 ?
  deny    Specify packets to reject
  permit  Specify packets to forward
  remark  Access list entry comment
```

```
Router(config)#access-list 10 deny ?
  A.B.C.D  Address to match
  any      Any source host
  host     A single host address
```

---

## Wildcard Mask Explanation

```
0.0.0.0 Wildcard mask, it means match this exact ip only
bit value 0 match this exact ip
bit value 1 will ignore(can be anything)
```

Example:

```
deny will block that ip
permit any all other
```

---

# Standard ACL Configuration

Block **PC1 (192.168.1.20)** from accessing the network.

```
Router(config)#access-list 10 deny 192.168.1.20 0.0.0.0 //PC1
```

Explanation:

```
if 192.168.1.0 0.0.0.255 is there, then it would block from 192.168.1.0 - 192.168.1.255
```

Allow all other traffic.

```
Router(config)#access-list 10 permit any
```

---

# Apply ACL on Client Side Interface

ACL should be applied on the **client-side interface**.

Direction:

```
IN PCs->Router
```

Explanation:

```
Activates filtering on incoming traffic
```

---

# Step 7: Testing the ACL

Testing results:

* **Ping from PC0 → Server:** Successful
* **Ping from PC1 → Server:** Destination host unreachable

This confirms that the **ACL is blocking PC1**.

---

# Step 8: Extended ACL Configuration / Creation

Extended ACLs allow filtering based on:

* Source IP
* Destination IP
* Protocol
* Port number

---

## Configuration

```
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
```

Allow **only HTTP access from PC0 to Server**

```
Router(config)#access-list 100 permit tcp host 192.168.1.10 host 192.168.2.100 eq 80
```

Explanation:

```
The first allows only pc0 to access the server using http service(TCP port 80)
```

Deny **FTP access from PC1 to Server**

```
Router(config)#access-list 100 deny tcp host 192.168.1.20 host 192.168.2.100 eq 21
```

Explanation:

```
Next line blocks pc1 form accessing the server via FTP which uses TCP port 212
```

Allow all other traffic.

```
Router(config)#access-list 100 permit ip any any
Router(config)#
```

---

# Step 9: Apply Extended ACL

```
Router(config)#interface gig0/0
Router(config-if)#no ip access-group 10 in
Router(config-if)#ip access-group 100 in
Router(config-if)#exit
Router(config)#
```

The **Extended Access Control List** is applied to the appropriate router interface so that it can actively filter network traffic.

---

# Step 10: Configure Server Services

```
Server -> Services -> HTTP, FTP enabled
```

---

# Step 11: Testing Application Access

Open web browser on **PC0** and type:

```
http://192.168.2.100
```

Result:

```
successful
```

FTP access test:

```
C:\>ftp 192.168.2.100
Trying to connect...192.168.2.100

%Error opening ftp://192.168.2.100/ (Timed out)
.
(Disconnecting from ftp server)
```

Result: **FTP access denied**

---

# Challenge

Try connecting a **new router** to the existing router where the **server is connected to the new router**.

Implement connectivity between the networks using **Static Routing**.

This will extend the topology and demonstrate how **multiple routers communicate through static routes**.
