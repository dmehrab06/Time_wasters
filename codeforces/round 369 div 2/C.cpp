#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)

using namespace std;

//Data Structure used: 2D doubly linked list
//store val; up, down, left and right node
//take row+2, col+2 area to avoid null pointer hasty checking
//when swapping two rectangle only outer boundary pointers need to be updated

LLI dp[103][103][103];

int did[103][103][103];

int col[103][103];

int treestate[103];

int N,need,color;

void init(){
    FREP(i,0,102)FREP(j,0,102)FREP(k,0,102){dp[i][j][k]=MXX;did[i][j][k]=-1;}
}

LLI solve(int tree, int prevcolor, int seg){
    if(tree>N){
        if(seg==need){
            return 0;
        }
        else{
            return MXX;
        }
    }
    if((did[tree][prevcolor][seg]!=-1)){
        return dp[tree][prevcolor][seg];
    }
    LLI ret1=MXX;
    if(treestate[tree]!=0){
        int dd=0;
        if(treestate[tree]!=prevcolor)dd=1;
        dp[tree][prevcolor][seg]=solve(tree+1,treestate[tree],seg+dd);
        did[tree][prevcolor][seg]=1;
        return dp[tree][prevcolor][seg];
    }
    else{
        FREP(i,1,color){
            LLI thiscost=col[tree][i];
            int dd=0;
            if(i!=prevcolor)dd=1;
            ret1=thiscost+solve(tree+1,i,seg+dd);
            dp[tree][prevcolor][seg]=min(dp[tree][prevcolor][seg],ret1);
        }
        did[tree][prevcolor][seg]=1;
        return dp[tree][prevcolor][seg];
    }
}

int main(){
    scanf("%d %d %d",&N,&color,&need);
    FREP(i,1,N){
        scanf("%d",&treestate[i]);
    }
    FREP(i,1,N){
        FREP(j,1,color){
            scanf("%d",&col[i][j]);
        }
    }
    init();
    LLI ans=solve(1,0,0);
    if(ans>=MXX){
        ans=-1;
    }
    cout<<ans<<"\n";
}

