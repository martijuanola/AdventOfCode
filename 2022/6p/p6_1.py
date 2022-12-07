import argparse
import re

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    l = f.readline()
    size = len(l)
    for i in range(size-3):
        if l[i] != l[i+1] and l[i] != l[i+2] and l[i] != l[i+3]  and l[i+1] != l[i+2] and l[i+1] != l[i+3] and l[i+2] != l[i+3]:
            print(l[i:i+4])
            return i+4

    f.flush()
    f.close()
    raise "None found!"

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input6.txt" if not args.d else "dummy6.txt"
    print(readInput(inputFile))

