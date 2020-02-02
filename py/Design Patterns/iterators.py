list = [1,2,3]
for i in list:
    print(i)


iter = list.__iter__()
print iter.next()
print iter.next()

print iter
print iter
print iter.next()
print iter

print iter.next()

numbers = [1,2,3,4,5]
numbers_again = [n for n in numbers]
print numbers_again


even_numbers = [n for n in numbers if n%2 == 0]
print even_numbers

odd_squares = [n**2 for n in numbers if n%2 ==1]
print odd_squares

matrix = [ [1,2,3], [4,5,6], [7,8,9] ]
flat = [n for row in matrix for n in row]
print flat
