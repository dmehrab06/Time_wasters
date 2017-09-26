#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
#define MNN -MXX
#define DBL double
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
using namespace std;


DBL root3=sqrt(3.0);
DBL dx,dy;
DBL hexn;
struct pti{
    LLI x;
    LLI y;
    pti(LLI _x=0, LLI _y=0){
        x=_x;
        y=_y;
    }
};

pti around[19]={pti(0,0),pti(0,2),pti(0,4),pti(0,-2),pti(0,-4),pti(1,1),pti(1,3),pti(1,-1),pti(1,-3),pti(-1,1),pti(-1,3),pti(-1,-1),pti(-1,-3),pti(2,0),pti(2,2),pti(2,-2),pti(-2,0),pti(-2,2),pti(-2,-2)};

struct pt{
    DBL x;
    DBL y;
    pt(DBL _x=0.0, DBL _y=0.0){
        x=_x;
        y=_y;
    }
    void conv(pti p){
        x=p.x;
        y=p.y;
    }
};


DBL dis(pt a, pt b){
    DBL d=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(d);
}

pti findhex(pt p){
    LLI hx=(LLI)(p.x/dx);
    LLI hy=(LLI)(p.y/dy);
    if((hx+hy)&(1)){
        hy++;
    }
    DBL mindis=-1.0;
    LLI mnx;
    LLI mny;
    FREP(i,0,18){
        LLI curx=hx+around[i].x;
        LLI cury=hy+around[i].y;
        DBL xx=(DBL)curx*dx;
        DBL yy=(DBL)cury*dy;
        pt pp(xx,yy);
        //pp.conv(pti(curx,cury));
        DBL d=dis(pp,p);
        if(mindis<0.0 || d<mindis){
            mnx=curx;
            mny=cury;
            mindis=d;
        }
    }
    pti hxx(mnx,mny);
    return hxx;
}

DBL hexwalk(pti h1, pti h2){
    LLI xdif=abs(h1.x-h2.x);
    LLI ydif=abs(h1.y-h2.y);
    DBL ctoc=hexn*root3;
    if(xdif>ydif){
        return ctoc*xdif;
    }
    else{
        LLI mx=max(h1.y,h2.y);
        LLI mn=min(h1.y,h2.y);
        LLI step=(mx-mn)-xdif;
        step/=2;
        return ctoc*(step+xdif);
    }
}

int main(){
    DBL ax,ay,bx,by;
    //double cut;
    while(scanf("%lf %lf %lf %lf %lf",&hexn,&ax,&ay,&bx,&by)==5){
        if(hexn<eps)break;
        dx=(3.0*hexn)/2.0;
        dy=(root3*hexn)/2.0;
        pti hxA=findhex(pt(ax,ay));
        //cout<<hxA.x<<" "<<hxA.y<<"\n";
        pti hxB=findhex(pt(bx,by));
        if(hxA.x==hxB.x && hxA.y==hxB.y){
            double dd=dis(pt(ax,ay),pt(bx,by));
            printf("%.3lf\n",dd);
            continue;
        }
      //  cout<<hxB.x<<" "<<hxB.y<<"\n";
        pt h1(dx*hxA.x,dy*hxA.y),h2(dx*hxB.x,dy*hxB.y);
        //h1.conv(hxA);
        //h2.conv(hxB);
        DBL dis1=dis(h1,pt(ax,ay));
        DBL dis2=dis(h2,pt(bx,by));
        DBL walk=hexwalk(hxA,hxB);
        printf("%.3lf\n",walk+dis1+dis2);
    }
    return 0;
}
