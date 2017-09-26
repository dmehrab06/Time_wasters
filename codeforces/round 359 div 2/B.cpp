#include <bits/stdc++.h>

using namespace std;

//int xpointsexist[200005];



int main(){
    vector<int>allnums;
    vector<int>sortednums;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        allnums.push_back(a);
        sortednums.push_back(a);
    }
    sort(sortednums.begin(),sortednums.end());
    for(int i=0;i<n;++i){
        int cur=sortednums[i];
        int idx=-1;
        for(int j=i;j<n;++j){
            if(allnums[j]==cur){
                idx=j;
                break;
            }
        }
        int curi=idx;
        int previ=idx-1;
        while(curi!=i){
            printf("%d %d\n",previ+1,curi+1);
            int t=allnums[previ];
            allnums[previ]=allnums[curi];
            allnums[curi]=t;
            curi--;
            previ--;
        }
    }
    //cout<<x<<" "<<dis<<"\n";
    return 0;
}
