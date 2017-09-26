#pragma warning (disable:4786)
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<utility>
using namespace std;

#define EPS 1e-10
typedef pair<int,int> Point;

double pi = acos(-1.);
double mytan(int dx,int dy){
	if(!dy){
		if(dx > 0)	return 0;
		else		return pi;
	}
	if(!dx){
		if(dy > 0)	return pi/2.;
		else		return 3.*pi/2.;
	}
	double at = atan2(1.*dy,1.*dx);
	if(at < 0)	at+=2*pi;
	return at;
}

int n;
Point p[1250];
int m;
double a[2550];

int main(){

	int T=0;
	int i,j,k,l;
	int tot;

	while(scanf("%d",&n)==1 && n){
		
		for(i=0;i<n;++i)
			scanf("%d%d",&p[i].first,&p[i].second);

		tot = 0;
		for(i=0;i<n;++i){
			m = 0;
			for(j=0;j<n;++j)if(i!=j)
				a[m++] = mytan(p[j].first - p[i].first,p[j].second-p[i].second);
			sort(a,a+m);
			for(j=0;j<m;++j)
				a[j+m] = a[j]+2*pi;

			j=0;
			k=0;
			l=k;
			while(j<m){
				while(k<j+m && a[k]-a[j] < pi/2.-EPS)++k;
				if(k==j+m)	break;	//no obtuse for point-i
				while(l<j+m && a[l]-a[j] < pi   )++l;
				if(k==j+m)	break;	//no obtuse for point-i
				if(l>k)	tot += l-k;
				++j;
			}
		}
		printf("Scenario %d:\n",++T);
		printf("There are %d sites for making valid tracks\n",n*(n-1)*(n-2)/6 - tot);
	}
	return 0;
}