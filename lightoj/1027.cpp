#include<bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define XX first
#define YY second
using namespace std;

int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        int m=0;
        int s=0;
        scanf("%d",&n);
        FREP(i,1,n){
            int a;
            scanf("%d",&a);
            s+=abs(a);
            if(a<0)m++;
        }
        printf("Case %d: ",cs++);
        if(m==n)printf("inf\n");
        else{
            int g=gcd(s,(n-m));
            int a=s/g;
            int b=(n-m)/g;
            printf("%d/%d\n",a,b);
        }
    }
    return 0;
}
