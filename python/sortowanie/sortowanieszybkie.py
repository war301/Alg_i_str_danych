def partition(array, begin, end):
    pivot = begin
    print("before partitioning", array[begin:end+1])
    for i in range(begin+1, end+1):
        if array[i] <= array[begin]:
            pivot += 1
            array[i], array[pivot] = array[pivot],array[i]
        print("partitioning", array[begin:end+1])
        print("#################################")
    array[pivot], array[begin] = array[begin], array[pivot]
    print("after partitioning", array[begin:end+1])
    print("#################################^")
    return pivot
def _quicksort(array, begin, end):
    if begin >= end:
        return
        print("array=", array)
    pivot = partition(array, begin, end)
    print("pivot index=", pivot, "array=", array)
    _quicksort(array, begin, pivot-1)
    _quicksort(array, pivot+1, end)
#interfejs
def quicksort(array, begin=0, end=None):
    if end is None:
        end = len(array) - 1
    return _quicksort(array, begin, end)

a=[5,2,8,9,1,3]
print("before sort",a)
quicksort(a)
print("after sort",a)