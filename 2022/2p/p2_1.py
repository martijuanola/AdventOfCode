import argparse

def readInput(inputFile):
    f = open(inputFile, 'r')
    
    score = 0
    for line in f:
    	hisPlay = line[0]
    	myPlay = line[2]
    	score += shapePlayedScore(myPlay)
    	score += roundResultsScore(hisPlay, myPlay)
    
    f.flush()
    f.close()
    return score

def shapePlayedScore(shape):
    if shape == 'X':
    	return 1
    elif shape == 'Y':
    	return 2
    else:
    	return 3

def roundResultsScore(hisPlay, myPlay):
    if hisPlay == 'A':
    	if myPlay == 'X':
    		return 3
    	elif myPlay == 'Y':
    		return 6
    	else: 
    		return 0
    elif hisPlay == 'B':
    	if myPlay == 'X':
    		return 0
    	elif myPlay == 'Y':
    		return 3
    	else: 
    		return 6
    else:
    	if myPlay == 'X':
    		return 6
    	elif myPlay == 'Y':
    		return 0
    	else: 
    		return 3


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input',  default='input2.txt', help='Input file')
    args = parser.parse_args()
    
    score = readInput(args.input)
    print('My score: ', score)
    