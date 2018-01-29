#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct b{
    int edgecost;
    int totaledges;

}mst;
typedef struct a{
    int src;
    int dest;
    int weight;
    int enabled;
}edge;

edge *alledges;
int *representative;


bool comp(edge a, edge b){
    return a.weight<b.weight;
}


int findrep(int a){
    if(representative[a]!=a){
        representative[a]=findrep(representative[a]);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y){
    int xp,yp;
    xp=findrep(x);
    yp=findrep(y);
    representative[yp]=xp;
}

mst KruskalMST(int V,int E){

    representative=new int[V+1];
    for(int i=1;i<=V;++i){
        representative[i]=i;
    }
    int taken=0;
    int totalweight=0;
    for(int i=1;(i<=E && taken<(V-1));++i){
        edge currentedge;
        currentedge=alledges[i];
            if(currentedge.enabled==1){
            int upar=findrep(currentedge.src);
            int vpar=findrep(currentedge.dest);
            if(upar!=vpar){
                unionfind(upar,vpar);
                taken++;
                totalweight+=currentedge.weight;
            }
        }
    }
    mst MST;
    MST.edgecost=totalweight;
    MST.totaledges=taken;
    delete[] representative;
    return MST;

}
int main(){
    int V,E;
    scanf("%d %d",&V,&E);
    alledges=new edge[E+1];
    edge garbage;
    garbage.enabled=0;
    alledges[0]=garbage;
    for(int i=1;i<=E;++i){
        edge EDGE;
        scanf("%d %d %d",&EDGE.src,&EDGE.dest,&EDGE.weight);
        EDGE.enabled=1;
        alledges[i]=EDGE;
    }

    std::sort(alledges+1,alledges+E+1,comp);
    mst MST;
    MST=KruskalMST(V,E);
    int originalMSTval=MST.edgecost;
    edge *compulsary;
    compulsary=new edge[E];
    printf("Following edges must be included in MST:\n");
    int mustedge=0;
    for(int i=1;i<=E;++i){
        alledges[i].enabled=0;
        alledges[i-1].enabled=1;
        mst secondary;
        secondary=KruskalMST(V,E);
        if(secondary.edgecost>originalMSTval || secondary.totaledges<(V-1)){
            compulsary[mustedge]=alledges[i];
            printf("%d %d %d\n",alledges[i].src,alledges[i].dest,alledges[i].weight);
            mustedge++;
        }
    }
    //printf("%d %d\n",MST.edgecost,MST.totaledges);
}
