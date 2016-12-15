#!/usr/bin/env python

# data:
# manufacturer: the name of the manufacturer (e.g., "Ford")
# model: the name of the model (e.g., "Focus")
# width: the width of the wheel base in inches
# length: the length of the car in inches
# public methods include:
# constructor with no arguments: sets all internal data to "-1"
# constructor with arguments: for all the protected data
# debug: prints out the values of all internal data in the class
#def __init__(self, num_holes=None):
#    if num_holes is None:
#        # Construct a gouda
#    else:
#        # custom cheese
    # common initializatio
class Vehicle:


	def __init__(self,manufacturer = None,model = None,width = None,length = None):
		if manufacturer is None and model is None and width is None and length is None:
			self.manufacturer = -1
                	self.model = -1
                	self.width = -1
                	self.length = -1

		else:		
			self.manufacturer = manufacturer
                	self.model = model
               		self.width = width
            		self.length = length

	def debug(self):
		print "Vehicle:"
		print " manufacturer = %s" %self.manufacturer
                print " model = %s" %self.model
                print " width = %s" %self.width
                print " length = %s" %self.length





