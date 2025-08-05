def solve():
    n = int(input())
    
    s = ''
    for _ in range(n):
        c, l = input().split()
        l = int(l);
        if(len(s) + l > 100):
            print("Too Long")
            return
        s += c * l

    print(s)










def main():
    solve()

if __name__ == "__main__":
    main()

