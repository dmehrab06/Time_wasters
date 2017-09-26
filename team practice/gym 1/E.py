if __name__=='__main__':
    fin = open('easy.in', 'r')
    fout= open('easy.out','w')
    str= fin.read()
    res=""
    f=0
    i = 0
    while i< len(str):
        if str[i]=='-':
            res+=str[i]
            i+=1
            if i<len(str):
                res+=str[i]
                i+=1
                f=1
                while i!=len(str) and str[i]!='-' and str[i]!='+' :
                    if f==1:
                        res+='+'
                    res+=str[i]
                    if str[i]!='0':f=0
                    i+=1
        else:
            res+=str[i]
            i+=1


    print(res)
    fout.write(res)
    fin.close()
    fout.close()