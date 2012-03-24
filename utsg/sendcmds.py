#!/usr/bin/env python

import socket
import sys

script,dport=sys.argv

sock=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

while True:
  cmd = sys.stdin.readline()
  if cmd.startswith('exit'):
    break
  sock.sendto(cmd, ('<broadcast>', int(dport)))
