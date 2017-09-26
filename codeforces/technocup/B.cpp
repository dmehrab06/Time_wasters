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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<PII>all;

char dir[200005];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",dir);
    all.PB(make_pair(0,0));
    FREP(i,1,(n)){
        int prevx=all[i-1].first;
        int prevy=all[i-1].second;
        char c=dir[i-1];
        if(c=='R'){
            prevy++;
        }
        else if(c=='L'){
            prevy--;
        }
        else if(c=='U'){
            prevx++;
        }
        else if(c=='D'){
            prevx--;
        }
        all.PB(make_pair(prevx,prevy));
    }
    int cnt=1;
    int prev=0;
    int srcx=0;
    int srcy=0;
    FREP(i,1,n){
        int curx=all[i].first;
        int cury=all[i].second;
        int manhattan=abs(curx-srcx)+abs(cury-srcy);
        if(manhattan>prev){
            prev=manhattan;
        }
        else{
            cnt++;
            prev=1;
            srcx=all[i-1].first;
            srcy=all[i-1].second;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}

