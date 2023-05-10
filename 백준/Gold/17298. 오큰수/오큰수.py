n = int(input())
array = list(map(int, input().split()))
stack = []
answer = []

for i in range(n-1, -1, -1):
    while stack:
        if array[i] < stack[-1]:
            answer.append(stack[-1])
            break
        else:
            stack.pop()
    if not stack:
        answer.append(-1)
    stack.append(array[i])
    
for s in answer[::-1]:
    print(s, end=" ")