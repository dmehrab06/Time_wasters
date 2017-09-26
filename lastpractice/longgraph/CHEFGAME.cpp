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
#define MXX 100000000000000
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
#define MDD 747474747
using namespace std;
using namespace __gnu_pbds;

#define MAXV 6675

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


vector<VI>points;

LLI key[MAXV];
int mstSet[MAXV];

LLI getdis(int src, int des){
    VI u = points[src];
    VI v = points[des];
    LLI d = 0;
    FREP(i,0,u.size()-1){
        LLI du = u[i];
        LLI dv = v[i];
        d = d +((du-dv)*(du-dv));
    }
    return d;
}

void init(int v){
    points.clear();MSET(mstSet,0);
    VI line;
    FREP(i,1,v+4)points.PB(line);
    FREP(i,1,v+4)key[i]=0;
}

int mxKey(int V)
{
   // Initialize min value
   LLI mx = 0; int mx_index;

   FREP(v,1,V){
    //cout<<v<<" "<<key[v]<<"\n";
    if ((!mstSet[v]) && (key[v] > mx)){
        mx = key[v]; mx_index = v;
        //cout<<mx<<" "<<mx_index<<"\n";
    }
   }
   return mx_index;
}

LLI primMST(int V){
     key[1] = 1;
     // The MST will have V vertices
     LLI s = 1;
     FREP(cnt,1,V){
        int u = mxKey(V);
        //cout<<"mxu "<<u<<"\n";
        LLI val = key[u]%MDD;
        //cout<<val<<"\n";
        s = s*val;
        s%=MDD;
        //cout<<"s now "<<s<<"\n";
        mstSet[u] =1;
        FREP(v,1,V){
            if(!mstSet[v]){
                LLI dis = getdis(u,v); //calculates euler distance
                //cout<<"from "<<u<<" to "<<v<<" "<<dis<<"\n";
                if(dis>key[v]){
                    key[v]=dis;
                }
            }
        }
     }
     return s;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        init(n);
        FREP(i,1,n){
            FREP(k,1,d){
                int v;
                scanf("%d",&v);
                points[i].PB(v);
            }
        }
        LLI ans = primMST(n);
        printf("%lld\n",ans);
    }

}
