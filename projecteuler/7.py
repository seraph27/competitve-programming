def sieve(n):
    prime = [True]*n
    p = 2
    while p*p < n:
        if prime[p]:
            for i in range(p*p, len(prime), p):
                prime[i] = False
        p+=1
    primes = [p for p in range(2, len(prime)) if prime[p]]
    return primes

def main():
    get = sieve(200000)
    print(get[10000])







if __name__ == "__main__":
    main()





