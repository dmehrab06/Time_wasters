/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
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

pair<double,int> arra[100005];
pair<double,int> arrb[100005];
pair<int,int> a[100005];
pair<int,int> b[100005];
pair<double,int>tot[100005];


int main(){
    int n;
    scanf("%d",&n);
    LLI totala=0;
    FREP(i,1,n){
        scanf("%d",&a[i].first);
        a[i].second=i;
        totala+=a[i].first;
    }
    LLI totalb=0;
    FREP(i,1,n){
        scanf("%d",&b[i].first);
        b[i].second=i;
        totalb+=b[i].first;
    }
    FREP(i,1,n){
        arra[i].first=(double)a[i].first/(double)totala;
        arra[i].second=i;
        arrb[i].first=(double)b[i].first/(double)totalb;
        arrb[i].second=i;
        tot[i].first=arra[i].first+arrb[i].first;
        tot[i].second=i;
    }
    sort(tot+1,tot+1+n);
    int pick=n/2+1;
    printf("%d\n",pick);
    vector<int>idx;
    RFREP(i,n,(n-pick+1)){
        idx.PB(tot[i].second);
    }
    SORTV(idx);
    int l=idx.size();
    FREP(i,0,(l-1)){
        printf("%d ",idx[i]);
    }
    printf("\n");
    return 0;
}
