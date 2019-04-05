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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
#define MDD 912
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int todes[1003][1003];
int fromsrc[1003][1003];

void init(int r, int c){
    FREP(i,1,r)todes[i][c] = 1;
    FREP(j,1,c)todes[r][j] = 1;
    RFREP(i,r-1,1){
        RFREP(j,c-1,1){
            todes[i][j] = todes[i+1][j]+todes[i][j+1];
            todes[i][j] %= 912;
        }
    }

    FREP(i,1,r)fromsrc[i][1] = 1;
    FREP(j,1,c)fromsrc[1][j] = 1;
    FREP(i,2,r){
        FREP(j,2,c){
            fromsrc[i][j] = fromsrc[i-1][j]+fromsrc[i][j-1];
            fromsrc[i][j] %= MDD;
        }
    }

}

int query(int r1, int c1, int r2, int c2){
    int forbid = 0;
    FREP(i,r1,r2){
        forbid = forbid + fromsrc[i][c1-1]*todes[i][c1];
        forbid = forbid%MDD;
    }
    FREP(i,c1,c2){
        forbid = forbid + fromsrc[r1-1][i]*todes[r1][i];
        forbid = forbid%MDD;
    }
    return forbid;
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int r,c,q;
        scanf("%d %d %d",&r,&c,&q);
        init(r,c);
        printf("Case %d\n",cs);
        FREP(i,1,q){
            int r1,c1,r2,c2;
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            printf("   Query %d: ",i);
            r1++;c1++;r2++;c2++;
            if(r1==1 && c1==1){printf("0\n");continue;}
            int notgo = query(r1,c1,r2,c2);
            int ans = todes[1][1]-notgo;
            while(ans<0)ans+=MDD;
            printf("%d\n",ans);
        }
    }
    return 0;
}
