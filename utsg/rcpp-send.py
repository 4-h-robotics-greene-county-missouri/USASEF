import rcpp

sender=rcpp.Sender(1)

while True:
  print '>',
  cmd = raw_input()
  sender.send(cmd)