/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<string>all;

int sz(int k){
    int szz=0;
    int i=0;
    while(all[k][i]!='$'){
        szz++;
        i++;
    }
    return szz;
}

void check(int k){
    int lnxt=sz(k+1);
    int lcur=sz(k);
    //int lstchecked=0;

    FREP(i,0,min(lnxt-1,lcur-1)){
        if(all[k][i]<all[k+1][i]){
            return;
        }
        if(all[k][i]>all[k+1][i]){
            all[k][i]='$';
            break;
        }
    }
    if(lcur>lnxt){
        all[k][lnxt]='$';
    }
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        string s;
        cin>>s;
        all.PB(s);
        all[i-1].PB('$');
    }
    RFREP(i,(n-2),0){
        check(i);
    }
    FREP(i,0,(n-1)){
        int s=sz(i);
        FREP(j,0,(s-1)){
            printf("%c",all[i][j]);
        }
        printf("\n");
    }
}
