#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MAXN 10003
#define MAXIT 20

using namespace std;
using namespace __gnu_pbds;

typedef tree < pair<int,int>, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<long long>v1;
vector<long long>v2;

int arr1[20];
int arr2[20];

void gen(int v1_sz, int v2_sz, long long W){
    int mask1 = (1<<v1_sz);
    int mask2 = (1<<v2_sz);

    for(int i = 0; i<mask1; ++i){
        long long tot_w = 0;
        for(int j = 0; j<v1_sz; ++j){
            if(i&(1<<j)){
                tot_w = tot_w + arr1[j];
            }
        }
        v1.push_back(tot_w);
    }

    for(int i = 0; i<mask2; ++i){
        long long tot_w = 0;
        for(int j = 0; j<v2_sz; ++j){
            if(i&(1<<j)){
                tot_w = tot_w + arr2[j];
            }
        }
        v2.push_back(tot_w);
    }

    //cout<<"hoise\n";

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
}

long long calc(long long W){
    long long combination = 0;
    for(int i = 0; i<(int)v1.size(); ++i){
        long long cur = v1[i];
        long long can = (W-v1[i]);
        if(v2[0]>can){
            continue;
        }
        if(v2[(int)v2.size()-1]<=can){
            combination = combination + (int)v2.size();
            continue;
        }
        int ase = (int)(upper_bound(v2.begin(),v2.end(),can)-v2.begin());
        combination = combination+ase;
    }
    return combination;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        v1.clear();
        v2.clear();
        int n,W;
        scanf("%d %d",&n,&W);
        int ordhek = n/2;
        int bakiordhek = n-ordhek;
        for(int i = 0; i<ordhek; ++i){
            scanf("%d",&arr1[i]);
        }
        for(int i = 0; i<bakiordhek; ++i){
            scanf("%d",&arr2[i]);
        }
        if(n==1){
            if(arr2[0]<=W){
                printf("Case %d: 2\n",cs);
            }
            else{
                printf("Case %d: 1\n",cs);
            }
        }
        else{
            gen(ordhek,bakiordhek,W);
            long long ans = calc(W);
            printf("Case %d: %lld\n",cs,ans);    
        }
        
    }
    return 0;
}