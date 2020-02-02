from singleton_borg import Singleton, Borg



x= Singleton()
x.val ='ssss'
print(x.val)


y= Singleton()
y.val = 'xxx'
print(y.val)


print x
print y

print x == y


a = Borg()
c = Borg()

print a ==c

a.val = 'Borg'

print a.val
print c.val
