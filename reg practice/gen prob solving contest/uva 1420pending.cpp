#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
#define MNN -MXX
#define DBL double
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
using namespace std;

struct mrg{
    int s;
    int e;
    int need;
    mrg(int _a=0, int _b=0){
        s=_a;
        e=_b;
        need=(e-s)/2+1;
    }
};

bool cmp(mrg &a, mrg &b){
    if((a.s+a.need)==(b.s+b.need)){
        if(a.s==b.s)return a.e<b.e;
        return a.s<b.s;
    }
    return (a.s+a.need)<(b.s+b.need);
}

mrg all[5001];

int main(){
    //int t;
    int N;
    int cs=1;
    while(scanf("%d",&N)==1 && N){
        //stack<int>going;
        FREP(i,1,N){
            int s,e;
            //init(N);
            scanf("%d %d",&s,&e);
            mrg a(s,e);
            all[i]=a;
        }
        sort(all+1,all+1+N,cmp);
        int line=0;
        int f=1;
        FREP(i,1,N){
            int nwin=max(line,all[i].s);
            line=nwin+all[i].need;
            if(line>all[i].e){f=0;break;}
        }
        printf("%s\n",f?"YES":"NO");
    }
    //int cs=1;
    return 0;
}
