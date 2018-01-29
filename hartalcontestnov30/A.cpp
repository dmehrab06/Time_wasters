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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int BITree[5000005];
vector<int>oka;

int getSum(int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0){
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index, int val)
{
    index = index + 1;
    while (index <= n){
        BITree[index] += val;
        index += index & (-index);
    }
}

int solve(int pos){
    int lo = 1;
    int hi = 5000003;
    //cout<<"solving for: "<<pos<<"\n";
    while(true){
        //cout<<"lo: "<<lo<<" hi: "<<hi<<"\n";
        int mid = (lo+hi)/2;
        int sumhere = getSum(mid);
        if(sumhere<pos)lo=mid+1;
        else if(sumhere>pos)hi=mid;
        else if(sumhere==pos){
            if(mid>1 && (getSum(mid-1)==sumhere)){
                hi = mid;
            }
            else{
                return mid;
            }
        }
    }
}

void init(){
    for(int i=1;i<=5000000;i+=2)updateBIT(5000000,i,1);
    for(int k=2;k<=100000;++k){
        int num = solve(k);
        //cout<<"for "<<k<<": "<<num<<"\n";
        int dec = 0;
        for(int j = num;(j-dec)<=1000000;j+=num){
            int pos = solve(j-dec);
            //cout<<"for "<<j<<": "<<pos<<"\n";
            updateBIT(5000000,pos,-1);
            //cout<<"update hoise\n";
            dec++;
        }
    }
}

int main(){
    init();
    //cout<<"hoise\n";
    int t;
    scanf("%d",&t);
    int cs = 1;
    while(t--){
        int n;
        scanf("%d",&n);
        int ans = solve(n);
        printf("Case %d: %d\n",cs++,ans);
    }
}
