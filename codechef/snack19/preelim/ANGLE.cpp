#include <bits/stdc++.h>

using namespace std;

double arr[1003];

pair<double, int> binsearch(int y, int z, int n, int p, int q){
	int lo = 1;
	int hi = n;
	double v = (double)p/(double)q;
	double valcheck  = (arr[y]*arr[y])+(arr[z]*arr[z])-2.0*arr[y]*arr[z]*v;
	if(valcheck<0.0)return make_pair(-1.0,-1);
	valcheck = sqrt(valcheck);
	if(arr[lo]>valcheck) return make_pair(-1.0,-1);
	while((lo+1)<hi){
		int mid = (lo+hi)/2;
		double v = arr[mid];
		if(v>valcheck){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	if(arr[hi]>valcheck){
		while(lo==y || lo==z){
			lo--;
		}
		if(lo<1){
			return make_pair(-1.0,-1);
		}
		else{
			double Y = arr[y]; double Z = arr[z]; double X = arr[lo];
			double theta = acos((Y*Y+Z*Z-X*X)/(2.0*Y*Z));
			return make_pair(theta,lo);
		}
	}
	else{
		while(hi==y || hi==z){
			hi--;
		}
		if(hi<1){
			return make_pair(-1.0,-1);
		}
		else{
			double Y = arr[y]; double Z = arr[z]; double X = arr[hi];
			double theta = acos((Y*Y+Z*Z-X*X)/(2.0*Y*Z));
			return make_pair(theta,hi);
		}
	}
}

void inp(int n){
	for(int i = 1; i<=n; ++i){
		scanf("%lf",&arr[i]);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,p,q;
		scanf("%d %d %d",&n,&p,&q);
		inp(n);
		sort(arr+1,arr+1+n);
		double mxangle = -1.0;
		int x = -1, y = -1, z = -1;
		for(int i = 1;i<=n;++i){
			for(int j = (i+1); j<=n; ++j){
				pair<double,int> ret = binsearch(i,j,n,p,q);
				if(ret.second!=-1){
					if(ret.first>mxangle){
						mxangle = ret.first;
						x = ret.second;
						y = i;
						z = j;
					}
				} 
			}
		}
		if(x!=-1){
			printf("%d %d %d\n",x,y,z);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}