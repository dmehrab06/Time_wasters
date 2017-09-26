/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define CCW 1
#define CW -1
using namespace std;

struct myvector{
    int dim;
    vector<double>w;
    vector<double>unit;
    double length;
    myvector(){

    }
    myvector(vector<double> inp){
        dim=inp.size();
        FREP(i,1,dim)w.PB(inp[i-1]);
        double sq=0;
        FREP(i,0,(dim-1)){
            sq=sq+(w[i]*w[i]);
        }
        length=sqrt(sq);
        FREP(i,0,(dim-1)){
            unit.PB(w[i]/length);
        }
    }
};

bool isunit(myvector a){
    if(fabs(a.length-1.00)<eps)return true;
    return false;
}

//vector operations

myvector add(myvector a, myvector b){
    int d=a.dim;
    vector <double> result;
    FREP(i,0,(d-1)){
        result.PB((a.w[i])+(b.w[i]));
    }
    myvector fin(result);
    return fin;
}

//scalar multiplication

myvector scalmul(myvector a, double scale){
    int d=a.dim;
    vector<double>result;
    FREP(i,0,(d-1)){
        result.PB((a.w[i])*scale);
    }
    myvector fin(result);
    return fin;
}

//dot product

double dot(myvector a, myvector b){
    int d=a.dim;
    double s=0;
    FREP(i,0,(d-1)){
        s=s+(a.w[i]*b.w[i]);
    }
    return s;
}

//finding angle between two vectors

double ang(myvector a, myvector b){
    double dotprod=dot(a,b);
    double mylen=a.length*b.length;
    double costheta=dotprod/mylen;
    return acos(costheta);
}

//rotation 2D only

myvector rotate2D(myvector a, double angle, int dir){
    double ax=a.w[0];
    double ay=a.w[1];
    vector<double>perp;
    if(dir==CCW){
        perp.PB(-ay);
        perp.PB(ax);
    }
    else{
        perp.PB(ay);
        perp.PB(-ax);
    }
    myvector perpa(perp);
    perpa=scalmul(perpa,sin(angle));
    a=scalmul(a,cos(angle));
    a=add(a,perpa);
    return a;
}

//cross product only for 3D

myvector cross(myvector a, myvector b){
    vector<double>fin;
    fin.PB(a.w[1]*b.w[2]-a.w[2]*b.w[1]);
    fin.PB(a.w[2]*b.w[0]-a.w[0]*b.w[2]);
    fin.PB(a.w[0]*b.w[1]-a.w[1]*b.w[0]);
    myvector res(fin);
    return res;
}

//rotation 3D  applicable when vector and reference are perpendicular

myvector rotate3D(myvector l, myvector refernc, double angle, int dir){
    if(dir==CCW){
        myvector u=cross(refernc,l);
        u=scalmul(u,sin(angle));
        l=scalmul(l,cos(angle));
        return add(l,u);
    }
    myvector u=cross(l,refernc);
    u=scalmul(u,sin(angle));
    l=scalmul(l,cos(angle));
    return add(l,u);
}

//orthogonal decomposition
//decompose c along unit vector v and perp(v)
pair<myvector,myvector> orthogon(myvector c, myvector v){
    if(!isunit(v)){
        vector<double>vals=v.unit;
        myvector unitv(vals);
        v=unitv;
    }
    double length=dot(c,v);
    myvector compalongv=scalmul(v,length);
    myvector compalongperpv=add(c,scalmul(compalongv,-1));
    pair<myvector,myvector>ret=make_pair(compalongv,compalongperpv);
    return ret;
}

//reflection of vector a with respect to n

myvector reflection(myvector a, myvector n){
    if(!isunit(n)){
        vector<double>vals=n.unit;
        myvector unitn(vals);
        n=unitn;
    }
    double val1=dot(a,n);
    val1=val1*2;
    myvector comp2=scalmul(n,val1);
    myvector r=add(a,scalmul(comp2,-1));
    return r;
}

struct mypoint{
    vector<double>pts;
    int dim;
    mypoint(vector<double>_pts){
        dim=_pts.size();
        pts=_pts;
    }
    mypoint(myvector v){
        dim=v.w.size();
        pts=v.w;
    }
};

struct myline{
    myvector P;
    myvector dir;
    //line represented as P+t*dir where t is a paramater
    myline(mypoint p1, mypoint p2){
        myvector newP1(p1.pts);
        myvector newP2(p2.pts);
        P=newP1;
        dir=add(newP2,scalmul(newP1,-1));
    }
    myline(myvector _p, myvector _dir){
        P=_p;
        dir=_dir;
    }
};

struct myplane{
    myvector C;
    myvector normal;
    double dis;
    myplane(myvector _C, myvector _n){
        C=_C;
        normal=_n;
        dis=dot(C,normal);
    }
};

bool isPointonLine(myline L, myvector Pt){
    mypoint mypt(Pt);
    bool tset=false;
    double initt;
    int sz=mypt.dim;
    FREP(i,0,(sz-1)){
        if(fabs(L.dir.w[i])<eps){
            //dir 0 cannot divide
            if(fabs(mypt.pts[i]-L.P.w[i])>eps){
                return false;
            }
        }
        else{
            double curt=(mypt.pts[i]-L.P.w[i])/(L.dir.w[i]);
            if(!tset){
                initt=curt;
                tset=true;
            }
            else{
                if(fabs(curt-initt)>eps){
                    return false;
                }
            }
        }
    }
    return true;
}

bool isPointonPlane(myplane Plane, myvector Pt){
    mypoint mypt(Pt);
    double sum=0;
    int sz=mypt.dim;
    FREP(i,0,(sz-1)){
        sum=sum+(Plane.normal.w[i])*(mypt.pts[i]);
    }
    if(fabs(sum-Plane.dis)<eps){
        return true;
    }
    return false;
}

bool isLineParalleltoPlane(myline line, myplane plane){
    double val=dot(plane.normal,line.dir);
    if(fabs(val)<eps)return true;
    return false;
}

bool isLineIncidenttoPlane(myline line, myplane plane){
    //first choose an arbitrary point
    if(isPointonPlane(plane,line.P) && isLineParalleltoPlane(line,plane)){
        return true;
    }
    return false;
}

double distbetnpoints(mypoint a, mypoint b){
    int sz=a.dim;
    double sum=0;
    FREP(i,0,(sz-1)){
        sum=sum+(a.pts[i]-b.pts[i])*(a.pts[i]-b.pts[i]);
    }
    return sqrt(sum);
}

pair<double,myvector> lineplaneintersection(myline line, myplane plane){
    double nc=dot(plane.normal,line.P);
    double nd=dot(plane.normal,line.dir);
    double t=(plane.dis-nc)/nd;
    vector<double>intersect;
    int sz=line.dir.dim;
    FREP(i,0,(sz-1)){
        intersect.PB(line.P.w[i]+(t*line.dir.w[i]));
    }
    myvector ret(intersect);
    return make_pair(t,ret);
}

bool ispointinsidebox(myvector Pt, myvector boxcorner){
    int sz=Pt.dim;
    FREP(i,0,(sz-1)){
        if(!(0<=Pt.w[i] && Pt.w[i]<=boxcorner.w[i]))return false;
    }
    return true;
}


int main(){
    return 0;
}
