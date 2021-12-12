"""
    1. convolution 연산을 할 때, padding을 원래 배열에서 추가해 계산하는 것이 편하다. 
"""
def RotateKey(key):
    rotate_key = [[0 for _ in range(len(key[0]))] for _ in range(len(key))]
    for i in range(len(key)):
        for j in range(len(key[0])):
            rotate_key[len(key)-j-1][i]=key[i][j]
    return rotate_key
def solution(key, lock):
    answer = False
    cnt = 0
    new_lock = [[2 for _ in range(len(lock)+2*(len(key)-1))] for _ in range(len(lock)+2*(len(key)-1))]
    for index, row in enumerate(lock):
        new_lock[len(key)+index-1][len(key)-1:len(lock)+len(key)-1] = row
        for i in row:
            if i == 0:
                cnt += 1
    key_temp = RotateKey(key)
    
    N = len(key)+len(lock)-1
    for rotate in range(4):
        key = RotateKey(key)
        for k in range(N*N):
            noMatch = 0
            cnt_temp = 0
            for i in range(len(key)):
                for j in range(len(key[0])):
                    if( new_lock[i+k//N][j+k%N] == 2):
                        continue
                    elif( key[i][j]+new_lock[i+k//N][j+k%N]==1 ):
                        if( new_lock[i+k//N][j+k%N] == 0 ):
                            cnt_temp += 1
                    else:
                        noMatch = 1
                        break
                if( noMatch ):
                    break
                if( cnt == cnt_temp ):
                    return True

    return answer
