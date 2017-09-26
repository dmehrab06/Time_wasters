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
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

int last(int n){
    int pos=30;
    int msk=1<<30;
    while(true){
        if((msk&n)){
            break;
        }
        pos--;
        msk>>=1;
    }
    return pos;
}

int main(){
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int cnt=0;
        while(true){
            int laspos=last(n);
           // cout<<n<<" "<<laspos<<"\n";
            int newn=n&(~(1<<laspos));
            newn=(newn<<1)|1;
           // cout<<newn<<"\n";
            if(newn==n){
                break;
            }
            cnt++;
            n=newn;
        }
        printf("Case %d: %d %d\n",cs++,cnt,n);
    }
    return 0;
}
