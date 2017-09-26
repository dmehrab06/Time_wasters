/*-------property of the half blood prince-----*/

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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int done[81];
int out[81];
int in[81][81];
int g[81][81];
int ans[81];
void init(int n){
    FREP(i,1,n){
        done[i]=0;
        out[i]=0;
        FREP(j,1,n){
            in[i][j]=0;
            g[i][j]=0;
        }
        ans[0]=0;
    }
}

void setin(int n){
    FREP(i,1,n){
        in[i][1]=i;
        in[i][0]++;
    }
    FREP(i,1,n){
        FREP(j,1,n){
            if(g[i][j]==1){
                in[j][++in[j][0]]=i;
            }
        }
    }
    FREP(i,1,n){
        FREP(j,1,n){
            if(g[i][j]==1){
                out[i]++;
            }
        }
    }
}

bool oka(int n){
    FREP(i,1,n){
        if(!done[i])return false;
    }
    return true;
}

void solve(int n){
    int idx=-1;
    int mx=200;
    FREP(i,1,n){
        if(in[i][0]<mx && !done[i]){
            mx=in[i][0];
            idx=i;
        }
    }
    int curmn=-1;
    int curmnidx=-1;
    FREP(j,1,in[idx][0]){
        int cur=in[idx][j];
        int ou=out[cur];
        if(ou>curmn){
            curmn=ou;
            curmnidx=cur;
        }
    }
    //cout<<"choosing "<<curmnidx<<"\n";
    done[curmnidx]=1;
    //cout<<curmnidx<<" done\n";
    FREP(j,1,n){
        if(g[curmnidx][j]==1){
            done[j]=1;
            //cout<<j<<" done\n";
        }
    }
    ans[++ans[0]]=curmnidx;
    return;
}

char inp[81];

int main(){
    int n;
    int cs=1;
    while(scanf("%d",&n)==1){
        init(n);
        FREP(i,1,n){
            scanf("%s",inp);
            FREP(j,1,n){
                g[i][j]=inp[j-1]-'0';
            }
        }
        setin(n);
       // cout<<"eschi\n";
        while(!oka(n)){
            solve(n);
        }
        printf("Case %d: %d",cs++,ans[0]);
        FREP(i,1,ans[0]){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
