#!/usr/bin/env python

"""
A simple echo client
"""

import socket

host = 'localhost'
port = 8080
size = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host,port))
s.settimeout(.25)

s.send('+++')

data = s.recv(size)

s.close()
print 'Received:', data 