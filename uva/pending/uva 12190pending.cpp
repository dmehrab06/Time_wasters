#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
using namespace std;

LLI pay(LLI consume){
    LLI tot=0;
    tot+=((min(max(consume,(LLI)0),(LLI)100))*2);
    consume-=100;
    tot+=((min(max(consume,(LLI)0),(LLI)9900))*3);
    consume-=9900;
    tot+=((min(max(consume,(LLI)0),(LLI)99000))*5);
    consume-=99000;
    tot+=(max(consume,(LLI)0)*7);
    return tot;
}

LLI cons(LLI bill){
    LLI lo=0;
    LLI hi=MXX;
    FREP(i,1,100){
        LLI mid=(lo+hi)/2;
        LLI b=pay(mid);
        if(b==bill){
            return mid;
        }
        else if(b<bill){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    return lo;
}

int main(){
    LLI A,B;
    while(scanf("%lld %lld",&A,&B)==2 && !(!A && !B)){
        LLI totalcons=cons(A);
        LLI lo=0;
        LLI hi=totalcons;
        LLI ans=-1;
        FREP(i,1,100){
            LLI myconsume=(lo+hi)/2;
            LLI mybill=pay(myconsume);
            LLI hisbill=pay(totalcons-myconsume);
            if(hisbill<mybill){
                hi=myconsume;
            }
            else{
                LLI diff=hisbill-mybill;
                if(diff==B){
                    ans=mybill;
                    break;
                }
                else{
                    if(diff<B){
                        hi=myconsume;
                    }
                    else{
                        lo=myconsume+1;
                    }
                }
            }
        }
        if(ans==-1)ans=lo;
        printf("%lld\n",ans);
    }
    return 0;
}
