def kopiec(arr, n, i):
    largest = i  
    l = 2 * i + 1     
    r = 2 * i + 2         
    if l < n and arr[largest] < arr[l]:
        largest = l   
    if r < n and arr[largest] < arr[r]:
        largest = r   
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]         
        kopiec(arr, n, largest)
  
def heapSort(arr):
    n = len(arr)   
    for i in range(n//2 - 1, -1, -1):
        kopiec(arr, n, i)   
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  
        kopiec(arr, i, 0)

a=[2,5,7,3,4,0]
heapSort(a)
print(a)        