n = int(input())
tower = []
stack = []
answer = 0

for _ in range(n):
    tower.append(int(input()))

for i in range(n-1, -1, -1):
    while stack:
        if tower[i] > stack[-1][-1]:
            stack.pop()
            if not stack:
                answer += n - i - 1
                break
        else:
            answer += stack[-1][0] - i - 1
            break
    stack.append((i,tower[i]))


print(answer)