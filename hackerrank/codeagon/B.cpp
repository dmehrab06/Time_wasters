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
#define MDD 1000003
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

PII crate[30];

LLI mxval(int msk, int cap, int n){
    vector<PII>info;
    int mymsk=1;
    FREP(i,1,n){
        if(mymsk&msk){
            info.PB(make_pair(crate[i].second,crate[i].first));
        }
        mymsk<<=1;
    }
    SORTV(info);
    REVV(info);
    LLI took=0;
    FREP(i,0,(n-1)){
        int match=info[i].first;
        int cantake=min(cap,info[i].second);
        took=took+match*cantake;
        cap-=cantake;
    }
    return took;

}

int main(){
    int n,c;
    cin>>n>>c;
    FREP(i,1,c){
        scanf("%d %d",&crate[i].first,&crate[i].second);
    }
    FREP(i,1,c){
        swap(crate[i].first,crate[i].second);
    }
    sort(crate+1,crate+1+c);
    LLI s=0;
    RFREP(i,c,1){
        if(n==0)break;
        int match=crate[i].first;
        int boxase=crate[i].second;
        int cantake=min(n,boxase);
        s+=(cantake*match);
        n-=cantake;
    }

    cout<<s<<"\n";
    return 0;
}
