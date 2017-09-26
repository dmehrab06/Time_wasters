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

int themsets[4][7005];
int n;
int dp[7005][4];
int vis[7005][4];

//win=2
//inf=1
//lose=0
int solve(int curpos, int turn){
    cout<<(turn==0?"rick":"morty")<<" in "<<curpos<<"\n";
    if(curpos==0){
        //turn lost
        vis[curpos][turn]=1;
        return dp[curpos][turn]=0;
    }
    if(dp[curpos][turn]!=-1){
        return dp[curpos][turn];
    }
    if(vis[curpos][turn]){
        cout<<"ageo eiram state e aschilo\n";
        return 1;
    }
    vis[curpos][turn]=1;
    int setsz=themsets[turn][0];
    int val=-1;
    FREP(i,1,setsz){
        int curnumber=themsets[turn][i];
        int nxtgroho=(curpos+curnumber)%n;
        int ans=solve(nxtgroho,1-turn);
        //cout<<"ans from "<<nxtgroho<<" "<<(1-turn)<<" "<<ans<<"\n";
        if(ans==0){
            cout<<(turn==0?"rick":"morty")<<" win from state "<<curpos<<" "<<" by choosing "<<curnumber<<"\n";
            val=2;
            break;
        }
        /*else if(ans==1){
            cout<<(turn==0?"rick":"morty")<<" may loop from state "<<curpos<<" "<<" by choosing "<<curnumber<<"\n";
            val=1;
        }*/
    }
    if(val==-1){
        cout<<(turn==0?"rick":"morty")<<" no way of win  from "<<curpos<<" "<<"\n";
        dp[curpos][turn]=3;
    }
    else{
        if(val==1){
            cout<<(turn==0?"rick":"morty")<<" is going for loop from "<<curpos<<" "<<"\n";
        }
        dp[curpos][turn]=val;
    }
    return dp[curpos][turn];
}

int solve2(int curpos, int turn){
    cout<<(turn==0?"rick":"morty")<<" in "<<curpos<<"\n";
    if(curpos==0){
        //turn lost
        vis[curpos][turn]=1;
        return dp[curpos][turn]=0;
    }
    if(dp[curpos][turn]!=-1){
        return dp[curpos][turn];
    }
    if(vis[curpos][turn]){
        cout<<"ageo eiram state e aschilo\n";
        return 1;
    }
    vis[curpos][turn]=1;
    int setsz=themsets[turn][0];
    int val=-1;
    FREP(i,1,setsz){
        int curnumber=themsets[turn][i];
        int nxtgroho=(curpos+curnumber)%n;
        int ans=solve2(nxtgroho,1-turn);
        //cout<<"ans from "<<nxtgroho<<" "<<(1-turn)<<" "<<ans<<"\n";
        if(ans==0){
            cout<<(turn==0?"rick":"morty")<<" win from state "<<curpos<<" "<<" by choosing "<<curnumber<<"\n";
            val=2;
            break;
        }
        else if(ans==1){
            cout<<(turn==0?"rick":"morty")<<" may loop from state "<<curpos<<" "<<" by choosing "<<curnumber<<"\n";
            val=1;
        }
    }
    if(val==-1){
        cout<<(turn==0?"rick":"morty")<<" no way of win  from "<<curpos<<" "<<"\n";
        dp[curpos][turn]=0;
    }
    else{
        if(val==1){
            cout<<(turn==0?"rick":"morty")<<" is going for loop from "<<curpos<<" "<<"\n";
        }
        dp[curpos][turn]=val;
    }
    return dp[curpos][turn];
}

int main(){
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    scanf("%d",&themsets[0][0]);
    FREP(i,1,themsets[0][0]){
        scanf("%d",&themsets[0][i]);
    }
    sort(themsets[0]+1,themsets[0]+1+themsets[0][0]);
    scanf("%d",&themsets[1][0]);
    FREP(i,1,themsets[1][0]){
        scanf("%d",&themsets[1][i]);
    }
    sort(themsets[1]+1,themsets[1]+1+themsets[1][0]);
    printf("rick\n");
    RFREP(i,(n-1),1){
        printf("trying for planet %d\n",i);
        solve(i,0);
    }
    RFREP(i,(n-1),1){
        if(dp[i][0]==3){
            dp[i][0]=-1;
            vis[i][0]=0;
        }
        if(dp[i][1]==3){
            dp[i][1]=-1;
            vis[i][0]=0;
        }
    }
    RFREP(i,(n-1),1){
        printf("trying for planet %d\n",i);
        solve2(i,0);
    }
    FREP(i,1,(n-1)){
        if(dp[i][0]==2){
            printf("Win ");
        }
        else if(dp[i][0]==1){
            printf("Loop ");
        }
        else if(dp[i][0]==0){
            printf("Lose ");
        }
    }
    printf("\n");
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    printf("morty\n");
    RFREP(i,(n-1),1){
        printf("trying for planet %d\n",i);
        solve(i,1);
    }
    FREP(i,1,(n-1)){
        if(dp[i][1]==2){
            printf("Win ");
        }
        else if(dp[i][1]==1){
            printf("Loop ");
        }
        else if(dp[i][1]==0){
            printf("Lose ");
        }
    }
    printf("\n");
    return 0;
}
