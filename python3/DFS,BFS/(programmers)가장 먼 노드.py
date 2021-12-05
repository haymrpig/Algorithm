"""
    1. deque 라이브러리를 통한 queue사용
    2. numpy를 이용해 해당 조건의 값 index찾
"""
from collections import deque
import numpy as np
def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n+1)]
    visited = [-1 for _ in range(n+1)]
    visited[1] = 0
    for node in edge:
        graph[node[0]].append(node[1])
        graph[node[1]].append(node[0])
    
    queue = deque()
    queue.append([1,0]) # 노드, depth
    while queue:
        pre_node, pre_depth = queue.popleft()
        for next_node in graph[pre_node]:
            if visited[next_node]==-1:
                queue.append([next_node, pre_depth+1])
                visited[next_node]=pre_depth+1
    visited = np.array(visited)
    answer = len(np.where(visited==visited[np.argmax(visited)])[0])
    return answer
