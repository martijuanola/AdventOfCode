import argparse
from functools import reduce
# import re

def readInput(inputFile):
    f = open(inputFile, 'r')

    forest = []
    for line in f.readlines():
        forest.append([int(char) for char in line[:-1]])
    
    f.flush()
    f.close()
    
    print(forest)
    return getVisibleTrees(forest)

def getVisibleTrees(forest):
    sizeX = len(forest[0])
    sizeY = len(forest)

    visibility = [[False for i in range(sizeX)] for i in range(sizeY)]
    
    top = [-1 for i in range(sizeX)]
    bottom = [-1 for i in range(sizeX)]
    left = [-1 for i in range(sizeY)]
    right = [-1 for i in range(sizeY)]

    for i in range(sizeY):
        for j in range(sizeX):
            val = forest[i][j]
            if val > top[j]:
                top[j] = val
                visibility[i][j] = True
            if val > left[i]:
                left[i] = val
                visibility[i][j] = True

    for i in range(sizeY-1, -1, -1):
        for j in range(sizeX-1, -1, -1):
            val = forest[i][j]
            if val > bottom[j]:
                bottom[j] = val
                visibility[i][j] = True
            if val > right[i]:
                right[i] = val
                visibility[i][j] = True

    print(visibility)
    return reduce(lambda acc, l: acc+sum(l), visibility, 0)



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input8.txt" if not args.d else "dummy8.txt"
    print("VisibleTrees -> ", readInput(inputFile))

