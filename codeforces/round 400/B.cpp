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



int arr[100005];

LLI subArraySum( int n, int sum)
{
    map<LLI, int> mp;

    LLI curr_sum = 0;
    LLI tot=0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];

        if (curr_sum == sum)
        {
            tot++;
        }

        if (mp.find(curr_sum - sum) != mp.end())
        {
            tot=tot+mp[curr_sum-sum];
        }

        mp[curr_sum]++;
    }
    return tot;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    FREP(i,0,(n-1)){
        scanf("%d",&arr[i]);

    }
    LLI totans=0;
    if(abs(k)>1){
        for(LLI i=1;i<1000000000000000;i=i*(abs(k))){
            LLI ans=subArraySum(n,i);
            totans+=ans;
        }
    }
    else{
            LLI ans=subArraySum(n,1);
            totans+=ans;

    }
    cout<<totans<<"\n";

    return 0;
}
