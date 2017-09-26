/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
#define MXXPRIME 1000004
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI primes[81000]; //[base][digit][startswith]

int smallestdiv[MXXPRIME+1];

int sievearr[MXXPRIME+1];

int totprimes = 0;

void sieve(){
    FREP(i,2,MXXPRIME){
        if(sievearr[i]==0){
            primes[++totprimes]=i;
            smallestdiv[i]=i;
            for(int j = (i+i);j<=MXXPRIME;j+=i){
                sievearr[j]=1;
                if(smallestdiv[j]==0){
                    smallestdiv[j]=i;
                }
            }
        }
    }
}

bool isprime(LLI M){
    if(M==1)return false;
    FREP(i,1,totprimes){
        if(M==primes[i])break;
        if((M>primes[i]) && (M%primes[i]==0))return false;
    }
    return true;
}

pair<LLI,LLI> solve2(LLI N, LLI M){
    if(N>=M)return make_pair(N-M,1);
    return make_pair(N,M);
}

pair<LLI,LLI> solve1(LLI N, LLI M){
    for(int i=1;i<=totprimes;){
        if(M==1){
            break;
        }
        if(M%primes[i]){
            i++;
            continue;
        }
        else{
            if(primes[i]>N){
                return make_pair(N,M);
            }
            else{
                M/=primes[i];
                N-=primes[i];
                if(M%primes[i]==0){
                    return make_pair(N,M);
                }
                i++;
            }
        }
    }
    if(isprime(M)){
        return solve2(N,M);
    }
    return make_pair(N,M);
}

int main(){
    LLI n,m;
    sieve();
    while(cin>>n>>m){
        if(m==1){
            cout<<n<<" "<<m<<"\n";
        }
        else if(isprime(m)){
            pair<LLI,LLI> ans = solve2(n,m);
            cout<<ans.first<<" "<<ans.second<<"\n";
        }
        else{
            pair<LLI,LLI> ans = solve1(n,m);
            cout<<ans.first<<" "<<ans.second<<"\n";
        }
    }
    return 0;
}
