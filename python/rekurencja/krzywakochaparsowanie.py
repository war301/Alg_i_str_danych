import turtle
def createLSystem(numIters,axiom):
    startString= axiom
    endString= ""
    for i in range(numIters):
        endString= processString(startString)
        startString= endString
    return endString
def processString(oldStr):
    newstr= ""
    for ch in oldStr:
        newstr= newstr+ applyRules(ch)
    return newstr
def applyRules(ch):
    newstr= ""
    if ch== 'F':
        newstr= 'F-F++F-F'   # Rule1●else:
        newstr= ch# no rulesapplysokeepthe character
    return newstr
def drawLsystem(aTurtle, instructions, angle, distance):
    for cmd in instructions:
        if cmd== 'F':
            aTurtle.forward(distance)
        elif cmd== 'B':
            aTurtle.backward(distance)
        elif cmd== '+':
            aTurtle.right(angle)
        elif cmd== '-':
            aTurtle.left(angle)
def main():
    inst= createLSystem(4, "F")   # createthe string
    print(inst)
    t = turtle.Turtle()            # createthe turtle
    wn= turtle.Screen()
    t.up()
    t.back(200)
    t.down()
    t.speed(9)
    drawLsystem(t, inst, 60, 5)   # drawthe picture
    # angle60, segment length5
    wn.exitonclick()    