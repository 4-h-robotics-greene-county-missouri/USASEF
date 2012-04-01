import rcpp

receiver = rcpp.Receiver(9001)

TIMEOUT = 1

while True:  
  data = receiver.receive(TIMEOUT)
  if data:
    print "rx: ", data
  else:
    print "tick"