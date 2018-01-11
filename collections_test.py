from collections import namedtuple,deque
Point = namedtuple('Point',['x','y'])
p = Point(1,2)
q = deque(['a','b','c'])
#insert at the end of queue
q.append('x')
#insert at the tail of the queue
q.appendleft('y')
print(list(q))