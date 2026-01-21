## Module 1: IP

In this module, you will be exploring two packet captures, `ip-wireshark-trace1-1.pcapng` and `ip-wireshark-trace2-1.pcapng`. Normally, you are required to capture these traces yourself; however, some of this functionality is only available in Linux/MacOS, hence, it will be provided.

### Part 1.1 (trace IP 1-1)

In this trace, you should be able to see the series of UDP segments sent by traceroute on a computer, and the ICMP TTL-exceeded messages returned to the computer by the intermediate routers. Answer the following questions based on this information:

1. Select the first UDP segment sent by the computer via the traceroute command to gaia.cs.umass.edu. Expand the Internet Protocol part of the packet in the packet details window. What is the IP address of the computer?
	 - `192.168.86.61`

2. What is the value in the time-to-live (TTL) field in this IPv4 datagram’s header?
	- `1`

3. What is the value in the upper-layer protocol field in this IPv4 datagram’s header?
    - `UDP`

4. How many bytes are in the IP header?
	- `20`    

5. How many bytes are in the payload of the IP datagram? Explain how you determined the number of payload bytes.
    - the data payload is `28 bytes`. the datagram header is `8 bytes`. if you specifically mean the entire payload of the ip layer, then it's `36 bytes`.

6. Has this IP datagram been fragmented? Explain how you determined whether or not the datagram has been fragmented.
    - yes, there are flag bits sets saying more fragments

Next, look at the sequence of UDP segments being sent from the computer via traceroute, destined to 128.119.245.12. The display filter that you can enter to do this is “ip.src==192.168.86.61 and ip.dst==128.119.245.12 and udp and !icmp”.

7. Which fields in the IP datagram always change from one datagram to the next within this series of UDP segments sent by the computer destined to 128.119.245.12, via traceroute? Why?
	- the destination port keeps chaning. I'm assuming it's 'cause the destination is forking a process to deal w/ it. 

8. Which fields in this sequence of IP datagrams (containingUDPsegments) stay constant? Why?
	- the src ip, dest ip src port, and length. 'cause they're all doing the same thing.

9. Describe the pattern you see in the values in the Identification field of the IP datagrams being sent by the computer.
	- they're incrementing


Now look at the ICMP packets being returned to the computer by the intervening routers where the TTL value was decremented to zero (and hence caused the ICMP error message to be returned to the computer). The display filter that you can use to show just these packets is “ip.dst==192.168.86.61 and icmp”.

10. What is the upper-layer protocol specified in the IP datagrams returned from the routers?
    - `ICMP`

11. Are the values in the Identification fields (across the sequence of all of ICMP packets from all of the routers) similar in behavior to your answer to question 9 above?
    - no. it appears it's getting responses out of order.

12. Are the values of the TTL fields similar across all of the ICMP packets from all of the routers?
    - somewhat. there are groups of decrementing ttls but it jumps around, no doubt due to network latency

### Part 1.2 (trace IP 1-1)

Sort the packet listing from Part 1.1, with any display filters cleared, according to time, by clicking on the Time column.

13. Find the first IP datagram containing the first part of the segment sent to 128.119.245.12 sent by the computer via the traceroute command to gaia.cs.umass.edu, after increasing the traceroute length to 3000. Has that segment been fragmented across multiple IP datagrams?
    - it does

14. What information in the IP header indicates that this datagram has been fragmented?
    - more fragments bit: set

15. What information in the IP header for this packet indicates whether this is the first fragment versus a latter fragment?  
	- fragment offset: 0

16. How many bytes are there in this IP datagram (header plus payload)?  
	- 2972 if you count all of the fragments

17. Now inspect the datagram containing the second fragment of the fragmented UDP segment. What information in the IP header indicates that this is not the first datagram fragment?
	- fragment offset: 1480

18. What fields change in the IP header between the first and second fragments?
	- fragment offset and checksum

19. Now find the IP datagram containing the third fragment of the original UDP segment. What information in the IP header indicates that this is the last fragment of that segment?
	- more fragments bit: not set

### Part 1.3 (trace IP 2-1)

Open the file ip-wireshark-trace2-1.pcapng. Take a closer look at the 20th packet in this trace, sent at t=3.814489. This is a DNS request (contained in an IPv6 datagram) to an IPv6 DNS server for the IPv6 address of youtube.com. The DNS AAAA request type is used to resolve names to IPv6 IP addresses.

20. What is the IPv6 address of the computer making the DNS AAAA request? This is the source address of the 20th packet in the trace. Give the IPv6 source address for this datagram in the exact same form as displayed in the Wireshark window.
	- `2601:193:8302:4620:215c:f5ae:8b40:a27a`

21. What is the IPv6 destination address for this datagram? Give this IPv6 address in the exact same form as displayed in the Wireshark window.
    - `2001:558:feed::1`

22. What is the value of the flow label for this datagram?
	- `0x63ed0`

23. How much payload data is carried in this datagram?
    - the UDP header says `37` bytes.

