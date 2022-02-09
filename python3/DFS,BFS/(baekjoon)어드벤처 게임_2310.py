from collections import deque

def checkAll(room_info, n):
    visited = [False for _ in range(n+1)]
    if room_info[1][0] == 'E' and room_info[1][1] > 0:
        return False
    
    dq = deque()
    dq.append([1, 0])
    while dq:
        prev_room, prev_money = dq.popleft()
        visited[prev_room]=True
        if( prev_room == n ):
            return True

        for i in range(2, len(room_info[prev_room])-1):
            next_room = room_info[prev_room][i]
            next_money = prev_money
            if visited[next_room]==True or (room_info[next_room][0]=="T" and room_info[next_room][1] > prev_money):
                continue
            
            if room_info[next_room][0]=="L":
                if next_money < room_info[next_room][1]:
                    next_money = room_info[next_room][1]
            elif room_info[next_room][0]=="T":
                next_money -= room_info[next_room][1]
            dq.append([next_room, next_money])
            
    return False

while True:
    n = int(input())

    if n == 0 :
        break

    room_info = [[]]
    for i in range(n):
        room_info.append(list(input().split()))
        room_info[i+1][1:]=list(map(int, room_info[i+1][1:]))
        #print(room_info[i+1] )
    answer = "Yes" if checkAll(room_info, n) else "No"
    print(answer)
