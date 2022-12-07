import argparse
# import re

class Directory:
    def __init__(self, name):
        self.name = name
        self.size = -1
        
        self.parent = None #Directory
        self.childs = [] #[Directory|File]

    def __init__(self, name, parent):
        self.name = name
        self.size = -1
        
        self.parent = parent #Directory
        self.childs = {} #[Directory|File]

    def addChild(self, child):
        if isinstance(child, Directory):
            self.childs["dir - " + child.getName()] = child
        elif isinstance(child, File):
            self.childs["file - " + child.getName()] = child
        else:
            raise "[DIR] Unknown object type!"

    def getDir(self, name):
        if self.childs.get("dir - " + name) == None:
            raise "[DIR] Directory not found!"
        return self.childs["dir - " + name]

    def getParentDir(self):
        return self.parent

    def getName(self):
        return self.name
      
    def getSize(self):
        if self.size == -1:
            self.size = 0
            for child in self.childs.values():
                self.size += child.getSize()

        return self.size

    def getSumOfSmallDirs(self, maxSize):
        r = 0
        if self.size == -1:
            raise "[DIR] - Size not calculated!"
        elif self.size <= maxSize:
            r += self.size

        for child in self.childs.values():
            if isinstance(child, Directory):
                r += child.getSumOfSmallDirs(maxSize)

        return r

    def recursiveString(self, tabDepth):
        s = (tabDepth*"  ") + f"- {self.name} (dir, size={self.size})"
        for child in self.childs.values():
            s += "\n" + child.recursiveString(tabDepth+1)
        return s

    def __str__(self):
        return self.recursiveString(0)

    

class File:
    def __init__(self, name, size):
        self.name = name
        self.size = size
    
    def getSize(self):
        return self.size

    def getName(self):
        return self.name

    def __str__(self):
        return f"- {self.name} (file, size={self.size})"

    def recursiveString(self, tabDepth):
        return (tabDepth*"  ") + f"- {self.name} (file, size={self.size})"


def readInput(inputFile):
    f = open(inputFile, 'r')

    root = Directory("root", None)
    root.addChild(Directory("/", root))
    currentDirectory = root

    tokens = f.readline()[:-1].split(" ")
    while tokens[0] != "":
        if tokens[0] == "$":
            if tokens[1] == "cd":
                if tokens[2] == "..":
                    currentDirectory = currentDirectory.getParentDir()
                else:
                    currentDirectory = currentDirectory.getDir(tokens[2])
                tokens = f.readline()[:-1].split(" ")
            elif tokens[1] == "ls":
                tokens = f.readline()[:-1].split(" ")
                while tokens[0] != "$" and tokens[0] != "":
                    if tokens[0] == "dir":
                        currentDirectory.addChild(Directory(tokens[1], currentDirectory))
                    else:
                        currentDirectory.addChild(File(tokens[1], int(tokens[0])))
                    tokens = f.readline()[:-1].split(" ")
            else:
                raise "Unknown OP!"
        else:
            raise "Problem!"


    print(root)

    print("Size -> ", root.getSize())

    print(root)

    f.flush()
    f.close()
    return root.getSumOfSmallDirs(100000)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', action='store_true', help='Use dummy test.')
    args = parser.parse_args()
    
    inputFile = "input7.txt" if not args.d else "dummy7.txt"
    print("Result -> ", readInput(inputFile))

