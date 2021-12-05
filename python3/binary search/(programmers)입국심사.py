"""
    1. 값이 큰 경우 이진탐색 고려하기
    2. numpy를 이용해서 vector와 상수와의 연산을 빠르게 진행할 수 있다. 
"""
import numpy as np
def BinarySearch(times, start, end, target):
    answer = 0
    while(start <= end):
        mid = (start+end)//2
        num_check = np.sum(mid//times)
        if num_check < target:
            start = mid+1
        else:
            end = mid-1
            answer = mid
    return answer

def solution(n, times):
    answer = 0
    times = np.array(times)
    answer = BinarySearch(times, 0, 10**18, n)
    return answer
