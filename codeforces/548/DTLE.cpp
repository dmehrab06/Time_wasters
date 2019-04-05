#include <bits/stdc++.h>
#define eps 1e-9
#define MDD 1000000007

using namespace std;

int rel_prime[100005];
int rel_not_prime[100005];
int rel_same[100005];

vector< set<int> >rel_not_prime_numbers;

long long dp[100005];
long long dphor[100005];

void init(){
    memset(dp,-1,sizeof(dp));
    memset(dphor,-1,sizeof(dphor));
    for(int i = 0; i<=100005+2; ++i){
        set<int>line;
        rel_not_prime_numbers.push_back(line);
    }
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

long long invmod(long long lob, int hor){
    long long h;
    if(dphor[hor]!=-1) h = dphor[hor];
    else{
        dphor[hor] = bigmod(hor,MDD-2);
        h = dphor[hor];
    }
    return (lob*h)%MDD;
}

void pre_calc_rels(int MAXN){
    for(int i = MAXN; i>=1; --i){
        int sq = sqrt(i);
        for(int j = 2; j<=sq; ++j){
            if(i%j==0){
                int d = i/j;
                for(int k = j; k<=MAXN; k+=j){
                    if(__gcd(k,i)<i){
                        rel_not_prime_numbers[i].insert(k);
                    }
                }
                if(d!=j){
                    for(int k = d; k<=MAXN; k+=d){
                        if(__gcd(k,i)<i){
                            rel_not_prime_numbers[i].insert(k);
                        }
                    }
                }
            }
        }
        rel_not_prime[i] = (int)rel_not_prime_numbers[i].size();
    }

    /*for(int i = 1; i<=MAXN; ++i){
        cout<<i<<": ";
        for(auto a: rel_not_prime_numbers[i]){
            cout<<a<<" ";
        }
        cout<<"\n";
    }*/

    for(int i = 1; i<=MAXN; ++i){
        for(int j = i; j<=MAXN; j+=i){
            rel_same[i]++;
        }
    }
    for(int i = 1; i<=MAXN; ++i){
        rel_prime[i] = MAXN- rel_not_prime[i] - rel_same[i];
    }
}

long long solve(int curg, int m){
    if(dp[curg]!=-1)return dp[curg];
    
    int a = rel_prime[curg];
    int b = rel_same[curg];

    long long lob = 0;

    for(auto a: rel_not_prime_numbers[curg]){
        int cur = a;
        int nxtg = __gcd(cur,curg);
        lob = lob+1+solve(nxtg,m);
        lob = lob%MDD;
    }

    lob = lob + a; lob%=MDD;
    lob = lob + b; lob%=MDD;

    int hor = m-b;

    return dp[curg] = invmod(lob,hor);

}
  
// Driver program to test above function 
int main() 
{ 
    init();
    int m;
    scanf("%d",&m);
    pre_calc_rels(m); 
    
    long long ll = 0;
    for(int  i = 1; i<=m; ++i){
        //cout<<"i: "<<i<<"\n";
        ll = solve(i,m) + ll;
        ll = ll%MDD;
    }

    cout<<(invmod(ll,m)+1)%MDD<<"\n";
    return 0; 
}