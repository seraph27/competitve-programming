def main():
    file = open("1.txt", "r")
    lines = file.readlines()
    file.close()
    one, two = list(), list()
    for line in lines:
        one.append(line.split()[0])
        two.append(line.split()[1])
    one.sort()
    two.sort()
    ans = 0
    for i in range(len(one)):
        ans += abs(int(one[i]) - int(two[i]))
    print(ans)

if __name__ == '__main__':
    main()
