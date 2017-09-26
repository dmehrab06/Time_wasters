//ac on 2009-03-10
#pragma warning(disable:4786)
#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 1000000000
#define MAX 1005

#define _min(a,b)	(((a)<(b))?(a):(b))
#define _max(a,b)	(((a)>(b))?(a):(b))
#define ADD(X,Y)	x[p]=X;y[p]=Y;p++;

typedef __int64 LL;

int n,m,d;
int p,x[MAX],y[MAX];

int X,Y;
map<int,int> mx,my;
vector<int> vx,vy;
/*
	u is mapped to v
	then,
	vx[v] = u;
	mx[u] = v;
	domain(u) = normal x
	domain(v) = {1,2,..,X}
*/

char mat[MAX][MAX];

void MAP(){
	int i;

	X = 0;
	mx.clear();
	vx.clear();	vx.push_back(-123123);	//gbg
	mx[x[0]] = ++X;
	vx.push_back(x[0]);
	for(i=1;i<p;i++)if(x[i]!=x[i-1]){
		mx[x[i]] = ++X;
		vx.push_back(x[i]);
	}

	Y = 0;
	my.clear();
	vy.clear();	vy.push_back(-123123);	//gbg
	my[y[0]] = ++Y;
	vy.push_back(y[0]);
	for(i=1;i<p;i++)if(y[i]!=y[i-1]){
		my[y[i]] = ++Y;
		vy.push_back(y[i]);
	}

	//passed all these checks
/*	for(i=1;i<=X;i++)
		assert(X == mx[vx[X]]);
	for(i=1;i<=Y;i++)
		assert(Y == my[vy[Y]]);	*/
}

struct Rec{
	int x1,x2,y1,y2;
	LL area;
	Rec(){}
	Rec(int x11,int x22,int y11,int y22){
		x1=x11;		x2=x22;
		y1=y11;		y2=y22;
//		if(x1>x2)	swap(x1,x2);
//		if(y1>y2)	swap(y1,y2);
		area = (x2-x1);
		area*= (y2-y1);
	}
	void inc(){
		x1-=d;
		x2+=d;
		y1-=d;
		y2+=d;
	}
	bool covers(Rec &b){
		return x1 <= b.x1 && b.x2 <= x2 && y1 <= b.y1 && b.y2 <= y2;
	}
};

bool operator<(const Rec &a,const Rec &b){
	return a.area > b.area;
}

vector<Rec> r,rec;
vector<LL> area,peri;

int main(){

	int i,j,k,l,cc;
	int T,N;
	Rec r1;

	LL ia;

	int x1,x2,ys,y1,y2,xr,xl,yb,yt;
	LL ar,pr,temp;

	scanf("%d",&T);

	for(N=1;N<=T;N++){
		scanf("%d%d%d",&n,&m,&d);

		for(i=n-1;i>=0;i--)
			scanf("%d%d",&x[i],&y[i]);	

		ia = 0;
		for(i=0;i<n;i++){
			j = (i+1)%n;
			ia += x[i]*y[j] - x[j]*y[i];
		}
		assert(ia%2==0 && ia > 0);
		ia/=2;

		r.clear();
		for(k=0;k<n;k++)for(l=k+2;l<n;l++){
			x1 = _min(x[k],x[l]);
			x2 = _max(x[k],x[l]);
			y1 = _min(y[k],y[l]);
			y2 = _max(y[k],y[l]);

			r1 = Rec(x1,x2,y1,y2);
			if(r1.area==0)
				continue;

			//check for intersection
			for(i=0;i<n;i++){
				j = (i+1)%n;
				xl = _min(x[i],x[j]);
				xr = _max(x[i],x[j]);
				yb = _min(y[i],y[j]);
				yt = _max(y[i],y[j]);
				if(yb==yt){
					if(!(r1.y1 < yb && yb < r1.y2))continue;
					if( xr <= r1.x1 || r1.x2 <= xl)	continue;
					break;
				}
				else{
					if(!(r1.x1 < xl && xl < r1.x2))continue;
					if( yt <= r1.y1 || r1.y2 <= yb)	continue;
					break;
				}
			}
			if(i < n)
				continue;

			//check for outside area
			cc = 0;
			for(i=0;i<n;i++){
				j = (i+1)%n;
				yb = _min(y[i],y[j]);
				yt = _max(y[i],y[j]);
				if(yb==yt)
					continue;

				if(!(yb <= r1.y1 && r1.y1+1 <= yt))
					continue;
				if(r1.x2 <= x[i])
					cc++;
			}

			if(cc%2)	//inside
				r.push_back(r1);
		}

		sort(r.begin(),r.end());

		rec.clear();
		rec.push_back(r[0]);
		for(i=1;i<r.size();i++){
			for(j=0;j<rec.size();j++)if(rec[j].covers(r[i]))
				break;
			if(j==rec.size())
				rec.push_back(r[i]);
		}
		assert(rec.size() <= n);
	
		area.clear();
		peri.clear();

		n = rec.size();

		memset(mat,0,sizeof(mat));

		for(k=1;k<=m;k++){
			//inc rect first
			for(i=0;i<rec.size();i++)
				rec[i].inc();

			//slicing
			p = 0;
			ADD(-INF,-INF);
			for(i=0;i<rec.size();i++){
				ADD(rec[i].x1,rec[i].y1);
				ADD(rec[i].x2,rec[i].y2);
			}
			sort(x,x+p);
			sort(y,y+p);
			MAP();

			//marking
			for(i=0;i<rec.size();i++){
				x1 = mx[rec[i].x1];
				x2 = mx[rec[i].x2];
				ys = y1 = my[rec[i].y1];
				y2 = my[rec[i].y2];
				for(;x1<x2;x1++)for(y1=ys;y1<y2;y1++)
					mat[x1][y1] = k;
			}

			//checking
			ar = 0;
			pr = 0;
			l = 0;
			for(i=1;i<=X;i++){
				for(j=1;j<=Y;j++){
					if(mat[i][j]==k){
						l++;
						temp = (vx[i+1]-vx[i]);
						temp*= (vy[j+1]-vy[j]);
						ar+=temp;
						pr += ((mat[i][j-1]!=k)*1 + (mat[i][j+1]!=k)*1)*(vx[i+1]-vx[i]) + ((mat[i-1][j]!=k)*1 + (mat[i+1][j]!=k)*1)*(vy[j+1]-vy[j]);
					}
				}
			}

			area.push_back(ar-ia);
			ia += area[area.size()-1];
			peri.push_back(pr);
		}

		printf("Case %d:\n",N);
		printf("  Perimeters:");
		for(i=0;i<m;i++)	printf(" %I64d",peri[i]);
		printf("\n");
		printf("  Areas:");
		for(i=0;i<m;i++)	printf(" %I64d",area[i]);
		printf("\n\n");


	}

	return 0;
}