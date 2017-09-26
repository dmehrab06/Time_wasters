#include <bits/stdc++.h>
using namespace std;

long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0){
        return 1;
    }
    if(x==1){
        return b;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}
long long int findMMI(long long int n,long long int M)
{
    return modpow(n,M-2,M);
}

int eucmodInv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if (x1 < 0)
       x1+=m0;
    return x1;
}

struct Point
{
    long long int x, y;
};

int orient(Point p, Point q, Point r)
{
   long long int v = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (!v) return 0;  // colinear
    if(v>0)return 1;
    return 2; // clock or counterclock wise
}

long long int pointx[100005];
long long int pointy[100005];

int cHull(Point points[], int n)
{
    if (n < 3) return 0;
    //vector<Point>CONHULL;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    int sz=0;
    do
    {
        pointx[sz]=points[p].x;
        pointy[sz]=points[p].y;
        sz++;
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orient(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;
    } while (p != l);  // While we don't come to first point

    return sz;
}

double findarea(int N){
    if(N<3)return 0.0000;
    double area=0.0000;
    for(int i=0;i<N;++i){
        area=area+((double)pointx[i]*(double)pointy[(i+1)%N]-(double)pointy[i]*(double)pointx[(i+1)%N]);
    }
    area=area/2.00000;
    if(area<0){
        area=area*(-1.0000);
    }
    return area;
}

typedef pair<long long int,long long int> pairs;

Point points[100005];

int main()
{
    int t;
    scanf("%d",&t);
    set<pairs>::iterator it;
    set<pairs>pointset;
    while(t--){
        pointset.clear();
        int q;
        scanf("%d",&q);
        while(q--){
            string cc;
            long long int x,y;
            //scanf("%c %d %d",&cc,&x,&y);
            cin>>cc>>x>>y;
            pairs pt=make_pair(x,y);
            if(cc[0]=='+'){
                pointset.insert(pt);
            }
            else{
                pointset.erase(pt);
            }
            int nn=0;
            for(it=pointset.begin();it!=pointset.end();it++){
                Point pp;
                pp.x=it->first;
                pp.y=it->second;//(it->first,it->second);
                points[nn]=pp;
                nn++;
            }
            //int nn = sizeof(points)/sizeof(points[0]);
            int sz=cHull(points, nn);
            double area=findarea(sz);
            printf("%.1lf\n",area);


        }
    }
    return 0;
}
