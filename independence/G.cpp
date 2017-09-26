/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

int poss[66];

int main(){
    memset(poss,-1,sizeof(poss));
    string meh;
    cin>>meh;
    int ll=meh.size();
    FREP(i,0,(ll-1)){
        if(meh[i]=='h'){
            if(poss[0]==-1){
                poss[0]=i;
            }
        }
        if(meh[i]=='e'){
            if(poss[1]==-1){
                poss[1]=i;
            }
        }
        if(meh[i]=='l'){
            if(poss[2]==-1){
                poss[2]=i;
            }
            else if(poss[3]==-1){
                poss[3]=i;
            }
        }
        if(meh[i]=='o'){
            if(poss[4]==-1){
                poss[4]=i;
            }
        }

    }
    FREP(i,0,4){
        if(poss[i]==-1){
            printf("NO\n");
            return 0;
        }
    }
    FREP(i,1,4){
        if(poss[i]<=poss[i-1]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
