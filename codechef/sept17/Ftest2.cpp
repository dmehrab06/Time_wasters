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
using namespace std;
using namespace __gnu_pbds;
#define MDD 1000000007
#define FEMSIZE 200005

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < VI > g;

vector < multiset<int> > xors;

void takeg(int n){
    g.clear();xors.clear();
    FREP(i,1,(n+4)){
        VI line; multiset<int> line2;
        g.PB(line); xors.PB(line2); xors[i-1].insert(i-1);
    }
    FREP(i,1,n-1){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v); g[v].PB(u);
    }
}

void takepsuedog(int n){
    g.clear();xors.clear();
    FREP(i,1,(n+4)){
        VI line; multiset<int> line2;
        g.PB(line); xors.PB(line2); xors[i-1].insert(i-1);
    }
    FREP(i,1,n-1){
        g[i-1].PB(i); g[i].PB(i-1);
    }
}

void dfs(int src, int par){
    int l = g[src].size();
    FREP(i,0,(l-1)){
        int v = g[src][i]; if(par==v)continue;
        dfs(v,src);
        multiset<int> cset = xors[v]; multiset<int>:: iterator it,it2;
        for(it = cset.begin();it!=cset.end();++it){
            int cur = *it; it2 = xors[src].find(cur);
            if(it2!=xors[src].end()) xors[src].erase(it2);
            else xors[src].insert(cur);
        }
    }
    return;
}

void print(int n){
    FREP(i,0,0){
        multiset<int>:: iterator it;
        multiset<int> ss = xors[i];
        cout<<"at node  "<<i<<": ";
        for(it=ss.begin();it!=ss.end();++it){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
}

bool isrestored(int n){
    FREP(i,0,(n-1)){
        if(xors[i].size()>1)return false;
    }
    return true;
}

int main(){
    int day = 100;
    FREP(n,2,200){
        //int n;
        //scanf("%d",&n);
        takepsuedog(n);
        cout<<"height "<<n-1<<"\n";
        //cout<<"restored on day ";
        //int f = 0;
        FREP(i,1,day){
            dfs(0,-1);
            cout<<"day "<<i<<"\n";
            print(n);
            //if(isrestored(n) && !f){
              //  cout<<i<<"\n";
               // f=1;
            //}
        }
        cout<<"\n";
    }

    return 0;
}
