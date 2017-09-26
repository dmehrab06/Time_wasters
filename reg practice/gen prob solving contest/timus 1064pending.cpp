#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
#define MNN -MXX
#define DBL double
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
using namespace std;

LLI twopow[67];

int bs(int get, int N, int it){
    int l=0;
    int r=N-1;
    int cnt=0;
    while(l<=r){
        int mid=(l+r)/2;
        cnt++;
        if(mid==get){
            return cnt==it?1:0;
        }
        if(get<mid){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return 0;
}

int bs(LLI x){
    if(x==1)return 0;
    int l=0;
    int h=66;
    while(true){
        int m=(l+h)/2;
        if(twopow[m]>=x){
            if(twopow[m-1]<x){
                return m;
            }
            else{
                h=m;
            }
        }
        else{
            l=m+1;
        }
    }
}
int ans1[100004];
int ans2[100004];
int main(){
    //int t;
    int get,pos;

    while(scanf("%d %d",&get,&pos)==2){
        bool f=0;
        bool s=0;
        int fp,sp;
        int sz=0;
        FREP(x,1,10000){
            if(bs(get,x,pos)){
                if(!f){
                    fp=x;
                    sp=x;
                    f=1;
                    s=1;
                }
                else{
                    sp=x;
                    s=1;
                }
            }
            else{
                if(s & f){
                    ans1[sz]=fp;
                    ans2[sz]=sp;
                    sz++;
                    f=0;
                    s=0;
                }
            }
        }
        if(s & f){
            ans1[sz]=fp;
            ans2[sz]=sp;
            sz++;
            f=0;
            s=0;
        }
        printf("%d\n",sz);
        FREP(i,0,(sz-1)){
            printf("%d %d\n",ans1[i],ans2[i]);
        }
    }
    //int cs=1;
    return 0;
}
