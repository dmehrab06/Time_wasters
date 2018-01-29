/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
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
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

struct PT {
      int  x,y,id;
      PT(){}
      PT(int _x,int _y){x=_x,y=_y;}
      PT operator + (const PT &p) const { return PT(x+p.x , y + p.y);}
      PT operator - (const PT &p) const { return PT(x-p.x , y - p.y);}
      PT operator * (double c) const { return PT(x*c,y*c);}
      PT operator / (double c) const { return PT(x/c,y/c);}
      void input(){scanf("%d %d",&x,&y);}
};

double dot(PT p,PT q){ return p.x * q.x + p.y * q.y;}
double cross(PT p,PT q) {return p.x*q.y - p.y*q.x;}
double dist2(PT p,PT q) {return dot(p-q , p-q);}
double DIM(PT p) {return sqrt(p.x*p.x+p.y*p.y);}

/*************************** END OF TEMPLATE ****************************/

#define MAXN 2005

PT allp[MAXN];
PT ref_point;

bool cmp(PT a, PT b){
    double k = cross(a-ref_point,b-ref_point);
    if(fabs(k) < eps){
        return dist2(a,ref_point) < dist2(b,ref_point);
    }
    else return k > 0;
}

void setreference(int n){
    int pid = 1;
    int miny = allp[1].y;
    FREP(i,2,n){
        if(allp[i].y<miny){
            miny = allp[i].y;
            pid = i;
        }
        else if(allp[i].y==miny){
            if(allp[i].x<allp[pid].x){
                pid = i;
            }
        }
    }
    ref_point = allp[pid];
    swap(allp[pid],allp[1]);
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            scanf("%d %d",&allp[i].x,&allp[i].y);
            allp[i].id = i;
        }
        //find reference point to sort by polar
        setreference(n);
        //checking colinearity with last point
        sort(allp+1,allp+1+n,cmp);
        int gotat = -1;
        RFREP(i,n-1,2){
            double val = cross(allp[n]-allp[1],allp[i]-allp[1]);
            if(fabs(val)>eps){
                gotat = i;
                break;
            }
        }
        printf("Case %d:\n",cs);
        if(gotat==-1){
            printf("Impossible\n");
        }
        else{
            FREP(i,1,gotat){
                if(i>1)printf(" ");
                printf("%d",allp[i].id-1);
            }
            RFREP(i,n,gotat+1){
                printf(" %d",allp[i].id-1);
            }
            printf("\n");
        }

    }
    return 0;
}
