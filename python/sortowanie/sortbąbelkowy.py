def bubbleSort( theSeq ):
    n = len( theSeq )
    for i in range( n - 1 ):
        for j in range( i,  n - 1 ) :
            if theSeq[j] > theSeq[j + 1] :
                tmp = theSeq[j]
                theSeq[j] = theSeq[j + 1]
                theSeq[j + 1] = tmp
a = [2,3,5,8,7]
print("before sorting ", a)
bubbleSort(a)
print("after sorting ", a)