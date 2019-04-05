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

string line;

int elevstate[103][103];
int elevtime[103];
LLI dp[103][103];
int vis[103][103];

vector < VI > adj;

void init(){
    MSET(elevstate,0);
    MSET(dp,-1);
    MSET(vis,0);
}

void parseline(int idx){
    int l = line.size();
    int curfloor = 0;
    FREP(i,0,(l-1)){
        if(ISNUM(line[i]))curfloor = curfloor*10+line[i]-'0';
        else{
            elevstate[idx][curfloor] = 1;
            //cout<<"elevator "<<idx<<" can reach "<<curfloor<<"\n";
            adj[idx].PB(curfloor);
            curfloor = 0;
        }
    }
    elevstate[idx][curfloor] = 1;
    //cout<<"elevator "<<idx<<" can reach "<<curfloor<<"\n";
    adj[idx].PB(curfloor);
}

void takeelevstate(int n){
    adj.clear();
    VI ln;
    FREP(i,1,(n+3))adj.PB(ln);
    FREP(i,1,n)cin>>elevtime[i];
    //out<<"done\n";
    scanf(" ");
    FREP(i,1,n){
        getline(cin,line);
        parseline(i);
        cout<<i<<"\n";
    }
}

LLI solve(int curfloor, int lstelev, int dest, int n){
    cout<<"at "<<curfloor<<" "<<lstelev<<"\n";
    vis[curfloor][lstelev]=1;
    if(curfloor==dest)return 0;
    if(dp[curfloor][lstelev]!=-1)return dp[curfloor][lstelev];
    LLI mnn = 1000000000000;
    PII mnelev = make_pair(-1,-1);
    FREP(i,1,n){
        if(elevstate[i][curfloor]==1){
            //elev i stops at this floor;
            if(i!=lstelev){
                //cout<<" found elevator "<<i<<" different\n";
                //switch korbo e
                FREP(j,0,adj[i].size()-1){
                    int nxtstop = adj[i][j];
                    if(vis[nxtstop][i]==0 && (nxtstop!=curfloor)){
                        //cout<<"vis value before setting"<<vis[nxtstop][i]<<"\n";
                        vis[nxtstop][i] = 1;
                        //cout<<"vis value after setting"<<vis[nxtstop][i]<<"\n";
                        //cout<<" going to "<<nxtstop<<" "<<i<<"\n";
                        LLI ret = solve(nxtstop,i,dest,n)+elevtime[i]*abs(curfloor-nxtstop);
                        if(ret<mnn){
                            mnn = ret;
                            mnelev = make_pair(nxtstop,i);
                        }
                    }

                }
            }
        }
    }
    if(mnelev.first!=-1){
        cout<<"answering for "<<curfloor<<" "<<lstelev<<"\n";
        cout<<"optimized for taking elev "<<mnelev.second<<" and going to "<<mnelev.first<<"\n";

    }
    dp[curfloor][lstelev] = (lstelev==0?0:60)+mnn;
    return dp[curfloor][lstelev];
}

int main(){
    int n,dest;
    while(scanf("%d %d",&n,&dest)==2){
        init();
        takeelevstate(n);
        LLI ans = solve(0,0,dest,n);
        printf("%lld\n",ans);
    }
    return 0;
}
