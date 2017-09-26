
#include <bits/stdc++.h>
#define LLI long long int
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

vector< pair<int,PII> >oka;

int main(){
    int k,r;
    scanf("%d %d",&k,&r);
    int ans=-1;
    for(int i=1;i<=10;++i){
        int tot=k*i;
        if(tot%10==0 || tot%10==r){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
