from collections import Counter
def main():
    file = open("1.txt", "r")
    lines = file.readlines()
    file.close()
    one, two = list(), list()
    for line in lines:
        one.append(line.split()[0])
        two.append(line.split()[1])
    ans = 0
    C1, C2 = Counter(one), Counter(two)
    print(C1, C2)
    for num in one:
        ans += int(num) * C2[num]
    print(ans)

if __name__ == '__main__':
    main()
