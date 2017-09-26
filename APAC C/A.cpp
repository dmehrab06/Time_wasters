//data structure-- adjacency matrix
//algo -- dfs

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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
//char s[1003];

char grid[50][50];

int visited[50][50];
int maxstep;
double P,Q;
double cP,cQ;
double mxx=0.00;
int R,C;

void init(){
    FREP(i,0,R)FREP(j,0,C)visited[i][j]=0;
}

double mypow(double b, double p){
    double s=1.00;
    FREP(i,1,p)s=s*b;
    return s;
}

void dfs(int curx, int cury, int taken, double added){
    //printf("in %d %d\n",curx,cury);
    if(taken==maxstep){

        if(added>mxx){
            mxx=added;
        }
        //cout<<curx<<" "<<cury<<" theke "<<(added+toadd)<<" nia back korlam\n";
        return;
    }
    if(taken>0)visited[curx][cury]++;
    for(int i=-1;i<=1;++i){
        for(int j=-1;j<=1;++j){
            if(i==0 && j==0)continue;
            if(i==0 || j==0){
                if(ISVALID(curx+i,cury+j,R,C)){
                    int didnotcatch=visited[curx+i][cury+j];
                    double toadd;
                    if(grid[curx+i][cury+j]=='A'){
                        double fail=mypow(cP,(double)didnotcatch);
                        toadd=fail*P;
                    }
                    else{
                        double fail=mypow(cQ,(double)didnotcatch);
                        toadd=fail*Q;
                    }
                    dfs(curx+i,cury+j,taken+1,added+toadd);
                }
            }
        }
    }
    if(visited[curx][cury]>0)visited[curx][cury]--;
    return;
}

char tmp[1000];
int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int startx,starty;
        scanf("%d %d %d %d %d",&R,&C,&startx,&starty,&maxstep);
        scanf("%lf %lf",&P,&Q);
        cP=1.00-P;
        cQ=1.00-Q;
        FREP(i,0,(R-1)){
            FREP(j,0,(C-1)){
                scanf("%s",tmp);
                grid[i][j]=tmp[0];
            }

        }

        init();
        mxx=0.00;
        dfs(startx,starty,0,0);
        //cout<<mxx<<"\n";
        printf("Case #%d: %.10lf\n",cs++,mxx);
    }
    return 0;
}
