queue = []

def length():
    """Returns number of waiting customers"""
    return len(queue)
def show():
    """print list of customers, longest waiting customer at end."""
    for name in queue:
        print("waiting customer: {}".format(name))
def add(name):
    """Customer with name 'name' joining the queue"""
    queue.insert(0, name)

def next():
    """Returns name of next to serve, removes customer from queue"""
    return queue.pop()


add('Spearing'); add('Fangohr'); add('Takeda')
show(); next()
