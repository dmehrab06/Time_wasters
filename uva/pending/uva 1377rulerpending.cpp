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

int mneed(int tot){
    int a=1+8*tot;
    int sq=sqrt(a);
    int b=1+sq;
    b/=2;
    return b;
}

int N;
int measures[52];
int mn;
int mnmsk;
int len;
void print(int msk){
    VI all;
    all.PB(0);
    int it=0;
    int itmsk=1;
    while(itmsk){
        if(itmsk&msk){
            all.PB(measures[it]);
        }
        itmsk<<=1;
        it++;
    }
    int sz=all.size();
    printf("%d\n0",sz);
    FREP(i,1,(sz-1)){
        printf(" %d",all[i]);
    }
    printf("\n");
}

pair<int,int> can(int msk, int need, int N){
    VI all;
    all.PB(0);
    int it=0;
    int itmsk=1;
    int mx=-1;
    while(itmsk){
        if(itmsk&msk){
            all.PB(measures[it]);
            if(measures[it]>mx){
                mx=measures[it];
            }
        }
        itmsk<<=1;
        it++;
    }
    int sz=all.size();
    if(sz<need || sz>7)return make_pair(-1,-1);
    if(sz>mn)return make_pair(-1,-1);
    set<int>parbo;
    FREP(i,0,(sz-1)){
        FREP(j,(i+1),(sz-1)){
            int dif=abs(all[i]-all[j]);
            parbo.insert(dif);
        }
    }
   // sort(parbo.begin(),parbo.end());
    FREP(i,0,(N-1)){
        if(parbo.find(measures[i])==parbo.end())return make_pair(-1,-1);
    }
    return make_pair(sz,mx);
}

int main(){
    //int N;
    int cs=1;
    while(scanf("%d",&N)==1 && N){
        //stack<int>going;
        set<int>ok;
        FREP(i,1,N){
            //init(N);
            int l;
            scanf("%d",&l);
            ok.insert(l);
        }
        set<int>::iterator it;
        int sz=0;
        for(it=ok.begin();it!=ok.end();it++){
            measures[sz]=*it;
            sz++;
        }
        int limit=(1<<sz)-1;
        //sort(all+1,all+1+N,cmp);
        int minneed=mneed(sz);
        mn=100;
        len=10000009;
        FREP(msk,0,limit){
            PII p=can(msk,minneed,sz);
            int ret=p.first;
            if(ret!=-1){
                if(ret<mn){
                    mn=ret;
                    mnmsk=msk;
                    len=p.second;
                }
                else if(ret==mn){
                    int ret2=p.second;
                    if(ret2<len){
                        len=ret2;
                        mnmsk=msk;
                    }
                }
            }
        }
        printf("Case %d:\n",cs++);
        print(mnmsk);
    }
    //int cs=1;
    return 0;
}
