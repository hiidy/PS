from collections import deque


n, k = map(int, input().split())
queue = deque([i for i in range(1, n+1)])
cnt = 0
lst = []


while queue:
    cnt += 1
    if cnt % k == 0:
        lst.append(str(queue.popleft()))
    else:
        queue.append(queue.popleft())

print("<" + ", ".join(lst) + ">")