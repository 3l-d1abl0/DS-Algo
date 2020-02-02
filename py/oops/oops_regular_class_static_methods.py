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

    @classmethod
    def set_raise_amt(cls, amount):
        cls.raise_amount = amount

emp1 = Employee('Corey', 'Anderson', 50000)
emp2 = Employee('Test', 'User', 60000)

'''
Employee.set_raise_amt(1.07)

print(Employee.raise_amount)
print(emp1.raise_amount)
print(emp2.raise_amount)

#But But
emp1.set_raise_amt(1.09)

print(Employee.raise_amount)
print(emp1.raise_amount)
print(emp2.raise_amount)
'''

#classMethods - alternative constructors

emp_str_1 = 'John-Doe-10000'
emp_str_2 = 'Tim-Locus-30000'
emp_str_3 = 'Joe-Chill-50000'

first, last, pay = emp_str_1.split('-')
new_emp_1 = Employee(first, last, pay)

print(new_emp_1.email)
print(new_emp_1.pay)
