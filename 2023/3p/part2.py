import argparse

schematic = []

def contactWithSymbol(yLine, firstX, lastX):
	startX = firstX if firstX == 0 else firstX-1
	endX = lastX if lastX == len(schematic[yLine])-1 else lastX+1
	startY = yLine if yLine == 0 else yLine-1
	endY = yLine if yLine == len(schematic)-1 else yLine+1

	# print(startX, "-",endX, "-",startY, "-",endY)

	for y in range(startY, endY+1):
		for x in range(startX, endX+1):
			if isSymbol(schematic[y][x]):
				return (y, x)
	return (-1, -1)

def isSymbol(char):
	return char == "*"

def isNumber(char):
	return char >= '0' and char <= '9'

def parseSchematic(inputFile):
	with open(inputFile) as f:
		for line in f:
			l = []
			for char in line:
				if char != '\n':
					l.append(char)
			schematic.append(l)

def main(inputFile):
	parseSchematic(inputFile)

	gears = {}

	for y in range(0, len(schematic)):
		line = schematic[y]
		number = 0
		first = -1
		for x in range(0, len(line)):
			if isNumber(line[x]):
				if first == -1:
					first = x
					number = int(line[x])
				else:
					number = number*10 + int(line[x])
			else:
				if first != -1:
					gear = contactWithSymbol(y, first, x-1)
					if gear != (-1, -1):
						if gear in gears:
							gears[gear].append(number)
						else:
							gears[gear] = [number]
					number = 0
					first = -1

		if first != -1: 
			gear = contactWithSymbol(y, first, len(line)-1)
			if gear != (-1, -1):
				if gear in gears:
					gears[gear].append(number)
				else:
					gears[gear] = [number]

	print(gears)

	result = 0

	for gear in gears:
		numbers = gears[gear]
		if len(numbers) == 2:
			result += numbers[0]*numbers[1]

	return result


if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('-d', action='store_true', help='Use dummy test.')
	parser.add_argument('-r', type=int, help='The expected result.', nargs='?', required=False)
	args = parser.parse_args()

	inputFile = "input.txt" if not args.d else "test.txt"
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