n, m = map(int, input().split())
array = list(map(int, input().split()))
array.sort()
result = []


def backtracking(num):
    if num == m:
        return print(' '.join(map(str, result)))
    for i in range(n):
        result.append(array[i])
        backtracking(num + 1)
        result.pop()

backtracking(0)