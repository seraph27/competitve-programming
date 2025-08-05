def solve():
    n = int(input())
    sign_in = {}
    sign_out = {}
    for _ in range(n):
        uid, t, action = input().split(None, 2)
        if action == "sign-in":
            sign_in[uid] = int(t)
        else:
            sign_out[uid] = int(t)

    maxspan = int(input())

    ans = []
    for uid in sign_in:
        if uid in sign_out:
            delta = sign_out[uid] - sign_in[uid]
            if delta <= maxspan:
                ans.append(uid)

    ans.sort(key=int)
    for u in ans:
        print(u)


def main():
    solve()

if __name__ == "__main__":
    main()
