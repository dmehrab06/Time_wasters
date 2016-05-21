#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int dp[5070][5003];
int n;
int weight[5070];
int strength[5070];
int maxstack(int frog, int wavail){
    if(frog==0){
        return 0;
    }
    if(dp[frog][wavail]!=-1){
        return dp[frog][wavail];
    }
    int ret1=0,ret2;
    if(weight[frog]<=wavail){
        ret1=1+maxstack(frog-1,min(wavail-weight[frog],strength[frog]-weight[frog]));
    }
    ret2=maxstack(frog-1,wavail);
    dp[frog][wavail]=max(ret1,ret2);
    return dp[frog][wavail];
}

struct frg{
    int w;
    int s;
    frg(int wt,int st){
        w=wt;
        s=st;
    }
};

bool mycompare(frg a, frg b){
    return (a.s-a.w)<(b.s-b.w);
}
int main()
{
   for(int i=0;i<5070;++i){
    for(int j=0;j<5003;++j){
        dp[i][j]=-1;
    }
   }
   //int n;
   //cin>>n;
   //int t=n;
   vector<frg>allfrogs;
    int a,b;
   while(scanf("%d %d",&a,&b)==2){
    frg f(a,b);
    allfrogs.push_back(f);
   }
   sort(allfrogs.begin(),allfrogs.end(),mycompare);
   int l=allfrogs.size();
   int mxs=-1;
   for(int i=0;i<l;++i){
    weight[i+1]=allfrogs[i].w;
    strength[i+1]=allfrogs[i].s;
    if(strength[i+1]>mxs){
        mxs=strength[i+1];
    }
   }
   n=l;
   int ans=maxstack(n,mxs);
   cout<<ans<<"\n";
  return 0;
}
