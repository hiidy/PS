n = input()
tmp = ""
ans = ""

for i in n:
    if i == " ":
        if "<" in tmp:
            tmp += i
        else:
            ans += tmp[::-1]
            tmp = ""
            ans += " "
    elif i == "<":
        ans += tmp[::-1]
        tmp = ""
        tmp += i
    elif i == ">":
        tmp += i
        ans += tmp
        tmp = ""
    else:
        tmp += i

ans += tmp[::-1]

print(ans)