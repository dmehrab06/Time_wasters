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

map < pair<PII,int> > statewin;


int solve(int n, int x, int curp){
    if(n==1 || n==2)return curp;
    if(x==0)return (1-curp);
    pair<PII,int>oka=make_pair(make_pair(n,x),curp);
    if(statewin.find(oka)!=statewin.end())return statewin[oka];
    int ret1=solve(n-1,x,1-curp);
    int ret2=solve(n-2,x,1-curp);
    int rem=x/2+x%2;
    int ret3=solve(n,x-rem,1-curp);
    if(ret1==curp || ret2==curp || ret3==curp){
        return statewin[oka]=curp;
    }
    return statewin[oka]=1-curp;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        int ans=solve(n,x,0);
        if(ans==0)printf("Mojo\n");
        else printf("Jojo\n");
    }
    return 0;
}
