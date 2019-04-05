def selection_sort(list):
    length_of_list = len(list)
    if length_of_list == 0:
        return None
    for i in range(0,length_of_list):
        smallest_index=i
        for j in range(i+1,length_of_list):
            if (list[j]<list[smallest_index]):
                temp = list[j];
                list[j]=list[smallest_index]
                list[smallest_index]=temp

my_list=[9,5,2,7,6,1,5,4]
selection_sort(my_list)
print my_list