24. What is the upper-layer protocol to which this datagram’s payload will be delivered at the destination?
	- IPv6? this is a vague question to me.

Find the IPv6 DNS response to the IPv6 DNS AAAA request made in the 20th packet in this trace. This DNS response contains IPv6 addresses for youtube.com.

25. How many IPv6 addresses are returned in the response to this AAAA request? 
	- 5? there's one response w/ 5 and one response w/ 1. I'm gonna go w/ 5 'cause the later questions lead to it. wireshark believes the response w/ 1 is the corresponding one though.

26. What is the first of the IPv6 addresses returned by the DNS for youtube.com (in the ip- wireshark-trace2-1.pcapng trace file, this is also the address that is numerically the smallest)? Give this IPv6 address in the exact same shorthand form as displayed in the Wireshark window.
	- `2607:f8b0:4006:806::200e`

## Module 2: NAT

In this module, you will investigate the behavior of a NAT router. This module will be different from others, where you have captured a trace file at a single Wireshark measurement point. Because you are interested in capturing packets at both the input and output sides of the NAT device, you will need to capture packets at two locations. Since many students don’t have easy access to a NAT device or to two computers on which to take Wireshark measurements, you will be using pre-captured trace files nat-inside-wireshark-trace1- 1.pcapng and nat-outside-wireshark-trace1-1.pcapng.

### Part 2.1 (trace inside 1-1)

In this file, you should see an HTTP GET request addressed to the external web server at IP address 138.76.29.8, as well as the subsequent HTTP response message (“200 OK”). Both of these messages in the trace file were captured on the LAN side of the router.

27.1 What is the IP address of the client that sends the HTTP GET request in the `nat-inside-wireshark-trace1-1.pcapng` trace? 
    - `192.168.10.11`

27.2. What is the source port number of the TCP segment in this datagram containing the HTTP GET request? 
    - `53924`

27.3. What is the destination IP address of this HTTP GET request? 
    - `138.76.29.8`

27.4. What is the destination port number of the TCP segment in this datagram containing the HTTP GET request?
    - `80`
    
28. At what time is the corresponding HTTP 200 OK message from the web server forwarded by the NAT router to the client on the router’s LAN side?
    - `0.030672101` since first reference
    
29. What are the source and destination IP addresses and TCP source and destination ports on the IP datagram carrying this HTTP 200 OK message?
    - ip4.src: `138.76.29.8`
    - ip4.dst: `192.168.10.11`
    - tcp.src: `80`
    - tcp.dst: `53924`

### Part 2.2 (trace outside 1-1)

Open the trace file `nat-outside-wireshark-trace1-1.pcapng`. Note that the time stamps in this file and the nat-inside-wireshark-trace1-1.pcapng file are not necessarily synchronized.

In the nat-outside-wireshark-trace1-1.pcapng trace file, find the HTTP GET message that corresponds to the HTTP GET message that was sent from the client to the 138.76.29.8 server at time t=0.27362245, where t=0.27362245 is the time at which this message was sent, as recorded in the `nat-inside-wireshark-trace1-1.pcapng` trace file.

30. At what time does this HTTP GET message appear in the nat-outside-wireshark-trace1- 1.pcapng trace file?
    - 0.027356291
    
31. What are the source and destination IP addresses and TCP source and destination port numbers on the IP datagram carrying this HTTP GET (as recorded in the nat-outside- wireshark-trace1-1.pcapng trace file)?
    - ip4.src: `10.0.1.254`
    - ip4.dst: `138.76.29.8`
    - tcp.src: `53924`
    - tcp.dst: `80`
    
32. Which of these four fields are different than in your answer to question 27 above?
    - ip4.src. it's now the outbound of the nat
    
33. Are any fields in the HTTP GET message changed?
    - not of much meaning
    
34. Which of the following fields in the IP datagram carrying the HTTP GET are changed from the datagram received on the local area network (inside) to the corresponding datagram forwarded on the Internet side (outside) of the NAT router: Version, Header Length, Flags, Checksum?
    - checksum
    
Find the HTTP reply containing the “200 OK” message that was received in response to the HTTP GET request you just examined in questions 30-34 above.

35. At what time does this message appear in the nat-outside-wireshark-trace1-1.pcapng trace file?
    - 0.030625966

36. What are the source and destination IP addresses and TCP source and destination port numbers on the IP datagram carrying this HTTP reply (“200 OK”) message (as recorded in the nat-outside-wireshark-trace1-1.pcapng trace file)?
    - Source Address: 138.76.29.8 (138.76.29.8)
    - Destination Address: 10.0.1.254 (10.0.1.254)
    - Source Port: 80
    - Destination Port: 53924

Consider what happens when the NAT router receives this datagram that you examined in questions 35 and 36, performs NAT translation, and finally forwards that datagram to the destination host on the LAN side.

37. What are the source and destination IP addresses and TCP source and destination port numbers on the IP datagram carrying the HTTP reply (“200 OK”) that is forwarded from the router to the destination host?
    - see above when the client recieves it. but reverse src and dst

## Module 3: DHCP

