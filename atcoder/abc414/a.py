def main():
    n, l, r = map(int, input().split())
    
    ans = 0
    for _ in range(n):
        x, y = map(int, input().split())
        if(x <= l and y >= r):
            ans+=1

    print(ans)
            






if __name__ == "__main__":
    main()




