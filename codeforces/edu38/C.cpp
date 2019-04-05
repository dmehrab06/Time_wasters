
#include <bits/stdc++.h>
#define VI vector<int>
#define PB push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;

long long sq[400005];
map<long long,int>squaremap;

pair<long long,long long> findvals(long long x){
    int ss = sqrt(x);
    FREP(i,ss,40000){
        long long nsq = (long long)i*(long long)i;
        long long needval = nsq-x;
        if(squaremap.find(needval)!=squaremap.end()){
            int m = squaremap[needval]; int div = i/m;
            for(int k = (max(1,div-2)); k<=(div+2); ++k)if((i/k)==m)return make_pair(i,k);
        }
    }
    return make_pair(-1,-1);
}

void precalc(){
    FREP(i,1,400000){
        sq[i] = (long long)i*(long long)i;
        squaremap[sq[i]] = i;
    }
}

int main(){
    int t;
    precalc();
    scanf("%d",&t);
    FREP(cs,1,t){
        int x;
        scanf("%d",&x);
        pair<long long,long long> ans = findvals(x);
        if(ans.first==-1)printf("-1\n");
        else printf("%lld %lld\n",ans.first,ans.second);
    }
    return 0;
}
