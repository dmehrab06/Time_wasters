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

bool possible;

int visited[100005];

vector<PII>ranges;

void init(int m){
    possible=true;
    FREP(i,0,(m-1)){
        visited[i]=0;
    }
}

void takeg(int n, int m){
    FREP(i,1,m){
        int l,r;
        scanf("%d %d",&l,&r);
        ranges.PB(make_pair(l,r));
    }
    SORTV(ranges);
}

int dfs(int cur, int m){
    visited[cur]=1;
    int curr=ranges[cur].second;
    int i=cur+1;
    while(i<m){
        PII currange=ranges[i];
        int ll=currange.first;
        int rr=currange.second;
        if(ll>curr){
            return i;
        }
        else{
            if(rr>curr){
                possible=false;
                return -1;
            }
            else{
                i=dfs(i,m);
                if(i==-1){
                    return -1;
                }
            }
        }
    }
    return i;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        init(m);
        ranges.clear();
        takeg(n,m);
        FREP(i,0,(m-1)){
            if(visited[i]==0){
                dfs(i,m);
            }
        }
        if(possible){
            if(ranges[0].first==0){
                if(ranges[0].second!=(n-1)){
                    printf("No\n");
                    continue;
                }
            }
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
