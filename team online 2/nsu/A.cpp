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

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("Case %d: ",cs++);
        int S=max(x1,(max(x2,max(y1,y2))));
        if((y1-y2)==0){
            printf("0 0 0 %d\n",S);
        }
        else if((y1-y2)<0){
            if((x2-x1)<0){
                printf("0 0 %d %d\n",(y2-y1),(x1-x2));
            }
            else{
                printf("0 %d %d %d\n",S,(y2-y1),S+(x1-x2));
            }
        }
        else{
            if((x2-x1)>0){
                printf("0 0 %d %d\n",(y1-y2),(x2-x1));
            }
            else{
                printf("0 %d %d %d\n",S,(y1-y2),S+(x2-x1));
            }
        }
    }
    return 0;
}
