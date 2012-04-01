import rcpp

sender=rcpp.Sender(9000)

while True:
  cmd = raw_input('>')
  sender.send(cmd)