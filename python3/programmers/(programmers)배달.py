"""
    1. numpy를 이용해서 특정 조건에 부합하는 값들을 찾을 수 있다. 
"""
from collections import deque
import numpy as np
def solution(N, road, K):
    answer = 0
    graph = [ list() for i in range(51) ] 
    for x,y,w in road:
        graph[x].append([y,w])
        graph[y].append([x,w])
        
    distance = np.full(51, 1000000000)
    distance[1]=0
    queue = deque()
    
    queue.append([0,1]) # weight, start
    while queue:
        dist, start = queue.popleft()
        for i in range(len(graph[start])):
            if( graph[start][i][1]+dist <= K and distance[graph[start][i][0]] > graph[start][i][1]+dist ):
                distance[graph[start][i][0]] = graph[start][i][1]+dist
                queue.append([distance[graph[start][i][0]], graph[start][i][0]])
    print(distance)
    return len( distance[np.where(distance<1000000000)])
