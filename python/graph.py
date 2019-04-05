friend_graph = dict()
hops_to_find_friend = 0

def add_friend(name,friend):
    if friend_graph.has_key(name):
        friend_graph[name].append(friend)
    else:
        list_tmp = list()
        list_tmp.append(friend)
        friend_graph[name] = list_tmp


def degree_of_seperation(me, stranger):
    global hops_to_find_friend
    friend_list = []
    if friend_graph.has_key(me):
        friend_list = friend_graph[me]
        print str(me) + " friends: " + str(friend_list)
        if stranger in friend_list:
            print "FOUND " + str(stranger)
            print "degree_of_seperation: " + str(hops_to_find_friend)
            exit(hops_to_find_friend)
        else:
            hops_to_find_friend += 1
            for connection in friend_list:
                degree_of_seperation(connection, stranger)
    return -1

add_friend("adam","bryan")
add_friend("adam","zig")
add_friend("adam","don")

add_friend("bryan","carl")
add_friend("bryan","clark")
add_friend("bryan","duster")
add_friend("bryan","zig")

add_friend("don","dale")

add_friend("dale","drake")
add_friend("drake","eddie")

print friend_graph
print "degree of sepreration: " + str(degree_of_seperation("adam","dale"))