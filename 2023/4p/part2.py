import argparse

cards = []

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

	return count


def main(inputFile):
	result = 0
	numLines = 0
	with open(inputFile) as f:
		for line in f:
			cards.append(1)
			numLines += 1

	with open(inputFile) as f:
		cardI = 0
		for line in f:
			aux = process_line(line)
			for i in range(1, aux+1):
				cards[cardI + i] += cards[cardI]
			result += cards[cardI]
			cardI += 1
	print(cards)
	
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