In this module, you will be using the Wireshark trace file `dhcp-wireshark-trace1-1.pcapng`. Enter “dhcp” into the display filter field.

### Part 3.1(trace DHCP 1-1)

Start by looking at the DHCP Discover message. Locate the IP datagram containing the first Discover message in your trace.

38. Is this DHCP Discover message sent out using UDP or TCP as the underlying transport protocol?
    - UDP, as all dhcp is

39. What is the source IP address used in the IP datagram containing the Discover message? Is there anything special about this address? Explain.
    - Source Address: 0.0.0.0
    - yes, broadcasts don't have a source in the ip layer. 

40. What is the destination IP address used in the datagram containing the Discover message. Is there anything special about this address? Explain.
    - Destination Address: broadcasthost (255.255.255.255)
    - again, broadcast.

41. What is the value in the transaction ID field of this DHCP Discover message?
    - Transaction ID: 0x56f415ed
    
42. Now inspect the options field in the DHCP Discover message. What are five pieces of information (beyond an IP address) that the client is suggesting or requesting to receive from the DHCP server as part of this DHCP transaction?
    - Option: (55) Parameter Request List
    Length: 10
    Parameter Request List Item: (1) Subnet Mask
    Parameter Request List Item: (121) Classless Static Route
    Parameter Request List Item: (3) Router
    Parameter Request List Item: (6) Domain Name Server
    Parameter Request List Item: (15) Domain Name
    Parameter Request List Item: (119) Domain Search
    Parameter Request List Item: (252) Private/Proxy autodiscovery
    Parameter Request List Item: (95) LDAP [TODO:RFC3679]
    Parameter Request List Item: (44) NetBIOS over TCP/IP Name Server
    Parameter Request List Item: (46) NetBIOS over TCP/IP Node Type

Now look at the DHCP Offer message. Locate the IP datagram containing the DHCP Offer message in your trace that was sent by a DHCP server in response to the DHCP Discover message.

43. How do you know that this Offer message is being sent in response to the DHCP Discover message you studied in questions 38-42 above?
    - it was sent to me and it was first.
    
44. What is the source IP address used in the IP datagram containing the Offer message? Is there anything special about this address? Explain.
    - Source Address: 192.168.86.1 (192.168.86.1) (looks like a router to me)
    - Destination Address: MacBook-Pro-6.local (192.168.86.65) (for some reason my macbook is resolving it to that idk.)
    
45. What is the destination IP address used in the datagram containing the Offer message? Is there anything special about this address? Explain
    - yeah. it didn't exist. 

46. Now inspect the options field in the DHCP Offer message. What are five pieces of information that the DHCP server is providing to the DHCP client in the DHCP Offer message?
    - router, lease time, subnet mask, bcast addr, dns server

Once the DHCP Offer message is received, the client may have all of the information it needs to proceed. However, the client may have received OFFERs from multiple DHCP servers, and so a second phase is needed, with two more mandatory messages – the client-to-server DHCP Request message, and the server-to-client DHCP ACK message. Locate the IP datagram containing the first DHCP Request message in your trace, and answer the following questions.

47. What is the UDP source port number in the IP datagram containing the first DHCP Request message in your trace? What is the UDP destination port number being used?
    - Source Address: (0.0.0.0)

48. What is the source IP address in the IP datagram containing this Request message? Is there anything special about this address? Explain.
    - it's bcasting again

49. What is the destination IP address used in the datagram containing this Request message? Is there anything special about this address? Explain.
    - Destination Address: broadcasthost (255.255.255.255)

50. What is the value in the transaction ID field of this DHCP Request message? Does it match the transaction IDs of the earlier Discover and Offer messages?
    - Transaction ID: 0x56f415ed
    - it does
    
51. Now inspect the options field in the DHCP Discover message and take a close look at the “Parameter Request List”. What differences do you see between the entries in the ‘parameter request list’ option in this Request message and the same list option in the earlier Discover message?
    - there are a few extra given back

Locate the IP datagram containing the first DHCP ACK message in your trace, and answer the following questions.

52. What is the source IP address in the IP datagram containing this ACK message? Is there anything special about this address? Explain.
    - Source Address: 192.168.86.1 (192.168.86.1)
    - yeah. it's from the router
    
53. What is the destination IP address used in the datagram containing this ACK message? Is there anything special about this address? Explain.
    - Destination Address: MacBook-Pro-6.local (192.168.86.65)
    - yeah. it's no longer broadcasting it. the machine accepted the parameters
    
54. What is the name of the field in the DHCP ACK message (as indicated in the Wireshark window) that contains the assigned client IP address?
    - Your (client) IP address: MacBook-Pro-6.local (192.168.86.65)
    
55. For how long a time (the so-called “lease time”) has the DHPC server assigned this IP address to the client?
    - 1 day
    
56. What is the IP address (returned by the DHCP server to the DHCP client in this DHCP ACK message) of the first-hop router on the default path from the client to the rest of the Internet?
    - Router: 192.168.86.1 (192.168.86.1)
