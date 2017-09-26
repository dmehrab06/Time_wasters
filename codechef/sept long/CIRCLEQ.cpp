#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define float double
using namespace std;


double cx[50005];
double cy[50005];
double r[50005];

float section(float h, float r=1) // returns the positive root of intersection of line y = h with circle centered at the origin and radius r
{
    // assume r is positive, leads to some simplifications in the formula below (can factor out r from the square root)
    return (h<r)?sqrt(r*r-h*h):0; // http://www.wolframalpha.com/input/?i=r+*+sin%28acos%28x+%2F+r%29%29+%3D+h
}

float g(float x, float h, float r=1) // indefinite integral of circle segment
{
    return (.5)*(sqrt(1-x*x/(r*r))*x*r+r*r*asin(x/r)-2*h*x); // http://www.wolframalpha.com/input/?i=r+*+sin%28acos%28x+%2F+r%29%29+-+h
}

float area(float x0, float x1, float h, float r) // area of intersection of an infinitely tall box with left edge at x0, right edge at x1, bottom edge at h and top edge at infinity, with circle centered at the origin with radius r
{
    if(x0>x1)
        swap(x0, x1); // this must be sorted otherwise we get negative area
    float s = section(h, r);
    return g(max(-s,min(s,x1)),h,r)-g(max(-s,min(s,x0)),h,r); // integrate the area
}

float area(float x0, float x1, float y0, float y1, float r) // area of the intersection of a finite box with a circle centered at the origin with radius r
{
    if(y0>y1)
        swap(y0,y1); // this will simplify the reasoning
    if(y0<0) {
        if(y1<0)
            return area(x0, x1, -y0, -y1, r); // the box is completely under, just flip it above and try again
        else
            return area(x0, x1, 0, -y0, r) + area(x0, x1, 0, y1, r); // the box is both above and below, divide it to two boxes and go again
    } else {
        assert(y1 >= 0); // y0 >= 0, which means that y1 >= 0 also (y1 >= y0) because of the swap at the beginning
        return area(x0, x1, y0, r) - area(x0, x1, y1, r); // area of the lower box minus area of the higher box
    }
}

float area(float x0, float x1, float y0, float y1, float cx, float cy, float r) // area of the intersection of a general box with a general circle
{
    x0 -= cx; x1 -= cx;
    y0 -= cy; y1 -= cy;

    return area(x0, x1, y0, y1, r);
}

pair<int, int> s4arr[50005];



struct query{
    int sx, sy, ex, ey;
    query(int _sx=0, int _sy=0, int _ex=0, int _ey=0){
        sx=_sx;
        sy=_sy;
        ex=_ex;
        ey=_ey;
    }
};

query allqs[100005];

pair<int, PII > events[600005];
map<PII,int>pointexist;
int res[100005];
int edgeres[100005];
int vres[100005];
int tree[200010];

const int MxV = 200007;

vector< VI > x2y;
vector< VI > y2x;

void sortall(){
    int l=x2y.size();
    FREP(i,0,(l-1)){
        sort(x2y[i].begin(),x2y[i].end());
    }
    l=y2x.size();
    FREP(i,0,(l-1)){
        sort(y2x[i].begin(),y2x[i].end());
    }
}

int bsinx2y(int x, int sy, int ey){
    if(sy>ey)return 0;
    int l=x2y[x].size();
    int lo=0;
    int hi=l-1;
    int ansl=-1;
    FREP(i,1,50){
        if(lo>hi)break;
        int mid=(lo+hi)/2;
        int cury=x2y[x][mid];
        if(cury>=sy){
            if((mid-1)>=0 && x2y[x][mid-1]>=sy){
                hi=mid;
            }
            else{
                ansl=mid;
                break;
            }
        }
        else{
            lo=mid+1;
        }
    }
    int ansr=-1;
    lo=0;
    hi=l-1;
    FREP(i,1,50){
        if(lo>hi)break;
        int mid=(lo+hi)/2;
        int cury=x2y[x][mid];
        if(cury<=ey){
            if((mid+1)<l && x2y[x][mid+1]<=ey){
                lo=mid+1;
            }
            else{
                ansr=mid;
                break;
            }
        }
        else{
            hi=mid;
        }
    }
    if(ansl<0 || ansr<0 || ansr<ansl)return 0;
    return (ansr-ansl+1);

}

int bsiny2x(int y, int sx, int ex){
    if(sx>ex)return 0;
    int l=y2x[y].size();
    int lo=0;
    int hi=l-1;
    int ansl=-1;
    FREP(i,1,50){
        if(lo>hi)break;
        int mid=(lo+hi)/2;
        int curx=y2x[y][mid];
        if(curx>=sx){
            if((mid-1)>=0 && y2x[y][mid-1]>=sx){
                hi=mid;
            }
            else{
                ansl=mid;
                break;
            }
        }
        else{
            lo=mid+1;
        }
    }
    int ansr=-1;
    lo=0;
    hi=l-1;
    FREP(i,1,50){
        if(lo>hi)break;
        int mid=(lo+hi)/2;
        int curx=y2x[y][mid];
        if(curx<=ex){
            if((mid+1)<l && y2x[y][mid+1]<=ex){
                lo=mid+1;
            }
            else{
                ansr=mid;
                break;
            }
        }
        else{
            hi=mid;
        }
    }
    if(ansl<0 || ansr<0 || ansr<ansl)return 0;
    return (ansr-ansl+1);

}

