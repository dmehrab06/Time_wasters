#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct a{
    int w;
    int v;
    double vpw;
    double taken;
    int index;
}item;

bool idxcomp(item a, item b){
    return a.index<b.index;
}
bool greedcomp(item a,item b){
    return a.vpw>b.vpw;
}

int main(){
    item *objects;
    int N,C;
    scanf("%d %d",&N,&C);
    objects=new item[N];
    for(int i=0;i<N;++i){
        item p;
        int wt,val;
        scanf("%d %d",&wt,&val);
        p.w=wt;
        p.v=val;
        double a=((double)val)/((double)wt);
        //printf("%lf\n",a);
        p.vpw=a;
        p.taken=0;
        p.index=i;
        objects[i]=p;
    }
    std::sort(objects,objects+(N),greedcomp);
    /*for(int i=0;i<N;++i){
        printf("%.2lf\n",objects[i].vpw);
    }*/
    double totalval=0;
    int remaining=C;
    for(int i=0;(i<N && remaining);++i){
        int a=objects[i].w;
        if(a>remaining){
            double b=((double)remaining)/((double)a);
            objects[i].taken=b;
            totalval=totalval+(remaining*(objects[i].vpw));
            remaining=0;
        }
        else{
            totalval+=objects[i].v;
            remaining-=a;
            objects[i].taken=1;
        }
    }
    printf("%.2lf\nProportions:\n",totalval);

    std::sort(objects,objects+(N),idxcomp);

    for(int i=0;i<N;++i){
        printf("%.2lf ",objects[i].taken);
    }
    printf("\n");
}
