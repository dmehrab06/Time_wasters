#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double a;
        scanf("%lf",&a);
        printf("%.12lf %.12lf\n",a*(double)3.0,a*(double)3.71);
    }
    return 0;
}
