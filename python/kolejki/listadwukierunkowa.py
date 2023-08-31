class Node:
    def __init__( self, data ) :
        self.item = data
        self.nref = None
        self.pref=None
        
class doublelinkedlist:
    def __init__(self):
        self.start_node=None        
        self.tail = None
        #self.forward = True

    #def setForward(self):
    #    self.forward = True

    #def setBackward(self):
    #    self.forward = False

    #def __iter__(self):
    #    if self.forward:
    #        self.cur = self.head
    #    else:
    #        self.cur = self.tail
    #    return self

    #def __next__(self):
    #    result = self.cur
    #    if self.forward:
    #        if self.cur.next is None:
    #            raise StopIteration
    #        self.cur = self.cur.next
    #    else:
    #        if self.cur.prev is None:
    #            raise StopIteration
    #        self.cur = self.cur.prev
    #    return result

    def insert_at_end(self, data):
        if self.start_node is None:
            new_node = Node(data)
            self.start_node = new_node
            return
        while self.start_node.nref is not None:
            self.start_node.nref
        new_node = Node(data)
        new_node.pref = self.start_node
        self.start_node.nref = new_node


    def dodajElementpocz(self,element):
        new_node=Node(element)
        if self.start_node is None:
            self.start_node=new_node
        else:
            new_node.nref=self.start_node
            self.start_node=new_node

    def delete_at_end(self):
        if self.start_node is None:
            print("Nie ma elementów do usunięcia")
            return 
        if self.start_node.nref is None:
            self.start_node = None
            return
        n = self.start_node
        while n.nref is not None:
            n = n.nref
        n.pref.nref = None
    
    def usunPoczatek(self): 
        if self.start_node is None:
            print("Nie ma co usuwać")
            return 
        if self.start_node.nref is None:
            self.start_node=None
            return
        self.start_node=self.start_node.nref
        self.start_prev=None 

    def wypisz(self):
        current=self.start_node
        if self.start_node == None:
            print("lista jest pusta")
            return
        while current is not None:
            print(current.item)
            current=current.nref             


new_linked_list=doublelinkedlist()
new_linked_list.dodajElementpocz(5)
new_linked_list.dodajElementpocz(15)
new_linked_list.dodajElementpocz(25)
new_linked_list.wypisz()
#new_linked_list.insert_at_end(3)
#new_linked_list.usunPoczatek()
#new_linked_list.wypisz()        

#list2=DoublyLinkedList()
#list2.insert_at_end(1)
#list2.insert_at_end(2)
#list2.wypisz()
#list2.delete_at_end()
#print(" ")
#list2.wypisz()
    