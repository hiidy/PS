import sys
input = sys.stdin.readline
from collections import deque
m, n = map(int, input().split())

dx = [1, -1 , 0, 0]
dy = [0, 0, 1, -1]

graph = [list(map(int, input().split())) for _ in range(n)]


def bfs(graph):
    queue = deque()
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                queue.append((i, j))
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx<0 or ny<0 or nx>=n or ny>=m:
                continue
            if graph[nx][ny] == -1:
                continue
            if graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx,ny))

bfs(graph)
answer = 0
for i in range(n):
    for j in range(m):
        answer = max(answer, graph[i][j])
        if graph[i][j] == 0:
            print(-1)
            break
    if graph[i][j] == 0:
        break
else:
    print(answer-1)