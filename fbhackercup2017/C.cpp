/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define ULLI unsigned long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.00000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

int dicetype[7]={0,4,6,8,10,12,20};

double dp[20006][24][7];

void init(){
    memset(dp,-1.0,sizeof(dp));
}

double solve(int val, int cur, int type){
    if(cur==0){
        if(val>=0)return (LLI)1.00;
        else return (LLI)0.00;
    }
    if(dp[val][cur][type]>(-1.0)){
        return dp[val][cur][type];
    }
    double ret=0.0;
    FREP(i,1,dicetype[type]){
        if(i>val)break;
        ret+=solve(val-i,cur-1,type);
    }
    return dp[val][cur][type]=ret;
}

pair<PII,int> parse(string roller){
    int throwtime=0;
    int cur=0;
    while(ISNUM(roller[cur])){
        throwtime=throwtime*10+roller[cur]-'0';
        cur++;
    }
    cur++;
    int diceside=0;
    while(ISNUM(roller[cur])){
        diceside=diceside*10+roller[cur]-'0';
        cur++;
    }
    int type=0;
    FREP(i,1,6){
        if(diceside==dicetype[i]){
            type=i;
            break;
        }
    }
    if(roller[cur]=='#'){
        return make_pair(make_pair(throwtime,type),0);
    }
    int sgn=(roller[cur]=='-')?1:-1;
    cur++;
    int offset=0;
    while(ISNUM(roller[cur])){
        offset=offset*10+roller[cur]-'0';
        cur++;
    }
    offset=offset*sgn;
    return make_pair(make_pair(throwtime,type),offset);
}

void sim(){
    FREP(type,1,7){
        FREP(cur,0,20){
            FREP(val,0,20003){
                solve(val,cur,type);
            }
        }
    }
}

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int main()
{
    init();
    sim();
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int mindamage,s;
        scanf("%d %d",&mindamage,&s);
        string dd;
        double mxx=-1.00;
        FREP(i,1,s){
            cin>>dd;
            dd.push_back('#');
            pair<PII,int>vals=parse(dd);
            int diceuse=vals.first.first;
            int typeuse=vals.first.second;
            int offset=vals.second;
            int val=(mindamage-1)+offset;
           // cout<<offset<<"\n";
           // cout<<val<<" "<<diceuse<<" "<<typeuse<<"\n";
            double rett=val<0?0.00:dp[val][diceuse][typeuse];
            FREP(i,1,diceuse){
                rett=rett/dicetype[typeuse];
            }
            double succ=1.00-rett;
            mxx=max(succ,mxx);
        }
        printf("Case #%d: %.6lf\n",cs++,mxx);
    }
    return 0;
}
