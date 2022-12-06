import argparse

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    count = 0
    lines = f.readlines()
    for line in lines:
        p1, p2 = getPairs(line)
        if p1[1] < p2[0] or p1[0] > p2[1]:
            continue
        count += 1

    f.flush()
    f.close()
    return count

def getPairs(l):
    pairs = l.split(',')
    p11 = int(pairs[0].split('-')[0])
    p12 = int(pairs[0].split('-')[1])
    p21 = int(pairs[1].split('-')[0])
    p22 = int(pairs[1].split('-')[1])
    return (p11, p12), (p21, p22)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input4.txt" if not args.d else "dummy4.txt"
    res = readInput(inputFile)
    print('The result: ', res)

