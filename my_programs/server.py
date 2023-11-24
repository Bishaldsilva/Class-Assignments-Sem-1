import socket
import threading

PORT = 5050
HOST = socket.gethostbyname(socket.gethostname())
ADDR = (HOST,PORT)
FORMAT = 'UTF-8'
BUFSIZE = 1024

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(ADDR)
clients = []

def broadcast(msg,name,cur_client = None):
    for i in clients:
        if i == cur_client:
            continue
        i.send(f"[{name}] {msg}".encode(FORMAT))

def client_thread(client,addr):
    client.send("Please enter your name: ".encode())
    name = client.recv(BUFSIZE).decode(FORMAT)
    msg = f"[{name}] has joined the chat"
    broadcast(msg,name,client)
    run = True
    while run:
        msg = client.recv(BUFSIZE).decode(FORMAT)
        if msg == "quit":
            client.close()
            clients.remove(client)
            msg = f"[{name}] has left the chat"
            broadcast(msg,name)
            break
        else:
            broadcast(msg,name,client)

def start():
    server.listen()
    print(F"Server is running at address {HOST}")
    while True:
        client,addr = server.accept()
        clients.append(client)
        print(f"client with address {addr} connected...")
        thread = threading.Thread(target=client_thread,args=(client,addr))
        thread.start()

start()
