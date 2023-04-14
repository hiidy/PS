from collections import deque
import sys

input = sys.stdin.readline

n = int(input())
queue = deque()

for _ in range(n):
    order = sys.stdin.readline().rstrip()

    if order[0:4] == 'push':
        queue.append(order[5:])
    elif order == 'pop':
        if queue:
            print(queue.popleft())
        else:
            print(-1)
    elif order == 'size':
        print(len(queue))
    elif order == 'empty':
        if queue:
            print(0)
        else:
            print(1)
    elif order == 'front':
        if queue:
            print(queue[0])
        else:
            print(-1)
    elif order == 'back':
        if queue:
            print(queue[-1])
        else:
            print(-1)
