#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

struct Point{
    LLI x;
    LLI y;
    Point(){
        x=0;
        y=0;
    }
    Point(LLI a , LLI b){
        x=a;
        y=b;
    }
};

bool mycompare(Point &p1, Point &p2){
    if(p1.x==p2.x){
        return p1.y<p2.y;
    }
    return p1.x<p2.x;
}

//(a.x−c.x)*(b.y−a.y)−(a.x−b.x)*(c.y−a.y)
LLI area(Point a, Point b, Point c){
   return abs((a.x-c.x)*(b.y-a.y)-(a.x-b.x)*(c.y-a.y));
}

vector<Point>allpoints;
int main(){
    allpoints.push_back(Point(-1000000000,-1000000000));
    long long int N,S;
    cin>>N>>S;
    for(int i=1;i<=N;++i){
        long long int x,y;
        cin>>x>>y;
        Point p(x,y);
        allpoints.push_back(p);
    }
    sort(allpoints.begin(),allpoints.end(),mycompare);
    unique(allpoints.begin(),allpoints.end(),mycompare);
    int l=allpoints.size();
    int A=1;
    int B=2;
    int C=3;
    LLI nw=area(allpoints[A],allpoints[B],allpoints[C]);
    while(1){
        bool ch=false;
        for(int i=1;i<l;++i){
            LLI curarea=area(allpoints[A],allpoints[B],allpoints[i]);
            if(curarea>nw){
                nw=curarea;
                C=i;
                ch=true;
            }
        }
        for(int i=1;i<l;++i){
            LLI curarea=area(allpoints[A],allpoints[i],allpoints[C]);
            if(curarea>nw){
                nw=curarea;
                B=i;
                ch=true;
            }
        }
        for(int i=1;i<l;++i){
            LLI curarea=area(allpoints[i],allpoints[B],allpoints[C]);
            if(curarea>nw){
                nw=curarea;
                A=i;
                ch=true;
            }
        }
        if(!ch)break;
    }
    //now draw parallel line of AB intersecting C,AC intersecting B,BC intersecting A
    //resulting triangle ans
    //the points of those lines intersecting
    //found by paper calculation
    LLI AX=allpoints[A].x;
    LLI AY=allpoints[A].y;
    LLI BX=allpoints[B].x;
    LLI CX=allpoints[C].x;
    LLI CY=allpoints[C].y;
    LLI BY=allpoints[B].y;
    cout<<AX+CX-BX<<" "<<AY+CY-BY<<"\n";
    cout<<BX+CX-AX<<" "<<BY+CY-AY<<"\n";
    cout<<AX+BX-CX<<" "<<AY+BY-CY<<"\n";
    return 0;
}
