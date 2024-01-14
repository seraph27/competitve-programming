import math
t = int(input())
for _ in range(t):
    a = int(input())
    v = list(map(int, input().split()))
    m=1e9+7
    for i in range(len(v)-1):
        m = min(m, (v[i+1] - v[i]))
    ans=0
    if(m>=0):
        ans = math.ceil((m+1)/2)
    print(ans)



