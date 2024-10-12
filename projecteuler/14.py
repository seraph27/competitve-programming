
ans = [0]*1000010
def colatz(n):
    cnt = 1
    while n>1:
        if n%2:
            n=3*n+1
        else:
            n//=2
        if not ans[n]:
            ans[n] = -1


def main():
    for i in range(1000000, 0, -1):
        ans[i] = 






if __name__ == "__main__":
    main()





