###########################################################################################################################
#
#	A dictionary is a collection which is unordered, changeable and indexed. In Python dictionaries are written with
#	curly brackets, and they have keys anvalues.
#	Functions for Dictionary : dict(),del(),len()
#
###########################################################################################################################

#!/usr/bin/env python
print('\n')

Dictionary = {"apple": "green","banana": "yellow","cherry": "red"}
print ("1. Dictionary = ", Dictionary)

Dictionary["apple"] = "red"
print ("2. Dictionary = ", Dictionary)

## It is possible to update the dictionary by adding new index
Dictionary["guava"] = "green"
print ("3. Dictionary = ", Dictionary)

## As well as deleting is done using del() function
del(Dictionary["guava"])
print ("4. Dictionary = ", Dictionary)

## dict() is constructor for Dictionary can be invoked for instantiation
Dictionary_2 = dict(apple="green", banana="yellow", cherry="red")
print ("5. Dictionary_2 = ", Dictionary_2)

## To Print Length of the Dictionary len() function is used
print ("Length of Dictionart_2 is : ", len(Dictionary_2))

print('\n')
