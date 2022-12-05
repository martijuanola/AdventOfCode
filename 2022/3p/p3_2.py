import argparse

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    res = 0
    lines = f.readlines()
    for i, l1 in enumerate(lines):
        if i % 3 == 0:
            character = findCharacter(l1, lines[i+1], lines[i+2])
            res += getPriority(character)

    f.flush()
    f.close()
    return res

def findCharacter(l1, l2, l3):
    for c in l1:
        if l2.find(c) != -1 and l3.find(c) != -1:
            return c
    raise "Something bad"

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
    