



def main():
    mx = 0;
    for i in range(100, 1000):
        for j in range(100, 1000):
            s = str(i*j)
            if s == s[::-1]:
                mx = max(mx, int(s))

    print(mx)





if __name__ == "__main__":
    main()





