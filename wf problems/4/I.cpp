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

int cont[105][5];

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        FREP(j,1,3){
            scanf("%d",&cont[i][j]);
        }
    }
    //int oka=1;
    FREP(i,1,n){
        int f=1;
        FREP(j,1,n){
            if(i==j)continue;
            int b=0;
            FREP(k,1,3){
                if(cont[i][k]>cont[j][k]){
                    b=1;
                    break;
                }
            }
            if(!b){
                f=0;
                break;
            }
        }
        printf("%s\n",f?"Yes":"No");
    }
    return 0;
}
