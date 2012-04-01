import rcpp

receiver = rcpp.Receiver(9000)

TIMEOUT = 1

while True:  
  data = receiver.receive(TIMEOUT)
  if data:
    print "rx: ", data
  else:
    print "tick"