#include <bits/stdc++.h>
using namespace std;
int main ()
{
     long long int value,remainder,x,i,j,e,numb,base,a,b;
    char s[10],val[110];
    vector<long long int>v;
    while(1)
    {   v.clear();
        scanf("%s",&s);
        numb=0;
        base=1;
        if(s[0]=='e')break;
        else if(s[0]=='f')
       {   a=strlen(s);

           x=0;

           for(i=5;i<a;i++)
           {
               x=x*10;
               x=x+(s[i]-48);
           }
           x=x*-1;

           scanf("%s",val);
           if(strlen(val)==1 && val[0]=='0')
            {
                printf("0\n");
                continue;
            }

            b=strlen(val);
           //cout<<x<<" "<<value<<endl;
           for(i=b-1;i>=0;i--)
    {
        remainder = val[i]-48;
        numb = numb + remainder * base;

        base = base * x;
        value = value / 10;
        //cout<<numb<<" ";
    }
    printf("%lld",numb);
    printf("\n");

       }

        else if(s[0]='t')
        {

            a=strlen(s);
           x=0;
           for(i=3;i<a;i++)
           {
               x=x*10;
               x=x+(s[i]-48);
           }
           x=x*-1;

            scanf("%lld",&value);
            if(value==0)
            {
                printf("0\n");
                continue;
            }

     while (value != 0)
    {
        remainder = value % x;

        value = value / x;
           //cout<<remainder<<" "<<value<<endl;
        if (remainder < 0)
        {
            remainder += abs(x);
            value += 1;
        }

        v.push_back(remainder);
    }
       e=v.size();

       for(i=e-1;i>=0;i--)
        printf("%lld",v[i]);
       printf("\n");
        }


    }

    return 0;
}
