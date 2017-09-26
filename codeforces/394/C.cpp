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

char passwords[52][52];
int dis[52][4]; //1 has distance for dig, 2 has distance for spec, 3 has distance for lower

bool isspecial(char a){
    return ( (a=='#') || (a=='&') || (a=='*') );
}

void takepass(int n, int m){
    FREP(i,0,(n-1)){
        scanf("%s",passwords[i]);
    }
}

void calcspecialdistance(int n, int m){
    FREP(i,0,(n-1)){
        int globdis=100000;
        FREP(j,0,(m-1)){
            if(isspecial(passwords[i][j])){
                int dis=min(j,m-j);
                globdis=min(dis,globdis);
            }
        }
        dis[i][2]=globdis;
    }
}

void calcdigdistance(int n, int m){
    FREP(i,0,(n-1)){
        int globdis=100000;
        FREP(j,0,(m-1)){
            if(ISNUM(passwords[i][j])){
                int dis=min(j,m-j);
                globdis=min(dis,globdis);
            }
        }
        dis[i][1]=globdis;
    }
}

void calclowerdistance(int n, int m){
    FREP(i,0,(n-1)){
        int globdis=100000;
        FREP(j,0,(m-1)){
            if(ISSML(passwords[i][j])){
                int dis=min(j,m-j);
                globdis=min(dis,globdis);
            }
        }
        dis[i][3]=globdis;
    }
}

int check(int chara, int charb, int charc){
    //int temp[53];
    int disa1=dis[chara][1];
    int disa2=dis[chara][2];
    int disa3=dis[chara][3];
    int disb1=dis[charb][1];
    int disb2=dis[charb][2];
    int disb3=dis[charb][3];
    int disc1=dis[charc][1];
    int disc2=dis[charc][2];
    int disc3=dis[charc][3];

    int D1=disa1+disb2+disc3;
    int D2=disa1+disb3+disc2;
    int D3=disa2+disb1+disc3;
    int D4=disa2+disb3+disc1;
    int D5=disa3+disb1+disc2;
    int D6=disa3+disb2+disc1;

    int D=1000000;
    D=min(D,D1);
    D=min(D,D2);
    D=min(D,D3);
    D=min(D,D4);
    D=min(D,D5);
    D=min(D,D6);
    return D;
}

int solve(int n, int m){
    calcdigdistance(n,m);
    calclowerdistance(n,m);
    calcspecialdistance(n,m);
    int ans=1000000;
    FREP(i,0,(n-1)){
        FREP(j,(i+1),(n-1)){
            FREP(k,(j+1),(n-1)){
                  ans=min(ans,check(i,j,k));
            }
        }
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    takepass(n,m);
    int ans=solve(n,m);
    printf("%d\n",ans);
    return 0;
}
