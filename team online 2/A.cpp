#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000000
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
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())



using namespace std;

LLI inc[2000005];
LLI cum[2000005];

void init(int R){
    FREP(i,0,R){
        inc[i]=0;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int R;
        scanf("%d",&R);
        int n;
        init(R);
        scanf("%d",&n);
        LLI oasisland=0;
        FREP(i,1,n){
            int lx,ly,w,h;
            scanf("%d %d %d %d",&lx,&ly,&w,&h);
            oasisland=oasisland+((LLI)w*(LLI)h);
            inc[lx]+=(LLI)h;
            inc[min(lx+w,R)]-=(LLI)h;
        }
        LLI weioasis=0;
        LLI huooasis=oasisland;
        int x=-1;
        LLI mnn=MXX;
        LLI st=0;
        FREP(i,0,R){
            st=st+inc[i];
            cum[i]=st;
        }
        FREP(i,1,R){
            weioasis+=cum[i-1];
            huooasis=oasisland-weioasis;
           // printf("%lld %lld\n",weioasis,huooasis);
            if(x<0){
                if(weioasis>=huooasis){
                    x=i;
                    mnn=weioasis-huooasis;
                }
            }
            else{
                LLI curmin=weioasis-huooasis;
                if(curmin>mnn){
                    break;
                }
                else{
                    x=i;
                }
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
