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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double getArea(vector<PDD>pts){
    double s = 0.0;
    FREP(i,0,pts.size()-1){
        s = s+(pts[i].first*pts[(i+1)%pts.size()].second);
        s = s-(pts[i].second*pts[(i+1)%pts.size()].first);
    }
    return fabs(s/2.0);
}

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

double sq(double a){return a*a;}


double dis(PDD a, PDD b){
    return sqrt(sq(a.first-b.first)+sq(a.second-b.second));
}

int main(){
    int n;
    cin>>n;
    double px,py;
    cin>>px>>py;
    PDD p = make_pair(px,py);
    vector<PDD>allpts;
    double mxrr = 0.0;
    double mnrr = 100000000.0;
    FREP(i,1,n){
        double x,y;
        cin>>x>>y;
        PDD pp = make_pair(x,y);
        mxrr = max(mxrr,dis(p,pp));
        mnrr = min(mnrr,dis(p,pp));
        allpts.PB(pp);
    }
    cout<<mnrr<<"\n";
    FREP(i,0,allpts.size()-1){
        PDD nw = allpts[i];
        PDD nx = allpts[(i+1)%allpts.size()];
        double a = nw.second-nx.second;
        double b = nx.first-nw.first;
        double c = -a*nw.first-b*nw.second;
        double lob = (a*p.first+b*p.second+c);
        lob = fabs(lob);
        double hor = sqrt(a*a+b*b);
        cout<<lob/hor<<"\n";
        mnrr = min(mnrr,lob/hor);
    }
    double ans = PI*((mxrr*mxrr)-(mnrr*mnrr));
    printf("%.10lf\n",ans);
    return 0;
}
