def merge(a, b):    
    out = []
    while (len(a) > 0 and len(b) > 0):         
        if (a[0] <= b[0]):            
            out.append(a[0])            
            del a[0]        
        else:            
            out.append(b[0])            
            del b[0]
        while (len(a) > 0):
            out.append(a[0])
            del a[0]    
        while (len(b) > 0):        
            out.append(b[0])        
            del b[0]
        return out
a=[1,2,3] 
b=[4,5]
print(merge(a,b))
def half(arr):    
    mid = len(arr) / 2    
    mid=int(mid)
    return arr[:mid], arr[mid:]
def mergesort(arr):
    if (len(arr) <= 1):        
        return arr
    left, right = half(arr)    
    L = mergesort(left) 
    print(L)   
    R = mergesort(right)
    print(R) 
    return merge(L, R)
a =[6,3,2,5,4,1]
print(mergesort(a))