import re
from itertools import permutations
"""
1. deep copy를 하려면 인덱스로 복사해야 한다. 
2. list는 +연산을 통해 이어붙일 수 있다. 
"""
def solution(expression):
    answer = 0
    order = [x for x in ['*','+','-'] if x in expression]
    orders = [list(x) for x in permutations(order)]
    line = re.split('(\D)', expression)
    
    for order in orders:
        line_ = line[:]
        for op in order:
            while op in line_:
                index = line_.index(op)
                line_[index-1]=str(eval(line_[index-1]+line_[index]+line_[index+1]))
                line_ = line_[:index]+line_[index+2:]
        
        answer = max(answer, abs(int(line_[0])))
        
    return answer
