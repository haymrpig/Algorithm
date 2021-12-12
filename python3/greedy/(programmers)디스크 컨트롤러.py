from queue import PriorityQueue
"""
    1. 정렬시, 요청 시간이 동일할 때, 작업시간이 적은 순으로 나열해야 한다. 
        -> 만약 예제 1번 같은 경우에 4번째 케이스, 5번째 케이스가 추가되었을 때를 생각해보자
        -> 둘의 값이 (20,10), (20,5) 라고 할 때
        -> (20,10)보다는 (20,5)를 먼저 pq에 삽입하고 25를 끝나는 시간으로 잡고 풀어야 정답이 나온다. 
"""
def solution(jobs):
    answer = 0
    jobs = sorted(jobs, key=lambda x:(x[0],x[1]))
    pq = PriorityQueue()
    cur = 0
    end = 0
    while True:
        if cur < len(jobs) and pq.empty():
            pq.put([jobs[cur][1], jobs[cur][0]])
            end = jobs[cur][0]
            cur+=1
        elif not pq.empty():
            dur, req = pq.get()
            end += dur
            answer += end-req
            while cur < len(jobs) and jobs[cur][0] <= end:
                pq.put([jobs[cur][1],jobs[cur][0]])
                cur+=1
        else:
            break
    return answer//len(jobs)
