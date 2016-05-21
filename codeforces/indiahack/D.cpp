#define START 1
#define END -1
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct a{
    int jobno;
    int point;
    int time;
}jobs;
bool jobsortcomp(jobs a, jobs b){
    return (a.time<b.time);
}


int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        jobs *jobtimes;

        int total;
        scanf("%d",&total);
        jobtimes=new jobs[(2*total+3)];
        int I=1;
        int serial=1;
        while(total--){
            int start,fin;
            jobs jobbegin,jobend;
            scanf("%d %d",&start,&fin);
            jobbegin.jobno=serial;
            jobend.jobno=serial;
            jobbegin.point=START;
            jobbegin.time=start;
            jobend.point=END;
            jobend.time=fin+1;
            jobtimes[I]=jobbegin;
            jobtimes[I+1]=jobend;
            I+=2;
            serial++;
        }

        std::sort(jobtimes+1,jobtimes+(I),jobsortcomp);
        /*for(int k=1;k<=(i-1);++k){
            printf("%d %d\n",jobtimes[k].time,jobtimes[k].point);
        }*/
            int *machinetimes;
        machinetimes=new int[(I+2)/2];
        for(int j=0;j<((I+2)/2);++j){
            machinetimes[j]=0;
        }
        int current_time=1;
        int job=0;
        int mx=-1;
        for(int j=1;j<=(I-1);++j){
            if(job>mx){
                mx=job;
            }
            int interval=jobtimes[j].time-current_time;
            current_time=jobtimes[j].time;
            machinetimes[job]+=interval;
                job+=jobtimes[j].point;

        }
        printf("Case %d: %d\n",cs++,mx);
        delete[] jobtimes;
        delete[] machinetimes;
    }
    return 0;
}
