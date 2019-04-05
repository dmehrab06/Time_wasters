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

int position[1000005];

LLI simulate(int n, int m, int curpos){
    int l = curpos, r = curpos;
    while(l>1 && position[l-1]==position[l])l--;
    while(r<n && position[r+1]==position[r])r++;
    LLI s = 0;
    int lconsider = l-1;
    while(lconsider>=1){
        LLI curdis = abs(position[l]-position[lconsider]);
        for(int ll = lconsider-1; ll>=max(1,lconsider-m+1); ll--){
            curdis+=abs(position[ll]-position[ll+1]);
        }
        lconsider = lconsider-m;
        s = s+curdis*2;
    }
    int rconsider = r+1;
    while(rconsider<=n){
        LLI curdis = abs(position[r]-position[rconsider]);
        for(int rr = rconsider+1; rr<=min(n,rconsider+m-1); rr++){
            curdis+=abs(position[rr]-position[rr-1]);
        }
        rconsider = rconsider+m;
        s = s+curdis*2;
    }
    return s;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        scanf("%d",&position[i]);
    }
    int l = 1;
    int r = n;
    while((r-l)>3){
        int mid1 = (l*2+r)/3; int mid2 = (l+r*2)/3;
        LLI dd1 = simulate(n,m,mid1); LLI dd2 = simulate(n,m,mid2);
        if(dd1<dd2){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    //FREP(i,1,n){
      //  cout<<simulate(n,m,i)<<"\n";
    //}
    LLI ans = 1000000000000000000;
    FREP(i,max(1,l-10),min(n,r+10)){
        ans = min(ans,simulate(n,m,i));
    }
    cout<<ans<<"\n";
    return 0;
}
