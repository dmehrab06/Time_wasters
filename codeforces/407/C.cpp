/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI arr1[100005];
LLI arr2[100005];
LLI arr[100005];
LLI diff[100005];


LLI maxSubArraySum1(int tot)
{
   LLI max_so_far = 0, max_ending_here = 0;
   for (int i = 1; i <= tot; i++)
   {
       max_ending_here = max_ending_here + arr1[i];
       if (max_ending_here < 0)
           max_ending_here = 0;

       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

LLI maxSubArraySum2(int tot)
{
   LLI max_so_far = 0, max_ending_here = 0;
   for (int i = 1; i <= tot; i++)
   {
       max_ending_here = max_ending_here + arr2[i];
       if (max_ending_here < 0)
           max_ending_here = 0;

       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        cin>>arr[i];
    }
    FREP(i,1,(n-1)){
        diff[i]=abs(arr[i]-arr[i+1]);
    }
    FREP(i,1,(n-1)){
        LLI val=diff[i];
        if(i%2){
            val=val*(-1);
        }
        arr1[i]=val;
    }
    FREP(i,1,(n-1)){
        LLI val=diff[i];
        if(i%2==0){
            val=val*(-1);
        }
        arr2[i]=val;
    }
    LLI ans1=maxSubArraySum1(n-1);
    LLI ans2=maxSubArraySum2(n-1);
    cout<<max(ans1,ans2)<<"\n";
}