void inc(int idx)
{
    if(idx <= 0) return;
    while (idx <= MxV && idx > 0){
        tree[idx] = tree[idx]+1;
        idx = idx + (idx & -idx);
    }
}

int cnt(int idx)
{
    if(idx <= 0) return 0;
    int tot = 0;
    while(idx > 0 && idx <= MxV){
        tot = tot + tree[idx];
        idx = idx - (idx & -idx);
    }
    return tot;
}

void s4calcwithboundary(int n, int q)
{
    int cur = 0;
    for(int i=0;i<n;i++)events[cur++]=make_pair(s4arr[i].first, make_pair(1, i));
    for(int i=0;i<q;i++)
    {
        events[cur++] = make_pair(allqs[i].sx, make_pair(0, i));
        events[cur++] = make_pair(allqs[i].ex, make_pair(2, i));
    }
    sort(events,events+cur);
    //cout<<"event sort korechi\n";
    for(int i=0;i<cur;i++)
    {
      //  cout<<i<<" tomo event e\n";
        int idx = events[i].second.second;
        int type = events[i].second.first;
        if(type == 1)inc(s4arr[idx].second);
        else if(type == 0){
            res[idx]-=cnt(allqs[idx].ey)-cnt(allqs[idx].sy-1);
        }
        else{
            res[idx]+=cnt(allqs[idx].ey)-cnt(allqs[idx].sy-1);
        }
    }
}

int main(){
    int N,Q;
    scanf("%d %d",&N,&Q);
    VI line;
    FREP(i,1,50006){
        x2y.PB(line);
        y2x.PB(line);
    }
    int f=1;
    FREP(i,1,N){
        int x,y,rr;
        scanf("%d %d %d",&x,&y,&rr);
        cx[i]=x;
        cy[i]=y;
        r[i]=rr;
        if(rr!=1)f=0;
        s4arr[i-1].first=x+1;
        s4arr[i-1].second=y+1;
        x2y[x].PB(y);
        y2x[y].PB(x);
        PII pt=make_pair(x,y);
        pointexist[pt]=1;
        //scanf("%lf %lf %lf",&cx[i],&cy[i],&r[i]);
    }
    if(!f){
        FREP(k,1,Q){
            double xl,yb,xr,yu;
            scanf("%lf %lf %lf %lf",&xl,&yb,&xr,&yu);
            double ans=0.00;
            FREP(i,1,N){
                ans=ans+area(xl,xr,yb,yu,cx[i],cy[i],r[i]);
            }
            printf("%.10lf\n",ans);
        }
    }
    else{
        sortall();
        int x,y,xx,yy;
        FREP(i,0,(Q-1))
        {
            scanf("%d %d %d %d", &x, &y, &xx, &yy);
           // if(x > xx) swap(x, xx);
           // if(y > yy) swap(y, yy);
            allqs[i] = query(x + 1, y + 1, xx + 1, yy + 1);
            PII pt1=make_pair(x,y);
            PII pt2=make_pair(xx,y);
            PII pt3=make_pair(x,yy);
            PII pt4=make_pair(xx,yy);
            int vexist=0;
            if(pointexist.find(pt1)!=pointexist.end())vexist++;
            if(pointexist.find(pt2)!=pointexist.end())vexist++;
            if(pointexist.find(pt3)!=pointexist.end())vexist++;
            if(pointexist.find(pt4)!=pointexist.end())vexist++;
            vres[i]=vexist;
            int edgepoints=bsinx2y(x,y+1,yy-1);
           // cout<<"bs1hoise\n";
            edgepoints+=bsinx2y(xx,y+1,yy-1);
           // cout<<"bs2hoise\n";
            edgepoints+=bsiny2x(y,x+1,xx-1);
           // cout<<"bs3hoise\n";
            edgepoints+=bsiny2x(yy,x+1,xx-1);
           // cout<<"bs4hoise\n";
            //edge e kono vertex count kora hoy nai
            edgeres[i]=edgepoints;
           // cout<<"in "<<i<<" "<<vexist<<" and "<<edgepoints<<"\n";
        }
        s4calcwithboundary(N,Q);
        FREP(i,0,(Q-1)){
            int total=res[i];
            int contributehalf=edgeres[i];
            int contributequarter=vres[i];
            int contributefull=total-(contributehalf+contributequarter);
            double ans=pi*contributefull;
            ans=ans+(pi*contributehalf)/2.0;
            ans=ans+(pi*contributequarter)/4.0;
            printf("%.10lf\n",ans);
        }
    }
    return 0;
}
