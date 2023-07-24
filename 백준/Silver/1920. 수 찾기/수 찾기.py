import sys
input = sys.stdin.readline

def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end)//2
        if array[mid] == target:
            return 1
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return 0

n = int(input())
array = list(map(int, input().split()))
m = int(input())
target = list(map(int, input().split()))

array.sort()
for i in target:
    print(binary_search(array, i, 0, len(array)-1 ))