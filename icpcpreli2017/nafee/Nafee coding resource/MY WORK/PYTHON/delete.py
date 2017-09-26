def prime_fact(n):
    div = n
    for a in range (2, n+1):
        if a > div:
            break
        print (a)
        count = 0
        while div % a == 0:
            count = count + 1
            div = div / a
        if count > 0:
            print (a, '^', count)
