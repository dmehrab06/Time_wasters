/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int par[100005][3];

int balance = 0;

int findpar(int v, int type){
    if(par[v][type]==v)return v;
    else return par[v][type]=findpar(par[v][type],type);
}

void unionfind(int x, int y, int type){
    int parx = findpar(x,type);
    int pary = findpar(y,type);
    if(parx<pary){
        par[pary][type]=parx;
    }
    else{
        par[parx][type]=pary;
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    FREP(i,1,n){
        par[i][0]=i;
        par[i][1]=i;
    }
    FREP(i,1,q){
        int tp,u,v;
        scanf("%d %d %d",&tp,&u,&v);
        tp--;
        if(findpar(u,tp)==findpar(v,tp)){
            if(balance==0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            int prevu = findpar(u,tp);int prevv = findpar(v,tp);
            unionfind(u,v,tp);
            int curu = findpar(u,tp);int curv = findpar(v,tp);
            int otherpu = findpar(u,1-tp); int otherpv = findpar(v,1-tp);
            if((otherpu!=prevu) && (otherpu==curu))balance++;
            if((otherpv!=prevv) && (otherpv==curv))balance++;
            if((otherpu==prevu) && (otherpu!=curu))balance--;
            if((otherpv==prevv) && (otherpv!=curv))balance--;
            if(balance==0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            FREP(i,1,n){
                findpar(i,0);findpar(i,1);
            }
        }
    }
    return 0;
}
