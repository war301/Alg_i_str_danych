def main():
    n=int(input("podaj n"))
    print(silnia(n))
    silniarek(n)
    print("n!=",factorial(n))
    print(f(n))


def silnia(n):
    if n==0 : #warunek stopu
        return 1
    else:
        return n*silnia(n-1) #rekurencyjne wywołanie funkcji
        #silnia nie może być ujemna bo będzie nieskończona 

def silniarek(n):
    fact=1
    for i in range(1,n+1):
        fact=fact*i
        print('fact=',fact) 

def tail_silnia(n,accumulator=1):
    if n==0:
        return accumulator
    else:
        return tail_silnia(n-1,accumulator*n)
def factorial(n):
    return tail_silnia(n,accumulator=1)        

def f(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return f(n-2)+f(n-1)


main()        