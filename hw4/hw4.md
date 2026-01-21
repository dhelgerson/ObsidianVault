![[img1.png]]
1. Answer the following questions using the figure above.  
	a. Assign IP addresses to all of the interfaces. For Subnet 1, use addresses of the   form 192.168.1.xxx; for Subnet 2, use addresses of the form 192.168.2.xxx; and   for Subnet 3, use addresses of the form 192.168.3.xxx.  
	b. Assign MAC addresses to all of the adapters.  


| subnet | host | ip           | mac               |
| ------ | ---- | ------------ | ----------------- |
| 1      | a    | 192.168.1.10 | fe:fe:fe:fe:fe:01 |
| 1      | b    | 192.168.1.20 | fe:fe:fe:fe:fe:02 |
| 1      | r1   | 192.168.1.1  | fe:fe:fe:fe:00:01 |
| 2      | r1   | 192.168.2.1  | fe:fe:fe:fe:00:02 |
| 2      | c    | 192.168.2.10 | fe:fe:fe:fe:fe:03 |
| 2      | d    | 192.168.2.20 | fe:fe:fe:fe:fe:04 |
| 2      | r2   | 192.168.2.2  | fe:fe:fe:fe:01:01 |
| 3      | r2   | 192.168.3.1  | fe:fe:fe:fe:01:02 |
| 3      | e    | 192.168.3.10 | fe:fe:fe:fe:fe:05 |
| 3      | f    | 192.168.3.20 | fe:fe:fe:fe:fe:06 |

c. Consider sending an IP datagram from Host E to Host B. Suppose all of the ARP   tables are up to date. Enumerate all the steps.  
	1. E sends frame to the router between subnet 2 and 3 w/ packet for b
	2. that router send frame to the router between subnet 1 and 2 for b
	3. 2nd router sends a frame to b w/ the packet.
d. Repeat c, now assuming that the ARP table in the sending host is empty (and the   other tables are up to date).  
	\1. e sends arp discover for r2 (192.168.3.1) to ff:ff:ff:ff:ff:ff
	\2. router replies w/ it's mac.
	\3. follow c1-3
2. Replace the router between Subnets 1 and 2 with a switch S1, and label the router between Subnets 2 and 3 as R1.  
a. Consider sending an IP datagram from Host E to Host F. Will Host E ask router R1 to help forward the datagram? Why? In the Ethernet frame containing the IP datagram, what are the source and destination IP and MAC addresses?  
	- No, it's in the same subnet, so it will send the frame straight to F, src and dst are E and F
b. Suppose E would like to send an IP datagram to B, and assume that E’s ARP cache   does not contain B’s MAC address. Will E perform an ARP query to find B’s MAC address? Why? In the Ethernet frame (containing the IP datagram destined to B) that is delivered to R1, what are the source and destination IP and MAC addresses?  
	- no, B is on a different subnet, E will perform an arp query for R1's mac if it doesn't have it, then pass the packet to R1.
	- src: E, dst: B (src and dst don't change for the ip packet. just mac addresses)
c. Suppose Host A would like to send an IP datagram to Host B, and neither A’s ARP cache contains B’s MAC address nor does B’s ARP cache contain A’s MAC address. Further suppose that the switch S1’s forwarding table contains entries for Host B and router R1only. Thus, A will broadcast an ARP request message. What actions will switch S1 perform once it receives the ARP request message? Will router R1 also receive this ARP request message? If so, will R1forward the message to Subnet 3? Once Host B receives this ARP request message, it will send back to Host A an ARP response message. But will it send an ARP query message to ask for A’s MAC address? Why? What will switch S1 do once it receives an ARP response message from Host B?
	- S1 will broadcast that arp request to the other inferfaces. B will reply.


