import pygame
import RPi.GPIO as GPIO
import time
import serial
pygame.mixer.pre_init(channels=8, buffer=1024)
pygame.mixer.init()

class PianoStairs():

	def __init__(self):
		self.numpins = 8
		self.ser = serial.Serial('/dev/ttyAMA0', 9600)
        # switch between piano and guitar every 3 minutes
		letters = ["g", "a", "b", "c", "d", "e", "f", "g2"]
		#letters = letters[::-1]
		self.piano_notes = [pygame.mixer.Sound("/home/pi/InteractiveClothRack/notes/"+letter+".wav") for letter in letters]
		#guit_let = ["e", "a", "d", "g", "b", "e2"]
		#self.guitar_notes = [pygame.mixer.Sound("guitar/"+letter+".wav") for letter in guit_let]

	def piano(self, i):
		self.piano_notes[i].play()

	#def guitar(self, i):
		#self.guitar_notes[i].play()

	def run(self):
		count = 0
		while True:
			numnotes = 0
			while numnotes < 8:
				line = self.ser.read()
				time.sleep(0.01)
				if len(line) < 1:
					continue
			#for i in range(0,7):
				if line[0] != '0':
					self.piano(numnotes)
					count +=1
					print "Motion detected! %d\n" % count
					numnotes +=1
					time.sleep(0.2)
				#elif self.Current_State==0 and self.Previous_State==1:
					#self.Previous_State=0
					#print "Ready\n"
				#time.sleep(0.01)
				#GPIO.cleanup()
				#else:
					#print "Ready\n"
if __name__ == "__main__":
	pianoStairs = PianoStairs()
	pianoStairs.run()
	