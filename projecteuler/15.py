def main():

    dp = [[0] * 21 for _ in range(21)]

    for i in range(21): 
        dp[i][0] = 1
        dp[0][i] = 1
    for i in range(20):
        for j in range(20):
            dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j]

    print(dp[2][2])
    print(dp[20][20])


    #comb solution

    sum = 1
    for i in range(1, 21):
        sum = sum * (20 + i) // i
    print(sum)



if __name__ == "__main__":
    main()





