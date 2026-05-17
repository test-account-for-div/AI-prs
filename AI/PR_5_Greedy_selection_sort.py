# Selection Sort using Greedy Approach

arr = [64, 25, 12, 22, 11]

n = len(arr)

for i in range(n):

    # Assume current index has minimum value
    min_index = i

    # Find actual minimum element
    for j in range(i + 1, n):

        if arr[j] < arr[min_index]:
            min_index = j

    # Swap elements
    arr[i], arr[min_index] = arr[min_index], arr[i]

print("Sorted Array:")
print(arr)