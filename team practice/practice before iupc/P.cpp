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

int edges[103][103];
int val[103];
int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        FREP(i,1,n){
            scanf("%d",&val[i-1]);
        }
        //VI line;
        FREP(i,1,(n+2)){
            edges[i-1][0]=0;
        }
        FREP(i,1,m){
            int u,v;
            scanf("%d %d",&u,&v);
            edges[u][++edges[u][0]]=v;
        }
        int cur=0;
        int lea=0;
        while(true){
            lea+=val[cur];
            int mx=-1;
            int nxt=-1;
            int deg=edges[cur][0];
            FREP(k,1,deg){
                int v=edges[cur][k];
                if(val[v]>mx){
                    mx=val[v];
                    nxt=v;
                }
            }
            if(nxt==-1){
                break;
            }
            cur=nxt;
        }
        printf("Case %d: %d %d\n",cs++,lea,cur);
    }

    return 0;
}
