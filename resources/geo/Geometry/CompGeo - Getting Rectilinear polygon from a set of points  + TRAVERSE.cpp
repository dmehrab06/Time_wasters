//ac
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 1005

#define NORTH    0
#define SOUTH  1
#define EAST  2
#define WEST 3

int n;
map<int,int> mx,my;
vector<int>  vx,vy;
vector<int> vvx[MAX],vvy[MAX];

struct Point{
    int x,y;
    Point(int _x=0,int _y=0){
        x = _x;
        y = _y;
    }
    void scan(){
        scanf("%d%d",&x,&y);
    }
}p[MAX],p0;

int dver[MAX][MAX];
int dhor[MAX][MAX];
Point ver[MAX][MAX];
Point hor[MAX][MAX];

int   dfinal[MAX];
Point final[MAX];

char ref[] = "NSEW";

bool sortx(const Point &a,const Point &b){
    if(a.x==b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool sorty(const Point &a,const Point &b){
    if(a.y==b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main(){
    
    int X,Y,i,x,y,y1,x1 , a,j;
    Point run;
    
    while(scanf("%d",&n)==1 && n){
        
        vx.clear();
        vy.clear();
        for(i=0;i<n;i++){
            p[i].scan();
            vx.push_back(p[i].x);
            vy.push_back(p[i].y);
        }
        p0 = p[0];
        
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        
        mx.clear();
        my.clear();
        
        X = 0;
        mx[vx[0]] = ++X;
        for(i=1;i<vx.size();i++)
            if(vx[i] != vx[i-1])
                mx[vx[i]] = ++X;
        
        Y = 0;
        my[vy[0]] = ++Y;
        for(i=1;i<vy.size();i++)
            if(vy[i] != vy[i-1])
                my[vy[i]] = ++Y;
        
        p0 = Point( mx[p0.x] , my[p0.y] );
        for(i=0;i<n;i++)
            p[i] = Point( mx[p[i].x] , my[p[i].y] );
        
  //      for(i=0;i<n;i++)
//            printf(">>> %d %d\n",p[i].x,p[i].y);
        
        
        sort(p,p+n,sortx);
        for(x=1;x<=X;x++)
            vvy[x].clear();
        for(i=0;i<n;i++)
            vvy[p[i].x].push_back( p[i].y );
        
/*      for(x=1;x<=X;x++){
            printf("x:%d :: ",x);
            for(i=0;i<vvy[x].size();i++)
                printf(" %d",vvy[x][i]);
            printf("\n");
        }
*/        
        sort(p,p+n,sorty);
        for(y=1;y<=Y;y++)
            vvx[y].clear();
        for(i=0;i<n;i++)
            vvx[p[i].y].push_back( p[i].x );
        
/*        for(y=1;y<=Y;y++){
            printf("y:%d :: ",y);
            for(i=0;i<vvx[y].size();i++)
                printf(" %d",vvx[y][i]);
            printf("\n");
        }
*/        
        //join verticals:
        for(x=1;x<=X;x++){
            for(i=0;i<vvy[x].size();i+=2){
                y  = vvy[x][i];
                y1 = vvy[x][i+1];
                
                ver[x][y]   = Point(x,y1);
                dver[x][y]  = NORTH;
                
                ver[x][y1]  = Point(x,y);
                dver[x][y1] = SOUTH;
            }
        }
        
        //join horizontals:
        for(y=1;y<=Y;y++){
            for(i=0;i<vvx[y].size();i+=2){
                x  = vvx[y][i];
                x1 = vvx[y][i+1];
                
                hor[x][y]   = Point(x1,y);
                dhor[x][y]  = EAST;
                
                hor[x1][y]  = Point(x,y);
                dhor[x1][y] = WEST;
            }
        }
        
        run = p0;
        for(i=0;i<n;i+=2){
            final[i]    = run;
            dfinal[i]   = dver[run.x][run.y];
            run         = ver[run.x][run.y];
            
            final[i+1]  = run;
            dfinal[i+1] = dhor[run.x][run.y];
            run         = hor[run.x][run.y];
        }
        
        a = 0;
        for(i=0;i<n;i++){
            j = (i+1)%n;
            a += final[i].x*final[j].y - final[j].x*final[i].y;
        }
        
        if(a > 0){      //CCW, so make CW
            run = p0;
            for(i=0;i<n;i+=2){
                final[i]    = run;
                dfinal[i]   = dhor[run.x][run.y];
                run         = hor[run.x][run.y];
            
                final[i+1]  = run;
                dfinal[i+1] = dver[run.x][run.y];
                run         = ver[run.x][run.y];
            }
        }
        
        for(i=0;i<n;i++)
            printf("%c",ref[ dfinal[i] ]);
        printf("\n");
        
    }
    return 0;
}