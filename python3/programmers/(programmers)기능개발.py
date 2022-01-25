def solution(progresses : list, speeds : list)-> list:
    """[summary]
        
    Args:
        progresses (list): progress of each work
        speeds (list): speed of each work
        
    Returns:
        list: number of work published at once
    """
    answer = []
    end_day = [-((progresses[i]-100)//speeds[i]) for i in range(len(progresses))]
    
    limit = end_day[0]
    cnt = 1
    for i in range(1, len(end_day)):
        if limit >= end_day[i]:
            cnt += 1
        else:
            answer.append(cnt)
            limit = end_day[i]
            cnt = 1
    answer.append(cnt)
    return answer
