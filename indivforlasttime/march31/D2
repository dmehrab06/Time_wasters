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

LLI dp[2][1003][1003];
int N;
vector<PII> locs;

LLI solve(int dir, int uneaten, int cur){
    //cout<<"dir: "<<dir<<", uneaten: "<<uneaten<<", cur: "<<cur<<"\n";

    if(dir==0 && uneaten==0 && cur==((int)locs.size()-2))return 0;
    if(dir==1 && uneaten==((int)locs.size()-1) && cur==1)return 0;
    if(dp[dir][uneaten][cur]!=-1)return dp[dir][uneaten][cur];
    LLI ret = 1000000000000;

    pair<int,PII>bestoption = make_pair(-1,make_pair(-1,-1));

    if(dir==0){
        //came from left
        //can go right or left
        //try to go left first, dir will be 1
        if(uneaten>0){
            LLI dif = abs(locs[cur].first-locs[uneaten].first);
            //ret = min(ret, dif+solve(1,cur+1,uneaten));
            //int lleft = uneaten-1; int rleft = (int)locs.size()-1-cur;
            int ret1 = (N-cur+uneaten-1)*dif+solve(1,cur+1,uneaten);
            if(ret1<ret){
                ret = ret1;
                bestoption = make_pair(1,make_pair(cur+1,uneaten));
            }
        }

        //try to go further right

        if(cur<((int)locs.size()-2)){
            LLI dif = abs(locs[cur].first-locs[cur+1].first);
            //ret = min(ret,dif+solve(0,uneaten,cur+1));
            //int lleft = uneaten, rleft = (int)locs.size()-2-cur;
            int ret1 = (N-cur+uneaten-1)*dif+solve(0,uneaten,cur+1);
            if(ret1<ret){
                ret = ret1;
                bestoption = make_pair(0,make_pair(uneaten,cur+1));
            }
        }
    }
    else{
        //came from right
        //can go right or left
        //try to go right first, dir will be 0
        if(uneaten<((int)locs.size()-1)){
            LLI dif = abs(locs[cur].first-locs[uneaten].first);
            //ret = min(ret, dif+solve(0,cur-1,uneaten));
            //int lleft = cur-1, rleft = (int)locs.size()-1-uneaten;
            int ret1 = (N+cur-uneaten-1)*dif+solve(0,cur-1,uneaten);
            if(ret1<ret){
                ret = ret1;
                bestoption = make_pair(0,make_pair(cur-1,uneaten));
            }
        }

        //try to go further left

        if(cur>1){
            LLI dif = abs(locs[cur].first-locs[cur-1].first);
            //ret = min(ret,dif+solve(1,uneaten,cur-1));
            //int lleft = cur-2, rleft = (int)locs.size()-uneaten;
            int ret1 = (N+cur-uneaten-1)*dif+solve(1,uneaten,cur-1);
            if(ret1<ret){
                ret = ret1;
                bestoption = make_pair(1,make_pair(uneaten,cur-1));
            }
        }
    }
    cout<<"best option for dir: "<<dir<<", uneaten: "<<uneaten<<", cur: "<<cur<<" is ";
    cout<<"go to dir: "<<bestoption.first<<" with "<<bestoption.second.first<<" and "<<bestoption.second.second<<" with val ret: "<<ret<<"\n";
    return dp[dir][uneaten][cur]  = ret;
}

int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    N = n;
    locs.PB(make_pair(l,0));
    locs.PB(make_pair(-1000,1));
    locs.PB(make_pair(100000000,1));
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        locs.PB(make_pair(a,1));
    }
    SORTV(locs);
    MSET(dp,-1);
    int pos = -1;
    FREP(i,0,locs.size()-1)if(locs[i].second==0)pos = i;
    locs.erase(locs.begin()+pos);
    //FREP(i,0,locs.size()-1)cout<<locs[i].first<<" "<<locs[i].second<<"\n";
    LLI ans1 = abs(l-locs[pos].first)+solve(0,pos-1,pos);
    cout<<"ans1 is "<<ans1<<"\n";
    LLI ans2 = abs(l-locs[pos-1].first)+solve(1,pos,pos-1);
    cout<<"ans2 is "<<ans2<<"\n";
    printf("%lld\n",min(ans1,ans2));
}
