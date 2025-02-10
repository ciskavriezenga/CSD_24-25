# function that returns element from teachers list by Key 'age'
def getAge(teacher):
    return teacher['age']

# function that returns length of teacher's name
def getNameLength(teacher):
    return len(teacher['name'])

# list of dictionaries
teachers = [{'name': 'Pieter', 'age': 23},
            {'name': 'Marc(ofchain)', 'age': 4000},
            {'name': 'Jochem', 'age': 16},
            {'name': 'Roald', 'age': 17}]

print("---------------- Teachers List ----------------")
for teacher in teachers:
    print(teacher)

# sorting by age
teachers.sort(key=getAge)

print("---------------- Teachers by Age ----------------")
for teacher in teachers:
    print(teacher)

# sorting by length name - in reverse order
teachers.sort(key=getNameLength, reverse=True)


print("---------------- Teachers by Length Name ----------------")
for teacher in teachers:
    print(teacher)
