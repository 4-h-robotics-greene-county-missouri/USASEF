#!/usr/bin/env python

# rcpp == robot control packet protocol
# a module to allow programs to send and receive packets
# uses UDP protocol and broadcast packets

import socket
import threading
import Queue

DEFAULT_HOST = '<broadcast>'
BASE_PORT = 31337

class Sender:
  def __init__(self, destination_port, destination_address=DEFAULT_HOST):
    self.dhost=destination_address
    self.dport=int(BASE_PORT+destination_port)
    self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    if destination_address=='<broadcast>':
      self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

  def send(self, packet):
    self.sock.sendto(packet, (self.dhost, self.dport))

def rx_thread(receiver):
  while receiver.running.isSet():
    data, addr = receiver.sock.recvfrom(1024)
    receiver.packet_queue.put(data)
  
class Receiver:
  def __init__(self, listen_port):
    self.lport=int(BASE_PORT+listen_port)
    self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    self.sock.bind(('', self.lport))
    self.packet_queue=Queue.Queue()
    self.running = threading.Event()
    self.running.set()
    self.thread = threading.Thread(target=rx_thread, args=(self,))
    self.thread.daemon = True
    self.thread.start()

  def packet_ready(self):
    return not self.packet_queue.empty()
  
  def receive(self, timeout=None):
    try:
      ret = self.packet_queue.get(True, timeout)
    except Queue.Empty:
      ret = None
    return ret
