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
    PDD getendp(){
        return make_pair(startpoint.first+dir.first,startpoint.second+dir.second);
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
        if(fabs(dir.first)<eps)return fabs((line2.dir.first)<eps);
        if(fabs(dir.second)<eps)return fabs((line2.dir.second)<eps);
        return (fabs((line2.dir.first/dir.first)-(line2.dir.second/dir.second))<eps);
    }
    void print(){
        cout<<"line start : "<<startpoint.first<<" "<<startpoint.second<<"\n";
        cout<<"line end : "<<startpoint.first+dir.first<<" "<<startpoint.second+dir.second<<"\n";
    }
};

double dot(PDD a, PDD b) {
	return (a.first*b.first+a.second*b.second);
}

PDD sub(PDD a, PDD b){
    return make_pair(a.first-b.first,a.second-b.second);
}

bool between(PDD a, PDD b, PDD c) { //is c between a and b
	return (dot(sub(c,a),sub(b,a))>=0.0) && (dot(sub(c,b),sub(a,b))>=0.0);
}

pair<double,PDD>getabc(line l1){
    PDD st = l1.startpoint;
    PDD ed = l1.getendp();
    double a = st.second - ed.second;
    double b = ed.first - st.first;
    double c = -st.second*(b)-st.first*(a);
    return make_pair(c,make_pair(a,b));
}

double distProjection(PDD beg, PDD ed, PDD proj) {
	pair<double,PDD>abc = getabc(line(beg,ed));
	double c = abc.first; double a = abc.second.first; double b = abc.second.second;
	return fabs(a*proj.first+b*proj.second+c)/sqrt(a*a+b*b);
}

double solve2line(line l1, line l2){ //L and L hole parbo

    pair<double,PDD>abc1 = getabc(l1);
    pair<double,PDD>abc2 = getabc(l2);

    double c1 = abc1.first; double a1 = abc1.second.first; double b1 = abc1.second.second;
    double c2 = abc2.first; double a2 = abc2.second.first; double b2 = abc2.second.second;

    if(fabs(a1*b2-a2*b1)>=eps) return 0;

    PDD l1s = l1.startpoint;
    PDD l1e = l1.getendp();
    PDD l2s = l2.startpoint;

    double dis = distProjection(l1s,l1e,l2s);
    return dis;

}

double getdis(PDD a, PDD b){
    double xx = a.first-b.first;
    double yy = a.second-b.second;
    return sqrt(xx*xx+yy*yy);
}

double solvelineseg(line l1, line l2){ //l1 is line , l2 is segment
    pair<double,PDD>abc = getabc(l1);
    double c = abc.first; double a = abc.second.first; double b = abc.second.second;
    double p, q;
    PDD st = l2.startpoint;
    PDD ed = l2.getendp();
    p = a*st.first+b*st.second+c;
    q = a*ed.first+b*ed.second+c;
    if((p*q)<0 || fabs(p*q)<eps) return 0; // segment line re cross korse
    return min(distProjection(l1.startpoint,l1.getendp(),st), distProjection(l1.startpoint,l1.getendp(), ed));
}

double solvesegseg(line l1, line l2){
    PDD oka = l1.linesolve(l2);
    if(INRANGED(oka.first,0.0,1.0) && INRANGED(oka.second,0.0,1.0))return 0.0; //segments are intersecting
    double dis = 1e+40;

    PDD l1s = l1.startpoint; PDD l1e = l1.getendp();
    PDD l2s = l2.startpoint; PDD l2e = l2.getendp();

    //cout<<l1s.first<<" "<<l1s.second<<" "<<l1e.first<<" "<<l1e.second<<"\n";
    //cout<<l2s.first<<" "<<l2s.second<<" "<<l2e.first<<" "<<l2e.second<<"\n";

    if(between(l2s,l2e,l1s))dis=min(dis,distProjection(l2s,l2e,l1s));
    else dis=min(dis,min(getdis(l1s,l2s),getdis(l1s, l2e)));

    //cout<<dis<<"\n";

    if(between(l2s,l2e,l1e))dis=min(dis,distProjection(l2s,l2e,l1e));
    else dis=min(dis,min(getdis(l2s,l1e),getdis(l2e,l1e)));
    //do the same now for l2

    //cout<<dis<<"\n";

    if(between(l1s,l1e,l2s))dis=min(dis,distProjection(l1s,l1e,l2s));
    else dis=min(dis,min(getdis(l2s,l1s),getdis(l2s, l1e)));

    //cout<<dis<<"\n";

    if(between(l1s,l1e,l2e))dis=min(dis,distProjection(l1s,l1e,l2e));
    else dis=min(dis,min(getdis(l1s,l2e),getdis(l1e,l2e)));

    //cout<<dis<<"\n";

    return dis;
}

int main() {
    double l1x1,l1y1,l1x2,l1y2; string type1;
    double l2x1,l2y1,l2x2,l2y2; string type2;
    while(true){
        cin>>l1x1>>l1y1>>l1x2>>l1y2>>type1;
        cin>>l2x1>>l2y1>>l2x2>>l2y2>>type2;
        if(type1=="END")break;
        line l1(make_pair(l1x1,l1y1),make_pair(l1x2,l1y2));
        line l2(make_pair(l2x1,l2y1),make_pair(l2x2,l2y2));
        double ans;
        if(type1==type2){
            if(type1=="L"){
                ans = solve2line(l1,l2);
            }
            else{
                ans = solvesegseg(l1,l2);
            }
        }
        else{
            if(type1=="L"){
                ans = solvelineseg(l1,l2);
            }
            else{
                line t = l1;
                l1 = l2;
                l2 = t;
                ans = solvelineseg(l1,l2);
            }
        }
        printf("%.5lf\n",ans);
    }
	return 0;
}
