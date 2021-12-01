def recur(order, depth, target, combi, cur=""):
    if depth == target:
        try:
            if cur in combi.keys():
                combi[cur]+=1
            else:
                combi[cur]=1
            return
        except Exception as err:
            print(err)
    
    for i in range(len(order)):
        cur += order[i]
        recur(order[i+1:], depth+1, target, combi, cur)
        cur = cur[:-1]
        
    return
    
def solution(orders, course):
    answer = []
    
    for i in range(len(orders)):
        orders[i] = sorted(orders[i])
    
    combi = {}
    for i in course:
        for order in orders:
            try:
                recur(order, 0, i, combi)
            except Exception as err:
                print(err)
        answer+=[ x for x in combi.keys() if combi[x]>=2 and combi[x]==max(combi.values())]
        combi.clear()
    answer.sort()
    return answer
