 #include <bits/stdc++.h>


using namespace std;



long long tem,mod = 1e9 + 7,dp[100000+10];

long long dpsum(int n){

tem=0;

for(int i=1;i<=n;++i){
    tem+=dp[i];
    if(tem>=mod){
        tem-=mod;
    }
}
return tem;

}
vector< vector<int> >g;
void dfs(int n,int p=-1){

    dp[n]=1;
    int l=g[n].size();
    for(int i=0;i<l;++i){
        if(g[n][i] != p){

        dfs(g[n][i],n);

        dp[n] += (dp[n] * dp[g[n][i]]);
        if(dp[n] >= mod) dp[n] -= mod;
        }
    }

}
int main(){
    int t;
    scanf("%d",&t);
    int v,x,y;
    while(t--){

        scanf("%d",&v);
        for(int i=1;i<=v;++i){
            dp[i]=0;
        }
        vector<int>line;
        for(int i=0;i<=v;++i){
            g.push_back(line);
        }
        for(int i=0;i<v-1;++i){
            scanf("%d %d", &x , &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(v);
        printf("%lld\n", dpsum(v));
        g.clear();

    }
    return 0;
}


