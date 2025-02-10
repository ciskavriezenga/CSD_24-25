
#
# start with an empty list and add elements
#
myList = []

if not myList:
  print("myList is empty")
else:
  print("myList is not empty")
  for item in myList:
    print(item)

myList.append(4)
myList.append(7)
myList.append(1)
myList.append(3)
myList.append(9)

if not myList:
  print("myList is empty")
else:
  print("myList is not empty")
  for item in myList:
    print(item)


#
# initialise list when it is created
#

myList = [42,0,105,38,2]
if not myList:
  print("myList is empty")
else:
  print("myList is not empty")
  for item in myList:
    print(item)


