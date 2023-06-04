from collections import defaultdict



def solve(idx, left, right):
    if idx == N: 
        weightDict[abs(left - right)] = True
        return

    if dp[abs(left - right)][idx] == 1:  
        return

    weightDict[abs(left - right)] = True  
    dp[abs(left - right)][idx] = 1

    solve(idx + 1, left + weight[idx], right) 
    solve(idx + 1, left, right + weight[idx])  
    solve(idx + 1, left, right) 


if __name__ == '__main__':
    N = int(input())
    dp = [[0 for _ in range(N+1)] for _ in range(15001)]
    weight = list(map(int, input().split()))
    M = int(input())
    case = list(map(int, input().split()))

    weightDict = defaultdict(bool)
    solve(0, 0, 0)

    for c in case:
        if weightDict[c]:
            print('Y', end=' ')
        else:
            print('N', end=' ')