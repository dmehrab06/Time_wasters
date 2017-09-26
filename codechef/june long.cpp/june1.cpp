#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);

    }
    int mx=-1;
    for(int i=1;i<=n;++i){
        mx=max(mx,arr[i]);

    }
    int mn=1000000009;
    for(int i=1;i<=n;++i){
        mn=min(mn,arr[i]);

    }
    for(int i=1;i<=q;++i){
        int a;
        scanf("%d",&a);
        if(a>=mn && a<=mx){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
