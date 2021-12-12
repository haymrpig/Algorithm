"""
    1. two pointer를 이용하여 모든 보석을 포함하는 최단 길이를 찾았다. 
    2. dictionary에서 원하는 key를 지우기 위한 del dic[key] 문법
    3. dic.keys() 메소드를 통해 dictionary의 key들을 다 확인할 수 있다. 
"""
def solution(gems):
    answer = [1,len(gems)]
    dic = {}
    for jewerly in gems:
        dic[jewerly]=0
    count = {}
    end = 0
    cnt = 0
    min_length = len(gems)
    for start in range(len(gems)):
        while( end < len(gems) and cnt != len(dic)):
            if gems[end] not in count.keys():
                cnt+=1
                count[gems[end]]=1
            else:
                count[gems[end]]+=1
            end+=1

        if cnt == len(dic) and min_length > end - start:
            answer[0]=start+1
            answer[1]=end
            min_length = end-start
        
        if count[gems[start]] <= 1:
            del count[gems[start]]
            cnt-=1
        else:
            count[gems[start]]-=1
            
    return answer
