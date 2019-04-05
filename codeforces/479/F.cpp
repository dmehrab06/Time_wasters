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

map<int, set< pair<int,PII> > >gogo;

int arr[200005];
int dp[200005];

pair<int,int> solve(int n){
    int mxans = 0, mxidx = -1;
    RFREP(i,n,1){
        int val = arr[i];
        if(gogo.find(val+1)==gogo.end()){
            int here = 1;
            gogo[val].insert(make_pair(-here,make_pair(i,i)));
            dp[i] = i;
            if(here>mxans){
                mxans = here;
                mxidx = i;
            }
        }
        else{
            int mxx = (*(gogo[val+1].begin())).first;
            int idx1 = (*(gogo[val+1].begin())).second.first;
            //int idx2 = (*(gogo[val+1].begin())).second.second;
            mxx = mxx*(-1);
            gogo[val].insert(make_pair(-(1+mxx),make_pair(i,idx1)));
            dp[i] = idx1;
            if((1+mxx)>mxans){
                mxans = 1+mxx;
                mxidx = i;
            }
        }
    }
    return make_pair(mxans,mxidx);
}

void form(int idx){
    cout<<idx<<" ";
    while(dp[idx]!=idx){
        cout<<dp[idx]<<" ";
        idx = dp[idx];
    }
    cout<<"\n";
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    pair<int,int> ans = solve(n);
    printf("%d\n",ans.first);
    form(ans.second);
    return 0;
}
