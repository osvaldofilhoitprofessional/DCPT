#!/usr/bin/python3.9

import socket,sys

ip = input("Digite o IP: ")
porta = int(input("Digite a porta: "))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

res = sock.connect((ip,porta))

banner = sock.recv(1024)

print(banner)
