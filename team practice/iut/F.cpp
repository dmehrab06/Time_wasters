/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('1'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000
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

struct info{
    double profit;
    double loss;
    double plratio;
};

bool cmp(info &a, info &b){
    if(fabs(a.loss)<eps || fabs(b.loss)<eps){
        return a.loss<b.loss;
    }
    return a.plratio>b.plratio;
}

int n,k,x0;
double dp[105][105];
int vis[105][105];

info all[105];

double solve(int cur, int left){
    if(left==0)return (double)x0;
    if(cur>=n)return (double)(MNN);
    if(vis[cur][left]!=-1){
        return dp[cur][left];
    }
    double ret1=solve(cur+1,left-1);
    ret1=all[cur].profit+ret1*(1.00-all[cur].loss);
    double ret2=solve(cur+1,left);
    vis[cur][left]=1;
    return dp[cur][left]=max(ret1,ret2);
}

int main(){
    while(scanf("%d %d %d",&n,&k,&x0)==3 && (n)){
        memset(vis,-1,sizeof(vis));
        FREP(i,1,n){
            double lv,ls,prob;
            scanf("%lf %lf %lf",&lv,&ls,&prob);
            all[i-1].profit=(prob/100.00)*(lv);
            all[i-1].loss=(1.00-(prob/100.00))*(ls/100.00);
            if(fabs(all[i-1].loss)<eps){
                all[i-1].plratio=MXX;
            }
            else{
                all[i-1].plratio=all[i-1].profit/all[i-1].loss;
            }
        }
        sort(all,all+n,cmp);
        double ans=solve(0,k);
        printf("%.2lf\n",ans);
    }
}
