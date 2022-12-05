import argparse

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    score = 0
    for line in f:
    	hisPlay = line[0]
    	result = line[2]
    	score += roundResultsScore(hisPlay, result)
    
    f.flush()
    f.close()
    return score

def roundResultsScore(hisPlay, result):
    if result == "X":
        if hisPlay == "A":
            return 0 + 3
        elif hisPlay == "B":
            return 0 + 1
        else:
            return 0 + 2
    elif result == "Y":
        if hisPlay == "A":
            return 3 + 1
        elif hisPlay == "B":
            return 3 + 2
        else:
            return 3 + 3
    else:
        if hisPlay == "A":
            return 6 + 2
        elif hisPlay == "B":
            return 6 + 3
        else:
            return 6 + 1

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input',  default='input2.txt', help='Input file')
    args = parser.parse_args()
    
    score = readInput(args.input)
    print('My score: ', score)
    