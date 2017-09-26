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

int deg[100005];

vector< multiset<int> >g1;

vector< VI >g2;

vector<PII>diredges;

multiset<PII>resolvededges;

stack<int>nodestacksim;

VI fin;

void takeg(int n, int m){
    g1.clear();g2.clear();
    VI line;
    multiset <int> line2;
    FREP(i,0,(n+3))g2.PB(line);
    FREP(i,0,(n+3))g1.PB(line2);

    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        PII edg=make_pair(u,v);
        diredges.PB(edg);
        g2[u].PB(v);
        g2[v].PB(u);
        g1[u].insert(v);
        g1[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
}

bool iseuler(int n){
    FREP(i,1,n){
        if(deg[i]%2){
            //cout<<i<<" "<<deg[i]<<"\n";
            return false;
        }
    }
    return true;
}

int vis[100005]; //proti test case e dfs chalanor age false korte hobe

int dfs(int cur){
    vis[cur]=1;
    int d=g2[cur].size();
    int sz=1;
    FREP(i,0,(d-1)){
        int v=g2[cur][i];
        if(!vis[v])sz+=dfs(v);
    }
    return sz;
}

void hierholzer(int src){
    nodestacksim.push(src);
    int sz=1;
    while(sz>0){
        int cur=nodestacksim.top();
        if(deg[cur]==0){
            fin.PB(cur);
            nodestacksim.pop();
            sz--;
        }
        else{
            multiset<int>::iterator it1=g1[cur].begin();
            int nxt=*it1;
            multiset<int>::iterator it2=g1[nxt].find(cur);
            g1[cur].erase(it1);
            g1[nxt].erase(it2);
            deg[cur]--;
            deg[nxt]--;
            nodestacksim.push(nxt);
           // resolvededges.insert(make_pair(cur,nxt));
            sz++;
        }
    }
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    takeg(n,m);
    int compsize=dfs(1);
    if(compsize!=n || !iseuler(n)){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        hierholzer(1);
        //printf("eikhane TLE khaisi\n");
        int l=fin.size();
        RFREP(i,l-1,1){
            int u=fin[i];
            int v=fin[i-1];
            resolvededges.insert(make_pair(u,v));
        }
        FREP(i,0,(m-1)){
            PII curedg=diredges[i];
            PII edg1=make_pair(curedg.first,curedg.second);
            PII edg2=make_pair(curedg.second,curedg.first);
            if(resolvededges.find(edg1)!=resolvededges.end()){
                printf("%d %d\n",edg1.first,edg1.second);
              //  resolvededges.erase(edg1);
            }
            else if(resolvededges.find(edg2)!=resolvededges.end()){
                printf("%d %d\n",edg2.first,edg2.second);
               // resolvededges.erase(edg2);
            }
        }
    }
    return 0;
}


