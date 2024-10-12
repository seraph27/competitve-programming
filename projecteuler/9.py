



def main():
    for a in range(1, 1001):
        for b in range(1, 1001):
            c = 1000-a-b
            if(a**2+b**2==c**2):
                print(a*b*c)
                break






if __name__ == "__main__":
    main()





