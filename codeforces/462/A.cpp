#include <bits/stdc++.h>

using namespace std;

long long a[52];
long long b[52];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    long long ans = 1e18+10;
    for(int i=1;i<=n;++i){
        long long ans1 = -1e18+10;
        cout<<ans1<<"\n";
        for(int j=1;j<=m;++j){
            for(int k=1;k<=n;++k){
                if(k==i)continue;
                long long ans2 = a[k]*b[j];
                ans1 = max(ans2,ans1);
            }
        }
        ans = min(ans,ans1);
    }
    cout<<ans<<"\n";
    return 0;
}
