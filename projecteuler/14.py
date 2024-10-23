ans = [0]*1000010
def colatz(n):
    if n < len(ans) and ans[n]!=0:
        return ans[n]
    if n==1:
        return 1
    if n%2==0:
        next = n//2
    else:
        next = n*3+1

    cnt = 1 + colatz(next)
    if n < len(ans):
        ans[n] = cnt
    return cnt


def main():
    for i in range(1000000, 0, -1):
        colatz(i)
    print(ans.index(max(ans)))







if __name__ == "__main__":
    main()





