import sys

input = sys.stdin.readline
n = int(input())


for _ in range(n):
    left = []
    right = []
    lst = input().rstrip()
    for i in lst:
        if i == "-" and left:
            left.pop()
        elif i == "<" and left:
            right.append(left.pop())
        elif i == ">" and right:
            left.append(right.pop())
        elif i.isdigit() or i.isalpha():
            left.append(i)
    right = right[::-1]
    left.extend(right)
    print(''.join(left))
