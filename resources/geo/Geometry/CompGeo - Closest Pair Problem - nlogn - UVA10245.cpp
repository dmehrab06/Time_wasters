//10245 - "The Closest Pair Problem" - "Plane Sweep Algorithm - Divide and Conquer"
//sub - 1(AC)
//2007 17 05 2:41pm
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAX 10005
#define INF 10000

#define S(x)	(x)*(x)
#define D2(A,B)	(S(A.x-B.x) + S(A.y-B.y))
#define D1(A,B)	sqrt(D2(A,B))

#define _abs(x)		(((x)>0)?(x):-(x))

int n;
struct Point{
	double x,y;
}p[MAX];

int ns1,ns2 , ns3,ns4;
Point s1[MAX],s2[MAX] , s3[MAX],s4[MAX];

int sortX(const void *p,const void *q){
	Point *a = (Point *)p;
	Point *b = (Point *)q;
	if(a->x < b->x)
		return -1;
	return 1;
}

int sortY(const void *p,const void *q){
	Point *a = (Point *)p;
	Point *b = (Point *)q;
	if(a->y < b->y)			/*MAJOR vul: IF er por SEMICOLON*/
		return -1;
	return 1;
}

double dist(int k1,int k2){
	
	double d,d2 ,d3;
	
	if(k2-k1+1 == 1)	////////
		return 0;
		
	if(k2-k1+1 == 2)
		return D1(p[k1],p[k2]);
		
	if(k2-k1+1 == 3){
		
		d  = D1(p[k1],p[k1+1]);
		d2 = D1(p[k1+1],p[k1+2]);
		d3 = D1(p[k1+2],p[k1]);
		if(d > d2)	d = d2;
		if(d > d3)	d = d3;
		return d;
	}
	
	int k,i,j;
	
	k = (k1 + k2) / 2;
	
	d  = dist(k1 , k);
	d2 = dist(k+1 , k2);
	
	if(d > d2)	d = d2;

	ns1 = 0;
	for(i = k; i>=k1 ; i--){
		if( p[k].x - p[i].x  >  d )
			break;
		s1[ ns1++ ] = p[i];
	}
	qsort( s1 , ns1 , sizeof(s1[0]) , sortY);


	ns2 = 0;
	for(i = k+1; i<=k2 ; i++){
		if( p[i].x - p[k].x  >  d )
			break;
		s2[ ns2++ ] = p[i];
	}
	qsort( s2 , ns2 , sizeof(s2[0]) , sortY);
	
	for(i=0;i<ns1;i++){
		for(j=0;j<ns2;j++){
			if(s2[j].y - s1[i].y > d)
				break;
				
			d2 = D1(s1[i],s2[j]);
			if(d2 < d)
				d = d2;
			
		}
	}

	return d;	
}

int main(){
	
	int i;
	double d;
	char buf[100];
	while(scanf("%d",&n)==1 && n){
		
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		if(n==1){
			printf("INFINITY\n");
			continue;
		}
		
		qsort(p,n,sizeof(p[0]),sortX);		
		
		d = dist(0,n-1);
		
		sprintf(buf,"%.4lf",d);
		sscanf(buf,"%lf",&d);
		
		if(d < INF)
			printf("%.4lf\n",d );
		else
			printf("INFINITY\n");
	}
	return 0;
}
