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
#define PDD pair<double,double>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) (l<=val && val<=r)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

struct line{
    PDD startpoint;
    PDD dir;
    line(PDD p1, PDD p2){
        startpoint = p1;
        dir.first = p2.first-p1.first;
        dir.second = p2.second-p1.second;
        //normalizedir();
        //cout<<"line parameters\n";
        //cout<<startpoint.first<<" "<<startpoint.second<<"\n";
        //cout<<dir.first<<" "<<dir.second<<"\n";
    }
    void normalizedir(){
        double sm = dir.first*dir.first+dir.second*dir.second;
        sm = sqrt(sm);
        dir.first/=sm; dir.second/=sm;
    }
    bool ispointonline(PDD myp){
        //cout<<"for point "<<myp.first<<" "<<myp.second<<"\n";
        if(fabs(dir.first)<eps){
            double t = (myp.second-startpoint.second)/dir.second;
            double xx = startpoint.first + t*dir.first;
            //cout<<xx<<" "<<myp.first<<"\n";
            //cout<<t<<"\n";
            if(fabs(xx-myp.first)<eps){
                if(INRANGED(t,0.0,1.0)){
                    return true;
                }
            }
        }
        else{
            double t = (myp.first-startpoint.first)/dir.first;
            double yy = startpoint.second + t*dir.second;
            //cout<<yy<<" "<<myp.second<<"\n";
            //cout<<t<<"\n";
            if(fabs(yy-myp.second)<eps){
                if(INRANGED(t,0.0,1.0)){
                    return true;
                }
            }
        }

        return false;
    }
    PDD linesolve(line line2){
        double hor = dir.first*line2.dir.second-line2.dir.first*dir.second;
        if(fabs(hor)<eps){
            return make_pair(-1000.00,-1000.00);
        }
        double lob = dir.second*(line2.startpoint.first-startpoint.first)-dir.first*(line2.startpoint.second-startpoint.second);
        double t2 = lob/hor;
        double t1;
        if(fabs(dir.first)<eps){
            t1 = line2.startpoint.second+(t2*line2.dir.second)-startpoint.second;
            t1 = t1/dir.second;
        }
        else{
            t1 = line2.startpoint.first+(t2*line2.dir.first)-startpoint.first;
            t1 = t1/dir.first;
        }
        return make_pair(t1,t2);
    }
    PDD getpoint(double t){
        PDD gopoint;
        gopoint.first = startpoint.first+t*dir.first;
        gopoint.second = startpoint.second+t*dir.second;
        return gopoint;
    }
    bool isparallel(line line2){
        return (dir.first==line2.dir.first && dir.second==line2.dir.second);
    }
    void print(){
        cout<<"line start : "<<startpoint.first<<" "<<startpoint.second<<"\n";
        cout<<"line end : "<<startpoint.first+dir.first<<" "<<startpoint.second+dir.second<<"\n";
    }
};


vector<line>myrec;

int main(){
    int t;
    scanf("%d",&t);
    FREP(i,1,t){
        myrec.clear();
        double x0,y0,x1,y1;
        scanf("%lf %lf %lf %lf",&x0,&y0,&x1,&y1);
        line myl(make_pair(x0,y0),make_pair(x1,y1));
        double xl,yt,xr,yb;
        scanf("%lf %lf %lf %lf",&xl,&yt,&xr,&yb);
        line myl1(make_pair(xl-eps,yt+eps),make_pair(xr+eps,yt+eps));
        line myl2(make_pair(xr+eps,yt+eps),make_pair(xr+eps,yb-eps));
        line myl3(make_pair(xl-eps,yb-eps),make_pair(xr+eps,yb-eps));
        line myl4(make_pair(xl-eps,yb-eps),make_pair(xl-eps,yt+eps));
        myrec.PB(myl1);myrec.PB(myl2);myrec.PB(myl3);myrec.PB(myl4);
        int f=0;

        if(INRANGED(x0,xl,xr) && INRANGED(x1,xl,xr) && INRANGED(y0,yb,yt) && INRANGED(y1,yb,yt)){
            printf("T\n");
            continue;
        }
        if(fabs(x0-x1)<eps && fabs(y0-y1)<eps){
            printf("F\n");
            continue;
        }

        FREP(k,0,myrec.size()-1){
            line currecline = myrec[k];
            PDD tpair = currecline.linesolve(myl);
            if(currecline.ispointonline(currecline.getpoint(tpair.first)) && myl.ispointonline(myl.getpoint(tpair.second))){
                f = 1;
                break;
            }
        }
        if(f)printf("T\n");
        else printf("F\n");

    }
    return 0;
}
