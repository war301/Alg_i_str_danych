import turtle
def koch(t, order, size):
    if order == 0: 
 # The basecaseisjusta straightline
        t.forward(size)
    else:
        koch(t, order-1, size/3)   
# Go 1/3 of the way
        t.left(60)
        koch(t, order-1, size/3)
        t.right(120)
        koch(t, order-1, size/3)
        t.left(60)
        koch(t, order-1, size/3)
def koch1(t, order, size):
    if order == 0: 
        t.forward(size)
    else:
        for angle in [60, -120, 60, 0]:
            koch(t, order-1, size/3)
            t.left(angle)    
    
def Main():
    t = turtle.Turtle()           
         # createthe turtle
    wn= turtle.Screen()
    koch1(t, 3, 200)
    koch(t,2,200)
    wn.exitonclick()

Main()    
