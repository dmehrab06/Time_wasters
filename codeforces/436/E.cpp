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

int dp[2003][103];
int ans[2003][103];
int savetime[103];
int value[103];
int destime[103];
int idex[103];

void init(){
    MSET(dp,-1);
}
int n, mxx= 0;

int solve(int timepassed, int idx){
    if(timepassed==mxx)return 0;
    if(idx>n)return 0;
    if(dp[timepassed][idx]!=-1)return dp[timepassed][idx];

    int ret1 = 0,ret2 = 0;
    if((timepassed+savetime[idx])<destime[idx]){
        ret1 = value[idx]+solve(timepassed+savetime[idx],idx+1);
    }
    ret2 = solve(timepassed,idx+1);
    if(ret1>ret2)ans[timepassed][idx]=1;

    else ans[timepassed][idx]=0;

    return dp[timepassed][idx] = max(ret1,ret2);
}

vector<int>items;

void printpath(int time, int idx){
    if(idx>n)return;
    if(ans[time][idx]){
        items.PB(idex[idx]);
        printpath(time+savetime[idx],idx+1);
    }
    else{
        printpath(time,idx+1);
    }
}

void sortit(int n){
    FREP(i,1,n){
        FREP(j,(i+1),n){
            if(destime[i]>destime[j]){
                swap(destime[i],destime[j]);
                swap(savetime[i],savetime[j]);
                swap(value[i],value[j]);
                swap(idex[i],idex[j]);
            }
        }

    }
}

int main(){
    scanf("%d",&n);
    init();
    FREP(i,1,n){
        scanf("%d %d %d",&savetime[i],&destime[i],&value[i]);
        idex[i]=i;
        mxx = max(destime[i],mxx);
    }
    sortit(n);
    cout<<solve(0,1)<<"\n";
    printpath(0,1);
    cout<<items.size()<<"\n";
    FREP(i,0,items.size()-1){
        cout<<items[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
