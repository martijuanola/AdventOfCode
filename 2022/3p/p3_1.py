import argparse

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    res = 0
    for line in f:
        character = findCharacter(line)
        res += getPriority(character)

    f.flush()
    f.close()
    return res

def findCharacter(line):
    size = len(line)
    mid = int(size / 2)
    for i in range(mid):
        if line.find(line[i], mid) != -1:
            return line[i]

    raise "NOT GOOD"

def getPriority(character):
    if character < 'a':
        return ord(character) - ord("A") + 27
    else:
        return ord(character) - ord("a") + 1

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-dummy', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input3.txt" if not args.dummy else "dummy3.txt"
    res = readInput(inputFile)
    print('The result: ', res)
    