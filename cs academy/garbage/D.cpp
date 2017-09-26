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
#define LLI unsigned long long int
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

LLI arr[100005];
LLI datas[100005];
LLI cumsum[100005];
LLI compdatas[100005];
LLI cumsum2[100005];
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    FREP(i,1,n){
        cin>>arr[i];
    }
    LLI xx=0;
    FREP(i,1,a){
        xx=xx^arr[i];
    }
    int pos=1;
    datas[pos++]=xx;
    for(int i=2;(i+a-1)<=n;++i){
        xx=xx^arr[i-1];
        xx=xx^arr[i+a-1];
        datas[pos++]=xx;
    }
    FREP(i,1,(pos-1)){
        compdatas[i]=~(datas[i]);
    }
    FREP(i,1,(pos-1)){
        cumsum[i]=cumsum[i-1]+datas[i];
        cumsum2[i]=cumsum2[i-1]+compdatas[i];
    }
    FREP(i,1,pos){
        cout<<datas[i]<<" "<<compdatas[i]<<"\n";
    }
    LLI ss=0;
    FREP(i,1,(pos-1)){
        LLI cur=datas[i];
        LLI curcomp=compdatas[i];
        LLI interval1=i+1;
        LLI interval2=i+(b-a);
        if(interval1<=interval2 && interval2<=(pos-1)){
            LLI ss=cumsum[interval2]-cumsum[interval1-1];
            LLI sscom=cumsum2[interval2]-cumsum2[interval1-1];
            LLI val1=cur*sscom;
            LLI val2=curcomp*ss;
            ss+=(val1+val2);
            ss%=1000000007;
        }

    }
    cout<<ss<<"\n";
}
