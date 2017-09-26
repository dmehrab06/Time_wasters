n = int(input())
blah = input().split(' ')
count = 0
if(n != 1):
    for i in range(n):
        x = blah[i]
        if(x == 1):
            count = count + 1
    if(count == n - 1):
        print("YES")
    else:
        print("NO")
else:
    y = blah[0]
    if(y == 1):
        print("YES")
    else:
        print("NO")