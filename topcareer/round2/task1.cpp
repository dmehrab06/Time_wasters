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

map<int,int>compresser;
int arr[100005];
int anss[100005];
LLI btree[600005];

void update(int idx,int val)
{
   while(idx<=600004)
   {
       btree[idx]+=val;
       btree[idx]%=1000000007;
       idx+=(idx & -idx);
   }
}

LLI sum(int idx)
{
    LLI sm=0;
    while(idx>0)
    {
       sm+=btree[idx];
       sm%=1000000007;
       idx-=(idx & -idx);
    }
    return sm;
}

int solution(vector<int> &A) {
    set<int>mm;
    FREP(i,0,A.size()-1){
        mm.insert(A[i]);
        arr[i]=A[i];
    }
    set<int>::iterator it;
    int tt = 1;
    for(it = mm.begin(); it!=mm.end();++it){
        int val  =*it;
        compresser[val]=tt;
        tt++;
    }
    FREP(i,0,A.size()-1){
        int curvv = compresser[arr[i]];
        LLI val = sum(curvv-1);
        LLI ans = val+1;
        ans%=1000000007;
        update(curvv,ans);
        anss[i]=ans;
    }
    LLI ans = 0;
    FREP(i,0,A.size()-1){
        ans += anss[i];
        ans%=1000000007;
    }
    return ans-A.size();
    // write your code in C++14 (g++ 6.2.0)
}

int main()
{
    vector<int>A={4};
    cout<<solution(A)<<"\n";
   return 0;
}
