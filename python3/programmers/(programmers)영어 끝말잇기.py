"""
    1. slicing을 이용하여 반복되는 단어를 쉽게 찾을 수 있다.
"""
def solution(n, words):
    answer = [0,0]
    for i in range(1, len(words)):
        if words[i-1][-1]!=words[i][0] or words[i] in words[:i]:
            return [i%n+1, i//n+1]
    return answer
