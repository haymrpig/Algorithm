import numpy as np
from collections import deque
"""
    1. 정방행렬 관련 문제는 numpy를 이용하여 쉽게 해결할 수 있다. 
    2. 이 문제같은 경우 모서리를 탐색해야 하기 때문에 배열을 2배 키워줘야 겹치는 모서리가 발생하지 않는다. 
"""
def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    characterX*=2
    characterY*=2
    itemX*=2
    itemY*=2
    
    N=51*2
    ground = np.zeros((N,N))
    for i in rectangle:
        ground[2*i[0]:2*i[2]+1, 2*i[1]:2*i[3]+1] = 1
    for i in rectangle:
        ground[2*i[0]+1:2*i[2], 2*i[1]+1:2*i[3]] = 0
    q = deque()
    q.append([characterX, characterY])
    ground[characterX,characterY]=0
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    
    while len(q) != 0:
        px, py = q.popleft()
        if px == itemX and py==itemY:
            answer = ground[px][py]//2
            break
        for x, y in zip(dx, dy):
            nx = px+x
            ny = py+y
            if nx>=0 and ny>=0 and nx<N and ny<N and ground[nx,ny]==1:            
                q.append([nx,ny])
                ground[nx,ny]=ground[px,py]+1
            
    return answer
