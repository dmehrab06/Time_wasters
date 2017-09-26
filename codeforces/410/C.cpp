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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
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

LLI arr[100005];

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int n;
    cin>>n;
    FREP(i,1,n){
        cin>>arr[i];
    }
    cout<<"YES\n";
    LLI gg=gcd(arr[1],arr[2]);
    FREP(i,3,n){
        gg=gcd(gg,arr[i]);
    }
    if(gg>1){
        cout<<"0\n";
        return 0;
    }
    int op=0;
    FREP(i,1,(n-1)){
        if((abs(arr[i])%2) && (abs(arr[i+1])%2)){
            LLI t1=arr[i];
            LLI t2=arr[i+1];
            arr[i]=t1-t2;
            arr[i+1]=t1+t2;
            op++;
        }
    }
    gg=gcd(abs(arr[1]),abs(arr[2]));
    FREP(i,3,(n)){
        gg=gcd(gg,abs(arr[i]));
    }
    if(gg>1){
        cout<<op<<"\n";
        return 0;
    }
    FREP(i,1,n){
        if(abs(arr[i])%2){
            op+=2;
        }
    }
    cout<<op<<"\n";
    return 0;
}
