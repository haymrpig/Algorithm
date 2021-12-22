"""
    1. list를 queue처럼 이용할 수 있다.
    2. any()를 이용하면 조건에 해당하는 값이 하나라도 있는 경우 True가 된다. 
"""
def solution(priorities, location):
    answer = 0
    queue = [(index,priority) for index, priority in enumerate(priorities)]
    
    while True:
        if len(queue)==0:
            break
            
        pre = queue.pop(0)
        if any(pre[1] < p[1] for p in queue):
            queue.append(pre)
        else:
            answer+=1
            if pre[0]==location:
                return answer
    return answer
