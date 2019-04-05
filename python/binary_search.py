def binary_search(list, item):
    low = 0
    high = len(list)-1
    iteration = 0

    while low <= high:
        mid = (low+high)/2
        if list[mid] == item:
            print str(mid+1) + " found in " + str(mid+1) + "th position"
            break
        if list[mid] > item:
            high = mid-1
        else:
            low = mid+1
        iteration+=1

    print str(iteration) + " iterations"
    return None

test_list=[1,2,3,4,5,7,8,9]

print binary_search(test_list,4)
print binary_search(test_list,1)
print binary_search(test_list,9)
print binary_search(test_list,6)