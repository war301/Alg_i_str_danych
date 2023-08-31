# Python program to for tree traversals 

# A class that represents an individual node in a 
# Binary Tree 
class Node: 
	def __init__(self,key): 
		self.left = None
		self.right = None
		self.val = key 


def breadthFirstTrav( bintree ):
    # Create a queue and add the root node to it.
    q=[]
    q.append( bintree )
    # Visit each node in the tree.
    while q != [] :
        # Remove the next node from the queue and visit it.
        node = q.pop()
        print( node.val )
        # Add the two children to the queue.
        if node.left is not None :
            q.append( node.left )
        if node.right is not None :
            q.append( node.right )



# Driver code 
root = Node(1) 
root.left	 = Node(2) 
root.right	 = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 


breadthFirstTrav(root)

