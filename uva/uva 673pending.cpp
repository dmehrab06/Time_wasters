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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

int solve(int n, int k){
    if(k==1)return n;
    int D=1;
    int a=(k-1)*n;
    while(D<=a){
        int p=(D*k);
        int q=p/(k-1);
        if(p%(k-1))q++;
        D=q;
    }
    return k*n+1-D;
}

int main(){
    int t;
    scanf("%d",&t);
    char s[32];
    while(t--){
        scanf("%s",s);
        vector<char>match;
        int l=strlen(s);
        int sz=0;
        int f=1;
        FREP(i,0,l-1){
            if(s[i]=='(' || s[i]=='['){
                match.push_back(s[i]);
                sz++;
            }
            else{
                if(s[i]==')'){
                    if(sz>0 && match[sz-1]=='('){
                        match.pop_back();
                        sz--;
                    }
                    else{
                        f=0;
                        break;
                    }
                }
                else if(s[i]==']'){
                    if(sz>0 && match[sz-1]=='['){
                        match.pop_back();
                        sz--;
                    }
                    else{
                        f=0;
                        break;
                    }
                }
            }
        }
        if(f && match.size()==0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        //printf("Case %d: %d\n",cs++,solve(n,k));
    }
    return 0;
}
