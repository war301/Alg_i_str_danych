def applyRules(ch):
    newstr= ""
    if ch== 'F':
        newstr= 'F-F++F-F'   # Rule1
    else:
        newstr= ch# no rulesapplysokeepthe character
    return newstr
def processString(oldStr):
    newstr= ""
    for ch in oldStr:
        newstr= newstr+ applyRules(ch)
    return newstr
def createLSystem(numIters,axiom):
    startString= axiom
    endString= ""
    for i in range(numIters):
        endString= processString(startString)
        startString= endString
    return endString
print(createLSystem(3, "F"))    