
/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PI acos(-1.0)
#define sq2 sqrt(2.0)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double rotmat[3][3];
double mymat[3][3];
double res[3][3];

void multi(){
    FREP(i,0,2){
        FREP(j,0,2){
            FREP(k,0,2){
                res[i][j]+=rotmat[i][k]*mymat[k][j];
            }
        }
    }
    FREP(i,0,2)FREP(j,0,2)mymat[i][j]=res[i][j];
}

void fillmat(){
    FREP(i,0,2){
        FREP(j,0,2){
            mymat[i][j]=((i==j)?0.5:0.0);
        }
    }
}

void fillrotmat(double ang){
    rotmat[0][0] = 1.0; rotmat[0][1] = 0.0; rotmat[0][2] = 0.0;
    rotmat[1][0] = 0.0; rotmat[1][1] = cos(ang); rotmat[1][2] = -sin(ang);
    rotmat[2][0] = 0.0; rotmat[2][1] = sin(ang); rotmat[2][2] = cos(ang);
}

void fillrotmat2(double ang){
    rotmat[2][2] = 1.0; rotmat[0][2] = 0.0; rotmat[1][2] = 0.0;
    rotmat[2][0] = 0.0; rotmat[0][0] = cos(ang); rotmat[0][1] = -sin(ang);
    rotmat[2][1] = 0.0; rotmat[1][0] = sin(ang); rotmat[1][1] = cos(ang);
}


int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        double Area;
        scanf("%lf",&Area);
        MSET(res,0.0);
        fillmat();
        double Tmp = Area;
        Area = min(sq2,Area);
        double lo = 0.0;
        double hi = PI/4.0;
        FREP(i,1,100){
            double m = lo+(hi-lo)/2.0;
            double ll = cos(m)+sin(m);
            if(ll<Area){
                lo = m;
            }
            else{
                hi = m;
            }
        }
        double loll = cos(lo)+sin(lo);
        double hill = cos(hi)+sin(hi);
        if(fabs(loll-Area)<eps){
            fillrotmat(lo);
        }
        else{
            fillrotmat(hi);
        }
        multi();
        MSET(res,0.0);
        Area = Tmp/Area;
        lo = 0.0;
        hi = PI/4.0;
        FREP(i,1,100){
            double m = lo+(hi-lo)/2.0;
            double ll = cos(m)+sin(m);
            if(ll<Area){
                lo = m;
            }
            else{
                hi = m;
            }
        }
        loll = cos(lo)+sin(lo);
        hill = cos(hi)+sin(hi);
        if(fabs(loll-Area)<eps){
            fillrotmat2(lo);
        }
        else{
            fillrotmat2(hi);
        }
        multi();
        printf("Case #%d:\n",cs);
        FREP(i,0,2){
            FREP(j,0,2){
                printf("%.8lf ",res[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}
