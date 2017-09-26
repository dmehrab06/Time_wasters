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
#define VD vector<double>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(int)(N);(i)++)
#define eps 0.0001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGEI(val,l,r) ((l)<=(val) && (val)<=(r))
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;

//-----------------------vector operations-----------------//
//---------------------------------------------------------//
//---------------------------------------------------------//
int A[200000];

int bin(int val, int n){
    int lo = 1;
    int hi = n;
    if(val<A[1])return 0;
    while(true){
        int m = (lo+hi)/2;
        if(A[m]<=val){
            if((m+1)<=n && A[m+1]<=val){
                lo = m+1;
            }
            else{
                return m;
            }
        }
        else{
            hi = m;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        FREP(i,1,n)scanf("%d",&A[i]);
        printf("Case %d:\n",cs++);
        while(q--){
            int l,r;
            scanf("%d %d",&l,&r);
            int idx1=bin(r,n);
            int idx2=bin(l-1,n);
            cout<<idx1<<" "<<idx2<<"\n";
            printf("%d\n",idx1-idx2);
        }
    }
    return 0;
}
