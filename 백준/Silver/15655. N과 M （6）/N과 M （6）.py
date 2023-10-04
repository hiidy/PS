n, m = map(int, input().split())
array = list(map(int, input().split()))
array.sort()
result = []
visited = [False] * n

def backtracking(num, start):
    if num == m:
        print(' '.join(map(str, result)))
    for i in range(start, n):
        if not visited[i]:
            visited[i] = True
            result.append(array[i])
            backtracking(num + 1, i+1)
            visited[i] = False
            result.pop()

backtracking(0, 0)