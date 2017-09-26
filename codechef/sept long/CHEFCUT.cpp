#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
using namespace std;

int AdjMat[101][101];
int tempMat[101][101];

int N;

vector<int>notst;
vector<LLI>allcosts;

void copymat(int N){
    FREP(i,1,N){
        FREP(j,1,N){
            tempMat[i][j]=AdjMat[i][j];
        }
    }
}

void buildmat(int N, int msk,int s, int t){
    int m=1;
    int cur=0;
    int l=notst.size();
    set<int>sets;
    set<int>sett;
    sets.insert(s);
    sett.insert(t);
    while(cur<l){
        if(msk&m){
            sets.insert(notst[cur]);
        }
        else{
            sett.insert(notst[cur]);
        }
        m<<=1;
        cur++;
    }
    copymat(N);
    LLI cost=0;
    FREP(i,1,N){
        FREP(j,1,N){
            if(sets.find(i)!=sets.end() && sett.find(j)!=sett.end()){
                cost+=tempMat[i][j];
            }
        }
    }
    allcosts.PB(cost);
}

void init(int N){
    FREP(i,1,N){
        FREP(j,1,N){
            AdjMat[i][j]=0;
        }
    }
}

int main(){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    int s,t;
    scanf("%d %d",&s,&t);
    FREP(i,1,N){
        if(i!=s && i!=t)notst.PB(i);
    }
    sort(notst.begin(),notst.end());
    FREP(i,1,M){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        AdjMat[u][v]=w;
    }
    int upto=(1<<(N-2));
    int start=0;
    FREP(i,start,(upto-1)){
        buildmat(N,i,s,t);
    }
    sort(allcosts.begin(),allcosts.end());
    printf("%lld\n",allcosts[K-1]);
}
