class Student:
    #Private instance variables are preceded by
    #Double Underscore '__'
    #Setter
    def setName(self, name):
        self.__name = name

    #Getter
    def getName(self):
        return self.__name

    def setMarks(self, marks):
        self.__marks = marks

    def getMarks(self):
        return self.__marks


    def display(self):
        print ('Name : ', self.getName())
        print('Marks : ', self.getMarks())


ss = Student()

ss.setName('Neo')
ss.setMarks(100)
#ss.__name = 'Uno'
ss.display()
#print(ss.__name)
ss.petname = 'The One'

print ss.__dict__
