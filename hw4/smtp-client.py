from socket import * 

msg = "\r\n I love computer networks!" 
endmsg = "\r\n.\r\n" 
# Choose a mail server (e.g. Google mail server) and call it mailserver 
mailserver = "127.0.0.1"

# Create socket called clientSocket and establish a TCP connection with mailserver 
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, 25))
recv0 = clientSocket.recv(1024).decode() 
print(recv0) 

if recv0[:3] != '220': 
    print('220 reply not received from server.') 

# Send HELO command and print server response. 
heloCommand = 'HELO localhost\r\n' 
clientSocket.send(heloCommand.encode()) 
recv1 = clientSocket.recv(1024).decode() 
print(recv1) 
if recv1[:3] != '250': 
    print('250 reply not received from server.')
    
# Email Content
from_addr = "tah568@hpc.msstate.edu"
to_addr = "drew@localhost"
subject = "Testing SMTP"
message = msg


# Send MAIL FROM command and print server response.
Command = f'MAIL FROM:<{from_addr}>\r\n' 
clientSocket.send(Command.encode()) 
recv = clientSocket.recv(1024).decode() 
print(recv)

# Send RCPT TO command and print server response.
Command = f'RCPT TO:<{to_addr}>\r\n' 
clientSocket.send(Command.encode()) 
recv = clientSocket.recv(1024).decode() 
print(recv)

# Send DATA command and print server response. 
Command = 'DATA\r\n' 
clientSocket.send(Command.encode()) 
recv = clientSocket.recv(1024).decode() 
print(recv)

# Send message data. 
Command = f'Subject: {subject}\r\nTo: {to_addr}\r\n\r\n{message}\r\n' 
clientSocket.send(Command.encode()) 

# Message ends with a single period. 
Command = endmsg 
clientSocket.send(Command.encode()) 
recv = clientSocket.recv(1024).decode() 
print(recv)

# Send QUIT command and get server response. 
Command = 'QUIT' 
clientSocket.send(Command.encode()) 
