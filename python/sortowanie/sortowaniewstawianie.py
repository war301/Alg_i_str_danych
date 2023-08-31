def insertionSort( theSeq ):
    n = len( theSeq )
    for i in range( 1, n ) :
        value = theSeq[i]
        pos = i
        while pos > 0 and value < theSeq[pos - 1] :
            theSeq[pos] = theSeq[pos - 1]
            pos -= 1
        theSeq[pos] = value

a=[5,3,4,8,4,7]
print("before sort ", a)
insertionSort(a)
print("after sort ", a)
