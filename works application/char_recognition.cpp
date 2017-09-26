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
#define ALPHABET_SIZE 2
#define INDEX(c) ((int)c - (int)'0')
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int lettergrid[10][15][15];

map<PII, vector<PII> >diffpairs;

map<PII,int>posinbitmask;

int dp[15][15][35000];

int needmask;

void initbit(int totlet){
    int c=0;
    FREP(i,1,totlet)
        FREP(j,(i+1),totlet){
            PII l_pair = make_pair(i,j);
            posinbitmask[l_pair]=c++;
        }
}

int getbitpos(PII charpair){
    return posinbitmask[charpair];
}

void setbitpos(PII charpair, int &msk){
    int pos=getbitpos(charpair);
    msk=msk | (1<<pos);
}

void resetbitpos(PII charpair, int &msk){
    int pos=getbitpos(charpair);
    msk=msk & (~(1<<pos));
}

void finddiff(int n, int m, int totlet){
    FREP(i,1,n)
        FREP(j,1,m)
            FREP(m,1,totlet)
                FREP(n,m+1,totlet)
                    if(lettergrid[m][i][j]!=lettergrid[n][i][j]){
                        PII xy = make_pair(i,j);
                        PII p_dif = make_pair(m,n);
                        diffpairs[xy].PB(p_dif);
                    }
}

int solve(int x, int y, int mask, int n, int m){
    if(mask==needmask)return 0;
    if(x==(n+1))return 1000000;
    if(dp[x][y][mask]!=-1)return dp[x][y][mask];
    int nxtx=x,nxty=y+1;
    if(y==m){
        nxtx=x+1;
        nxty=1;
    }
    int ret1=solve(nxtx,nxty,mask,n,m);
    PII curxy_pair=make_pair(x,y);
    vector < PII > charset = diffpairs[curxy_pair];
    int ll=charset.size();
    FREP(i,0,(ll-1)){
        PII c_pair=charset[i];
        setbitpos(c_pair,mask);
    }
    int ret2=1+solve(nxtx,nxty,mask,n,m);
    FREP(i,0,(ll-1)){
        PII c_pair=charset[i];
        resetbitpos(c_pair,mask);
    }
    return dp[x][y][mask]=min(ret1,ret2);
}

void takeinp(int n, int m, int k){
    char str[20];
    FREP(i,1,k){
        FREP(r,1,n){
            scanf("%s",str);
            FREP(c,1,m){
                lettergrid[i][r][c]=str[c-1];
            }
        }
    }
}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    takeinp(n,m,k);
    initbit(k);
    finddiff(n,m,k);
    int needbit=k*(k-1);
    needbit/=2;
    needmask=(1<<needbit)-1;
    memset(dp,-1,sizeof(dp));
    int ans=solve(1,1,0,n,m);
    printf("%d\n",ans);
}
