#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000009
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define PB push_back
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

VI price;
int bs(int lo, int hi, int val){
    int mid=(lo+hi)/2;
    if(price[mid]<=val){
        if(price[mid+1]>val){
            return mid;
        }
        else{
            return bs(mid+1,hi,val);
        }
    }
    return bs(lo,mid,val);
}
int main(){
    int n;
    scanf("%d",&n);

    price.PB(MNN);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        price.PB(a);
    }
    price.PB(MXX);
    sort(price.begin(),price.end());
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int pp;
        scanf("%d",&pp);
        int idx=bs(0,n+1,pp);
        printf("%d\n",idx);
    }
    return 0;
}
