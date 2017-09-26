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
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
using namespace std;
int N,M;
int mat[506][506];
//algo used: binary search in 2d array
//for each row find lower bound of L
//then binary search and extend the square from there
int rl(int lo, int hi, int val, int r){ //finding lower bound in row
    int mid=(lo+hi)/2;
    if(mat[r][mid]>=val){
        if((mid-1)<1)return mid;
        if(mat[r][mid-1]<val)return mid;
        return rl(lo,mid,val,r);
    }
    return rl(mid+1,hi,val,r);
}

PII squarebs(int lox, int loy, int hix, int hiy, int val){ //extending square
    int midx=(lox+hix)/2;
    int dx=midx-lox;
    int midy=loy+dx;
    if(mat[midx][midy]<=val){
        if((midx+1)>N || (midy+1)>M){
            return make_pair(midx,midy);
        }
        else if(mat[midx+1][midy+1]>val){
            return make_pair(midx,midy);
        }
        else{
            return squarebs(midx+1,midy+1,hix,hiy,val);
        }
    }
    return squarebs(lox,loy,midx,midy,val);
}

int main(){
    while(scanf("%d %d",&N,&M)==2 && !(!N && !M)){
        FREP(i,1,N){
            FREP(j,1,M){
                scanf("%d",&mat[i][j]);
            }
        }
        int q;
        scanf("%d",&q);
        FREP(i,1,q){
            int L,R;
            scanf("%d %d",&L,&R);
            int mx=0;
            FREP(k,1,N){
                int lx=k;
                if(mat[lx][M]<L)continue;
                int ly=rl(1,M,L,lx);
                //eibar eikhan theke rx , ry er jonno binsearch
                int dx=N-lx;
                int dy=M-ly;
                int rx=lx+min(dx,dy);
                int ry=ly+min(dx,dy);
                //cout<<lx<<" "<<ly<<"\n";
                //cout<<rx<<" "<<ry<<"\n";
                if(mat[lx][ly]>R){
                    continue;
                }
                PII pp=squarebs(lx,ly,rx,ry,R);
                int dd=pp.first-lx+1;
                //cout<<dd<<"\n";
                mx=max(dd,mx);
            }
            printf("%d\n",mx);
        }
        printf("-\n");
    }
    return 0;
}
