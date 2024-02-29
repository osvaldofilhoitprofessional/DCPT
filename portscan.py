#!/usr/bin/python3.9

import socket,sys

for porta in range(1,65535):
    mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    if (mysock.connect_ex((sys.argv[1],porta)) == 0):
        print("Porta ",porta, "[ABERTA]")
        mysock.close()
