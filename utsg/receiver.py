#!/usr/bin/env python

import socket

HOST = ''
PORT = 8888

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((HOST, PORT))

while True:
  data, addr = s.recvfrom(1024)
  print 'rx:', data
