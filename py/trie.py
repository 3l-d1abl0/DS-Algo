class Node:
    def __init__(self):
        self.children = [None] *26
        self.isLeaf = False

    def isLeafNode(self):
        return self.isLeaf is True

    def ifFreeNode(self):
        for i in self.children:
            if i:
                return False
        return True

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, key):
        #print ('insert -> {}').format(key)
        size = len(key)
        crntNode = self.root
        #print crntNode.children
        for lvl in range(size):
            idx = ord(key[lvl])- ord('a')
            #print('{} : {}').format(key[lvl], ord(key[lvl]))
            if not crntNode.children[idx]:
                crntNode.children[idx] = Node()
                #print ('{}').format(key[lvl])
            crntNode = crntNode.children[idx]

        crntNode.isLeaf = True
        #print ('{}').format(crntNode.isLeaf)

    def del_word(self, root, keys, idx):
        if root :
            if idx == len(keys):
                #print ('{} ===> {}').format(keys[idx-1], idx-1)
                if root.isLeafNode() is False:
                    #print ('{}').format(root.isLeafNode())
                    return False
                root.isLeaf = False
                return root.ifFreeNode()
            else:
                #print ('{}--- {}').format(keys[idx], idx)
                index = ord(keys[idx])-ord('a')
                if not root.children[index]:
                    return False
                else:
                    toDel = self.del_word(root.children[index], keys, idx+1)
                    if toDel:
                        #del root.children[index]
                        root.children[index] = None
                        return root.ifFreeNode()
                    return False

    def deleteWord(self, keys):
        size = len(keys)
        if size > 0:
            self.del_word(self.root,keys,0)

    def search(self, key):
        size = len(key)
        crntNode = self.root
        for lvl in range(size):
            idx = ord(key[lvl])-ord('a')
            if not crntNode.children[idx]:
                return False
            crntNode = crntNode.children[idx]
        #print crntNode
        return crntNode != None and crntNode.isLeaf is True

    def traverseRest(self, root, prefix):
        #print('current {}').format(prefix)
        if root != None and root.isLeaf is True:
            print prefix
        #for child in root.children:
        for i in range(26):
            if root.children[i]:
                #print('i= {} :: {} + {}').format(i,prefix,chr(i+97))
                self.traverseRest(root.children[i], prefix+chr(i+97))
            #print('i :: {}').format(i)


    def prefix_search(self, prefix):
        #go till the word hits end and check the children
        crntNode = self.root
        for ch in prefix:
            idx = ord(ch) - ord('a')
            if not crntNode.children[idx]:
                return False
            crntNode = crntNode.children[idx]
        self.traverseRest(crntNode, prefix)





if __name__ == '__main__':

    #keys = ["the","a","there","anaswe","any","by","their"]
    keys = ["chandan",  "mittal", "chirag", "shashank","abhinav", "arun", "abhishek", "abhisaar"]
    output = ["Not present in trie","Present in tire"]

    #trie Object
    t= Trie()

    for key in keys:
        t.insert(key)

    print("{} --- {}").format("abhishek", output[t.search("abhishek")])
    print("{} --- {}").format(keys[3], output[t.search(keys[3])])
    print("{} --- {}").format("matty", output[t.search("matty")])
    print("{} --- {}").format(keys[5], output[t.search(keys[5])])

    #print("{} --- {}").format("the", output[t.search("the")])
    #print("{} --- {}").format("these", output[t.search("these")])
    #print("{} --- {}").format("their", output[t.search("their")])
    #print("{} --- {}").format("thaw", output[t.search("thaw")])


    print('Deleting ...  {}').format(keys[5])
    t.deleteWord(keys[5])
    print("{} --- {}").format(keys[5], output[t.search(keys[5])])

    #Prefix Search
    t.prefix_search("abhi")
    t.prefix_search("aru")
