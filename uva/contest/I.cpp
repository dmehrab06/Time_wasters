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
#define PDD pair<double,double>
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

struct line{
    PDD startpoint;
    PDD dir;
    PDD normaldir;
    line(PDD p1, PDD p2){
        startpoint = p1;
        dir.first = p2.first-p1.first;
        dir.second = p2.second-p1.second;
        normaldir.first = -dir.second;
        normaldir.second = dir.first;
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
            return make_pair(10000000000.00,10000000000.00);
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

vector<PDD>point_list;
vector<int>point_validity;
vector<line>line_list;

vector<PDD>players;
vector<int>teamid;

vector<PDD>recpoints;

int lx,by,rx,ty;

double sq(double x){return x*x;}

void checkfurthervalidity(int lx, int by, int rx, int ty){
    double llx=lx; double bby=by; double rrx=rx; double tty=ty;
    FREP(i,0,point_list.size()-1){
        if(INRANGED(point_list[i].first,llx,rrx) && INRANGED(point_list[i].second,bby,tty)){

        }
        else{
            point_validity[i]=0;
        }
    }
}

double getdis(PDD f, PDD s){
    return sqrt(sq(f.first-s.first)+sq(f.second-s.second));
}

double get_clockwise_angle(PDD p)
{
    double angle = 0.0;
    //int quadrant = get_quadrant(p);

    /*making sure the quadrants are correct*/
    //cout << "Point: " << p << " is on the " << quadrant << " quadrant" << endl;

    /*calculate angle and return it*/
    angle = -atan2(p.first,-p.second);
    return angle;
}

bool cmp(PDD &a, PDD &b){
    //double da = getdis(a,make_pair(0.0,0.0));
    //double db = getdis(b,make_pair(0.0,0.0));
    //double ta = acos(a.first/da); double tb = acos(b.first/db);
    double ta = get_clockwise_angle(a);
    double tb = get_clockwise_angle(b);
    return ta<tb;
}

double orderandcalc(PDD center){
    checkfurthervalidity(lx,by,rx,ty);
    vector<PDD>allpts;
    FREP(i,0,point_list.size()-1){
        if(point_validity[i]==1){
            allpts.push_back(point_list[i]);
        }
    }
    FREP(i,0,allpts.size()-1){
        allpts[i].first-=center.first;
        allpts[i].second-=center.second;
    }
    sort(allpts.begin(),allpts.end(),cmp);
    FREP(i,0,allpts.size()-1){
        allpts[i].first+=center.first;
        allpts[i].second+=center.second;
    }
    //FREP(i,0,allpts.size()-1){
      //  cout<<allpts[i].first<<" "<<allpts[i].second<<"\n";
   // }
   if(allpts.size()<3){
    return 0.0;
   }
    double ar = 0.0;
    FREP(i,0,allpts.size()-1){
        int cc = i; int nn = (i+1)%allpts.size();
        double v1 = allpts[cc].first*allpts[nn].second;
        double v2 = allpts[cc].second*allpts[nn].first;
        ar = ar + (v1-v2);
    }
    return fabs(ar/2.0);
}

void init(){
    recpoints.clear();
    players.clear();
    teamid.clear();
}

void calcrpt(int lx, int by, int rx, int ty){
    recpoints.PB(make_pair(lx,by));
    recpoints.PB(make_pair(rx,by));
    recpoints.PB(make_pair(rx,ty));
    recpoints.PB(make_pair(lx,ty));
}

void insertrlines(){
    FREP(i,0,3){
        int c = i; int n = (i+1)%4;
        line l(recpoints[c],recpoints[n]);
        line_list.push_back(l);
    }
}

PDD getpointfront(PDD start, PDD dir){
    return make_pair(start.first+dir.first,start.second+dir.second);
}

bool issame(PDD f, PDD s){
    return (fabs(f.first-s.first)<eps && fabs(f.second-s.second)<eps);
}

PDD mid(PDD f, PDD s){
    return make_pair((f.first+s.first)/2.0,(f.second+s.second)/2.0);
}

double getplayerarea(int idx, int n){
    line_list.clear();
    point_list.clear();
    point_validity.clear();
    insertrlines();
    //cout<<"in "<<idx<<"\n";
    FREP(i,0,n-1){
        if(i==idx){
            continue;
        }
        if(issame(players[i],players[idx]))return 0.0;
        line l(players[idx],players[i]);
        PDD m = mid(players[idx],players[i]);
        PDD normp = getpointfront(m,l.normaldir);
        line thisl(m,normp);
        line_list.push_back(thisl);
    }
    /*FREP(i,0,line_list.size()-1){
        line_list[i].print();
    }*/
    FREP(i,0,line_list.size()-1){
        FREP(j,(i+1),(line_list.size()-1)){
            PDD tt = line_list[i].linesolve(line_list[j]);
            PDD pt = line_list[i].getpoint(tt.first);
            point_list.push_back(pt);
            point_validity.push_back(1);
        }
    }
    //FREP(i,0,point_list.size()-1){
      //  cout<<point_list[i].first<<" "<<point_list[i].second<<"\n";
    //}
    PDD curpoint = players[idx];
    FREP(k,0,point_list.size()-1){
        PDD pp = point_list[k];
        double d = getdis(curpoint,pp);
        FREP(i,0,(n-1)){
            if(i==idx)continue;
            if(getdis(players[i],pp)<d){
                point_validity[k]=0;
                break;
            }
        }
    }
    return orderandcalc(curpoint);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        //int lx,by,rx,ty;
        scanf("%d %d %d %d",&lx,&by,&rx,&ty);
        calcrpt(lx,by,rx,ty);
        int n;
        scanf("%d",&n);
        FREP(i,1,(2*n)){
            int x,y;
            scanf("%d %d",&x,&y);
            players.PB(make_pair(x,y));
        }
        double gg = 0.0;
        FREP(i,0,(n-1)){
            double aa = getplayerarea(i,2*n);
            //cout<<aa<<"\n";
            gg+=aa;
        }
        double ss = 0.0;
        FREP(i,n,(2*n-1)){
            double aa = getplayerarea(i,2*n);
            //cout<<aa<<"\n";
            ss+=aa;
        }
        cout<<gg<<" "<<ss<<"\n";
        if(gg>ss){
            printf("Gryffindor\n");
        }
        else{
            printf("Slytherin\n");
        }
    }
    return 0;
}
