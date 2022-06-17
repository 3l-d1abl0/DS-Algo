class Stack:
    
    def __init__(self):
        self.__storage =[]


    def __len__(self):
        return len(self.__storage)

    def push(self, item):
        self.__storage.append(item)

    def pop(self):
        if len(self.__storage) == 0:
            return None
            
        return self.__storage.pop()