//Convex Hull - nlogn - Graham Scan
//points are INTEGERS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100005

#define LMT 1e-12

#define myabs(x) ( ((x)>0) ? (x) : -(x) )
#define TRA(A,B,C) ( (A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x) )

#define SS(x) ((x)*(x))
#define D1(A,B) (  sqrt( SS(A.x-B.x) + SS(A.y-B.y) )  )

int n,cn;
struct Point{
	int x,y;
	double theta,d;
}p[MAX],cp[MAX] , PP;

double RX,RY;

double PI = 2*acos(0.);
double GetAngle(double dx,double dy){      //return RANGE:: [0,2*pi)
	double at;
    if(myabs(dx) < LMT){
        if(dy > 0)	return PI/2;
        else		return 3*PI/2;
    }    
    if(myabs(dy) < LMT){
        if(dx > 0)	return 0;
        else		return PI;
    }
    at = atan2(dy,dx);
    if(at < 0)		at+=2*PI;
    return at;    
}

//sort accoriding to ascending order of angles
int Sort(const void *p,const void *q){
    Point *a = (Point *)p;
    Point *b = (Point *)q;
    if(myabs(a->theta - b->theta) < LMT){
    	if(a->d < b->d)
    		return 1;
		return -1;
    }    
    if(a->theta > b->theta)
        return 1;
    return -1;
}
    
int start(int n,Point *P){
    int k,i;
    int minx,miny;
    k = 0;
    minx = P[0].x;
    miny = P[0].y;
    for(i=1;i<n;i++){
        if(miny==P[i].y && P[i].x < minx){
            k = i;
            minx = P[i].x;
            miny = P[i].y;
        }    
        else if(P[i].y < miny){
            k = i;
            minx = P[i].x;
            miny = P[i].y;
        }    
    }    
    return k;
}

void ConvexHull(int n,Point *P,int *cn,Point *CP){
    int i,i1,S,n1;
    double AA;
    if(n <= 2){
        for(i=0;i<n;i++){
            CP[i].x = P[i].x;
            CP[i].y = P[i].y;
        }
        *cn = n;
        return;
    }
    //getting the angles O(n)
    for(i=0;i<n;i++){
        P[i].theta = GetAngle(P[i].x-RX , P[i].y-RY);  //angle P[i]-R-X'
        P[i].d = sqrt( SS(P[i].x - RX) + SS(P[i].y - RY) );
    }    
    //sorting according to angles O(nlogn)
    qsort(P,n,sizeof(P[0]),Sort);
    
    //initial point:    
    S = start(n,P);     //finding starting point O(n)
	CP[0] = P[S];
	
    n1 = 1;

    //processing O(n) ~ O(2*n)
    for(i1=1;i1<n;i1++){
        i = (i1+S) % n;
        if(myabs(P[i].theta - CP[n1-1].theta) < LMT)
        	continue;
        //in case of allpossible points:: TRA() < 0
        while(n1>=2 && TRA(CP[n1-2],CP[n1-1],P[i]) <= 0)
        	n1--;
		CP[n1] = P[i];
        n1++;
    }
    while(n1>3 && TRA(CP[n1-2],CP[n1-1],CP[0]) <= 0)
    	n1--;
    *cn = n1;    
}

int main(){
    int i,j;
    int x,y;
    int Q;
    
    int c_area;
    int t_area;
    
    double g;
    
	while(scanf("%d",&n)==1){
	    x=y=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			x+=p[i].x;
			y+=p[i].y;
  		}    
  		RX=x / ((double)(n));
  		RY=y / ((double)(n));
  		
  		ConvexHull(n,p,&cn,cp);
  		c_area = 0;
  		for(i=0;i<cn;i++){
  			j =(i+1) % cn;
  			c_area+= cp[i].x*cp[j].y - cp[j].x*cp[i].y;
    	}    
    	//remark: c_area = actual area * 2
 	}    
	return 0;
}    
