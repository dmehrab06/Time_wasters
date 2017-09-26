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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define LEFT 1
#define RIGHT 2
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int dp[20][3];

int leftmostlight[20];
int rightmostlight[20];
int haslight[20];

int lastfloor;

int n,m;

void init(){
    memset(haslight,0,sizeof(haslight));
    memset(dp,-1,sizeof(dp));
}

int solve(int curfloor, int stair){
    if(curfloor==n)return 0;
    if(dp[curfloor][stair]!=-1)return dp[curfloor][stair];
    int curtime = 0;
    int curpos = (stair==LEFT?1:m+2);
    if(haslight[curfloor]==1){
        if(stair==LEFT){
            curtime = rightmostlight[curfloor]-1;
            curpos = rightmostlight[curfloor];
        }
        else if(stair==RIGHT){
            curtime = (m+2)-leftmostlight[curfloor];
            curpos = leftmostlight[curfloor];
        }
    }
    if(curfloor==lastfloor)return dp[curfloor][stair]=curtime;
    int t1 = curpos; int ret1 = solve(curfloor+1,LEFT);
    int t2 = (m+3)-curpos; int ret2 = solve(curfloor+1,RIGHT);
    return dp[curfloor][stair] = min(curtime+t1+ret1,curtime+t2+ret2);

}


int main(){
    while(cin>>n>>m){
        init();
        int f = 0;
        lastfloor = 0;
        RFREP(i,n,1){
            string lightstate;
            cin>>lightstate;
            int lftmstlight = 203;
            int rghtmstlight = -1;
            FREP(j,0,(m+1)){
                if(lightstate[j]=='1'){
                    lftmstlight = min(j+1,lftmstlight);
                    rghtmstlight = max(j+1,rghtmstlight);
                }
            }
            if(rghtmstlight>=lftmstlight){
                lastfloor = max(lastfloor,i-1);
                f = 1;
                haslight[i-1]=1;
                leftmostlight[i-1]=lftmstlight;
                rightmostlight[i-1]=rghtmstlight;
            }
        }
        if(!f){
            cout<<"0\n";
            return 0;
        }

        int ans = solve(0,LEFT);
        cout<<ans<<"\n";
    }
    return 0;
}
