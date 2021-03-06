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

vector < vector <pair<int,char> > >g;

int dp[30][103][103];

void takeg(int n, int m){
    g.clear();
    FREP(i,1,(n+4)){
        vector< pair<int,char> > line;
        g.PB(line);
    }
    FREP(i,1,m){
        int u,v; char c;
        cin>>u>>v>>c;
        g[u].PB(make_pair(v,c));
    }
}

int solve(int prev, int mxnode, int lucnode){
    //if(g[mxnode].size()==0)return 0;
    //if(g[lucnode].size()==0)return 1;
    if(dp[prev][mxnode][lucnode]!=-1)return dp[prev][mxnode][lucnode];
    int f = 0;
    FREP(i,0,g[mxnode].size()-1){
        int cc = (g[mxnode][i].second-'a')+1;
        if(cc>=prev){
            //cout<<"max is checking by moving from "<<mxnode<<" to "<<g[mxnode][i].first<<"\n";
            int ff = 0;
            FREP(j,0,g[lucnode].size()-1){
                int dd = (g[lucnode][j].second-'a')+1;
                if(dd>=cc){
                    //cout<<"lucas is checking by moving from "<<lucnode<<" to "<<g[lucnode][j].first<<"\n";
                    ff = ff | (1-solve(dd,g[mxnode][i].first,g[lucnode][j].first));
                    if(ff==1){
                        //cout<<"lucas is successful by moving from "<<lucnode<<" to "<<g[lucnode][j].first<<"\n";
                        break;
                    }
                }
            }
            //cout<<"ff = "<<ff<<"\n";
            if(ff==0){
                //cout<<"max is successful by moving from "<<mxnode<<" to "<<g[mxnode][i].first<<"\n";
                f = 1;
                break;
            }
        }
    }
    //cout<<"last letter used "<<(char)(prev+'a'-1)<<" max pos: "<<mxnode<<" lucas pos "<<lucnode<<" then win is "<<(f?"MAX":"LUCAS")<<"\n";
    return dp[prev][mxnode][lucnode] = f;
}

int main(){
    int n,m;
    cin>>n>>m;
    takeg(n,m);
    MSET(dp,-1);
    FREP(i,1,n){
        FREP(j,1,n){
            //cout<<"lets check for "<<i<<","<<j<<"\n";
            solve(0,i,j);
        }
    }
    FREP(i,1,n){
        FREP(j,1,n){
            if(dp[0][i][j]==1){
                printf("A");
            }
            else{
                printf("B");
            }
        }
        printf("\n");
    }
    return 0;
}
