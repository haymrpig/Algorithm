def solution(record):
    answer = []
    namespace = {}
    
    for r in record:
        rr = r.split(' ')
        if rr[0] in ['Enter', 'Change']:
            namespace[rr[1]]=rr[2]
    
    return [f"{namespace[r.split(' ')[1]]}님이 들어왔습니다." if r.split(' ')[0]=="Enter" else f"{namespace[r.split(' ')[1]]}님이 나갔습니다." for r in record if not r.split(' ')[0]=="Change"]
