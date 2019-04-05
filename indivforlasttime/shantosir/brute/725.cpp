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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

bool isok(int lob, int hor){
    int dig[10]; memset(dig,0,sizeof(dig));
    FREP(i,1,5){
        dig[lob%10] = 1;
        lob/=10;
    }
    FREP(i,1,5){
        dig[hor%10] = 1;
        hor/=10;
    }
    int f = 1;
    FREP(i,0,9)if(dig[i]==0)f=0;
    return (f && !hor && !lob);
}

void solve(int ans, int cs){
    if(cs>1)printf("\n");
    int sol = 0;
    FREP(i,1000,99999){
        int hor = i;
        int lob = hor*ans;
		if(lob>99999)break;
        if(isok(lob,hor)){
            printf("%d / ",lob);
            if(hor<10000)printf("0");
            printf("%d = %d\n",hor,ans);
            sol++;
        }
    }
    if(!sol){
        printf("There are no solutions for %d.\n",ans);
    }
}

int main(){
    int n;
    int cs = 1;
    while(scanf("%d",&n)==1 && n){
        solve(n,cs);
        cs++;
    }
    return 0;
}
