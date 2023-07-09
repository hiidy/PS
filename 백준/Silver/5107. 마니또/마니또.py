import sys
input= sys.stdin.readline

def dfs(v): #dfs
    global check
    visited[v]= True
    for i in graph[v]:
        if not visited[i]:
            dfs(i)
            visited[i] = True
            check += 1

case = 1 #케이스 번호

while True:
    N = int(input())
    cnt = 1 # 마니또 이름을 숫자로 바꿔서 저장할 변수
    li= dict() #사람들의 이름을 정수로 바꿔서 저장할 딕셔너리
    if N == 0: 
        break
    graph = [ [] for _ in range(N+1)]
    manitto = []
    answer = 0
    for _ in range(N):
        a, b= map(str,input().split())
        manitto.append([a,b])
        if a not in li.keys(): # { 'Andrew' :0, "Sally' : 1 } 과 같은 형식으로 저장
            li[a]= cnt
            cnt +=  1
        if b not in li.keys(): # 마찬가지
            li[b] = cnt
            cnt += 1

    for a,b in manitto: # 이름들의 value값을 받아와서 그래프로 변환한다. 
        k= li.get(a)
        t= li.get(b)
        graph[k].append(t)

    result = []
    for i in range(1,N+1): #마니또를 찾을차례
        if i in result: #만약 해당 사람이 마니또 연결고리에 이미 들어가있으면 중복 제외처리한다. 
            continue
        check = 1
        visited= [False] *(N+1) 
        dfs(i) # i번째 사람부터 dfs를 돌기 시작한다. 
        if check == visited.count(True): #dfs 돌고 마니또 연결고리를 찾으면
            for i in range(len(visited)):
                if visited[i]== True:
                    if i not in result: #해당 사람들을 result에 추가해서 중복을 제외할 수 있도록한다.
                        result.append(i)
            answer +=1 #연결고리 하나를 추가한다.
    
    print("{} {}".format(case,answer))

    case += 1