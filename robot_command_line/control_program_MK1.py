#This defines all of the variables' packet data. 
go = "w+90+90"
stop = "w+00+00"
left = "w+90-90"
right = "w-90+90"
com = 0
#instuction printing.
print "Press any single WASD key and then press enter. \nThe robot will move in the appropriate manner. \npress and enter q to quit."

#This loops the actual human-to-program interface code.
while True:
	
	kb = raw_input()
	if kb == 'w':
		com = go
		print com
	elif kb == 's':
		com = stop
		print com
	elif kb == 'a':
		com = left
		print com
	elif kb == 'd':
		com = right
		print com
	elif kb == 'q':
		break