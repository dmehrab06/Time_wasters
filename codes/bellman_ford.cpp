#define MAXINT 100000
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef	 struct	 xx{
	int u;
	int v;
	int w;
}edge;

edge *alledges;
int *nodedis;

int BELLMAN_FORD(int V, int E ){
	for(int i=1;i<=V-1;++i){
		for(int j=1;j<=E;++j){
			edge e;
			e=alledges[j];
			if(nodedis[e.u]+e.w<nodedis[e.v]){
				
				nodedis[e.v]=nodedis[e.u]+e.w;
			} 
		}
	}
	for(int j=1;j<=E;++j){
		edge e;
		e=alledges[j];
		if(nodedis[e.u]+e.w<nodedis[e.v]){		
			return 1;
		} 
	}
	return 0;
}
int main(){
	
	
	
	
	int V,E;
	scanf("%d %d",&V,&E);
	alledges=new edge[E+1];
	nodedis=new int[V+1];
	nodedis[1]=0;
	for(int i=2;i<=V;++i){
		nodedis[i]=MAXINT;
	}
	int high=100;
	for(int i=1;i<=E;++i){
		int a,b,val;
		scanf("%d %d %d",&a,&b,&val);
		edge e;
		e.u=a;
		e.v=b;
		e.w=val;
		alledges[i]=e;
		if(val<high){
			high=val;
		}
	}
	int neg_cycle=BELLMAN_FORD(V,E);
	if(neg_cycle){
		
	
		high*=(-1);
		int extracost;
		int low=1;
		int prev=0;
		while(low<high){
			extracost=(low+high)/2;
			for(int j=1;j<=E;++j){
				alledges[j].w+=(extracost-prev);
			}
			nodedis[1]=0;
			for(int i=2;i<=V;++i){
				nodedis[i]=MAXINT;
			}
			int neg_cycle=BELLMAN_FORD(V,E);
			if(neg_cycle){
				low=extracost+1;
			}
			else{
				high=extracost;
			}
			prev=extracost;
			printf("%d %d\n",low,high);
			
		}
		printf("Minimum edge cost: %d %d %d\n",low,high,(low+high)/2);
	}
	else{
		printf("Minimum edge cost: 0\n");
	}
	return 0;
	
}
/*
4 5
1 2 1
2 3 -2
3 4 -3
4 2 1
4 1 2
2 3
2 1
Minimum edge cost: 2





*/
