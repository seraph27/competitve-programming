import sys
sys.set_int_max_str_digits(100005)
T = int(input())
for _ in range(T):
    n = int(input())
    l = 0 
    r = n
    best = 0
    while(l<=r):
        mid = (l+r) // 2
        if mid*(mid+1)//2<=n: 
            ans = mid
            l = mid+1
        else: 
            r = mid-1

    print(ans)