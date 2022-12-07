import argparse
import re

markerSize = 14

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    l = f.readline()
    size = len(l)

    d = {}

    for i in range(markerSize):
        c = l[i]
        addToDict(d, c)

    for i in range(markerSize, size):
        if len(d) == markerSize:
            return i
        else:
            removeFromDict(d, l[i-14])
            addToDict(d, l[i])


    f.flush()
    f.close()
    raise "None found!"

def addToDict(d, c):
    if d.get(c) != None:
            d[c] += 1
    else:
        d[c] = 1

def removeFromDict(d, c):
    if d.get(c) == 1:
        d.pop(c)
    else:
        d[c] -= 1
            

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input6.txt" if not args.d else "dummy6.txt"
    print(readInput(inputFile))

