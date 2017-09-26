/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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

int arr[100005];

int main(){
    int n;
    cin>>n;
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    int mx=1;
    int fp=1;
    int bp=2;
    int shuru=0;
    int need=0;
   // int prev=0; //1 means bp>fp -1 means fp<bp
    int cur=fp;
    for(;bp<=n;){
        if(!shuru){
            if(arr[bp]>arr[fp]){
                shuru=1;
                //prev=1;
                need=-1;
                bp++;
                cur=(bp-1);
            }
            else if(arr[fp]>arr[bp]){
                shuru=1;
                //prev=-1;
                need=1;
                bp++;
                cur=(bp-1);
            }
            else{
                bp++;
                fp=bp-1;
                cur=fp;
            }
        }
        else{
            int now=0;
            if(arr[cur]>arr[bp]){
                now=-1;
            }
            else if(arr[bp]>arr[cur]){
                now=1;
            }
            if(now==need){
               // prev=now;
                need=-now;
                bp++;
                cur=bp-1;
            }
            else{
                int ll=(bp-fp);
                mx=max(ll,mx);
                fp=bp-1;
                cur=fp;
                shuru=0;
            }
        }
    }
    if(shuru){
        mx=max(mx,bp-fp);
    }
    printf("%d\n",mx);
}
