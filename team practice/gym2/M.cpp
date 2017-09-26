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

int ase[105];
int unit[105];
int lagbe[105];
int cost[105];

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n)scanf("%d",&ase[i]);
    FREP(i,1,n)scanf("%d",&unit[i]);
    FREP(i,1,n)scanf("%d",&cost[i]);
    int mx=0;
    FREP(i,1,n){
        int here=(ase[i]/unit[i])+(ase[i]%unit[i]?1:0);
        if(here>mx)mx=here;
    }
    FREP(i,1,n){
        lagbe[i]=mx*unit[i];
        lagbe[i]-=ase[i];
    }
    int tot=0;
    FREP(i,1,n){
        tot+=lagbe[i]*cost[i];
    }
    printf("%d\n",tot);
    return 0;
}
