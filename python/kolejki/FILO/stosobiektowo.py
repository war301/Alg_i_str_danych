class filoqueue:
    def __init__(self):
        self.stack=[]

    def add(self,name):
        self.stack.append(name)
    
    def usun(self):
        self.stack.pop()


    def show(self):
        for name in self.stack:
            print("waiting customer: {}".format(name)) 

    def length(self):
        return len(self.stack)        
     
q1 = filoqueue(); q2 = filoqueue()
q1.add('Spearing'); q1.add('Fangohr'); q1.add('Takeda')
q2.add('John'); q2.add('Peter')
print("{} customers in queue1:".format(q1.length())); q1.show() 
q1.usun()
print("{} customers in queue1:".format(q1.length())); q1.show() 
