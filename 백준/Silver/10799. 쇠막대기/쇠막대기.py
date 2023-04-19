lst = input()
stack = []
ans = 0

for i in range(len(lst)):

    if lst[i] == "(":
        stack.append("(")
    else:
        if lst[i-1] == "(":
            stack.pop()
            ans += len(stack)
        else:
            stack.pop()
            ans += 1

print(ans)