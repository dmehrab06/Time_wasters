#pragma warning (disable:4786)

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<assert.h>

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
using namespace std;

#define _abs(x)		(((x)>0)?(x):-(x))
#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

#define EPS 1e-12

#define S(x)	((x)*(x))
#define C(x)	((x)*(x)*(x))

#define Z(x)	(_abs(x) < EPS)
#define N(x)	(x < -EPS)
#define ZN(x)	(x < EPS)
#define P(x)	(x > EPS)
#define ZP(x)	(x > -EPS)

typedef pair<double,double> Point;

//#define NAFI
#ifdef NAFI
typedef __int64 LL;
#else
typedef long long LL;
#endif

int n;
Point p[1400];

int m;
double a[10000];

double pi = acos(-1.);
double mytan(double dx,double dy){
	if(Z(dy)){
		if(dx > 0)	return 0;
		else		return pi;
	}
	if(Z(dx)){
		if(dy > 0)	return pi/2.;
		else		return 3.*pi/2.;
	}
	double at = atan2(dy,dx);
	if(at < 0)	at+=2*pi;
	return at;
}

int lo[10000],clo[10000];

int main(){

	int i,j,k, t,N=0;

	int ll,uu,mm;

	LL cnt,ntri;

	while(scanf("%d",&n)==1 && n){
		
		for(i=0;i<n;++i)
			scanf("%lf%lf",&p[i].first,&p[i].second);

		ntri =n;
		ntri*=n-1;
		ntri*=n-2;
		//ntri/=6;
		ntri/=2;

		cnt = 0;

		for(i=0;i<n;++i){
		//i=0;{
		
			m = 0;
			for(j=0;j<n;++j)if(i!=j)
				a[m++] = mytan(p[j].first-p[i].first,p[j].second-p[i].second);
			
			sort(a,a+m);
			for(j=0;j<m;++j)
				a[j+m] = a[j]+2*pi;

			lo[0] = -1;
			clo[0] = lo[0];
			for(j=1;j<2*m;++j){
				lo[j] = lower_bound(a,a+2*m,a[j]-pi) - a;
				clo[j] = clo[j-1] + lo[j];
			}

			for(k=0;k<m;k++)if(a[k]-a[0] > pi)
				break;
			if(k==m)
				continue;	//no triangle for this point.

			j = 0;
			while(j<m){

				t = lower_bound(a,a+2*m,a[j]+pi) - a;

				ll = k;
				uu = j+m-1;
				while(uu-ll > 5){
					mm = (ll+uu)/2;
					if(t > lo[mm])	ll=mm;
					else			uu=mm-1;
				}
				for(mm=uu;mm>=ll;mm--)if(t > lo[mm])
					break;

				if(t>0)	cnt += ((LL)(t))*((LL)(mm-t+1)) - (clo[mm]-clo[t-1]);
				else	cnt += ((LL)(t))*((LL)(mm-t+1)) - (clo[mm]);

				++j;
				while( ZN((a[k]-a[j]) - pi) )
					++k;
			}
		}

		printf("City %d: %.2lf\n",++N,1.*cnt/(1.*ntri));
	}


	return 0;
}
