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

int r[31];
int c[31];

void init(){
    FREP(i,0,30){
        r[i]=0;
        c[i]=0;
    }
}

int main(){
    int rw,cl;
    while(scanf("%d %d",&rw,&cl)==2){
        if(rw==0  && cl==0)break;
        init();
        FREP(i,1,rw){
            int h;
            scanf("%d",&h);
            r[h]++;
        }
        FREP(i,1,cl){
            int h;
            scanf("%d",&h);
            c[h]++;
        }
        int len=0;
        FREP(i,0,30){
            int mx=max(c[i],r[i]);
            len+=(mx*i);
        }
        cout<<len<<"\n";
    }
    return 0;
}
