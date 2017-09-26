#include <bits/stdc++.h>
#define mx 1e6+10
using namespace std;

long long ck(long long m)
{
    int l=0;

    for(long long i=2 ; i<=(sqrt(m+.0))+1 ; i++){
        if(m%i==0){
            return 1;
            l=1;
            //break;
        }
        if(l)
            break;
    }
    return 0;
}

int main()
{
    long long m,n;
    while(scanf("%lld%lld",&n,&m)!=EOF){
    long long ckk=ck(m),mm=1;
    if(m==1)
        printf("%lld 1\n",n);
    /*else if(ckk==0){
        if(n>=m)
            printf("%lld 1\n",n-m);
        else
            printf("%lld %lld\n",n,m);

    }*/
    else{
        for (long long i = 2 ; i<=mx ; i++){
            if((ck(m))==0){
                   mm=0;
                   break;
                }
            else if((m%i==0) && n>=i)
                {

                m = m / i;
                n = n - i;

                }
            ///cout<<n<<" "<<m<<endl;

              if(i>n || m<i)
                break;
            }
        //cout<<n<<" "<<m<<endl;
        if(mm==0)
            {
                if(n>=m)
                    printf("%lld 1\n",n-m);
                else
                    printf("%lld %lld\n",n,m);
            }
        else
            printf("%lld %lld\n",n,m);
    }
    }

    return 0;
}
