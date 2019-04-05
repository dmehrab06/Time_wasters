#include <bits/stdc++.h>

using namespace std;

typedef struct ss{
	int x;
	int y;
}intPoint;

intPoint allp[100005];

bool intpoint_inside_trigon(intPoint s, intPoint a, intPoint b, intPoint c)
{
    int as_x = s.x-a.x;
    int as_y = s.y-a.y;

    bool s_ab = (b.x-a.x)*as_y-(b.y-a.y)*as_x > 0;

    if((c.x-a.x)*as_y-(c.y-a.y)*as_x > 0 == s_ab) return false;

    if((c.x-b.x)*(s.y-b.y)-(c.y-b.y)*(s.x-b.x) > 0 != s_ab) return false;

    return true;
}

bool isallinside(int n, int mid){
	intPoint a; a.x = 0; a.y = 0;
	intPoint b; b.x = 0; b.y = mid;
	intPoint c; c.x = mid; c.y = 0;
		
	for(int i = 0; i<n; ++i){
		if(!intpoint_inside_trigon(allp[i],a,b,c)){
			return false;
		}
	}
	return true;
}

int main(){
	int mxp = -1;
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		scanf("%d %d",&allp[i].x,&allp[i].y);
		mxp = max(mxp,allp[i].x+allp[i].y);
	}
	printf("%d\n",mxp );
	return 0;
}