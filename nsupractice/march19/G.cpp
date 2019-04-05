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



ifstream fin("wifi.in");

int arr[100005];
int cumsum[20][100005];

void pre(int bit, int n){
    FREP(i,1,n)cumsum[bit][i] = (arr[i]&(1<<bit))?1:0;
    FREP(i,1,n)cumsum[bit][i]+=cumsum[bit][i-1];
}

int getonecnt(int bit, int l, int r){
    return cumsum[bit][r]-cumsum[bit][l-1];
}

void precalc(int n){
    FREP(i,0,19)pre(i,n);
}

int getval(int l, int r){
    if(l>r)return 0;
    int s = 0;
    RFREP(i,19,0){
        int vv  = getonecnt(i,l,r);
        s<<=1;
        if(vv)s++;
    }
    return s;
}

int slide(int n, int v){
    int fp = 0;
    int bp = 1;
    int cur = 0;
    int mxlen = 0;
    while(bp<=n){
        if(cur<=v && fp<n){
            fp++;
            int orval = getval(bp,fp);
            if(orval<=v)mxlen = max(mxlen,(fp-bp+1));
            cur = orval;
        }
        else{
            bp++;
            int orval = getval(bp,fp);
            if(orval<=v)mxlen = max(mxlen,(fp-bp+1));
            cur = orval;
        }
    }
    return mxlen;
}

int main(){
    int t;
    fin>>t;
    FREP(cs,1,t){
        int n,v;
        fin>>n>>v;
        FREP(i,1,n)fin>>arr[i];
        precalc(n);
        cout<<slide(n,v)<<"\n";
    }
    fin.close();
    return 0;
}
