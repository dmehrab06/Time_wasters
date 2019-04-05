/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

pair<int,LLI> dp[64][32][32][26];

char a[32];
char b[32];

void init(){MSET(dp,-1);
    //for(int i = 0;i<20;++i)for(int j = 0;j<20;++j)for(int k = 0;k<20;++k)for(int l = 0;l<20;++l)cout<<dp[i][j][k][l].first<<" "<<dp[i][j][k][l].second<<"\n";
}


pair<int,LLI> solve(int cur, int amatched, int bmatched, int let, int alen, int blen){
    if((amatched+bmatched)==(alen+blen))return make_pair(cur,(LLI)1);
    if(dp[cur][amatched][bmatched][let].first!=-1)return dp[cur][amatched][bmatched][let];
    int alet = -1, blet = -1;
    if(amatched<alen)alet = a[amatched]-'A';
    if(bmatched<blen)blet = b[bmatched] - 'A';
    pair<int,LLI> ret = make_pair(10000,0);
    if(blet==alet){
        pair<int,LLI> ret1 = solve(cur+1,amatched+1,bmatched+1,alet,alen,blen);
        if(ret1.first<ret.first){
            ret = ret1;
        }
        else if(ret1.first==ret.first){
            ret.second+=ret1.second;
        }
    }
    else{
        if(alet!=-1){
            pair<int,LLI> ret1 = solve(cur+1,amatched+1,bmatched,alet,alen,blen);
            if(ret1.first<ret.first)ret = ret1;
            else if(ret1.first==ret.first)ret.second+=ret1.second;
        }

        if(blet!=-1){
            pair<int,LLI> ret1 = solve(cur+1,amatched,bmatched+1,blet,alen,blen);
            if(ret1.first<ret.first)ret = ret1;
            else if(ret1.first==ret.first)ret.second+=ret1.second;
        }

    }
    return dp[cur][amatched][bmatched][let] = ret;
}

int main(){
    int T;
    scanf("%d",&T);
    FREP(cs,1,T){
        init();
        scanf("%s %s",a,b);
        int la = strlen(a); int lb = strlen(b);
        pair<int,LLI> ans = solve(0,0,0,0,la,lb);
        printf("Case %d: %d %lld\n",cs,ans.first,ans.second);
    }
    return 0;
}
