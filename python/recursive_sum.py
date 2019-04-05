def recrusive_sum(list_nums):

    ### Error Handling 1: arguemnt is not an array
    if not isinstance(list_nums, list):
        print str(list_nums) + " is not an array"
        if isinstance(list_nums,int):
            return list_nums
        return None

    print "list:" + str(list_nums)
    length = len(list_nums)

    ### Error Handling 2: Empty Array Scenario
    if length < 1:
        print str(list_nums) + " is empty array"
        return None
    ### Base condition
    elif length == 1:
        return list_nums[length - 1]
    else:
        ### Intialize sum variable
        try:
            sum
        except NameError:
            sum = list_nums[length - 1]

        del list_nums[length - 1]
        ### recurision
        return sum + recrusive_sum(list_nums)

print recrusive_sum([1,2,5,4])
print recrusive_sum([])
print recrusive_sum(1)