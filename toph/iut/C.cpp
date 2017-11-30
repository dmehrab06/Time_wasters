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

//string poly;

vector < vector <PII> >g;

int vis[1003];

void takeinp(int interaction){

    vector <PII> line;
    FREP(i,0,(1003+4)){
        g.PB(line);
    }

    FREP(i,1,interaction){
        int u,v,t;
        scanf("%d %d %d",&u,&v,&t);
        g[u].PB(make_pair(t,v));
        g[v].PB(make_pair(t,u));
    }

    FREP(i,1,1003)SORTV(g[i]);
}

bool bfs(int src, int X, int des, int Y){
    set< pair<int, int> > setds;
    //vis[src]=X;
    setds.insert(make_pair(X, src));
    FREP(i,1,1003)vis[i]=1000000009;
    vis[src]=X;
    while (!setds.empty()){
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int v = tmp.second;
        int tv = tmp.first;
        //cout<<"at v: "<<v<<" "<<tv<<"\n";
        if(v==des){
            if(tv<=Y)return true;
            return false;
        }
        vector< PII >::iterator i;
        for (i = g[v].begin(); i != g[v].end(); ++i){
            int there = (*i).first;
            int tov = (*i).second;
            if (there>=tv && vis[tov]>there){
                if (vis[tov] != 1000000009)
                    setds.erase(setds.find(make_pair(vis[tov], tov)));
                vis[tov] = there;
                setds.insert(make_pair(vis[tov], tov));
            }
        }
    }
    return false;
}

int main(){
    int interaction;
    scanf("%d",&interaction);
    takeinp(interaction);
    int q;
    scanf("%d",&q);
    while(q--){
        int src, X, des, Y;
        scanf("%d %d %d %d",&src,&X,&des,&Y);
        printf("%s\n",bfs(src,X,des,Y)?"Yes":"No");
    }
    return 0;
}
