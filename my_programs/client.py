import socket
from threading import Thread

PORT = 5050
HOST = socket.gethostbyname(socket.gethostname())
ADDR = (HOST,PORT)
FORMAT = 'UTF-8'
BUFSIZE = 1024

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(ADDR)

def send():
    while True:
        msg = input()
        client.send(msg.encode(FORMAT))
        if msg == "quit":
            client.close()
            break

def recv():
    while True:
        msg = client.recv(BUFSIZE).decode(FORMAT)
        print(msg)

send_thread = Thread(target=send)
send_thread.start()

recv_thread = Thread(target=recv)
recv_thread.start()