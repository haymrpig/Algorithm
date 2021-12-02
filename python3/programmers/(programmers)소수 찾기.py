import numpy as np
"""
    1. //연산도 가능하지만 numpy의 sqrt도 가능하다.
    2. set은 중복 허용x, value값이 필요없다면 dictionary보단 set을 사용하자
"""
def IsPrimeNum(number):
    if( number ==0 or number==1):
        return False
    
    for i in range(2, int(np.sqrt(number))+1):
        if number%i==0:
            return False
        
    return True
    
def MakeNumber(numbers, cur, combination):
    if cur!="":
        if IsPrimeNum(int(cur)):
                combination.add(cur)
    
    for i in range(len(numbers)):
        if len(cur)==0 and numbers[i]=='0':
            continue
        MakeNumber(numbers[:i]+numbers[i+1:], cur+numbers[i], combination)
    return combination
        

def solution(numbers):
    answer = 0
    combination=set()
    MakeNumber(numbers, "", combination)  
    answer = len(combination)
    return answer
