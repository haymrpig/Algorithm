import numpy as np
from queue import PriorityQueue
def solution(maps):
    answer = 0
    
    queue = PriorityQueue()
    queue.put([1,0,0])
    maps = np.array(maps)
    distance = np.full((maps.shape[0], maps.shape[1]), 1000000000, dtype='int32')

    # x,y,depth
    while(not queue.empty()):
        dist,x,y = queue.get()
        if x==maps.shape[0]-1 and y==maps.shape[1]-1:
            return dist
        for i,j in [[1,0],[-1,0],[0,1],[0,-1]]:
            next_x=x+i
            next_y=y+j
            if( next_x>=maps.shape[0] or next_x<0 or next_y>=maps.shape[1] or next_y<0 or maps[next_x,next_y]==0):
                continue
            if distance[next_x,next_y]>dist+1 :
                distance[next_x, next_y] = dist+1
                queue.put([dist+1,next_x, next_y])
        
    return -1
