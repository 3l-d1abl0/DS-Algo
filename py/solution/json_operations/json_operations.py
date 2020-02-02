import json
from pprint import pprint

#read the height File Data
with open('name_dob_height.json','r') as f:
    height_data = json.load(f)

#Read the salary File Data
with open('name_dob_salary.json','r') as f:
    salary_data = json.load(f)

#Add salary from Salary Data
for idx in range(len(height_data)):
    height_data[idx]["Salary"] = salary_data[idx]["Salary"]
#SOrt via Dob(ascending), Salary(Descending), Height(ascending)
height_data = sorted(height_data, key = lambda i: (i['Date_of_birth'], i['Salary'], i['Height']))

'''
pprint(heigh_data)
with open('output.txt', 'w') as op_file:
    json.dump(height_data, op_file, indent=4, sort_keys=True)
'''
with open('output.csv', 'w') as op_file:
    op_file.write('FirstName, LastName, Dob, Salary, Height')
    op_file.write('\n')
    for idx in range(len(height_data)):
        ls = '{}, {}, {}, {}, {}'.format(height_data[idx]["First_name"], height_data[idx]["Last_name"], height_data[idx]["Date_of_birth"], height_data[idx]["Salary"], height_data[idx]["Height"])
        op_file.write(ls)
        op_file.write('\n')
