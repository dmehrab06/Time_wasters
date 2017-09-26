print ('HELLO\n')

month=(input('Give month\n'))
date=(input('Give date\n'))

print ('month = ' + month)
print ('date = ' + date)
 
int (month)
int (date)

if month == 1 :
    month_add = 0
elif month == 2 :
    month_add = 31
elif month == 3 :
    month_add = 59
elif month == 4 :
    month_add = 90
elif month == 5 :
    month_add=120
elif month == 6 :
    month_add = 151
elif month == 7 :
    month_add = 181
elif month == 8 :
    month_add = 212
elif month == 9 :
    month_add = 243
elif month == 10 :
    month_add = 273
elif month == 11 :
    month_add = 304
elif month == 12 :
    month_add = 334

print (month_add)

work = date + month_add
w = work % 7

if w == 1:
    print ('\n\nWednesday')
elif w == 2:
    print ('\n\nThursday')
elif w == 3:
    print ('\n\nFriday')
elif w == 4:
    print ('\n\nSaturday')
elif w == 5:
    print ('\n\nSunday')
elif w == 6:
    print ('\n\nMonday')
elif w == 0:
    print ('\n\nTuesday')


print ('\n\nGOODBYE')
