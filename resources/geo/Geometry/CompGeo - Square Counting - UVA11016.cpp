//11016 - "Square Counting"	"O(x*nlogn)
//sub - 1(AC)
//20-03-06
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 101
#define EPS 5e-6

#define _max(x,y) ((x)>(y) ? (x):(y))
#define _min(x,y) ((x)<(y) ? (x):(y))

struct Point{
	int x,y;
}p[MAX];

struct Y{
	double y1,y2;
}s[MAX];

int sort_Y(const void *p,const void *q){
	Y *a = (Y *)p;
	Y *b = (Y *)q;
	if(a->y1+a->y2 < b->y1+b->y2)
		return 1;
	else
		return -1;
}

int main(){
	int n,i,j,x1,x2,x;
	int ny,y[MAX];
	int area;
	int aL,aD;
	while(scanf("%d",&n)==1&&n){
		//0<=x1<=x2<=10000
		x1=10000;
		x2=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			if(x1 > p[i].x)
				x1 = p[i].x;
			if(x2 < p[i].x)
				x2 = p[i].x;
		}

		area = 0;
		aL = aD = 0;

		for(x=x1;x<x2;x++){
			ny = 0;
			for(i=0;i<n;i++){
				j = (i+1)%n;

				if(p[i].x==p[j].x)
					continue;
				
				if(_min(p[i].x,p[j].x) <= x && x+1 <= _max(p[i].x,p[j].x)){
					
					s[ny].y1 = p[i].y + (p[j].y - p[i].y) * (x   - p[i].x) / ((double)(p[j].x - p[i].x));
					s[ny].y2 = p[i].y + (p[j].y - p[i].y) * (x+1 - p[i].x) / ((double)(p[j].x - p[i].x));

					ny++;
				}
			}


			qsort(s,ny,sizeof(Y),sort_Y);

			for(i=0;i<ny;i++){
				if(i%2==0)
					y[i] = (int)(floor(_min(s[i].y1 , s[i].y2) + EPS));
				else
					y[i] = (int)(ceil (_max(s[i].y1 , s[i].y2) - EPS));
			}

			for(i=0;i+1<ny;i+=2){
				if(!(y[i]-y[i+1] > 0) )
					continue;

				area+=y[i]-y[i+1];

				if((x+y[i])%2==0){	//light theke shuru
					aL+=(y[i]-y[i+1] + 1)/2;
					aD+=(y[i]-y[i+1]    )/2;
				}
				else{	//dark theke shuru
					aD+=(y[i]-y[i+1] + 1)/2;
					aL+=(y[i]-y[i+1]    )/2;
				}

			}
		}
		printf("%d %d\n",_max(aL,aD) , _min(aL,aD));
	}
	return 0;
}