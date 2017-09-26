#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
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
using namespace std;

struct pt{
    double x;
    double y;
    pt(){
        x=0.0;
        y=0.0;
    }
    pt(double _x, double _y){
        x=_x;
        y=_y;
    }

};

bool mycmp(pt &a , pt &b){
    return a.x<b.x;
}

double cumsum[2005];
double px[2005];
double py[2005];
double dp[2005][2005];
pt pts[2005];
int N;

double dis(int p1, int p2){
    double a= (px[p1]-px[p2])*(px[p1]-px[p2])+(py[p1]-py[p2])*(py[p1]-py[p2]);
    return sqrt(a);
}

void init(){
    sort(pts+1,pts+1+N,mycmp);
    FREP(i,1,N){
        px[i]=pts[i].x;
        py[i]=pts[i].y;
    }
    FREP(i,0,2004)FREP(j,0,2004)dp[i][j]=-1.0;
    cumsum[0]=0.0;
    cumsum[1]=0.0;
    FREP(i,2,N){
        cumsum[i]=dis(i,i-1);
    }
    FREP(i,2,N){
        cumsum[i]=cumsum[i]+cumsum[i-1];
    }
    return;
}

double solve(int s1, int s2){
    if(s1==N){
        return dp[s1][s2]=dis(s1,s2);
    }
    if(!(dp[s1][s2]<0.0)){
        return dp[s1][s2];
    }
    FREP(i,(s1+1),N){
        double d1=dis(i,s1);
        //double d2=cumsum[i-1]-cumsum[s2];
        int p=(i-1);
        double ret;
        if(s2<=p && p<=s1){
            //ekrokom
            ret=d1+solve(i,s2);
        }
        else{
            //arekrokom
            double d2=cumsum[p]-cumsum[s1+1];
            d2+=dis(s2,s1+1);
            ret=d1+d2+solve(i,i-1);
        }

        if(dp[s1][s2]<0.0 || ret<dp[s1][s2]){
            dp[s1][s2]=ret;
        }
    }
    return dp[s1][s2];
}

int main(){
    while(scanf("%d",&N)==1){
        FREP(i,1,N){
            scanf("%lf %lf",&pts[i].x,&pts[i].y);
        }
        init();
        solve(1,1);
       /* FREP(i,0,N){
            FREP(j,0,N){
                printf("%.2lf\n",dp[i][j]);
            }
            printf("\n");
        } */
        printf("%.2lf\n",dp[1][1]);
    }
    return 0;
}
