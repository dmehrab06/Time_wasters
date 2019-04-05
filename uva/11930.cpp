#include <bits/stdc++.h>

using namespace std;

int used[50000];
int comp[50000];
vector<int>topo;
vector< vector< int > >g,gt;

struct Point 
{ 
    int x; 
    int y; 
    Point(int _x = 0, int _y = 0){
    	x = _x, y = _y;
    }
}; 
  
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
int orientation(Point p, Point q, Point r) 
{ 
    long long val = (long long)(q.y - p.y) * (r.x - q.x) - (long long)(q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

struct Line{
	Point p1, p2;
	Line(Point _p1, Point _p2){
		p1 = _p1, p2 = _p2;
	}	
	bool doesIntersect(Line l){
		return doIntersect(p1,p2,l.p1,l.p2);
	}
};

vector<Line>alllines;

void init(){
	memset(used,0,sizeof(used));
	memset(comp,-1,sizeof(comp));
	topo.clear();
	g.clear(); gt.clear();
	alllines.clear();
}

void dfs1(int cur){
	used[cur] = 1;
	for(auto v: g[cur]){
		if(!used[v]){
			dfs1(v);
		}
	}
	topo.push_back(cur);
}

void dfs2(int cur, int c){
	comp[cur] = c;
	for(auto v: gt[cur]){
		if(comp[v]==-1){
			dfs2(v,c);
		}
	}
}

int getnode(int v){
	int val = 2*abs(v);
	if(v<0)val = val+1;
	return val;
}

void addedge1(int fc, int sc){
	int notsc = sc*(-1);
	g[getnode(fc)].push_back(getnode(notsc));
	gt[getnode(notsc)].push_back(getnode(fc));

	int notfc = fc*(-1);
	g[getnode(sc)].push_back(getnode(notfc));
	gt[getnode(notfc)].push_back(getnode(sc));
}

void addedge2(int fc, int sc){
	int notfc = fc*(-1);
	g[getnode(notfc)].push_back(getnode(sc));
	gt[getnode(sc)].push_back(getnode(notfc));

	int notsc = sc*(-1);
	g[getnode(notsc)].push_back(getnode(fc));
	gt[getnode(fc)].push_back(getnode(notsc));
}

bool solve2SAT(int m){
	for(int i = 2; i<= (2*m+1); ++i){
		if(!used[i]){
			dfs1(i);
		}
	}

	int tot = (int)topo.size();
	
	for(int i = 0, j = 0; i<tot; ++i){
		int cur = topo[tot-i-1];
		if(comp[cur]==-1){
			dfs2(cur,j);
			j++;
		}
	}

	for(int i = 0, j = 0; i<tot; ++i){
		int cur = topo[tot-i-1];
		if(comp[cur]==-1){
			dfs2(cur,j);
			j++;
		}
	}

	for(int i = 1; i<=m; ++i){
		if(comp[2*i]==comp[2*i+1]){
			return false;
		}
		//assigned[i] = (comp[2*i]>comp[2*i+1])?1:0;
	}

	return true;
}

void makeg(int n, int m){
	for(int i = 1; i<=(6*m); ++i){
		vector<int>line;
		g.push_back(line);
		gt.push_back(line);
	}

	for(int i = 1; i<=n; ++i){
		int x1,x2,x3,x4,x5,x6,x7,x8;
		scanf("%d %d %d %d %d %d %d %d",&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8);
		Point p1(x1,x2); Point p2(x3,x4);
		Point p3(x5,x6); Point p4(x7,x8);
		Line l1(p1,p3); Line l2(p2,p4);
		alllines.push_back(l1); alllines.push_back(l2);
	}

	for(int i = 0; i<m; i+=2){
		addedge2(i+1,i+2);
	}

	for(int i = 0; i<m; ++i){
		for(int j = (i+1); j<m; ++j){
			if(alllines[i].doesIntersect(alllines[j])){
				addedge1(i+1,j+1);
				//printf("%d %d\n",i+1,j+1);
			}
		}
	}
}

void solve(int m){

	//printf("Case %d: ",cs);
	if(solve2SAT(m)){
		printf("YES\n");		
	}
	else{
		printf("NO\n");
	}
}

int main(){
	while(true){
		int n;
		scanf("%d",&n);
		if(n==0)break;
		init();
		int m = 2*n;
		makeg(n,m);
		solve(m);
	}
	return 0;
}


