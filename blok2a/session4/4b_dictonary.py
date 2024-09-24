# Dictionaries
# also see https://docs.python.org/3/library/stdtypes.html#mapping-types-dict

# initialize
a = {'foo': 1, 'bar': 2, 'bliep': 100, 'blop': 1000}
# different 'ways' are possible,
# e.g. the next line results in the same dictionary as the above line of code
# a = dict(foo=1, bar=2, bliep=100, blop=1000)

# display the keys in the dictionary
print("\nThe keys in dictionary a are:", a.keys())
# display the values in the dictionary
print("The values in dictionary a are:", a.values())

# display the length of the dictionary
print("\nThe length of dicationary a is:", len(a))

# display the value connected to a key
print("\nretrieve the value for a key:", a.get('foo'))

# overwrite a value
print("\nThe key 'bar' in dictionary a corresponds with: ", a['bar'])
a['bar']=9999999
print("After assigning 9999999 to  key 'bar' corresponds with: ", a['bar'])


# pop a value from the dictionary
print("\nBefore popping a value, dictionary a contains: ", a)
print("popping the value 'foo':", a.pop('foo'))
print("After popping a value, dictionary a contains: ", a)

# remove a key
print("\nWe can also remove a key value pair, by using 'del a['THE_KEY']':")
del a['blop']
print("After removing the 'blop' key value pair, dictionary a contains: ", a)


# check if a key exists
print("\nWe can check if a key exists")
print("For example, when running ['bar' in a]:", 'bar' in a)
print("When running ['foo' in a']:", 'foo' in a)

# clear the dictionary
a.clear()
print("\nAfter clearing the dictionary, a contains:", a)
# add a key
a['newKey']='bar'
print("\nAfter adding 'newKey' to the dictionary, a contains:", a)

# be aware - a dictionary is passed by reference to a function!!
# e.g. a string is not, see the two functions below and their usage and resulting values

def appendBar(aString):
    # append bar to the string
    # Question: will the original string be altered?
    aString += "bar"

def addBoogusKey(aDict):
    # add bar as key and x as value to the dictionary
    # Question: will the original dictionary be altered?
    aDict['addedBoogus'] = "altered!"

print("\nWhen we pass a string to a function"
+ "the original string variable will not be altered")
foo = "foo"
appendBar(foo)
print("After calling the function appendBar with variable foo - consisting of 'foo':", foo)

print("When we pass a dictionary to a function"
+ "the original dictionary can actually  be altered")
addBoogusKey(a)
print("After calling the function addBoogusKey with dictionary a, a contains a new key", a)

print("If we do not want a function to alter the original dictionary, "
+ "we can simply call the function with a copy of the dictionary")
# create a new dictionary
b = {'test': 100}
addBoogusKey(b.copy())
print("We passed a copy of dictionary b {'test': 100} to the function addBoogusKey"
    + "the original dictionary b consists of:", b)
addBoogusKey(b)
print("We passed dictionary b {'test': 100} itself to the function addBoogusKey"
    + "the original dictionary b consists of:", b)

