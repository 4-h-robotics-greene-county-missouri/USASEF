import rcpp

receiver = rcpp.Receiver(1)

TIMEOUT = 1

while True:  
  data = receiver.receive(TIMEOUT)
  if data:
    print "rx: ", data
  else:
    print "tick"