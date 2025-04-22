def primes():
    D = {}
    q = 2
    while q < 1000000:
        if q not in D:
            yield q  
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1


def main():
    sum = 0
    p = list(primes())
    best_len = 1
    for i in range(len(p)):
        sum = 0
        for j in range(i, len(p)):
            sum += p[j]
            if(sum > 1000000):
                break
            if(j-i+1 < best_len):
                continue
            if sum in p:
                if j - i + 1 > best_len:
                    best_len = j - i + 1
                    best = sum

    print(best, best_len)






if __name__ == "__main__":
    main()





