/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int l[100005];
int r[100005];

int main(){
    int n;
    scanf("%d",&n);
    int ls=0;
    int rs=0;
    FREP(i,1,n){
        scanf("%d %d",&l[i],&r[i]);
        ls+=l[i];
        rs+=r[i];
    }
    int beauty=abs(ls-rs);
    int mxbeauty=beauty;
    int mxcol=0;
    FREP(i,1,n){
        int currs=rs;
        int curls=ls;
        currs-=r[i];
        currs+=l[i];
        curls-=l[i];
        curls+=r[i];
        int curb=abs(curls-currs);
        if(curb>mxbeauty){
            mxbeauty=curb;
            mxcol=i;
        }
    }
    printf("%d\n",mxcol);
    return 0;
}
