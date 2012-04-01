RCPP

Robot
Control
Packet
Protocol


rcpp is a python module that programs can use to send and/or receive UDP data packets formatted in the RCCP protocol


rcpp-send.py is an example of a sending program

rcpp-receive is an example of a receiving program


The RCPP is defined as follows:

Each packet begins with a type code character.

---------------------------------------------------------------------------------------
Type: t 
Name: text
Description: a line of text data
Length: variable
example: 'tRobot Startup'
---------------------------------------------------------------------------------------
Type: m
Name: Motor
Description: Two servo motor speeds for both the left and the right continuous servos. Ranged between -90 and 90.
Length: 7 bytes
Example: m+90+90
---------------------------------------------------------------------------------------
Type: r
Name: Radiation
Description: A single byte of data sent whenever the gieger-mueller tube detects radiation.
Length: 1
Example: r
---------------------------------------------------------------------------------------
Type: c
Name: Counts Per Minute
Description: A raw calculation of how many signals detected per minute from the gieger-mueller tube.
Length: variable
Example: c50
---------------------------------------------------------------------------------------
Type: 
Name: 
Description: 
Length: 
Example: 
---------------------------------------------------------------------------------------
Type: 
Name: 
Description: 
Length: 
Example: 
---------------------------------------------------------------------------------------
