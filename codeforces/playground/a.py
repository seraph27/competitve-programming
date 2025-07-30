import sys

def solve():
    a, b = map(int, input().split())
    print(a + b)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
