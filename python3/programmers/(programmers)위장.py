"""
    1. collections의 Counter 메소드는 딕셔너리 형식으로 해당 key가 몇 번 들어가는지 셀 수 있다. 
    2. functools의 reduce 메소드는 집계, 누적에 많이 쓰이면, 첫번째 인자로 함수, 두번째 인자는 누적자, 세번째 인자는 초기값이다. 
"""
from collections import Counter
from functools import reduce
def solution(clothes):
    answer = 1
     
    cnt = Counter([kind for name, kind in clothes])
        
    return reduce(lambda x,y: x*(y+1), cnt.values(), 1)-1
