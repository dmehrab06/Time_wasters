
#include <bits/stdc++.h>
#define LLI long long int
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

int arr[1003];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    int tot=0;
    for(int i=2;i<=n;++i){
        if((arr[i]+arr[i-1])<k){
            int nd=k-(arr[i]+arr[i-1]);
            arr[i]+=nd;
            tot+=nd;
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
