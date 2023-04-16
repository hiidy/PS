n = int(input())
postifx = input()
num_list = []
stack = []


for _ in range(n):
    num_list.append(int(input()))

for i in postifx:
    if i.isalpha():
        stack.append(num_list[ord(i)-65])
    else:
        b = stack.pop()
        a = stack.pop()
        if i == "+":
            result = a + b
        elif i == "-":
            result = a - b
        elif i == "*":
            result = a * b
        elif i == "/":
            result = a / b
        stack.append(result)

print(f'{stack[-1]:.2f}')