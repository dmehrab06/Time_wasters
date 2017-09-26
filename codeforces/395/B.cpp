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

int arr[200005];

int ans[200005];

int idx[200005];

void createoddidx(int n){
    if(n==1){
        idx[1]=1;
    }
    int oddcount=1;
    for(int i=n;i>=1;i-=2){
        idx[i]=oddcount;
        oddcount+=2;
    }
    int evencount=2;
    for(int i=2;i<=n;i+=2){
        idx[i]=evencount;
        evencount+=2;
    }
    FREP(i,1,n){
        int id=idx[i];
        int val=arr[i];
        ans[id]=val;
    }
    FREP(i,1,n){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

void createevenidx(int n){
    int oddcount1=1;
    int oddcount2=n-1;
    for(int i=n;i>(n/2);i--){
        if(i%2==0){
            idx[i]=oddcount1;
            oddcount1+=2;
        }
        else{
            idx[i]=oddcount2;
            oddcount2-=2;
        }
    }
    int evencount1=n;
    int evencount2=2;
    for(int i=1;i<=(n/2);i++){
        if(i%2==0){
            idx[i]=evencount2;
            evencount2+=2;
        }
        else{
            idx[i]=evencount1;
            evencount1-=2;
        }
    }
    FREP(i,1,n){
        int id=idx[i];
        int val=arr[i];
        ans[id]=val;
    }
    FREP(i,1,n){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    if(n%2){
        createoddidx(n);
    }
    else{
        createevenidx(n);
    }
    return 0;
}
