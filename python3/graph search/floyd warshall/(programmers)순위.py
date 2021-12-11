def solution(n, results):
    answer = 0
    game = [[0 for _ in range(101)] for _ in range(101)]    
    for win, lose in results:
        game[win][lose] = 1
        
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                if( game[i][k] and game[k][j] ):
                    game[i][j]=1
                
    for i in range(1,n+1):
        sum = 0
        for j in range(1, n+1):
            sum += game[i][j]+game[j][i]
        if( sum == n-1):
            answer+=1
        
    return answer
