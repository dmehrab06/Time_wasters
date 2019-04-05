#include <bits/stdc++.h>
#define MDD 100000007
using namespace std;

map < long long, int > rhs;

int invmod[100005];

long long bigmod(long long base, long long p){
    if(p==0)return 1;
    long long ret = bigmod(base,p/2);

    if(p%2==0){
        return (ret*ret)%MDD;
    }

    else{
        return (((base*ret)%MDD)*ret)%MDD;
    }
}

void init(int k){
    int sq = sqrt(MDD);
    long long p = 1;
    for(int i = 0; i<=sq; ++i){
        long long inv = bigmod(p,MDD-2);
        invmod[i] = inv;
        p = p*k;
        p = p%MDD;
    }

}

long long solve(int result, int k){
    rhs.clear();
    int sq = sqrt(MDD);

    for(int i = 0; i<=sq; ++i){
        long long cur = (long long)invmod[i]*result;
        cur = cur%MDD;
        rhs[cur] = i;
    }   

    long long f = bigmod(k,sq);
    long long kp = 1;
    for(int i = 0; i<=sq; ++i){
        if(rhs.find(kp)!=rhs.end()){
            int j = rhs[kp];
            return (long long)i*sq+j;
        }
        kp = kp*f;
        kp = kp%MDD;
    }
    return -1;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int k,result;
        scanf("%d %d",&k,&result);
        init(k);
        printf("Case %d: %lld\n",cs,solve(result,k));
    }
    return 0;
}