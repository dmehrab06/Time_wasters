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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector< pair<PII,int> > knightpow;
set< pair<PII,int> > coinset;
LLI ans[100005];
LLI interans[100005];

int main(){
    MSET(interans,-1);
    int n,k;
    scanf("%d %d",&n,&k);
    FREP(i,0,n-1){
        int p;
        scanf("%d",&p);
        pair<PII,int>knight = make_pair(make_pair(p,-1),i);
        knightpow.PB(knight);
    }
    FREP(i,0,n-1){
        int coin;
        scanf("%d",&coin);
        knightpow[i].first.second = coin;
        ans[i] = coin;
    }
    SORTV(knightpow);
    FREP(i,0,n-1){
        pair<PII,int>knight2 = make_pair(make_pair(-knightpow[i].first.second,knightpow[i].first.first),knightpow[i].second);
        coinset.insert(knight2);
    }
    RFREP(i,knightpow.size()-1,0){
        int kid = knightpow[i].second;
        int kknightpow = knightpow[i].first.first;
        int kcoin = knightpow[i].first.second;
        pair<PII,int>tofind = make_pair(make_pair(-kcoin,kknightpow),kid);
        //cout<<"searching for\n";
        //cout<<tofind.first.first<<" "<<tofind.first.second<<" "<<tofind.second<<"\n";
        if(coinset.find(tofind)==coinset.end()){
          //  cout<<"wrong\n";
        }
        else{
            coinset.erase(tofind);
        }
        if( (i==0) || (i>0 && knightpow[i-1].first.first<kknightpow)){
           // cout<<"checking for "<<kid<<"\n";
            int cnt = 0;
            LLI steal = 0;
            set< pair<PII,int> >::iterator it;
            for(it = coinset.begin();it!=coinset.end();++it){
                if(cnt>=k)break;
                pair<PII,int>killknight = *it;
                LLI val = -killknight.first.first;
                LLI killid = killknight.second;
               // cout<<"will kill "<<killid<<" take "<<val<<" coins\n";
                steal+=val;
                cnt++;
            }
            interans[i] = steal;
        }
    }
    LLI lastval = -1;
    FREP(i,0,n-1){
        if(interans[i]!=-1){
            lastval = interans[i];
        }
        else{
            interans[i] = lastval;
        }
    }
    FREP(i,0,n-1){
        int kid = knightpow[i].second;
        LLI get = interans[i];
        ans[kid] += get;
    }
    FREP(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
