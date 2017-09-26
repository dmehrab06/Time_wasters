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

double gaussmat[103][103];
double ans[103];  // An array to store solutio
int nosol[103];

vector< VI > gin;
vector< VI > gout;

//gauss template found from Anik Sarker who claims he found it from Morris

void Gauss(int n) {
    FREP(i,1,n){
        int k=i;

        FREP(j,(i+1),n)if(fabs(gaussmat[k][i])<fabs(gaussmat[j][i]))k=j;

        if(fabs(gaussmat[k][i])<eps)continue;

        if(k!=i)FREP(j,1,(n+1))swap(gaussmat[k][j],gaussmat[i][j]);

        FREP(j,1,n){
            if(i==j)continue;
            RFREP(k,(n+1),i){
                gaussmat[j][k]-=gaussmat[j][i]/gaussmat[i][i]*gaussmat[i][k];
            }
        }
    }
    memset(nosol,0,sizeof(nosol));
    RFREP(i,n,1){
        if(fabs(gaussmat[i][n+1])>eps && fabs(gaussmat[i][i])<eps) nosol[i]=1;
        else{
            if(fabs(gaussmat[i][n+1])<eps)ans[i]=0;
            else ans[i]=gaussmat[i][n+1]/gaussmat[i][i];
        }
        FREP(j,(i+1),n)if(fabs(gaussmat[i][j])>eps && nosol[j])nosol[i] = 1;
    }
}

void init(int n){
    gin.clear(); gout.clear();
    FREP(i,1,(n+3)){
        VI line;
        gin.PB(line); gout.PB(line);
    }
    memset(gaussmat,0,sizeof(gaussmat));
    memset(ans,0,sizeof(ans));
}

int main(){
    int n;
    int cs = 1;
    while(scanf("%d",&n)==1){
        if(!n)break;
        init(n);
        while(true){
            int u,v;
            scanf("%d %d",&u,&v);
            if(!u && !v)break;
            gout[u].PB(v);
            gin[v].PB(u);
        }
        FREP(u,1,n){
            gaussmat[u][u]=1.0;
            if(u==1){
                gaussmat[u][n+1]=1.0;
            }
            else{
                gaussmat[u][n+1]=0.0;
            }
            int indeg = gin[u].size();
            FREP(i,0,indeg-1){
                int v = gin[u][i];
                int sz = gout[v].size();
                double w = 1.0/(double)sz;
                gaussmat[u][v]-=w;
            }
        }
        //print(n);
        Gauss(n);
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",cs++);
        FREP(i,1,q){
            int node;
            scanf("%d",&node);
            if(nosol[node]){
                printf("infinity\n");
            }
            else{
                printf("%.3lf\n",ans[node]);
            }
        }
    }
    return 0;
}
