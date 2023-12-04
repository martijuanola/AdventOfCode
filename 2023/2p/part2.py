import argparse

def process_line(line):
	# Strip is necessary because last word is word + \n
	mainBlocks = line.strip("\n").split(":")

	#HEADER
	gameID = int(mainBlocks[0].split(" ")[1])

	maxRed = 0
	maxGreen = 0
	maxBlue = 0

	#GAMES
	for play in mainBlocks[1].split(";"):
		for color in play.split(","):
			elements = color.split(" ")
			number = int(elements[1])
			color = elements[2]
			if color == 'red' and number > maxRed:
				maxRed = number
			elif color == 'blue' and number > maxBlue:
				maxBlue = number
			elif color == 'green' and number > maxGreen:
				maxGreen = number

	return maxRed*maxGreen*maxBlue


def main(inputFile):
	result = 0
	with open(inputFile) as f:
	    for line in f:
	        power = process_line(line)
	        result += power
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