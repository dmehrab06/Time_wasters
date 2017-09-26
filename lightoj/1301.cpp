#define START 1
#define END -1
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
 
typedef struct a{
    int point;
    long long int time;
}jobs;
bool jobsortcomp(jobs a, jobs b){
    if(a.time==b.time){
        return a.point>b.point;
    }
    return (a.time<b.time);
}
 
 
int main(){
int t;
int tt=1;
scanf("%d",&t);
while(t--){
    jobs *jobtimes;
 
    int total;
    scanf("%d",&total);
    jobtimes=new jobs[(2*total+3)];
    int I=1;
    while(total--){
        long long int start,fin;
        jobs jobbegin,jobend;
        scanf("%lld %lld",&start,&fin);
        jobbegin.point=START;
        jobbegin.time=start;
        jobend.point=END;
        jobend.time=fin;
        jobtimes[I]=jobbegin;
        jobtimes[I+1]=jobend;
        I+=2;
    }
 
    std::sort(jobtimes+1,jobtimes+(I),jobsortcomp);
    /*for(int k=1;k<=(i-1);++k){
        printf("%d %d\n",jobtimes[k].time,jobtimes[k].point);
    }*/
 
    int job=0;
    int mx=-1;
    for(int j=1;j<=(I-1);++j){
        if(job>mx){
            mx=job;
        }
        job+=jobtimes[j].point;
 
    }
    printf("Case %d: %d\n",tt,mx);
    tt++;
    delete [] jobtimes;
}
return 0;
}
