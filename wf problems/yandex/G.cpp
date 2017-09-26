/*-------property of the half blood prince-----*/
//dmehrab06
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
#define MAXP 1000006
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector< VI >xs;
vector< VI >ys;

void init(){
    VI line;
    FREP(i,0,2000015){
        xs.PB(line);
        xs[i].PB(0);
        ys.PB(line);
        ys[i].PB(0);
    }
}

void sortthem(){
    FREP(i,0,2000015){
        SORTV(xs[i]);
        SORTV(ys[i]);
    }
}

set<PII>allpts;

set< vector<PII> >possiblesquares;

int main(){
    int n;
    scanf("%d",&n);
    init();
    int atmost=sqrt(n);
    FREP(i,1,n){
        int x,y;
        scanf("%d %d",&x,&y);
        x+=MAXP;
        y+=MAXP;
        if(xs[x][0]==atmost){
            ys[y][0]++;
            ys[y].PB(x);
        }
        else{
            xs[x][0]++;
            xs[x].PB(y);
        }
        allpts.insert(make_pair(x,y));
    }
    //int total=0;
    sortthem();
    FREP(i,0,2000015){
        int szx=xs[i][0];
        FREP(j,1,szx){
            FREP(k,(j+1),szx){
                int x=i;
                int y1=xs[i][j],y2=xs[i][k];
               // printf("edge paisi ( %d , %d ) and ( %d, %d )\n",x-MAXP,y1-MAXP,x-MAXP,y2-MAXP);
                int d=abs(y1-y2);
                PII p1=make_pair(x+d,y1);PII p2=make_pair(x+d,y2);
                if(allpts.find(p1)!=allpts.end() && allpts.find(p2)!=allpts.end()){
                    //total++;
                    vector<PII>mysquare;
                    mysquare.PB(make_pair(x,y1));mysquare.PB(make_pair(x,y2));
                    mysquare.PB(p1);mysquare.PB(p2);
                    SORTV(mysquare);
                    possiblesquares.insert(mysquare);
                 //   printf("square ache\n");
                }
                p1=make_pair(x-d,y1);p2=make_pair(x-d,y2);
                if(allpts.find(p1)!=allpts.end() && allpts.find(p2)!=allpts.end()){
                    //total++;
                    vector<PII>mysquare;
                    mysquare.PB(make_pair(x,y1));mysquare.PB(make_pair(x,y2));
                    mysquare.PB(p1);mysquare.PB(p2);
                    SORTV(mysquare);
                    possiblesquares.insert(mysquare);
               //     printf("square ache\n");
                }
            }
        }
    }
    FREP(i,0,2000015){
        int szy=ys[i][0];
        FREP(j,1,szy){
            FREP(k,(j+1),szy){
                int y=i;
                int x1=ys[i][j],x2=ys[i][k];
                int d=abs(x1-x2);
               // printf("edge paisi ( %d , %d ) and ( %d, %d )\n",x1-MAXP,y-MAXP,x2-MAXP,y-MAXP);
                PII p1=make_pair(x1,y+d);PII p2=make_pair(x2,y+d);
                if(allpts.find(p1)!=allpts.end() && allpts.find(p2)!=allpts.end()){
                    //total++;
                    vector<PII>mysquare;
                    mysquare.PB(make_pair(x1,y));mysquare.PB(make_pair(x2,y));
                    mysquare.PB(p1);mysquare.PB(p2);
                    SORTV(mysquare);
                    possiblesquares.insert(mysquare);
               //     printf("square ache\n");
                }
                p1=make_pair(x1,y-d);p2=make_pair(x2,y-d);
                if(allpts.find(p1)!=allpts.end() && allpts.find(p2)!=allpts.end()){
                    //total++;
                    vector<PII>mysquare;
                    mysquare.PB(make_pair(x1,y));mysquare.PB(make_pair(x2,y));
                    mysquare.PB(p1);mysquare.PB(p2);
                    SORTV(mysquare);
                    possiblesquares.insert(mysquare);
              //      printf("square ache\n");
                }
            }
        }
    }
    printf("%lld\n",(LLI)possiblesquares.size());
    return 0;
}
