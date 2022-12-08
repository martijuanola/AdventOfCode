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
    return getHighestScenicScore(forest)

def getHighestScenicScore(forest):
    sizeX = len(forest[0])
    sizeY = len(forest)

    scenicScores = [[1 for i in range(sizeX)] for i in range(sizeY)]

    for i in range(sizeY):
        for j in range(sizeX):
            val = forest[i][j]
            # Right
            aux = 0
            found = False
            jj = j+1
            while not found and jj < sizeX:
                aux += 1
                if forest[i][jj] >= val:
                    found = True
                jj += 1
            scenicScores[i][j] *= aux
            if aux == 0:
                continue

            # left
            aux = 0
            found = False
            jj = j-1
            while not found and jj >= 0:
                aux += 1
                if forest[i][jj] >= val:
                    found = True
                jj -= 1
            scenicScores[i][j] *= aux
            if aux == 0:
                continue

            # up
            aux = 0
            found = False
            ii = i-1
            while not found and ii >= 0:
                aux += 1
                if forest[ii][j] >= val:
                    found = True
                ii -= 1
            scenicScores[i][j] *= aux
            if aux == 0:
                continue

            # down
            aux = 0
            found = False
            ii = i+1
            while not found and ii < sizeY:
                aux += 1
                if forest[ii][j] >= val:
                    found = True
                ii += 1
            scenicScores[i][j] *= aux
            if aux == 0:
                continue

    # print(scenicScores)

    return reduce(lambda acc, l: max(acc, max(l)), scenicScores, -1)



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input8.txt" if not args.d else "dummy8.txt"
    print("Highest Scenic Score -> ", readInput(inputFile))

