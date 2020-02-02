class Employee:

    #classvariable
    raise_amount = 1.04
    num_of_emps = 0

    def __init__(self, first, last, pay):
        self.fname = first
        self.lname = last
        self.pay = pay
        self.email = first+'.'+last+'@company.com'

        Employee.num_of_emps +=1

    def fullname(self):
        return '{} {}'.format(self.fname, self.lname)

    def apply_raise(self):
        self.pay = int(self.pay*self.raise_amount)

emp1 = Employee('Corey', 'Anderson', 50000)
emp2 = Employee('Test', 'User', 60000)

print(emp1.__dict__)
print(emp2.__dict__)
print(Employee.__dict__)

print(Employee.fullname(emp1))


print(Employee.raise_amount)
print(emp1.raise_amount)
emp1.raise_amount = 1.05
print(emp1.raise_amount)
print(emp2.raise_amount)
print(Employee.raise_amount)

print(emp1.num_of_emps)
