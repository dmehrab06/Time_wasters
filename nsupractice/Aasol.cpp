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

vector < vector <PII> >edg;
string line;
int elevtime[103];
vector<VI>floorelevs;
int dis[10020];

void makeintergraph(int n){
    FREP(i,0,103){
        FREP(j,0,floorelevs[i].size()-1){
            FREP(k,j+1,floorelevs[i].size()-1){
                int curf = i;
                int elev1 = floorelevs[i][j];
                int elev2 = floorelevs[i][k];
                int u = (elev1-1)*100+curf;
                int v = (elev2-1)*100+curf;
                edg[u].PB(make_pair(v,60));
                edg[v].PB(make_pair(u,60));
            }
        }
    }
}

void parseline(int idx){
    int l = line.size();
    int curfloor = 0;
    VI adj;
    FREP(i,0,(l-1)){
        if(ISNUM(line[i]))curfloor = curfloor*10+line[i]-'0';
        else{
            //cout<<"elevator "<<idx<<" can reach "<<curfloor<<"\n";
            adj.PB(curfloor);
            floorelevs[curfloor].PB(idx);
            curfloor = 0;
        }
    }
    //cout<<"elevator "<<idx<<" can reach "<<curfloor<<"\n";
    adj.PB(curfloor);
    floorelevs[curfloor].PB(idx);
    FREP(i,1,adj.size()-1){
        int u = adj[i-1]+100*(idx-1);
        int v = adj[i]+100*(idx-1);
        int w = abs(u-v)*elevtime[idx];
        edg[u].PB(make_pair(v,w));
        edg[v].PB(make_pair(u,w));
    }
}

void takeinp(int n){
    FREP(i,1,100*n+5)dis[i] = 1000000000;
    FREP(i,1,n)scanf("%d",&elevtime[i]);
    scanf(" ");
    VI ln2;
    floorelevs.clear();
    FREP(i,0,104)floorelevs.PB(ln2);
    edg.clear(); vector<PII>ln;
    FREP(i,1,100*n+50)edg.PB(ln);
    FREP(i,1,n){
        getline(cin,line);
        parseline(i);
    }
    makeintergraph(n);
}

int dijkstra(int dest, int n){
    set<PII>djkq;
    FREP(i,0,floorelevs[0].size()-1){
        int curelev = floorelevs[0][i];
        djkq.insert(make_pair(0,(curelev-1)*100));
        dis[(curelev-1)*100] = 0;
    }
    while(!djkq.empty()){
        PII cur = *(djkq.begin());
        djkq.erase(djkq.begin());
        int curw = cur.first; int curnode = cur.second;
        FREP(i,0,edg[curnode].size()-1){
            PII nxt = edg[curnode][i];
            int v = nxt.first;
            int w = nxt.second;
            if((curw+w)<dis[v]){
                dis[v] = curw+w;
                djkq.insert(make_pair(dis[v],v));
            }
        }
    }
    int mnans = 1000000000;
    FREP(i,1,n){
        int nn = (i-1)*100+dest;
        mnans = min(dis[nn],mnans);
    }
    return mnans;
}

int main(){
    int n,dest;
    while(scanf("%d %d",&n,&dest)==2){
        takeinp(n);
        int ans = dijkstra(dest,n);
        if(ans==1000000000){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
