#!/usr/bin/env python3
#import socket module
from socket import *
import sys # In order to terminate the program serverSocket = socket(AF_INET, SOCK_STREAM) #Prepare a sever socket
#Fill in start
s = socket( AF_INET , SOCK_STREAM ) # our socket
s.bind(('',8080)) # listen on port 8080
s.listen()
while True:
    #Establish the connection
    print('Ready to serve...')
    c, addr = s.accept()
    try:
        message = c.recv(2048).decode()
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()
        f.close()
        #Send one HTTP header line into socket 
        c.send(("HTTP/1.x 200 OK\n\n").encode())
        #Send the content of the requested file to the client 
        for i in range(0, len(outputdata)):
            c.send(outputdata[i].encode()) 
        c.send("\r\n".encode())

        c.close() 
    except IOError:
    #Send response message for file not found #Fill in start
        c.send(("HTTP/1.x 404 OK").encode())
    #Close client socket
    c.close()

s.close()