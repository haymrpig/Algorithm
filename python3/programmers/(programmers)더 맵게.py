import heapq as hq
def solution(scoville, K):
    answer = 0
    hq.heapify(scoville)
    while True:
        first = hq.heappop(scoville)
        if first >= K :
            return answer
        if len(scoville) == 0 :
            return -1
        second = hq.heappop(scoville)
        hq.heappush(scoville,first+2*second)
        answer+=1
    return answer
