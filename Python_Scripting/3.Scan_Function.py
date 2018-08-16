#!/usr/bin/env python
print('\n')

x = raw_input("Enter A Value : ")

## Normal if Nested Sequence
if x < 0:									
	print ("1. Entered Value is less than 0")
else:
	if x < 10:
		print ("2. Entered Value is less than 10")
	else:
		if x < 20:
			print ("3. Entered Value is less than 20")
		else:
			print ("4. Entered Value is greater than 20")


## if using elif Sequence
if x < 0:									
	print ("1. Entered Value is less than 0")
elif x < 10:
	print ("2. Entered Value is less than 10")
elif x < 20:
	print ("3. Entered Value is less than 20")
else:
	print ("4. Entered Value is greater than 20")


## range() function
print('\n')
print ("Printing from range function : ",range(5))

## for loop
print('\n')
words = ["KPIT", "Technologies", "Hinjewadi", "Phase - 1", "SEZ"]
for w in words:
	print (w)

## For loop using range functionality
print('\n')
for i in range(len(words)):
	print ('Word at index {} is : {}'.format(i,words[i]))

## while loop
print('\n')
count = 0
while count < len(words):
	print words[count]
	count = count+1

