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
using namespace std;

char target1[100007];
char target2[100007];
char given[100007];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",given);
    target1[0]='r';
    target2[0]='b';
    int until=n-1;
    FREP(i,1,(n-1)){
        if(target1[i-1]=='r'){
            target1[i]='b';
        }
        else{
            target1[i]='r';
        }
        if(target2[i-1]=='r'){
            target2[i]='b';
        }
        else{
            target2[i]='r';
        }
    }
    //try to reach target1 from front
    if(n%2){
        target1[n]='b';
        target2[n]='r';
        if(given[n-1]=='r'){
            given[n]='b';
        }
        else{
            given[n]='r';
        }
        until++;
    }
    int rr=0;
    int bb=0;
    int br=0;
    int rb=0;
    for(int i=0;i<=until;i+=2){
        if(given[i]=='r' && given[i+1]=='b'){
            rb++;
        }
        else if(given[i]=='b' && given[i+1]=='r'){
            br++;
        }
        else if(given[i]=='r' && given[i+1]=='r'){
            rr++;
        }
        else{
            bb++;
        }
    }
    int mx=max(rr,bb);
    int mv1=mx;
    int mv2=rb;
    int mv3=br;
    int ans1=mv1+mv2;
    int ans2=mv1+mv3;
    cout<<min(ans1,ans2)<<"\n";
    return 0;
}
