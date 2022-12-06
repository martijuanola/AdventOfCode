import argparse
import re

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    stacks = readStacks(f)

    print(stacks)

    line = f.readline()
    while line != '':
        nums = list(map(lambda x: int(x), re.findall(r'\d+', line)))

        sublist = stacks[nums[1]-1][-nums[0]:]
        stacks[nums[1]-1] = stacks[nums[1]-1][:-nums[0]]
        stacks[nums[2]-1] += sublist
        
        line = f.readline()

    print(stacks)

    f.flush()
    f.close()
    return stacks

def readStacks(f):
    line = f.readline()
    nStacks = int((len(line)+1)/4)
    stacks = [[] for i in range(nStacks)]
    while line != "\n":
        for i in range(nStacks):
            c = line[i*4+1]
            if c >= 'A' and c <= 'Z':
                stacks[i].insert(0, c)
        line = f.readline()
    return stacks

def processResult(stacks):
    s = ""

    for stack in stacks:
        s += stack.pop()

    print("Result: ", s)

    pass

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input5.txt" if not args.d else "dummy5.txt"
    stacks = readInput(inputFile)
    processResult(stacks)

