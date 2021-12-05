"""
    1. list를 stack처럼 사용 -> append, pop()
"""
def Check(s):
    check = {'{':'}', '[':']','(':')'}
    temp = []
    for i in range(len(s)):
        if not temp:
            temp.append(s[i])
        elif temp[-1] in ['}', ']', ')']:
            return False
        elif check[temp[-1]]==s[i]:
            temp.pop()
        else:
            temp.append(s[i])
    if not temp:
        return True
    else:
        return False

def solution(s):
    answer = 0
    
    for i in range(len(s)-1):
        if Check(s):
            answer+=1
        s = s[1:]+s[0]
    
    return answer
