"""
    1. zip을 이용하여 간단하게 parsing이 가능하다. 
    2. 가격이 0원이 되면 더이상 자신의 부모에게 값을 넘겨주지 않아도 되므로 이때 break를 걸어줘야 시간초과가 발생하지 않는다. 
"""
def solution(enroll, referral, seller, amount):
    answer = []
    graph, answer = {},{e:0for e in enroll}
    for en,ref in zip(enroll, referral):
        graph[en]=ref
        
    for sellers, cost in zip(seller, amount):
        cost*=100
        while graph[sellers] != "-": 
            answer[sellers] += cost-cost//10 
            cost = cost//10

            sellers = graph[sellers]
        answer[sellers]+=cost-cost//10
    return list(answer.values())
