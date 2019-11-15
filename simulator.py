
import serial
import random

port = "dev/cu.SLAB_USBtoUART"

ser = serial.Serial(port,115200)

counter = 1


while True:
	# Microwave Probability + Frequency
	mProb = random.randint(1,900)
	mOff = 0

	# Fridge Probability + Frequency
	fProbs = [0,0,0,0]
	fClose = 0
	index = 0
	for prob in fProbs:
		fProbs[index] = random.randint((300 * index) + 1, 300 * (index + 1))


	# Cabinet Probability + Frequency
	cProb = random.randint(1,900)
	cClose = 0

	# Door Probability + Frequency
	dProbs = [0,0,0,0,0,0,0,0,0,0]
	index = 0
	for prob in dProbs:
		dProbs[index] = random.randint((120 * index) + 1, 120 * (index + 1))


	while (counter <= 1200):
		fPhase = Integer(counter/300)
		dPhase = Integer(counter/120)

		if(counter == mProb):
			mOff = counter + random.randint(1,300)
			ser.write(b'On')
		if(counter == mOff):
			ser.write(b'Off')

		if(counter == fProbs[fPhase]):
			fClose = counter + random.randint(1,30)
			ser.write(b'Touch')
		if(counter == fClose):
			ser.write(b'Released')

		if(counter == cProb):
			cClose = counter + random.randint(1,300)
			ser.write(b'Open')
		if(counter == cClose):
			ser.write(b'Closed')

		if(counter == dProbs[dPhase]):
			probster = random.randint(1,5)
			if(probster == 1 || probster == 2):
				ser.write(b'In')
			if(probster == 3 || probster == 4):
				ser.write(b'Out')
			if(probster == 5):
				ser.write(b'None')


		sleep(1)
		counter++

	counter = 1



























	
