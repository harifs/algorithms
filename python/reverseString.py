class Reverse:
    classStr = ""
    def __init__(self,str):
        if str:
            self.classStr = str
            print "initialized with String: " + str

    def getReverse(self):
        return self.classStr[::-1]

if __name__ == '__main__':
    myStr = Reverse("abcdefg")
    print myStr.getReverse()
