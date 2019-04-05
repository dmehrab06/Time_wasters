#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MAXN 1e10L
#define MAXIT 20
#define MDD 100000007

using namespace std;
using namespace __gnu_pbds;

typedef tree < pair<int,int>, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<long long>sticks;

long long find(long long a, long long b){
    //cout<<"finding for "<<a<<" "<<b<<"\n";
    vector<long long>::iterator it1;
    vector<long long>::iterator it2;
    
    long long l = b-a;
    long long u = b+a;

    int pos1 = (int)(lower_bound(sticks.begin(),sticks.end(),l+1)-sticks.begin());
    int pos2 = (int)(lower_bound(sticks.begin(),sticks.end(),u)-sticks.begin())-1;

    int ase = (pos2-pos1+1);

    //cout<<pos1<<" "<<pos2<<"\n";

    int lpos = sticks[pos1];
    int upos = sticks[pos2];

    if(a>=lpos && a<=upos)ase--;
    if(b>=lpos && b<=upos)ase--;

    return max((long long)0,(long long)ase);
}


int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        sticks.clear();
        sticks.push_back(-1);
        sticks.push_back(30000000000);
        
        int n;
        scanf("%d",&n);

        for(int i = 0; i<n; ++i){
            long long sz;
            scanf("%lld",&sz);
            sticks.push_back(sz);
        }

        sort(sticks.begin(),sticks.end());

        long long cnt = 0;

        for(int i = 1; i<(int)sticks.size()-1; ++i){
            for(int j = (i+1); j<(int)sticks.size()-1;++j){
                cnt = cnt + find(sticks[i],sticks[j]);
            }
        }
        
        printf("Case %d: %lld\n",cs,cnt/3);    
    }
    //cout<<getcatalan(2)<<"\n";
    return 0;
}