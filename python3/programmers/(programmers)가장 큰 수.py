"""
    1. 3과 30을 그냥 비교하면 30이 더 커 303이 나오므로 문제의 조건에 부합하지 않는다. 
    2. 3이 30보다 크게 될려면, 문자로 비교하되, 숫자의 범위가 1000까지이니 3번을 반복하여 비교하면 된다. 
        -> 333, 303030 중 333이 문자로 비교할 경우 더 크다. 
    3. 마지막에 int로 변경 후, str으로 바꾸는 이유는 00과 같은 값은 0으로 출력되야 하기 때문이다.
    
    !!! lambda 함수를 이용하여 쉽게 구현이 가능하다 !!!
"""
def solution(numbers):
    answer = ''
    numbers = sorted(list(map(lambda x:str(x), numbers)), key=(lambda x:x*3), reverse=True)
    answer = str(int("".join(numbers)))
    return answer
