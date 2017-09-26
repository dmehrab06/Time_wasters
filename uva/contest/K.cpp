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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<LLI>sides;
vector<LLI>square;
vector<LLI>tri;

double sq(double val){
    return val*val;
}

double gettriarea(){
    double area = 0.0;
    FREP(i,0,tri.size()-1){
        area+=sq(tri[i]);
    }
    area = area *(sqrt(3));
    area/=4.0;
    return area;
}

double getsquarearea(){
    double area = 0.0;
    FREP(i,0,square.size()-1){
        area+=sq(square[i]);
    }
    return area;
}

void init(){
    sides.clear();
    square.clear();
    tri.clear();
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        init();
        scanf("%d",&n);
        LLI cur = 0;
        while(n--){
            char cc[3]; int sz;
            scanf("%s %d",cc,&sz);
            if(cc[0]=='C' || cc[0]=='S'){
                square.PB(sz);
            }
            else{
                tri.PB(sz);
            }
            cur+=sz;
            if(cc[0]=='C'){
                sides.PB(cur);
                cur=sz;
            }
        }
        double minarea = gettriarea()+getsquarearea();
        double totarea = sides[1]*sides[2];
        double ans = totarea-minarea;
        printf("%.4lf\n",ans);
    }
    return 0;
}
