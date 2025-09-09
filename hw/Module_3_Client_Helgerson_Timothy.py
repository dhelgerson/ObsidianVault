#!/usr/bin/env python3
from time import time,sleep
from socket import *

s = socket(AF_INET, SOCK_DGRAM)
s.settimeout(1)

s.connect(('localhost',12000))

for i in range(1,11):
    message = f"Ping {i} {time()}".encode()
    start = time()
    s.send(message)
    try:
        recv = s.recv(64)
        stop = time()
        print(recv.decode(),(stop-start)*1000,'ms')
        sleep(1)
    except timeout:
        print("Request Timed Out")

# s.close()