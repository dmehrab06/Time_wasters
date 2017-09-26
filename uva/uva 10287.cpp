#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

double sqrt3=sqrt(3.0);

int main()
{
   double hex;
  while (scanf("%lf",&hex)==1){
      double r1=(hex*sqrt3)/2.0;
      double r3=r1/2.0;
      double r2=(hex*sqrt3)/(2.0+sqrt3);
      double pentaval=sqrt(28.0);
      double quadra=(pentaval-(7.0/sqrt3))*hex;
      double r4=quadra*3.0/10.0;
      printf("%.10lf %.10lf %.10lf %.10lf\n",r1,r2,r3,r4);
  }
  return 0;
}
