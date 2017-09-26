#include <bits/stdc++.h>
#include "bitmap_image.hpp"
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
#define VD vector<double>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(int)(N);(i)++)
#define eps 0.0001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGEI(val,l,r) ((l)<=(val) && (val)<=(r))
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;

//-----------------------vector operations-----------------//
//---------------------------------------------------------//
//---------------------------------------------------------//

int seeddone = 0;

int pixellevel = 1;

int screen_height,screen_width;
int leftx,rightx,lefty,righty;
set<VI>usedcolors;

double linewidth;

int orientation(pair<double,double> p, pair<double,double> q, pair<double,double> r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (fabs(val)<eps) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

double area_convexHull(vector <pair<double,double> > points)
{
    int n=points.size();
    if (n < 3) return 0.0;
    vector< pair<double,double> > hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].first < points[l].first)
            l = i;
    int p = l, q;
    do
    {
        hull.push_back(points[p]); q = (p+1)%n;
        for (int i = 0; i < n; i++){
           if(orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;

    } while (p != l);  // While we don't come to first point

    double area = 0.0;
    int hsz = hull.size();
    for (int i = 0; i < hull.size(); i++)
        area += ((hull[i].first*hull[(i+1)%hsz].second)-(hull[i].second*hull[(i+1)%hsz].first));
    return fabs(area/2.0);
}



struct color{
    int r,g,b;
    color(int _r=0, int _g=0, int _b=0){
        r=_r; g=_g; b=_b;
    }
    int getr(){return r;} void setr(int _r){r=_r;}
    int getg(){return g;} void setg(int _g){g=_g;}
    int getb(){return b;} void setb(int _b){b=_b;}

    void print(){printf("color is ( %d %d %d )\n",r,g,b);}
};

struct point{
    int x,y;
    point(int _x=0, int _y=0){
        x=_x; y=_y;
    }
    int getx(){return x;} void setx(int _x){x=_x;}
    int gety(){return y;} void sety(int _y){y=_y;}

    void print(){printf("point is ( %d, %d )\n",x,y);}
};

struct line{
    double a,b,c;
    point startpoint; point endpoint;
    bool slopereversed;
    bool slopebig;
    line(point _s, point _e){
        startpoint=_s; endpoint=_e;
        if(startpoint.gety()>endpoint.gety()){
            point tmp = startpoint;
            startpoint = endpoint;
            endpoint = tmp;
        }
        if(fabs(endpoint.gety()-startpoint.gety())>fabs(endpoint.getx()-startpoint.getx()))slopebig=true;
        else slopebig = false;
        if(startpoint.getx()>endpoint.getx()){slopereversed=true; endpoint.setx(2*startpoint.getx()-endpoint.getx());}
        else slopereversed = false;
        a = -(startpoint.gety()-endpoint.gety());
        b = (startpoint.getx()-endpoint.getx());
        c = -(startpoint.getx()*a+startpoint.gety()*b);
    }
};

vector < vector <color> > img_color;
vector < line > lines;

double getdis(pair<double,double>p, line l){
    double x0 = p.first; double y0 = p.second;
    //cout<<"checking from point "<<x0<<" "<<y0<<" ";
    double lob = fabs(l.a*x0+l.b*y0+l.c);
    double hor = sqrt(l.a*l.a+l.b*l.b);
    //cout<<"dis here is "<<lob/hor<<"\n";
    return lob/hor;
}

pair<double,double> convpoint(point pt){
    pair<double,double> mypt = make_pair((double)pt.getx(),(double)pt.gety());
    return mypt;
}

struct rectangle{
    vector<point>pts;
    rectangle(vector<point>_pts){
        pts=_pts;
    }
    double findintersectingarea(rectangle r){
        line l1=line(r.pts[0],r.pts[1]);
        line l2=line(r.pts[2],r.pts[3]);
        vector< pair<double,double> >insidepoints;
        FREP(i,0,pts.size()-1){
            pair<double,double> pddpt = convpoint(pts[i]);
            double dis1 = getdis(pddpt,l1);
            double dis2 = getdis(pddpt,l2);
            if(fabs((dis1+dis2)-linewidth)<eps)insidepoints.PB(pddpt);
        }
        FREP(i,0,r.pts.size()-1){
            pair<double,double> pddpt = convpoint(r.pts[i]);
            if(INRANGED(pddpt.first,pts[0].getx(),pts[1].getx()) && INRANGED(pddpt.second,pts[0].gety(),pts[2].gety())){
                insidepoints.PB(pddpt);
            }
        }
    }
};

pair<double,double> getpoint(int px, int py){
    double xx = px+0.5;
    double yy = py+0.5;
    return make_pair(xx,yy);
}

color updcolor(color lcolor, double dis){
    dis=1.0-dis;
    lcolor.r*=dis; lcolor.b*=dis; lcolor.g*=dis;
    return lcolor;
}

VI getrandcolor(){
    VI hukka; hukka.PB(255); hukka.PB(255); hukka.PB(255);
    return hukka;
    if(!seeddone){
        srand(time(0));
        seeddone=1;
    }
    while(true){
        int r=rand()%256;
        int g=rand()%256;
        int b=rand()%256;
        vector<int>curcolor; curcolor.PB(r); curcolor.PB(g); curcolor.PB(b);
        if(usedcolors.find(curcolor)==usedcolors.end()){
            usedcolors.insert(curcolor);
            return curcolor;
        }
    }
}

color convert(VI colv){
    color mycolor(colv[0],colv[1],colv[2]);
    return mycolor;
}

PII findrev(int x0, int y0, int x, int y, bool rev){
    if(!rev)return make_pair(x,y);
    return make_pair(2*x0-x,y);
}

void writepixel(int x0, int y0, int x, int y, bool rev, line ll, color linecolor){
    PII pp=findrev(x0,y0,x,y,rev);
    if(INRANGEI(pp.first,leftx,rightx-1) && INRANGEI(pp.second,lefty,righty-1)){
        pair<double,double>pt = getpoint(pp.first,pp.second);
        double dis =getdis(pt,ll);
        color newcolor = updcolor(linecolor,dis);
        img_color[pp.second-lefty][pp.first-leftx] = newcolor;
    }
}

void unwsmallslope(int x0, int y0, int x1, int y1, color linecolor, bool rev, line ll){
    //cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<"\n";
    int dx = x1-x0; int dy = y1-y0; int d = 2*dy-dx;
    int iE = 2*dy; int iNE = 2*(dy-dx);
    int x = x0; int y = y0;
    for(int lev=-pixellevel;lev<=pixellevel;++lev){
        writepixel(x0,y0,x,y+lev,rev,ll,linecolor);
    }
    while(x<x1){
        //cout<<"d er value "<<d<<"\n";
        if(d<=0){
            //cout<<"d minus\n";
            d+=iE; x++;
        }
        else{
            //cout<<"d plus\n";
            d+=iNE; x++; y++;
        }
        for(int lev=-pixellevel;lev<=pixellevel;++lev){
            writepixel(x0,y0,x,y+lev,rev,ll,linecolor);
        }
    }
}

void unwbigslope(int x0, int y0, int x1, int y1, color linecolor, bool rev, line ll){
    //cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<"\n";
    //cout<<"in big\n";
    int dx = x1-x0; int dy = y1-y0; int d = 2*dx-dy;
    int iN = 2*dx; int iNE = 2*(dx-dy);
    int x = x0; int y = y0;
    for(int lev=-pixellevel;lev<=pixellevel;++lev){
        writepixel(x0,y0,x+lev,y,rev,ll,linecolor);
    }
    while(y<y1){
        //cout<<"d er value "<<d<<"\n";
        if(d<=0){
            //cout<<"d minus\n";
            d+=iN; y++;
        }
        else{
            //cout<<"d plus\n";
            d+=iNE; x++; y++;
        }
        for(int lev=-pixellevel;lev<=pixellevel;++lev){
            writepixel(x0,y0,x+lev,y,rev,ll,linecolor);
        }
    }
}

void solve1(){
    FREP(i,0,(lines.size()-1)){
        cout<<i<<"\n";
        line curline = lines[i];
        point sp = curline.startpoint ; point ep = curline.endpoint;
        color lcolor = convert(getrandcolor());
        if(curline.slopebig)unwbigslope(sp.getx(),sp.gety(),ep.getx(),ep.gety(),lcolor,curline.slopereversed,curline);
        else unwsmallslope(sp.getx(),sp.gety(),ep.getx(),ep.gety(),lcolor,curline.slopereversed,curline);
    }
}

void read_data(){
    ifstream fin("input.txt");
    fin>>screen_width>>screen_height;
    if(screen_height%2)screen_height++;if(screen_width%2)screen_width++;
    righty=(screen_height/2); lefty = -righty;
    rightx=(screen_width/2); leftx = -rightx;
    cout<<leftx<<" "<<rightx<<" "<<lefty<<" "<<righty<<"\n";
    int n;
    fin>>n;
    FREP(i,1,n){
        double a,b,c;
        fin>>a>>b>>c;
        double x1,y1,x2,y2;
        fin>>x1>>y1>>x2>>y2;
        int xx1 = round(x1); int xx2 = round(x2); int yy1 = round(y1); int yy2 = round(y2);
        point p1(xx1,yy1); point p2(xx2,yy2);
        line l(p1,p2);
        lines.PB(l);
    }
    fin.close();
}

void init_buffers(){
    //height borabor y, width borabor x
    //so row borabor y, column borabor x
    int width=screen_width;
    int height=screen_height;
    FREP(i,0,(height-1)){
        vector<color>line;
        img_color.PB(line);
        FREP(j,0,width-1){
            img_color[i].PB(color(0,0,0));
        }
    }
}

void save(int i){
    bitmap_image image(screen_width,screen_height);
    for(int j=0;j<screen_height;j++){
        for(int i=0;i<screen_width;i++){
            image.set_pixel(i,j,img_color[screen_height-1-j][i].r,img_color[screen_height-1-j][i].g,img_color[screen_height-1-j][i].b);
        }
    }
    string idx; if(i==1)idx="1";if(i==2)idx="2";if(i==3)idx="3";
    image.save_image(idx+".bmp");

}

void free_memory(){
    img_color.clear();
    vector< vector<color> >().swap(img_color);
    usedcolors.clear();
    set<VI>().swap(usedcolors);
}

int main(){
    read_data();
    init_buffers();
    //cout<<"read hoise\n";
    solve1();
    save(2);
    return 0;
}
