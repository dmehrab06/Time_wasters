#include <bits/stdc++.h>
#define PI acos(-1.0)

using  namespace std;

int main(){
	int n,r;
	while(scanf("%d %d",&n,&r)==2){
		double lo = 0.0;
		double hi = 20000000000000000000.00;
		for(int i = 1; i<=100; ++i){
			double mid = (lo+hi)/2.0;
			double v = mid/((double)r+mid);
			double a = asin(v);
			double tot = 2.0*a*n;
			if(tot>(2.0*PI)){
				hi = mid;
			}
			else{
				lo = mid;
			}
		}
		printf("%.10lf\n",lo);
	}
	return 0;
}