import argparse


ZERO = 'zero'
ONE = 'one'
TWO = 'two'
THREE = 'three'
FOUR = 'four'
FIVE = 'five'
SIX = 'six'
SEVEN = 'seven'
EIGHT = 'eight'
NINE = 'nine'

def getStartingNumber(string):
	if string.startswith(ZERO):
		return 0
	elif string.startswith(ONE):
		return 1
	elif string.startswith(TWO):
		return 2
	elif string.startswith(THREE):
		return 3
	elif string.startswith(FOUR):
		return 4
	elif string.startswith(FIVE):
		return 5
	elif string.startswith(SIX):
		return 6
	elif string.startswith(SEVEN):
		return 7
	elif string.startswith(EIGHT):
		return 8
	elif string.startswith(NINE):
		return 9
	else:
		return -1

def processSubString(acum):
	first = -1
	last = -1
	while len(acum) > 2:
		num = getStartingNumber(acum)
		if num != -1:
			if first == -1:
				first = num
			last = num

		acum = acum[1:]
	return first, last
	
def process_line(line):
	result = -1
	last = -1

	acum = ""

	for char in line:
		if char.isdigit():
			auxF, auxL = processSubString(acum)
			acum = ""
			if auxF != -1:
				if result == -1:
					result = auxF
				last = auxL


			if result == -1:
				result = int(char)
			last = int(char)
		else:
			acum = acum + char

	auxF, auxL = processSubString(acum)
	if auxF != -1:
		if result == -1:
			result = auxF
		last = auxL


	result = result*10+last

	if result < 10:
		raise Exception('ERROR! Current state {result = %(r)i, last %(l)i}' % {"r": result, "l": last})

	return result

def main(inputFile):
	result = 0
	with open(inputFile) as f:
	    for line in f:
	        result += process_line(line)
	return result

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('-d', action='store_true', help='Use dummy test.')
	parser.add_argument('-r', type=int, help='The expected result.', nargs='?', required=False)
	args = parser.parse_args()

	inputFile = "input.txt" if not args.d else "test2.txt"
	print('Using input file \'%s\'.' % inputFile)

	result = main(inputFile)

	if args.r != None:
		if result == args.r:
			print('CORRECT!')
		else:
			print('FALSE!')
		print('Expected %(e)i and actual %(a)i.' % {"e": args.r, "a": result})
	else:
		print('Result is: %i' % result)


