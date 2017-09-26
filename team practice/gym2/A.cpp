/*-------property of the half blood prince-----*/

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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int representative[1003];

vector< pair<int,PII> >alledges;

int findrep(int a){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a]);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y){
    int xp,yp;
    xp=findrep(x);
    yp=findrep(y);
    representative[yp]=xp;
}

char all[1005][35];

void init(int n){
    FREP(i,1,n){
        representative[i]=i;
    }
}


int dis(int i, int j, int l){
    int mx=-1;
    FREP(k,0,(l-1)){
        int dis=abs(all[i][k]-all[j][k]);
        mx=max(mx,dis);
    }
    return mx;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        scanf("%s",all[i]);
    }
    int mxx=-1;
    FREP(i,1,n){
        FREP(j,(i+1),n){
            int d=dis(i,j,m);
            int u=i;
            int v=j;
            int w=d;
            pair<int,PII>oka=make_pair(w,make_pair(u,v));
            alledges.PB(oka);
        }
    }
    sort(alledges.begin(),alledges.end());
    int taken=0;
    int l=alledges.size();
    init(n);
    while(taken<(n-1)){
        FREP(i,0,(l-1)){
            pair<int,PII>cur=alledges[i];
            int w=cur.first;
            int u=cur.second.first;
            int v=cur.second.second;
            if(findrep(u)!=findrep(v)){
                unionfind(u,v);
                mxx=max(w,mxx);
                taken++;
            }
        }
    }
    printf("%d\n",mxx);
    return 0;
}
