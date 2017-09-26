#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define MAXMOD 100000000

using namespace std;

struct pt{
    double x;
    double y;
    pt(double _x=0.0, double _y=0.0){
        x=_x;
        y=_y;
    }
};

pt cirint(double x1, double y1, double r1, double x2, double y2, double r2, int sign){
    double A=(x2-x1)*2.0;
    double B=(y2-y1)*2.0;
    double C=(r1*r1-r2*r2)+(x2*x2-x1*x1)+(y2*y2-y1*y1);
    double P=1+((A*A)/(B*B));
    double Q=((2*C*A)/(B*B))+(2*x1)-((2*y1*A)/B);
    double R=((C*C)/(B*B))+(x1*x1)-((2*y1*C)/B)+(y1*y1)-(r1*r1);
    double nischaoyok=sqrt((Q*Q)-(4*P*R));
    double XA=(Q+nischaoyok)/(2*P);
    double YA=(C-(XA*A))/B;
    double val1=(XA-x2)*(YA+y2);
    double XB=(Q-nischaoyok)/(2*P);
    double YB=(C-(XB*A))/B;
    double val2=(XB-x2)*(YB+y2);
    if(fabs(val1)<eps){
        if(val2>0.00){
            return pt(XB,YB);
        }
        else{
            return pt(XA,YA);
        }
    }
    else if(fabs(val2)<eps){
        if(val1>0.00){
            return pt(XA,YA);
        }
        else{
            return pt(XB,YB);
        }
    }
    else{
        if(val1>0.00){
            return pt(XA,YA);
        }
        else{
            return pt(XB,YB);
        }
    }
}

vector<double>sides;

double calc(double rad){
    double x=1/(2*rad);
    double val=0.0;
    int l=sides.size();
    FREP(i,0,(l-1)){
        double xx=x*sides[i];
       // if(xx<-1.00 || xx>1.000)return (double)MXX;
        val+=asin(xx);
    }
    return val;
}

vector<pt>result;

double bestx,besty,bestr;
double lastdeviation=MXX;
int xd,yd;

double simulate(int n,double x1, double y1, double r1){
    double curx=0.0;
    double cury=sides[0];
    double nxtl=sides[1];
    pt pt1=cirint(x1,y1,r1,curx,cury,nxtl,0);
    curx=pt1.x;
    cury=pt1.y;
    //result.PB(pt(curx,cury));
    FREP(i,2,(n-2)){
        nxtl=sides[i];
        pt pt1=cirint(x1,y1,r1,curx,cury,nxtl,0);
        //pt pt2=cirint(x1,y1,r1,curx,cury,nxtl,1);
        curx=pt1.x;
        cury=pt1.y;
        //result.PB(pt(curx,cury));
    }
    //finally
    double findis=sqrt((curx*curx)+(cury*cury));
    double dev=fabs(findis-sides[n-1]);
    if(dev<lastdeviation){
        lastdeviation=dev;
        bestx=x1;
        besty=y1;
        bestr=r1;
    }
    return dev;
}

void finalsimulate(int n,double x1, double y1, double r1){
    result.PB(pt(0.0,0.0));
    result.PB(pt(0.0,sides[0]));
    double curx=0.0;
    double cury=sides[0];
    double nxtl=sides[1];
    pt pt1=cirint(x1,y1,r1,curx,cury,nxtl,0);
    curx=pt1.x;
    cury=pt1.y;
    result.PB(pt(curx,cury));
    FREP(i,2,(n-2)){
        nxtl=sides[i];
        pt pt1=cirint(x1,y1,r1,curx,cury,nxtl,0);
        curx=pt1.x;
        cury=pt1.y;
        result.PB(pt(curx,cury));
    }
}

struct triple{
    double x,y,r;
    triple(double _x=0.0, double _y=0.0, double _r=0.0){
        x=_x;
        y=_y;
        r=_r;
    }
};

triple gettrip(double y){
    double B=y;
    double A=(sides[1]*sides[1])-(B-sides[0])*(B-sides[0]);
    A=sqrt(A);
    double x1=(A*A+B*B-B*sides[0])/(2.0*A);
    double y1=sides[0]/2.00;
    double r1=sqrt(x1*x1+y1*y1);
    triple tt(x1,y1,r1);
    return tt;
}

//1 means + er dike
//-1 means - er dike
int main(){
    int n;
    scanf("%d",&n);
    double mxside=MNN;
    FREP(i,1,n){
        double side;
        scanf("%lf",&side);
        sides.PB(side);
        if(side>mxside){
            mxside=side;
        }
    }
   // double r1=findrad();
    double h=sides[0]+sides[1];
    double l=sides[0]-sides[1];
    h=h-0.00001;
    l=l+0.00001;
    double coverage=h-l;
    double step=coverage/1000.00;
    double bstdev=MXX;
    double bst;
    for(double y=l;y<=h;y=y+step){
        //double mid=(l+h)/2.0;
        triple ret=gettrip(y);
       /* double dev=simulate(n,ret.x,ret.y,ret.r);
        if(!(fabs(fabs(dev)-bstdev)<eps)){
            if(fabs(dev)<bstdev){
                bstdev=fabs(dev);
                bst=y;
               // break;
            }
        }*/
        double ret2=calc(ret.r);
        if(fabs(ret2-pi)<eps && ret.r>mxside){
            //printf("paisi\n");
            bst=y;
            break;
        }
        else{
            if(fabs(ret2-pi)<bstdev){
                bstdev=fabs(ret2-pi);
                bst=y;
            }
        }
       /* else{
            triple ret2=gettrip(mid+0.00000001);
            double dev2=simulate(n,ret2.x,ret2.y,ret2.r);
            if(fabs(dev2)<fabs(dev)){
                l=mid;
            }
            else{
                h=mid;
            }
        }*/
    }
    /*if(bst<-999999.00){
        bst=l;
    }*/
   // printf("%.10lf\n",bst);
    triple bestret=gettrip(bst);
    finalsimulate(n,bestret.x,bestret.y,bestret.r);
   // printf("%.10lf\n",r1);
    //r1=
    int ll=result.size();
    FREP(i,0,(ll-1)){
        printf("%.10lf\n%.10lf\n\n",result[i].x,result[i].y);
    }
    return 0;
}
