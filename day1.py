def sort012(arr):
    left = 0
    i = 0
    right = len(arr) - 1

    while i <= right:
        if arr[i] == 0:
            temp = arr[left]
            arr[left] = arr[i]
            arr[i] = temp
            left += 1
            i += 1
        elif arr[i] == 1:
            i += 1
        else:
            temp = arr[right]
            arr[right] = arr[i]
            arr[i] = temp
            right -= 1

arr1 = [0,1,2,1,0,2,1,0]
sort012(arr1)
print(arr1)

arr2 = [2,2,2,2]
sort012(arr2)
print(arr2)

arr3 = [0,0,0,0]
sort012(arr3)
print(arr3)

arr4 = [1,1,1,1]
sort012(arr4)
print(arr4)

arr5 = [2,0,1]
sort012(arr5)
print(arr5)

arr6 = []
sort012(arr6)
print(arr6)
