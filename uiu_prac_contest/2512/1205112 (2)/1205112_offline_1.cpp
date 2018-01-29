#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct a{
    int jobno;
    int start;
    int end;
}jobs;
bool comp(jobs a, jobs b){
    return (a.end<b.end);
}

int main(){
    jobs *alljobs;

    int total;
    scanf("%d",&total);
    alljobs=new jobs[total];
    int i=0;
    while(total--){
        int serial,start,fin;
        jobs job;
        scanf("%d %d %d",&serial,&start,&fin);
        job.start=start;
        job.end=fin;
        job.jobno=serial;
        alljobs[i]=job;
        i++;
    }

    std::sort(alljobs,alljobs+(i-1),comp);
    vector<int>jobstodo;
    int f=0;
    int todojob=0;
    for(int k=0;k<i;++k){
        if(alljobs[k].start>=f){
            jobstodo.push_back(alljobs[k].jobno);
            f=alljobs[k].end;
            todojob++;
        }
    }
    /*for(int k=0;k<i;++k){
        printf("%d %d %d\n",alljobs[k.jobno,alljobs[k].start,alljobs[k].end);
    }*/
    printf("%d",todojob);
    for(int k=0;k<jobstodo.size();++k){
        printf(" %d",jobstodo[k]);
    }
    printf("\n");

}
