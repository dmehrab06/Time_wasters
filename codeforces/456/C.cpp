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

struct enemy{
    LLI init_hp, max_hp, regen;
    vector<pair<LLI,LLI>>update;

    enemy(){
        init_hp = 0, max_hp = 0, regen = 0;
    }

    enemy(LLI _i , LLI _m, LLI _r){
        init_hp = _i;
        max_hp = _m;
        regen = _r;
    }

    LLI curhp(LLI moment){
        if(update.size()==0 || (update[0].first>moment)){
            return min(max_hp,init_hp+moment*regen);
        }
        pair<LLI,LLI>dummy = make_pair(moment+1,-1);
        vector<pair<LLI,LLI>>::iterator it;
        it = upper_bound(update.begin(),update.end(),dummy);
        pair<LLI,LLI>latest = *it;
        LLI lattime = latest.first; LLI hp = latest.second;
        return min(max_hp,hp+(moment-lattime)*regen);
    }

};

enemy allenemys[100005];
LLI healthinfo[100005];

void getinfoatmoment(LLI moment, int tot_enemy){
    FREP(i,1,tot_enemy){
        healthinfo[i] = allenemys[i].curhp(moment);
       cout<<"health of enemy "<<i<<" at "<<moment<<" is "<<healthinfo[i]<<"\n";
    }
}

void takeenemy(int n){
    FREP(i,1,n){
        int m,it,r;
        scanf("%d %d %d",&m,&it,&r);
        enemy e(it,m,r);
        allenemys[i] = e;
    }
}

void takeupdates(int m, int tot){
    FREP(i,1,m){
        int t,e,h;
        scanf("%d %d %d",&t,&e,&h);
        allenemys[e].update.push_back(make_pair(t,h));
    }
    FREP(i,1,tot){
        SORTV(allenemys[i].update);
    }
}

int killcount(LLI moment, int tot, LLI damage){
    getinfoatmoment(moment,tot);
    int cnt = 0;
    FREP(i,1,tot){
        if(damage>=healthinfo[i])cnt++;
    }
    return cnt;
}

LLI profit(LLI bounty, LLI increase, LLI damage, LLI moment, int tot){
    return (LLI)killcount(moment,tot,damage)*(bounty+moment*increase);
}

int main(){
    int n,m;
    LLI bounty,damage,increase;
    cin>>n>>m>>bounty>>increase>>damage;
    takeenemy(n);
    takeupdates(m,n);
    FREP(moment,1,12){
        cout<<"at moment "<<moment<<" profit is "<<profit(bounty,increase,damage,moment,n)<<"\n";
    }
    return 0;
}
