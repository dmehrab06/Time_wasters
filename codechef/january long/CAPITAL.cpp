/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

map<int,int>compress;
map<int,int>poptonode;

int pop[50005];
int nodepop[50005];

vector <  vector < int > >g;

int check(int node, int n){
    //cout<<"checking for node "<<node<<"\n";
    int deg=g[node].size();
    set<int>serials;
    serials.insert(compress[nodepop[node]]);
    //cout<<"inserting "<<compress[pop[node].first]<<" for population "<<pop[node].first<<"\n";
    FREP(i,0,(deg-1)){
        serials.insert(compress[nodepop[g[node][i]]]);
       // cout<<"inserting "<<compress[pop[g[node][i]].first]<<" for population "<<pop[g[node][i]].first<<"\n";
    }
    int ans=-1;
    FREP(i,1,n){
        if(serials.find(i)==serials.end()){
            ans=i;
            break;
        }
    }
    return ans;
}

void takeg(int n, int m){
    g.clear();
    VI line;
    FREP(i,0,(n+2)){
        g.push_back(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
}




int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        poptonode.clear();
        FREP(i,1,n){
            scanf("%d",&pop[i]);
            nodepop[i]=pop[i];
            poptonode[pop[i]]=i;
        }
        FREP(i,1,n){
            pop[i]=pop[i]*(-1);
        }
        sort(pop+1,pop+1+n);
        FREP(i,1,n){
            pop[i]=pop[i]*(-1);
        }
        compress.clear();
        FREP(i,1,n){
            compress[pop[i]]=i;
            //cout<<pop[i].first<<" ";
        }
        //cout<<"\n";
        takeg(n,n-1);
        FREP(i,1,n){
            int ans=check(i,n);
            if(i>1)printf(" ");
            if(ans==-1){
                printf("0");
            }
            else{
                printf("%d",poptonode[pop[ans]]);
            }
        }
        printf("\n");
    }
    return 0;
}


