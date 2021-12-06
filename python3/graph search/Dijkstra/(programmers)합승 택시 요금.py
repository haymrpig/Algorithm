"""
    1. priority queue는 empty, put, get 메소드를 제공한다.
"""
from queue import PriorityQueue

def Dijkstra(dist, start, road):
    pq = PriorityQueue()
    pq.put([start,0])
    while not pq.empty():
        pre_node, pre_weight = pq.get()
        for info in road[pre_node]:
            next_node, next_weight = info
            if dist[next_node] > pre_weight+next_weight:
                dist[next_node]=pre_weight+next_weight
                pq.put([next_node, dist[next_node]])
    return dist

def solution(n, s, a, b, fares):
    answer = 0
    
    road = [[]for _ in range(n+1)]
    for info in fares:
        road[info[0]].append([info[1], info[2]])
        road[info[1]].append([info[0], info[2]])
    
    a_dist = [100000000 for i in range(n+1)]
    a_dist[a]=0
    b_dist = [100000000 for i in range(n+1)]
    b_dist[b]=0
    s_dist = [100000000 for i in range(n+1)]
    s_dist[s]=0
    
    a_dist = Dijkstra(a_dist, a, road)
    b_dist = Dijkstra(b_dist, b, road)
    s_dist = Dijkstra(s_dist, s, road)
    
    answer = a_dist[s]+b_dist[s] if a_dist[s]+b_dist[s]!=200000000 else -1
    for i in range(1, n+1):
        answer = min(answer, a_dist[i]+b_dist[i]+s_dist[i])
    return answer
