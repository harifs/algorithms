# anagram of this
# is si
# his hsi - ihs shi - ish sih
# this htis hits hist thsi htsi hsti hsit -

### return dict
def anagram(word,char):
    i=0
    retDict=[]
    while(i<len(word)):
        #insertAt(word,char,i)
        retDict.append(word[:i]+char+word[i:])
        i+=1
        #print retDict
    return retDict

## test anagram()
#print anagram("his",'t')

def getAnagram(word):
    if(len(word)<3):
        return word
    i=2
    anagram_array=[]
    resultArray=[]

    j=0
    while j<=(len(word)-2):
        anagram_array.append(word[j:j+2])
        anagram_array.append(word[j:j+2][::-1])
        j+=1

    print "started array:" + str(anagram_array)
    while i<len(word):
        for each in anagram_array:
            resultArray.extend(anagram(each,word[i]))
        i+=1
        #print anagram_array
    return resultArray

## test getAnagram()
#print getAnagram("this")


if __name__ == '__main__':
    print getAnagram("his")