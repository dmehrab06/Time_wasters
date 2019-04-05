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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

vector<int>stairs;
vector<int>lifts;

int timetostair(int sx, int sy, int stairy, int ex, int ey){
    return abs(stairy-sy)+abs(sx-ex)+abs(stairy-ey);
}

int timetolift(int sx, int sy, int lifty, int ex, int ey, int v){
    int dx = abs(sx-ex);
    int lifttime = dx/v;
    if(dx%v)lifttime++;
    //error(lifttime);
    return abs(sy-lifty)+abs(lifty-ey)+lifttime;
}

int main(){
    int n,m,st,lift,v;
    scanf("%d %d %d %d %d",&n,&m,&st,&lift,&v);
    stairs.PB(-1);stairs.PB(0);
    FREP(i,1,st){
        int cc;
        scanf("%d",&cc);
        stairs.PB(cc);
    }
    stairs.PB(m+1);stairs.PB(m+2);
    lifts.PB(-1);lifts.PB(0);
    FREP(i,1,lift){
        int cc;
        scanf("%d",&cc);
        lifts.PB(cc);
    }
    lifts.PB(m+1);lifts.PB(m+2);
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int t = 1000000000;
        int sx, sy, ex, ey;
        scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
        vector<int>::iterator itstair,itlift;
        itstair = upper_bound(stairs.begin(),stairs.end(),sy);
        itlift = upper_bound(lifts.begin(),lifts.end(),sy);
        int lstair = stairs[itstair-stairs.begin()];
        //cout<<lstair<<"\n";
        int rstair = stairs[itstair-stairs.begin()-1];
        //cout<<lstair<<"\n";
        int llift = lifts[itlift-lifts.begin()];
        //cout<<lstair<<"\n";
        int rlift = lifts[itlift-lifts.begin()-1];
        //cout<<lstair<<"\n";
        //error(lstair,rstair,llift,rlift);
        if(INRANGEI(lstair,1,m))t=min(t,timetostair(sx,sy,lstair,ex,ey));
        if(INRANGEI(rstair,1,m))t=min(t,timetostair(sx,sy,rstair,ex,ey));
        if(INRANGEI(llift,1,m))t=min(t,timetolift(sx,sy,llift,ex,ey,v));
        if(INRANGEI(rlift,1,m))t=min(t,timetolift(sx,sy,rlift,ex,ey,v));

        /*itstair = upper_bound(stairs.begin(),stairs.end(),ey);
        itlift = upper_bound(lifts.begin(),lifts.end(),ey);
        lstair = stairs[itstair-stairs.begin()];
        //cout<<lstair<<"\n";
        rstair = stairs[itstair-stairs.begin()-1];
        //cout<<lstair<<"\n";
        llift = lifts[itlift-lifts.begin()];
        //cout<<lstair<<"\n";
        rlift = lifts[itlift-lifts.begin()-1];
        //cout<<lstair<<"\n";
        error(t);
        //error(lstair,rstair,llift,rlift);
        if(INRANGEI(lstair,1,m))t=min(t,timetostair(ex,ey,lstair,sx,sy));
        error(lstair,t);
        if(INRANGEI(rstair,1,m))t=min(t,timetostair(ex,ey,rstair,sx,sy));
        error(rstair,t);
        if(INRANGEI(llift,1,m))t=min(t,timetolift(ex,ey,llift,sx,sy,v));
        error(llift,t);
        if(INRANGEI(rlift,1,m))t=min(t,timetolift(ex,ey,rlift,sx,sy,v));
        error(rlift,t);*/
        if(sx==ex)t=min(t,abs(sy-ey));
        printf("%d\n",t);
    }
    return 0;
}
