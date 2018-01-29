/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//int dp[10][10];

int dis[70][70];

void init(){
    FREP(i,0,69)FREP(j,0,69)if(i==j)dis[i][j]=0; else dis[i][j]=100000000;
}

void floyd(){
    FREP(k,0,63){
        FREP(i,0,63){
            FREP(j,0,63){
                if((dis[i][k]+dis[k][j])<dis[i][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

int gethash(int x, int y){return (x*8+y);}

void makeg(){
    FREP(i,0,7){
        FREP(j,0,7){
            int x = i; int y = j;
            FREP(k,0,7){
                int nx = x+dx[k]; int ny = y+dy[k];
                if(!(INRANGEI(nx,0,7) && INRANGEI(ny,0,7)))continue;
                int dd = (nx*x)+(ny*y);
                int src = gethash(x,y);
                int des = gethash(nx,ny);
                dis[src][des] = dd;
            }
        }
    }
}

int solve(int sx, int sy, int desx, int desy){
    int src  = gethash(sx,sy);
    int des = gethash(desx,desy);
    return dis[src][des];
}

int main(){
    init();
    //cout<<"hoise\n";
    makeg();
    //cout<<"graph banaisi\n";
    floyd();
    //cout<<"floyd chalaisi\n";
    int sx,sy,ddx,ddy;
    while(scanf("%d %d %d %d",&sx,&sy,&ddx,&ddy)==4){
        printf("%d\n",solve(sx,sy,ddx,ddy));
    }
    return 0;
}
