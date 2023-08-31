def fib1(n):
    fib1=[n+2]
    fib1.append(0)
    fib1.append(1)
    for i in range(n-1):
        fib1[i]=fib1[i-1]+fib1[i-2]
        print(fib1[i]," ",fib1[i-1]," ",fib1[i-2])
        fib1.append(fib1[i])
    return fib1[n+1]    
def Main():
    print(fib1(7))
Main()