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

class Developer(Employee, object):
    raise_amount = 1.20

    def __init__(self, first, last, pay, prog_lang):
        super(Developer, self).__init__(first, last, pay)
        #Employee.__init__(self, first, last, pay)
        self.prog_lang = prog_lang
        print('My Prog Lang '+self.prog_lang)


class Manager(Employee, object):

    def __init__(self, first, last, pay, emp = None):
        super(Manager, self).__init__(first, last, pay)
        if emp is None:
            self.employees = []
        else:
            self.employees = emp

    def add_emp(self, emp):
        if emp not in self.employees:
            self.employees.append(emp)

    def remove_emp(self,emp):
        if emp in self.employees:
            employees.remove(emp)

    def print_emp(self):

        if len(self.employees) is 0:
            print 'Manges no employee'
        else:
            for emp in self.employees:
                print emp.fullname()



if __name__ == "__main__":

    # emp1 = Employee('Corey', 'Anderson', 50000)
    # emp2 = Employee('Test', 'User', 60000)

    # print(emp1.__dict__)
    # print(emp2.__dict__)
    # print(Employee.__dict__)
    #print(Employee.fullname(emp1))



    dev1 = Developer('Corey', 'Anderson', 50000, 'JS')
    dev2 = Developer('Test', 'User', 60000, 'Python')

    # print(dev1.fullname())
    # print(dev2.fullname())
    #
    # print(dev2.prog_lang)
    #
    #
    print(help(Developer))
    # print(dev2.pay)
    # dev2.apply_raise()
    # print(dev2.pay)

    man1 = Manager('Mana','ger', 12990)

    man1.print_emp()

    man1.add_emp(dev2)

    man1.print_emp()


    print (isinstance(man1, Developer))

    print(issubclass(Developer, Employee))
