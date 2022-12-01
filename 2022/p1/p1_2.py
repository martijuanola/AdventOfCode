import queue

def readInput(inputFile):
	q = queue.PriorityQueue()
	
	f = open('input1.txt', 'r')
	elf = 0
	elfID = 0
	
	for line in f:
		if line != '\n':
			elf += int(line)
		else:
			q.put((-elf, elfID+1))
			elf = 0
			elfID += 1

	f.flush()
	f.close()

	return q

if __name__ == '__main__':
	q = readInput('input.txt')

	s = q.get()[0] + q.get()[0] + q.get()[0]
	print('Sum of top 3 elfs calories: ', -s)
	