import argparse

def process_line(line):
	result = -1
	last = -1

	for char in line:
		if char.isdigit():
			if result == -1:
				result = int(char)
			else:
				last = int(char)

	if last != -1:
		result = result*10+last
	else:
		result = result*11

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

	inputFile = "input.txt" if not args.d else "test1.txt"
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


