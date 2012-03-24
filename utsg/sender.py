#!/usr/bin/env python

import socket
from sys import argv

script,dhost,dport,message=argv

sock=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
if dhost=='<broadcast>':
  sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
sock.sendto(message, (dhost, int(dport)))
