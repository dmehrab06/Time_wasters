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

int arr[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int onlyzero=1;
        int onlyone=1;
        FREP(i,1,n){
            scanf("%d",&arr[i]);
            if(arr[i]==1){
                onlyzero=0;
            }
            if(arr[i]==0){
                onlyone=0;
            }
        }
        if(onlyzero || onlyone){
            printf("0\n");
            continue;
        }
        int lftmst0=-1,rghtmst1=-1;
        int lftmst1=-1,rghtmst0=-1;
        int cnt1=0;
        FREP(i,1,n){
            if(lftmst0==-1 && arr[i]==0){
                lftmst0=i;
            }
            if(lftmst1==-1 && arr[i]==1){
                lftmst1=i;
            }
            if(arr[i]==1){
                rghtmst1=i;
                cnt1++;
            }
            if(arr[i]==0){
                rghtmst0=i;
            }
        }
        int oneplace=cnt1;
        int zeroplace=cnt1+1;
        int zeromove=max(0,zeroplace-lftmst0+(lftmst1-(lftmst0+1)));
        int onemove=max(0,rghtmst1-oneplace+((rghtmst1-1)-rghtmst0));
        int mv=max(zeromove,onemove);
        printf("%d\n",mv);
    }
    return 0;
}
