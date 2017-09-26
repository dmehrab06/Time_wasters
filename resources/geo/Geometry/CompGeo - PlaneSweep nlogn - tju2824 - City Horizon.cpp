//2824 - City Horizon - PLANE SWEEPING - nlogn - vector/map/set
#pragma warning(disable:4786)
#include<stdio.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define OPEN	0
#define CLOSE	1

#define MAX		80005

//typedef unsigned __int64 LL;
typedef unsigned long long LL;

int n;
int a[MAX],b[MAX],h[MAX];

struct HEvent{
	int type,x;

	HEvent(int _type=0,int _x=0){
		type = _type;
		x = _x;
	}
};

bool operator<(const HEvent &p,const HEvent &q){
	if(p.x==q.x)
		return p.type > q.type;
	return p.x < q.x;
}

vector<int>		vy1,vy;
map<int,int>	my;
vector<HEvent>	v[MAX];

struct Event{
	int type,x,y;

	Event(int _type=0,int _x=0,int _y=0){
		type = _type;
		x = _x;
		y = _y;
	}
};

bool operator<(const Event &p,const Event &q){
	if(p.x==q.x)
		return p.type > q.type;
	return p.x < q.x;
}

vector<Event>	ve;
set<int>		se;


int main(){

	int i,j,Y,last,cnt,hh;
	LL area;

	while(scanf("%d",&n)==1 && n){
		
		vy1.clear();
		for(i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&h[i]);
			vy1.push_back(h[i]);
		}
		sort(vy1.begin(),vy1.end());

		vy.clear();
		vy.push_back(vy1[0]);
		for(i=1;i<vy1.size();i++)
			if(vy1[i] != vy1[i-1])
				vy.push_back(vy1[i]);

		my.clear();
		for(i=0;i<vy.size();i++)
			my[vy[i]] = i+1;

		Y = vy.size();

		for(i=0;i<Y;i++)
			v[i].clear();

		for(i=0;i<n;i++){
			v[ my[h[i]]-1 ].push_back(HEvent(OPEN,a[i]));
			v[ my[h[i]]-1 ].push_back(HEvent(CLOSE,b[i]));
		}

		ve.clear();
		for(i=0;i<Y;i++){
			
			if(v[i].size()==0)
				continue;

			sort(v[i].begin(),v[i].end());

/*			printf(">> %d(%d)\n",i,vy[i]);
			for(j=0;j<v[i].size();j++)
				printf("... %d %d\n",v[i][j].type,v[i][j].x);
			printf("\n");
*/
			last = v[i][0].x;
			cnt = 1;

			for(j=1;j<v[i].size();j++){
				
				if(v[i][j].type == OPEN)
					cnt++;
				else
					cnt--;

				if(cnt == 0){
					ve.push_back( Event(OPEN,last, vy[i] ) );
					ve.push_back( Event(CLOSE,v[i][j].x, vy[i] ) );
					if(j+1 < v[i].size())
						last = v[i][j+1].x;
					else
						last = 1000000000;
				}
			}
		}

		sort(ve.begin(),ve.end());

/*		printf("\n");
		for(i=0;i<ve.size();i++)
			printf("%d :: %d %d\n",ve[i].type, ve[i].x, ve[i].y);
		printf("\n");
*/
		se.clear();
		se.insert(0);
		se.insert(-ve[0].y);
		
		area = 0;
		hh = -(*se.begin());

		for(i=1;i<ve.size();i++){
			area += ((LL)(hh))*(ve[i].x - ve[i-1].x);

			if(ve[i].type == OPEN)	se.insert(-ve[i].y);
			else					se.erase (-ve[i].y);

			hh = -(*se.begin());
		}
		
//		printf("%I64u\n",area);
		printf("%llu\n",area);

	}

	return 0;
}