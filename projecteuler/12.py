def div(n):
    cnt = 0
    i = 1
    while i*i < n:
        if n%i==0:
            cnt+=2
        i+=1
    if i*i==n:
        cnt+=1
    return cnt

def main():
    v, add = 1, 1
    while(div(v) < 500):
        add+=1
        v+=add
    print(v)






if __name__ == "__main__":
    main()





