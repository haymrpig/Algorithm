def solution(triangle):
    answer = 0
    num = len(triangle)*(len(triangle)+1)//2
    dp = [[0 for _ in range(len(triangle[i]))] for i in range(len(triangle))]
    
    dp[0][0]=triangle[0][0]
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            if j==0:
                dp[i][j]=dp[i-1][j]
            elif j==len(triangle[i])-1:
                dp[i][j]=dp[i-1][j-1]
            else:
                dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])
            dp[i][j]+=triangle[i][j]
    
    answer = max(dp[len(triangle)-1])
    
    return answer
