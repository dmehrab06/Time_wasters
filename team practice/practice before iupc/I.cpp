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

stack<int>swamp;

int val[30];

void init(){
    while(!swamp.empty()){
        swamp.pop();
    }
    FREP(i,0,29)val[i]=0;
}

char str[103];

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        init();
        scanf("%s",str);
        int l=strlen(str);
        FREP(i,0,(l-1)){
            int cur=str[i]-'A';
            if(swamp.empty()){
                swamp.push(cur);
            }
            else{
                int ok=swamp.top();
                if(ok==cur){
                    swamp.pop();
                }
                else{
                    val[cur]++;
                    val[ok]++;
                    swamp.push(cur);
                }
            }
        }
        printf("Case %d\n",cs++);
        FREP(i,0,25){
            if(val[i]){
                printf("%c = %d\n",i+'A',val[i]);
            }
        }
    }
    return 0;
}
