import rcpp
import time # Lol I is a Timelord!
print "Please type in port of desired robot."
port = raw_input()
port = int(port)
sender = rcpp.Sender(port)
#This defines all of the variables' packet data. 
go = "m+90+90\n"
stop = "m+00+00\n"
left = "m+90-90\n"
right = "m-90+90\n"
varibledrive = 0
com = 0
#instuction printing.
print "Press any single WASD key and then press enter.\nThe robot will move in the appropriate manner.\nEntering v will give a custom foreward speed prompt. It will go that speed for 5 seconds. \npress and enter q to quit."

#This loops the actual human-to-program interface code.
while True:
	
	kb = raw_input()
	if kb == 'w':
		com = go
		sender.send(com)
	elif kb == 's':
		com = stop
		sender.send(com)
	elif kb == 'a':
		com = left
		sender.send(com)
	elif kb == 'v':
		print "Please type your desired speed between 0 and 90: \n"
		user_speed_input = raw_input()
		if len( user_speed_input ) == 1:
				user_speed_input = "0" + user_speed_input
		varibledrive = "m+" + user_speed_input + "+" + user_speed_input
		com = varibledrive
		sender.send(com)
		print com
		time.sleep(5)
		com = stop
		sender.send(com)
		print "The robot has stopped."
	elif kb == 'd':
		com = right
		sender.send(com)
	elif kb == 'q':
		com = stop
		sender.send(com)
		break