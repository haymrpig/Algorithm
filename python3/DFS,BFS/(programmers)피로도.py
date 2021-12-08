def DFS(dungeons, life, cnt, max_num):
    if( max_num < cnt ):
        max_num = cnt
    for i in range(len(dungeons)):
        if( life >= dungeons[i][0] ):
            max_num = DFS(dungeons[0:i]+dungeons[i+1:], life-dungeons[i][1], cnt+1, max_num)
    return max_num
def solution(k, dungeons):
    answer = -1
    answer = DFS(dungeons, k, 0, 0)
    
    return answer
