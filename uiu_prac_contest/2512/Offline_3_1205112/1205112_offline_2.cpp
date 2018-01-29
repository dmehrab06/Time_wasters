#define MAXINT 100000
#include <cstdio>
#include <cstdlib>

using namespace std;

int minimum(int a,int b){
	if(a<b){

		return a;
	}
	else{

		return b;
	}
}

int main(){

	int Adj[40][40];
	int sp[40][40];

	for(int i=1;i<40;++i){

		for(int j=1;j<40;++j){
			if(i==j){
				Adj[i][j]=0;
			}
			else{
				Adj[i][j]=MAXINT;
			}


			sp[i][j]=0;
		}
	}

	int V,E;
	scanf("%d %d",&V,&E);
	for(int i=1;i<=E;++i){
		int a,b,val;
		scanf("%d %d %d",&a,&b,&val);
		Adj[a][b]=val;
		Adj[b][a]=val;
		sp[a][b]=1;
		sp[b][a]=1;
	}
	for(int k=1;k<=V;++k){
		for(int i=1;i<=V;++i){
			if(i==k){
				i++;
			}
			if(i<=V){


				for(int j=1;j<=V;++j){
					if(j==k){
						j++;
					}
					if(j<=V){


						int dis=Adj[i][k]+Adj[k][j];
						if(dis<Adj[i][j]){
							Adj[i][j]=dis;
							sp[i][j]=1;
						}
						else if(dis==Adj[i][j]){
							if(dis<MAXINT){
								sp[i][j]+=(sp[i][k]*sp[k][j]);
							}

						}

					}
				}
			}
		}
		//printf("\nk: %d\n",k);
		/*for(int i=1;i<=V;++i){
			for(int j=i+1; j<=V;++j){
				printf("%d %d %d %d\n",i,j,Adj[i][j],sp[i][j]);
			}
		}
		printf("\n");*/

	}
	int src,dest;
	scanf("%d %d",&src,&dest);
	printf("%d\n",sp[src][dest]);
	/*for(int i=1;i<=V;++i){
		for(int j=i+1; j<=V;++j){
			printf("%d %d %d %d\n",i,j,Adj[i][j],sp[i][j]);
		}
	}*/
}
/*
sample

4 5
1 2 1
1 3 2
1 4 1
2 3 1
4 3 1
1 3

ans 3

7 10
1 2 3
1 3 2
2 4 4
3 4 15
3 6 4
4 5 5
3 7 6
6 7 11
6 5 10
7 5 4
1 5

output 2

6 8
1 2 1
1 3 1
1 4 3
2 6 1
3 4 2
4 5 1
4 6 1
2 5 3
1 5
*/
