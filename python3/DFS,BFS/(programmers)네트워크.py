def DFS(x, computers, visited):
    visited[x] = 1
    for i in range(len(computers)):
        if( visited[i] == 0 and computers[x][i]==1 ):           
            DFS(i, computers, visited)
    return visited
        
def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(n)]
    for i in range(n):
        if( visited[i] == 0 ):
            answer+=1
            visited = DFS(i, computers, visited)
    return answer
