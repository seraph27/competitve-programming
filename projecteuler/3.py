



def main():
    prime = [True]*1000000
    p = 2
    val = 600851475143
    while p*p<=1000001:
        if prime[p]:
            for i in range(p*p, 1000000, p):
                prime[i] = False
        p+=1

    primes = [p for p in range(2, len(prime)) if prime[p]]
    print(primes)
    s = set()
    while(val>1):
        for x in primes:
            if(val%x==0):
                s.add(x)
                val//=x
                break
        else:
            s.add(val)
            break
    print(max(s))






if __name__ == "__main__":
    main()





