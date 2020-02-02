import random

class Animal(object):

    def __init__(self, name):
        self.name = name

class Dog(Animal):

    def __init__(self, name):
        print 'INIT'
        super(Dog, self).__init__(name)
        self.breed = random.choice(['Hound', 'Pug', 'Labrador', 'Mastiff', 'Shepherd'])

    def fetch(self, thing):
        print '%s bring me %s !'%(self.name, thing)

print 'main'
if __name__ == "__main__":

    d = Dog('Doggo')

    d.fetch('Bazooka')
    print '+_+_+_'

    print(d.name)
    print(d.breed)
