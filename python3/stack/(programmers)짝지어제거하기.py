def solution(s):
    answer = -1
    stack = []
    for alphabet in s:
        if len(stack)==0 or stack[-1]!=alphabet:
            stack.append(alphabet)
        else:
            stack.pop(-1)
        
    return 1 if len(stack)==0 else 0
