if __name__ == '__main__':

    input_file = "shopx-in.txt"

    #with open(input_file) as file:
    #line = file.readline()
    line = input()

    t = int(line)

    while(t):
        #q = int(file.readline())
        q = int(input())
        t-=1
        wordMap = {}; maxFreq=0; maxFeqList =[]

        while(q):
            q-=1
            #line = file.readline().strip()
            line = input().strip()

            if line !="top":
                word,qty = line.split(" ")
                qty = int(qty)

                if word in wordMap:
                    wordMap[word] += qty
                else:
                    wordMap[word] = qty

                if wordMap[word] == maxFreq:
                    maxFeqList.append(word)
                elif wordMap[word] > maxFreq:
                    maxFeqList = [word]
                    maxFreq = wordMap[word]

            else:#"top"
                maxFeqList.sort()
                print(' '.join(maxFeqList))
