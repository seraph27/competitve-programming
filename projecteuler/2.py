



def main():
    dp = [0]*(10000)
    dp[0], dp[1] = 1, 2
    sum = 2
    for i in range(2, len(dp)):
        dp[i] = dp[i-1] + dp[i-2]
        if(dp[i]>4*10**6):
            break
        sum+=dp[i] if dp[i]%2==0 else 0 
    print(sum)






if __name__ == "__main__":
    main()





