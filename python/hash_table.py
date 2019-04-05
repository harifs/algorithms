
my_dict = dict()

def lookup(key):
    if my_dict.has_key(key):
        return my_dict[key]
    return None

def add(key,value):
    if lookup(key):
        print str(key) + " already exists: " + str(my_dict[key])
    else:
        my_dict[key] = value
        print str(key) + " -> " + str(my_dict[key]) + " added"


add("a","A")
add("b","B")
add("c","C")
add("d","D")

print "Looking up " + str(lookup("c"))
add("a","X")
add("x","X")
print "Looking up " + str(lookup("x"))

