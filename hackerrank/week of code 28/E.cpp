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
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
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


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

map< PII , double>dp;

int minlen;

char balls[32];

bool getbit(int n, int i){
    return (n&(1<<(i-1)));
}

bool isallone(int n, int len){
    int msk=1;
    FREP(i,0,(len-1)){
        if( !(n&msk) ) return false;
        msk<<=1;
    }
    return true;
}

int extract(int n, int i, int len){
    int baad_dibo=(i-1);
    int s= 0;
    int curval = 1; int msk =1;
    FREP(k,0,(len-1)){
        if(k!=baad_dibo){
            if(n&msk)s+=curval;
            curval<<=1;
        }
        msk<<=1;
    }
    return s;
}

int getnum(){
    int len=strlen(balls);
    int ss=0;
    FREP(i,0,(len-1)){
        ss=ss*2+((balls[i]=='W')?1:0);
    }
    return ss;
}

double solve(int bits, int len){
    //cout<<"in "<<bits<<", "<<len<<"\n";
    PII dpidx=make_pair(bits,len);
    if(len==minlen){
       // cout<<"ar delete kora jabe na\n";
        return 0.0;
    }
    if(bits==0){
       // cout<<"ar white nai\n";
        return 0.0;
    }
    if(isallone(bits,len)){
       // cout<<"sob one\n";
        return (double)(len-minlen);
    }
    if(dp.find(dpidx)!=dp.end())return dp[dpidx];

    double s = 0.0;

    FREP(i,1,len){
      //  cout<<"in xi="<<i<<"\n";
        int lft=getbit(bits,i)?1:0;
      //  cout<<i<<"th bit from left "<<lft<<"\n";
        int rgt=getbit(bits,len+1-i)?1:0;
      //  cout<<i<<"th bit from right "<<rgt<<"\n";
        int getlt=extract(bits,i,len);
      //  cout<<"extracting from left "<<getlt<<"\n";
        int getrt=extract(bits,len+1-i,len);
      //  cout<<"extracting from right "<<getrt<<"\n";
        double ret1=(double)lft+solve(getlt,len-1);
      //  cout<<"lft nia pamu "<<ret1<<"\n";
        double ret2=(double)rgt+solve(getrt,len-1);
        //cout<<"adding "<<max(ret1,ret2)<<"\n";
      //  cout<<"rgt nia pamu "<<ret2<<"\n";
        s+=max(ret1,ret2);
    }
    s/=(double)len;

    return dp[dpidx]=s;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    minlen=n-k;
    scanf("%s",balls);
    int ballbit=getnum();
    //cout<<ballbit<<"\n";
    double ans=solve(ballbit,n);
    printf("%.10lf\n",ans);
    return 0;
}
