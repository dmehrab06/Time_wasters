c = int(input ('column = ?\n'))
r = int(input ('row = ?\n'))

def grid(c, r):
    for a in range (1, r):
        print ('+ - - - - ' * (c-1) + '+')
        
        print ('|         ' * (c-1) + '|')
        print ('|         ' * (c-1) + '|')
        print ('|         ' * (c-1) + '|')
        print ('|         ' * (c-1) + '|')

    print ('+ - - - - ' * (c-1) + '+')
    


grid (c, r)
