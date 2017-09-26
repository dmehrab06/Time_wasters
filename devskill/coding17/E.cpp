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
#define MDD 100000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI dp[25][3][20][10];

double tenpow[24];

void pre(){
    tenpow[0]=1.0;
    FREP(i,1,23){
        tenpow[i]=tenpow[i-1]*10.0;
    }
}

void init(){
    memset(dp,-1,sizeof(dp));
}

string xx;

string getst(LLI X){
    string res="";
    while(X){
        res.push_back(X%10+'0');
        X/=10;
    }
    //reverse(res.begin(),res.end());
    //res.push_back('0');res.push_back('0');
    return res;
}

LLI solve(int pos, int hascarry, int carryleft, LLI n, double untilnow, int mxlen, int cur){
    if(carryleft<0)return 0;
    if(untilnow>(double)n)return 0;
    if(pos==mxlen){
        if(carryleft==0){return 1;}
        return 0;
    }
    if(dp[pos][hascarry][carryleft][cur]!=-1){
        return dp[pos][hascarry][carryleft][cur];
    }
    double nxtval = (double)cur*tenpow[pos]+untilnow;
    int xval = xx[pos]-'0';
    int val = cur+xval+hascarry;
    int nextcarry = 0;
    if(val>=10){
        nextcarry = 1;
    }
    LLI s = 0;
    for(int i=0;i<10;++i){
        s+=solve(pos+1,nextcarry,carryleft-nextcarry,n,nxtval,mxlen,i);
        //cout<<nextval<<" "<<s<<"\n";
    }
    return dp[pos][hascarry][carryleft][cur]=s;
}

int cntcarry(int a, int b){
    int cnt = 0;
    int mxx = max(a,b);
    int mnn = min(a,b);
    int cc = 0;
    while(mxx){
        int aa = mxx%10;
        int bb = mnn%10;
        int vv = aa+bb+cc;
        if(vv>=10){
            cc=1;
            cnt++;
        }
        else{
            cc=0;
        }
        mxx/=10;
        mnn/=10;
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    pre();
    int cs =1;
    while(t--){
        LLI n,x,k;
        cin>>n>>x>>k;
        init();
        xx = getst(x);

        //cout<<xx<<"\n";
        LLI ans = 0;
        if(k>0){
            FREP(dig,0,9){
                ans += solve(0,0,k,n,0.0,xx.size(),dig);
                init();
            }

        }
        else{
            LLI ss=0;
            FREP(i,1,xx.size()){
                FREP(dig,0,9){
                    ss+=solve(0,0,i,n,0.0,xx.size(),dig);
                    init();
                }
                init();
            }
            ans = n-ss;
        }
        LLI ans2=0;
        FREP(i,1,n){
            if(cntcarry(x,i)==k){
                ans2++;
            }
        }
        cout<<"Case "<<cs++<<": "<<ans<<" "<<ans2<<"\n";
        if(ans!=ans2){
           // cout<<"for "<<n<<" "<<x<<" "<<k<<"\n";
        }
    }
    return 0;
}
