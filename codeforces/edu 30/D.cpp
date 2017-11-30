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

int kdone=1;

int arr[100005];

void solve(int l, int r, int lnum, int rnum, int k){
    //cout<<"in l: "<<l<<" r: "<<r<<" lnum: "<<lnum<<" rnum: "<<rnum<<"\n";
    if((l+1)==r){
        arr[l]=lnum;
        return;
    }
    if(kdone==k){
        int cur = lnum;
        FREP(i,l,r-1){
            arr[i] = cur;
            cur++;
        }
        return;
    }
    if(kdone>k){
        return;
    }
    if(kdone<k){
        int mid = (l+r)/2;
        int midnum = (lnum+rnum)/2;
        kdone+=2;
        solve(l,mid,midnum+1,rnum,k);
        solve(mid,r,lnum,midnum,k);
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k%2==0){
        cout<<"-1\n";
        return 0;
    }
    solve(0,n,1,n,k);
    if(kdone!=k){
        cout<<"-1\n";
        return 0;
    }
    FREP(i,0,n-1)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
