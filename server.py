#__Coding:UTF-8__

#FileName:server.py
#Auther:bnhc

import socket
host=''
hostname = socket.gethostname()
#hostip = getipaddrs(hostname)
#print('Host IP:',hostip)
port = 9999
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((host,port))
s.listen(4)
while True:
    conn,addr = s.accept()
    print('Connected by',addr)
    data = conn.recv(1024)
    if not data:break
    conn.sendall(data)
    print('Reveived',repr(data))
    conn.close()
