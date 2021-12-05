"""
    1. ord : 아스키->숫자, chr : 숫자->아스키
"""
def solution(name):
    answer = 0
    current = 0
    len_word = len(name)
    
    move = len_word-1
    for i in range(len_word):
        answer+= ord(name[i])-ord('A') if name[i]<'N' else ord('Z')-ord(name[i])+1
        index = i+1
        while(index<len_word and name[index]=='A'):
            index+=1
        move = min(move, i+len_word-index+min(i, len_word-index))
        
    answer+=move
    return answer
