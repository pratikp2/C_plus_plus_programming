#!/usr/bin/env python
print ("\n")

## Srtings ##
print ('Hello')					#  word	# works with ''," " and """ """
print ("Hello World : From python")		#  sentense
print ("""Hello world from Python.
this is made of multiple lines.""")		#  paragraph : Follows exact paragraph orientation given in """ """
print ("\n")

## Input Functions
First_Name = raw_input("Input your first name :  ")
Last_Name = raw_input("Enter Your last name :  ")
print ("Hello, Entered name is " + First_Name + " " + Last_Name)


## Identifiers (Type : Variables) ##	# Numbers : 1.integer 2.long 3.float 4.complex
var1 = var2 = var3 = 100		# Integer assignment 	OR var1,var2,var3 = 100, 200, 300
var4 = 99.9				# Float assignment
var5 = 100000*10000			# Long assignment
var6 = complex(var1,20)			# Complex assignment
print (var1)
print (var4)
print (var5)
print ("Comples Number is", var6.real, "+ i",var6.imag)
print ("\n")


## Identifiers (Type : String) ##
Line = 'User Name'		# String assignment
print (Line)
print ("\n")

## Identifiers (Type : List) ##
List = ["apple", "banana", "cherry"]		# List is list of different datatypes. Declared using [], modifiable
print ("List = ", List)
List[0] = 20
print ("New List = ", List)
print ("\n")

## Identifiers (Type : List) ##
Tuple = ("apple", "banana", 100)		# Tuples are read only list. Declared using ()
print ("Tuple = ", Tuple)
print ("Tuple[0] = ", Tuple[0])
#Tuple[0] = 'guava'
print ("\n")
