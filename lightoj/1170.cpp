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

vector< long long >bstelem;

vector< long long >fact;

void gen(){
    set<long long>bep;
    for(int i = 2; i<=100000; ++i){
        long long cur = (long long)i*(long long)i;
        while(cur<=MAXN){
            bep.insert(cur);
            cur = cur*i;
        }
    }

    set<long long>::iterator it;

    for(it = bep.begin(); it!=bep.end(); ++it){
        bstelem.push_back(*it);
    }

    //printf("done\n");
}

long long bigmod(long long a, long long p){
    if(p==0)return 1L;
    long long ret = bigmod(a,p/2);
    if(p%2==0){
        return (ret*ret)%MDD;
    }
    else{
        return (((a*ret)%MDD)*ret)%MDD;
    }
}

void genfact(int n){
    fact.push_back(1L);
    for(int i = 1; i<=n; ++i){
        long long cur = fact[(int)fact.size()-1];
        cur = cur*i;
        cur = cur%MDD;
        fact.push_back(cur);
    }
}

long long getcatalan(int n){
    long long lob = fact[2*n];
    //cout<<"lob holo: "<<lob<<"\n";
    long long hor = (fact[n+1]*fact[n])%MDD;
    return (lob*(bigmod(hor,MDD-2)))%MDD;
}

int main(){
    gen();
    genfact(2*(int)bstelem.size());
    //cout<<(int)bstelem.size()<<"\n";
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        long long a,b;
        scanf("%lld %lld",&a,&b);
        vector<long long>::iterator it1 = upper_bound(bstelem.begin(),bstelem.end(),b);
        vector<long long>::iterator it2 = upper_bound(bstelem.begin(),bstelem.end(),a-1);
        int tot1 = (int)(it1-it2);
        //cout<<"pawa gese: "<<tot1<<"\n";
        /*int tot2 = 0;
        for(int i = 0; i<(int)bstelem.size(); ++i){
            if(bstelem[i]>=a && bstelem[i]<=b){
                tot2++;
            }
            if(bstelem[i]>b)break;
        }
        cout<<tot1<<" "<<tot2<<"\n";*/
        
        if(tot1==0){
            printf("Case %d: 0\n",cs);    
        }
        else{
            printf("Case %d: %lld\n",cs,getcatalan(tot1));    
        }
    }
    //cout<<getcatalan(2)<<"\n";
    return 0;
}