print ('HELLO\n')
inp = input ('What is ur 3 digit roll \tplease?\n')
print ('Ur roll is ' + inp)
roll=int(inp)

if roll<1 or roll>120:
    print ('Invalid roll number\n')
else:
    if roll%2==0:
        sec='B'
    else:
        sec='A'

    if roll<61:
        lab='1'
    else:
        lab='2'

    print ('Ur section is ' + sec + lab)
