#include<stdio.h>
#include<math.h>

#define MAX_VERTEX 1000
#define MAX_ANGLE 12.
#define INF_DOUBLE 100000000.
#define INF_INT 10000
#define PI (2.*acos(0.))
#define LIMIT 1e-10

#define side2(a,b,c,d) ((a-c)*(a-c) + (b-d)*(b-d))
#define myabs(a) ((a>0)?(a):-(a))

int px[MAX_VERTEX],py[MAX_VERTEX];
int cx[MAX_VERTEX],cy[MAX_VERTEX];

double GetAngle(int dx,int dy){
	if(dx==0){
		if(dy>0) return PI/2.;
		else return 3.*PI/2.;
	}
	else if (dy==0){
		if (dx>0)
			return 0;
		else return PI;
	}
	if(atan2(dy,dx)<0) return atan2(dy,dx) + 2.*PI;
	return atan2(dy,dx);
}

int FindStaringPoint(int n,int *x,int *y){
	int i,miny,p;
	miny=INF_INT;
	for(i=0;i<n;i++){
		if(y[i]==miny){
			if(x[i]<x[p]){
				p=i;
			}
		}
		else if(y[i]<miny){
			miny=y[i];
			p=i;
		}
	}
	return p;
}

void ConvexHull(int n,int *x,int *y,int *cn,int *cx,int *cy){
	int i,j,k;
	long dis,disbak;
	double min,ag,lastAg;
	if(n==0){
		*cn=0;
		return;
	}
	if(n==1){
		cx[0]=x[0];
		cy[0]=y[0];
		*cn=1;
		return;
	}
	k=FindStaringPoint(n,x,y);
	cx[0]=x[k];
	cy[0]=y[k];
	lastAg=0;
	for(i=1;i<n;i++){
		min=MAX_ANGLE;  //for any angle highest is 2*PI
		disbak=(long)INF_DOUBLE;
		for(j=0;j<n;j++){
			if(x[j]==cx[i-1]&&y[j]==cy[i-1])
				continue;
			ag=GetAngle(x[j]-cx[i-1],y[j]-cy[i-1]) - lastAg;
			while(ag < -LIMIT)
				ag+=2.*PI;
			while(ag >= 2.*PI+LIMIT)
				ag-=2.*PI;
			dis=side2(x[j],y[j],cx[i-1],cy[i-1]);
			if(myabs(ag-min) < LIMIT){
				if(dis<disbak){
					k=j;
					disbak=dis;
				}
			}
			if(ag<min){
				min=ag;
				k=j;
				disbak=dis;
			}
		}
		cx[i]=x[k];
		cy[i]=y[k];
		if(cx[i]==cx[0]&&cy[i]==cy[0])
			break;
		//lastAg=min+lastAg;
		lastAg=GetAngle(cx[i]-cx[i-1],cy[i]-cy[i-1]);
	}
	*cn=i;
}

void main(){
	int i,pn,cn;
	while(scanf("%d",&pn)==1){
		for(i=0;i<pn;i++)
			scanf("%d%d",&px[i],&py[i]);
		ConvexHull(pn,px,py,&cn,cx,cy);
		printf("%d\n",cn);
		for(i=0;i<cn;i++)
			printf("%d %d\n",cx[i],cy[i]);
	}
}