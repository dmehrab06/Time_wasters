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

vector<PII>pts;
vector<PDD>ans;

int ansflag;

PDD conv(PII pt){
    PDD myp;
    myp.first = pt.first; myp.second = pt.second;
    return myp;
}

void init(){
    ansflag = 0;
    pts.clear();
    ans.clear();
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

void solve1(){
    FREP(i,0,3){
        FREP(j,(i+1),3){
            vector<PII>astrays;
            FREP(k,0,3){
                if(k!=i && k!=j){
                    astrays.PB(pts[k]);
                }
            }
            PDD pt1 = conv(pts[i]);
            PDD pt2 = conv(pts[j]);
            line line1(pt1,pt2);
            //line1.normalizedir();
            line line2(pt2,pt1);
            //line2.normalizedir();
            //cout<<"line formed with "<<i<<" "<<j<<"\n";
            int ll = astrays.size();
            FREP(k,0,(ll-1)){
                PDD curpt = conv(astrays[k]);
                if(line1.ispointonline(curpt) || line2.ispointonline(curpt)){
                    //cout<<curpt.first<<" "<<curpt.second<<" line er majhkhane pawa geche\n";
                    if(ansflag==0){
                        ans.PB(pt1);
                        ans.PB(pt2);
                        if(k==0){
                            ans.PB(conv(astrays[1]));
                        }
                        else{
                            ans.PB(conv(astrays[0]));
                        }
                        ansflag =1;
                    }
                }
            }
        }
    }
}

void solve2(){
    FREP(i,0,3){
        FREP(j,0,3){
            if(i==j)continue;
            line ll(conv(pts[i]),conv(pts[j]));
            vector<PDD>astray;
            FREP(k,0,3){
                if(k!=i && k!=j){
                    astray.PB(conv(pts[k]));
                }
            }
            line ll1(astray[0],astray[1]);
            PDD sol1 = ll.linesolve(ll1);
            if((sol1.first>1.0 || fabs(sol1.first-1.0)<eps) && (sol1.second>1.0 || fabs(sol1.second-1.0)<eps)){
                //ll.print();
                //cout<<"er sathe\n";
                //ll1.print();
                //cout<<"chedbindu sofol\n";
                if(ansflag == 0){
                    ans.PB(make_pair(ll.startpoint.first,ll.startpoint.second));
                    ans.PB(make_pair(ll1.startpoint.first,ll1.startpoint.second));
                    ans.PB(ll.getpoint(sol1.first));
                    int valid = 1;
                    FREP(m,0,2){
                        if(!INRANGED(ans[m].first,-1000000,1000000) || !INRANGED(ans[m].second,-1000000,1000000)){
                            valid = 0;
                            break;
                        }
                    }
                    if(!valid){
                        ans.clear();
                    }
                    else{
                        ansflag = 1;
                    }
                }
            }
            line ll2(astray[1],astray[0]);
            PDD sol2 = ll.linesolve(ll2);
            if((sol2.first>1.0 || fabs(sol2.first-1.0)<eps) && (sol2.second>1.0 || fabs(sol2.second-1.0)<eps)){
                //ll.print();
                //cout<<"er sathe\n";
                //ll2.print();
                //cout<<"chedbindu sofol\n";
                if(ansflag == 0){
                    ans.PB(make_pair(ll.startpoint.first,ll.startpoint.second));
                    ans.PB(make_pair(ll2.startpoint.first,ll2.startpoint.second));
                    ans.PB(ll.getpoint(sol2.first));
                    int valid = 1;
                    FREP(m,0,2){
                        if(!INRANGED(ans[m].first,-1000000,1000000) || !INRANGED(ans[m].second,-1000000,1000000)){
                            valid = 0;
                            break;
                        }
                    }
                    if(!valid){
                        ans.clear();
                    }
                    else{
                        ansflag = 1;
                    }
                }
            }
        }
    }
}

void solve3(){
    FREP(i,0,3){
        FREP(j,0,3){
            if(i==j)continue;
            line ll(conv(pts[i]),conv(pts[j]));
            vector<PDD>astray;
            FREP(k,0,3){
                if(k!=i && k!=j){
                    astray.PB(conv(pts[k]));
                }
            }
            line ll1(astray[0],astray[1]);
            if(ll.isparallel(ll1)){
                //ll.print();
                //cout<<"er sathe\n";
                //ll1.print();
                //cout<<"parallel\n";
                PDD p1 = ll.getpoint(-1.0);
                PDD p2 = ll.getpoint(2.0);

                line ext1(p1,ll1.startpoint);
                line ext2(p2,ll1.getpoint(1.0));

                PDD ched = ext1.linesolve(ext2);

                PDD p3 = ext1.getpoint(ched.first);

                if(INRANGED(p3.first,-1000000,1000000) && INRANGED(p3.second,-1000000,1000000)){
                    if(ansflag == 0){
                        ans.PB(p1);
                        ans.PB(p2);
                        ans.PB(p3);
                        ansflag = 1;

                    }
                }
            }
            line ll2(astray[1],astray[0]);
            if(ll.isparallel(ll2)){
                //ll.print();
                //cout<<"er sathe\n";
                //ll1.print();
                //cout<<"parallel\n";
                PDD p1 = ll.getpoint(-1.0);
                PDD p2 = ll.getpoint(2.0);

                line ext1(p1,ll2.startpoint);
                line ext2(p2,ll2.getpoint(1.0));

                PDD ched = ext1.linesolve(ext2);

                PDD p3 = ext1.getpoint(ched.first);

                if(INRANGED(p3.first,-1000000,1000000) && INRANGED(p3.second,-1000000,1000000)){
                    if(ansflag == 0){
                        ans.PB(p1);
                        ans.PB(p2);
                        ans.PB(p3);
                        ansflag = 1;
                    }
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        FREP(i,1,4){
            int x,y;
            scanf("%d %d",&x,&y);
            PII pt = make_pair(x,y);
            pts.PB(pt);
        }
        solve1();
        solve2();
        solve3();
        if(ansflag==1){
            printf("YES ");
            FREP(i,0,2){
                printf("%.10lf %.10lf ",ans[i].first,ans[i].second);
            }
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
