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
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

int pope[100007];
int P;
int bs(int l, int h ,int v){
    int m=(l+h)>>1;
    if(pope[m]<=v){
        if((m+1)>P){
            return m;
        }
        else if(pope[m+1]>v){
            return m;
        }
        else{
            return bs(m+1,h,v);
        }
    }
    return bs(l,m,v);
}

int main(){
    int Y;
    while(scanf("%d",&Y)==1){
        scanf("%d",&P);
        for(int i=1;i<=P;++i){
            scanf("%d",&pope[i]);
        }
        int mx=0;
        int mxl=-1;
        int mxr=-1;
        for(int i=1;i<=P;++i){
            int l=pope[i];
            int r=l+Y-1;
            int k=bs(i,P,r);
            int period=(k-i+1);
            if(period>mx){
                mx=period;
                mxl=i;
                mxr=k;
            }
        }
        printf("%d %d %d\n",mx,pope[mxl],pope[mxr]);
    }
    return 0;
}
