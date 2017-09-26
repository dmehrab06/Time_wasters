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
#define eps 1e-10
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define pi acos(-1.0)
using namespace std;

//pre[mod][initval]

int arr[100005];
int pre[503][503];

void calc(int n){

    FREP(j,1,502){
        FREP(i,0,(n-1))
            pre[j][i%j]+=arr[i];
    }

}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    FREP(i,0,(n-1)){
        scanf("%d",&arr[i]);
    }
    calc(n);
    FREP(i,1,q){
        int mod,val;
        scanf("%d %d",&val,&mod);
        if(val>=mod){
            printf("0\n");
        }
        else if(mod<503){
            printf("%d\n",pre[mod][val]);
        }
        else{
            int s=0;
            for(int i=val;i<n;i+=mod){
                s+=arr[i];
            }
            printf("%d\n",s);
        }
    }
    return 0;
}
