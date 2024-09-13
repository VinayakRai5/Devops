def binary_search(arr, target):
    i = 0
    j = len(arr) - 1
    while i<=j:
        mid = i + (j - i) // 2
        if target == arr[mid]:
            return mid
        elif target > arr[mid]:
            i = mid + 1
        else:
            j = mid - 1
    return -1
    
arr = [1,2,3,4,5,6,7,8,9]
target = 1
k=''
for i in range(0,len(arr)):
    if target%10 == 1:
        k = 'st'
    elif target%10 == 2:
        k = 'nd'
    elif target%10 == 3:
        k = 'rd'
    else:
        k = 'th'

print("Element is present at {}{} index".format(binary_search(arr, target)+1, k))