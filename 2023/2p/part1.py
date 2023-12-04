import argparse

red = 0
blue = 0
green = 0

def process_line(line):
	# Strip is necessary because last word is word + \n
	mainBlocks = line.strip("\n").split(":")

	#HEADER
	gameID = int(mainBlocks[0].split(" ")[1])

	#GAMES
	for play in mainBlocks[1].split(";"):
		for color in play.split(","):
			elements = color.split(" ")
			number = int(elements[1])
			color = elements[2]
			if color == 'red' and number > red:
				return gameID, False
			elif color == 'blue' and number > blue:
				return gameID, False
			elif color == 'green' and number > green:
				return gameID, False

	return gameID, True


def main(inputFile):
	result = 0
	with open(inputFile) as f:
	    for line in f:
	        gameID, isPossible = process_line(line)
	        if isPossible:
	        	result += gameID
	return result

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('-d', action='store_true', help='Use dummy test.')
	parser.add_argument('-r', type=int, help='The expected result.', nargs='?', required=False)
	parser.add_argument('-red', type=int, default=0, help='RED cubes.', nargs='?', required=False)
	parser.add_argument('-green', type=int, default=0, help='GREEN cubes.', nargs='?', required=False)
	parser.add_argument('-blue', type=int, default=0, help='BLUE cubes.', nargs='?', required=False)
	args = parser.parse_args()

	inputFile = "input.txt" if not args.d else "test.txt"
	print('Using input file \'%s\'.' % inputFile)

	red = args.red
	green = args.green
	blue = args.blue

	result = main(inputFile)

	if args.r != None:
		if result == args.r:
			print('CORRECT!')
		else:
			print('FALSE!')
		print('Expected %(e)i and actual %(a)i.' % {"e": args.r, "a": result})
	else:
		print('Result is: %i' % result)


