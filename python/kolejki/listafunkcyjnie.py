# LISTA FUNKCYJNIE

import copy
Null = None


def nullP( ls ):
    if (ls == Null):
        return(True)
    else:
        return(False)


def cons(a,b):
    return([a,b])


def car(ls):
    return(ls[0])



def cdr(ls):
    return(ls[1])



def Lenght(ls,n=0):
    if(nullP(ls)):
        return(n)
    else:
        return(Lenght(cdr(ls),n+1))



l = cons(1, cons(2, cons(3, Null)))  # (=[1,[2,[3,[]]4]])

#l = cons(1, cons(2, cons(3, cons(4, Null))))
#l = l.cons(1, l.cons( 2, l.cons(3, empty)));



def Map(f, ls):
    #print(ls)
    if (ls != Null):
        return( cons(f(car(ls)), Map(f, cdr(ls))) )
    else:
        return(Null)


def f(x):
    return(2*x)


print(car(l))  # 1
print(cdr(l))  # (=[2,[3,[4]]])
print(car(cdr(l)))  # 2
print(cdr(cdr(l)))
print(Lenght(l))
print("test map:")
print(l)
print(Map(f,l))  #*2

# kopiowanie wbudowaną funkcją
print("Copy:")
kopia  = l.copy()
print(kopia)