def length(queue):
    return len(queue)

def show(queue):
    for name in queue:
        print("waiting customer: {}".format(name))

def add(queue, name):
    queue.insert(0, name)

def next(queue):
    return queue.pop()


q1 = []
q2 = []
add(q1, 'Spearing'); add(q1, 'Fangohr'); add(q1, 'Takeda')
add(q2, 'John'); add(q2, 'Peter')
print("{} customers in queue1:".format(length(q1))); show(q1)
print("{} customers in queue2:".format(length(q2))); show(q2)
