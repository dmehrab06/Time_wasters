#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
using namespace std;
double polyn[105];
//ofstream fout("112.txt");
double pw(double x, int n){
    int i=1;
    double s=1;
    while(i<=n){
        s=s*x;
        i++;
    }
    return s;
}
double fxval(int degree,double x){
    int n=degree-1;
    int i=1;
    double s=0;
    //printf("in fxval\n");

    while(n>=0){
        double a=(pw(x,n))*polyn[i];
        s+=a;
     //   printf("%.3lf\n",s);
        i++;
        n--;
    }
    return s;
}
double extreme(double low,double high, int degree){
   // fout<<"low: "<<low<<" high: "<<high<<"\n";
    double mid=(low+high)/2.0;
    double result1=fxval(degree,mid);
    //fout<<"mid: "<<mid<<"\n";
    //printf("%.3lf\n",result1);
    //fout<<result1<<"\n";
    if(fabs(result1)<0.0001){
        return mid;
    }
    double dif1=fabs(result1);
    double a=0.01;
    double result2=fxval(degree,mid+a);
    //fout<<result2<<"\n";
    while((result1*result2)<0){
        a=a/10.0;
        result2=fxval(degree,mid+a);
      //  fout<<result2<<"\n";
    }
    double dif2=fabs(result2);
    if(dif2<dif1){
        return extreme(mid,high,degree);
    }
    else{
        return extreme(low,mid,degree);
    }
}
int main(){

    int coeff,query;
    cin>>coeff>>query;
    int n=coeff-1;
    for(int i=1;i<coeff;++i){
        double a;
        cin>>a;
        polyn[i]=(a*n);
        n--;
    }
   /* for(int i=1;i<coeff;++i){
        printf("%.3lf\n",polyn[i]);
    }*/
    double a;
    cin>>a;
    for(int i=1;i<=query;++i){
        double low,high;
        cin>>low>>high;
        double result;
        result=extreme(low,high,coeff-1);
        printf("%.3lf\n",result);
    }
}
