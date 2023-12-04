import argparse

def process_line(line):
	numbers = line.strip("\n").split(":")[1].split('|')
	winningNumbers = numbers[0]
	myNumbers = numbers[1]

	winning = set()
	for num in winningNumbers.split(" "):
		if num.isnumeric():
			winning.add(int(num))

	count = 0
	for num in myNumbers.split(" "):
		if num.isnumeric() and int(num) in winning:
			count += 1

	if count == 0:
		return count
	return 2**(count-1)


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


