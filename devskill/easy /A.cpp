#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int tst;
	scanf("%d",&tst);
	while(tst--){
		double v,t;
		scanf("%lf %lf",&v,&t);
		double a=v/t;
		a=a*(-1.0);
		printf("%.2lf\n",a);
	}
	return 0;
}
