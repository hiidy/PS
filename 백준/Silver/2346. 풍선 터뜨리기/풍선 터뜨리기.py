from collections import deque

n = int(input())
lst = list(map(int, input().split()))
queue = deque(enumerate(lst))
answer = []

while queue:
    idx, num = queue.popleft()
    answer.append(idx + 1)

    if num > 0:
        queue.rotate(-(num -1))
    elif num < 0:
        queue.rotate(-num)

for i in answer:
    print(i, end=" ")