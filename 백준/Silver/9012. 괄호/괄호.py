n = int(input())

for _ in range(n):
    lst = input()
    stack = []
    for i in range(len(lst)):
        if lst[i] == "(":
            stack.append(lst[i])
        else:
            if stack:
                if stack[-1] == "(":
                    stack.pop()
            else:
                stack.append(")")

    if stack:
        print("NO")
    else:
        print("YES")