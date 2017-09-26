#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

int dp[502][502][502];

int N;

int dish[502];
int bfcompress[502];
//int afcompress[502];
void init(){
    FREP(i,0,500)FREP(j,0,500)FREP(k,j,500)dp[i][j][k]=-1;
}

int solve(int idx, int top, int bottom){
    if(idx>N)return 0;
    if(dp[idx][top][bottom]!=-1){
        return dp[idx][top][bottom];
    }
    int cur=dish[idx];
    if(cur>top && cur<bottom)return 0;
    if(top==0 && bottom==0){
        int ret1,ret2;
        ret1=1+solve(idx+1,cur,cur);
        ret2=solve(idx+1,top,bottom);
        dp[idx][top][bottom]=max(ret1,ret2);
        return dp[idx][top][bottom];
    }
    if(cur==top && cur==bottom){
        int ret1,ret2;
        ret1=1+solve(idx+1,cur,bottom);
        ret2=solve(idx+1,top,bottom);
        dp[idx][top][bottom]=max(ret1,ret2);
        return dp[idx][top][bottom];
    }
    if(cur<=top){
        int ret1,ret2;
        ret1=1+solve(idx+1,cur,bottom);
        ret2=solve(idx+1,top,bottom);
        dp[idx][top][bottom]=max(ret1,ret2);
        return dp[idx][top][bottom];
    }
    if(cur>=bottom){
        int ret1,ret2;
        ret1=1+solve(idx+1,top,cur);
        ret2=solve(idx+1,top,bottom);
        dp[idx][top][bottom]=max(ret1,ret2);
        return dp[idx][top][bottom];
    }

}

int main(){
    while(scanf("%d",&N)==1 && N){
        FREP(i,1,N){
            scanf("%d",&dish[i]);
            bfcompress[i]=dish[i];
        }
        sort(bfcompress+1,bfcompress+1+N);
        map<int,int>com;
        com[bfcompress[1]]=1;
        int st=1;
        FREP(i,2,N){
            if(bfcompress[i]>bfcompress[i-1]){
                st++;
                com[bfcompress[i]]=st;
            }
            //afcompress[i]=st;
        }
        //check
        /*map<int,int>::iterator it;
        for(it=com.begin();it!=com.end();++it){
            printf("%d %d\n",it->first,it->second);
        }*/
        FREP(i,1,N){
            dish[i]=com[dish[i]];
        }
       /* FREP(i,1,N){
            //dish[i]=com[dish[i]];
            printf("%d\n",dish[i]);
        }*/
        init();
        int ans=solve(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
