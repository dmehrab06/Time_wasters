#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>ans;
vector<int>list;
bool f=false;
int n,s,k;
bool check(){
   // cout<<"checking for vector\n";
   // for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    //cout<<"\n";
    if(ans.size()!=n)return false;
    int ss=0;
    for(int i=0;i<n;++i){
        ss+=ans[i];
    }
    if(s!=ss)return false;
    int dif=0;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            dif+=abs(ans[i]-ans[j]);
        }
    }
    if(dif!=k)return false;
    return true;
}

void dfs(int deep, int cur){
    if(f)return;
    //cout<<"in "<<deep<<" cur "<<cur<<"\n";
    ans.push_back(cur);
    if(deep==n){
        if(check()){
          //  cout<<"check hoise\n";
            list=ans;
            f=true;
            //ans.pop_back();
            //return;
        }
      //  cout<<"check hoise\n";
        //ans.pop_back();
        //return;
    }
    if(deep<n){
        for(int i=cur;i<=s;++i){
            dfs(deep+1,i);
            if(f)break;
        }
    }
    //if(f)return;
    ans.pop_back();
    //return ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&n,&s,&k);
      //  cout<<"hoise1\n";
        ans.clear();
        list.clear();
        dfs(1,0);
      //  printf("hoise\n");
        if(!f){
            printf("-1\n");
        }
        else{
            for(int i=0;i<n;++i){
                printf("%d ",list[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
