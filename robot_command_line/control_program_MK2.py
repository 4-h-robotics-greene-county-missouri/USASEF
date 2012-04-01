import rcpp
print "Please type in port of desired robot."
port = raw_input()
port = int(port)
sender = rcpp.Sender(port)
#This defines all of the variables' packet data. 
go = "m+90+90\n"
stop = "m+00+00\n"
left = "m+90-90\n"
right = "m-90+90\n"
com = 0
#instuction printing.
print "Press any single WASD key and then press enter. \nThe robot will move in the appropriate manner. \npress and enter q to quit."

#This loops the actual human-to-program interface code.
while True:
	
	kb = raw_input()
	if kb == 'w':
		com = go
		print com
		sender.send(com)
	elif kb == 's':
		com = stop
		print com
		sender.send(com)
	elif kb == 'a':
		com = left
		print com
		sender.send(com)
	elif kb == 'd':
		com = right
		print com
		sender.send(com)
	elif kb == 'q':
		com = stop
		sender.send(com)
		break