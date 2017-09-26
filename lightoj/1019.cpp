#include<bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000
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
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define XX first
#define YY second
using namespace std;

int setbit(int n, int i){return (n|(1<<i));}
int resetbit(int n, int i){return (n&(~(1<<i)));}
bool isset(int n, int i){return (n&(1<<i));}
int cnt(int n){ int c=0; FREP(i,0,18)if(n&(1<<i))c++; return c;}

pair<PII,int> getline(PII p1, PII p2){
    int A=p1.YY-p2.YY;
    int B=p2.XX-p1.XX;
    int C=A*p1.XX+B*p1.YY;
    return make_pair(make_pair(A,B),C);
}

bool isonline(pair<PII,int>line, PII p){
    return line.XX.XX*p.XX+line.XX.YY*p.YY==line.YY;
}

set< pair<PII,int> >S;
pair<PII,int> lines[300];
PII points[20];
int MAXMASK, totalline;
int dp[70005];
int used[300];
int N;

void init(){
    FREP(i,0,70000)dp[i]=-1;
    FREP(i,0,250)used[i]=0;
}

int solve(int mask){
    if(mask==MAXMASK)return 0;
    if(dp[mask]!=-1)return dp[mask];

    int curset=cnt(mask);
    int ret=MXX;
    FREP(i,0,totalline-1){
        if(!used[i]){
            pair<PII,int>curline=lines[i];
            used[i]=1;
            int nmask=mask;
            FREP(i,0,(N-1)){
                if(isonline(curline,points[i])){
                    nmask=setbit(nmask,i);
                }
            }
            int thisset=cnt(nmask);
            if(thisset>curset)ret=min(ret,1+solve(nmask));
            used[i]=0;
        }
    }
    dp[mask]=ret;
    return dp[mask];

}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        //int n;
        scanf("%d",&N);
        FREP(i,0,(N-1)){
            //int x,y;
            scanf("%d %d",&points[i].XX,&points[i].YY);
        }
        S.clear();
        FREP(i,0,(N-1)){
            FREP(j,(i+1),(N-1)){
                pair<PII,int>curline=getline(points[i],points[j]);
                S.insert(curline);
            }
        }
        set<pair<PII,int>>::iterator it;
        totalline=0;
        for(it=S.begin();it!=S.end();++it){
            lines[totalline++]=*it;
        }
        init();
        MAXMASK=(1<<N)-1;
        int ans=solve(0);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
