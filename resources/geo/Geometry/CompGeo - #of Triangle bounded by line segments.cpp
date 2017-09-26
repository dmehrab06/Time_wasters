//10979 - "How many triangles?"
//sub - 3(WA,WA,AC)
//15-08-06 7:15pm
//15-08-06 10:33pm
//828
#include<stdio.h>

#define myabs(x) (((x)>0)?(x):-(x))
#define swap(x,y)	{swp_tmp=x;x=y;y=swp_tmp;}

#define inrange(a,b,x)	(a<=x&&x<=b)

#define INF 10000000

#define NONE 0
#define ISECT 1
#define OVERLAP 2

int swp_tmp;

int nn;
struct Line{
	int x1,y1,x2,y2,ix1,ix2;
	int a,b,c;	//ax+by+c = 0;
}L[15];

int n,mat[70][70];
double x[70],y[70];

inline int LF(int a,int b,int c,int x,int y){
	return a*x + b*y + c;
}

inline int det(int a,int b,int c,int d){
	return a*d-b*c;
}

int Isect(Line L1,Line L2,double *x,double *y){
	int a1,b1,c1,a2,b2,c2;
	int p[4];
	
	a1=L1.a;
	b1=L1.b;
	c1=L1.c;
	p[0]=LF(a1,b1,c1, L2.x1,L2.y1);
	p[1]=LF(a1,b1,c1, L2.x2,L2.y2);

	a2=L2.a;
	b2=L2.b;
	c2=L2.c;
	p[2]=LF(a2,b2,c2, L1.x1,L1.y1);
	p[3]=LF(a2,b2,c2, L1.x2,L1.y2);
	
	if(!det(a1,a2,b1,b2)){	//a1*b2 - a2*b1 = 0 => a1/a2 = b1/b2	i.e. parallel
	    if(c1*a2!=c2*a1)	//i.e. a1/a2 = b1/b2 != c1/c2
	    	return NONE;	//non-coincident
	    	
		int Xmin,Xmax;
		int Ymin,Ymax;

		Xmin = L1.x1;Xmax = L1.x2;
		if(Xmin > Xmax)	swap(Xmin,Xmax);

		Ymin = L1.y1;Ymax = L1.y2;
		if(Ymin > Ymax)	swap(Ymin,Ymax);
		
		if( inrange(Xmin,Xmax,L2.x1) && inrange(Ymin,Ymax,L2.y1) )
			return OVERLAP;
		if( inrange(Xmin,Xmax,L2.x2) && inrange(Ymin,Ymax,L2.y2) )
			return OVERLAP;
		return NONE;
	}		
	
	if(p[0]*p[1] > 0 || p[2]*p[3] > 0)
		return NONE;

	*x = - det(c1,c2,b1,b2) / ((double)(det(a1,a2,b1,b2)));
	*y = - det(a1,a2,c1,c2) / ((double)(det(a1,a2,b1,b2)));
	return ISECT;
}

int push(double X,double Y){
    int k;
   	for(k=0;k<n;k++){
	    if(myabs(x[k]-X) < 1e-10 && myabs(y[k]-Y) < 1e-10)
	    	break;
	}  		
	if(k==n){	//new node
		x[n] = X;
		y[n] = Y;
		n++;
	}				
	return k;
}    

int main(){
    int i,j,k,count ,F;
    double X,Y,x1,y1,x2,y2,x3,y3;
    while(scanf("%d",&nn)==1){
        
        for(i=0;i<70;i++)
        	for(j=0;j<70;j++)
        		mat[i][j] = INF;
        
        n = 0;
    	for(i=0;i<nn;i++){
    		scanf("%d%d%d%d",&L[i].x1,&L[i].y1,&L[i].x2,&L[i].y2);
    		if(L[i].x1 == L[i].x2 && L[i].y1 == L[i].y2){
    			nn--;
    			i--;
    			continue;
      		}    
    		L[i].a = L[i].y1 - L[i].y2;
    		L[i].b = L[i].x2 - L[i].x1;
    		L[i].c = L[i].x1 * L[i].y2 - L[i].x2*L[i].y1;
    		
    		L[i].ix1 = push(L[i].x1,L[i].y1);
    		L[i].ix2 = push(L[i].x2,L[i].y2);
    		
    		mat[L[i].ix1][L[i].ix2] = mat[L[i].ix2][L[i].ix1] = 1;
     	}    

     	for(i=0;i<nn;i++){
     		for(j=i+1;j<nn;j++){
     		    
     		    F = Isect(L[i],L[j] , &X,&Y);
     		    
     		    if(F==OVERLAP){
     		        
      				mat[L[i].ix1][L[j].ix1] = mat[L[j].ix1][L[i].ix1] = 1;
      				mat[L[i].ix1][L[j].ix2] = mat[L[j].ix2][L[i].ix1] = 1;
      				mat[L[i].ix2][L[j].ix1] = mat[L[j].ix1][L[i].ix2] = 1;
      				mat[L[i].ix2][L[j].ix2] = mat[L[j].ix2][L[i].ix2] = 1;
      				
           		}    
     		    else if(F==ISECT){
     		    	k = push(X,Y);
       	  				
      				mat[k][L[i].ix1] = mat[L[i].ix1][k] = 1;
      				mat[k][L[i].ix2] = mat[L[i].ix2][k] = 1;
      				
      				mat[k][L[j].ix1] = mat[L[j].ix1][k] = 1;
      				mat[k][L[j].ix2] = mat[L[j].ix2][k] = 1;
      			}				
       		}    
      	}    
      	
      	for(k=0;k<n;k++){
      		for(i=0;i<n;i++){
      			for(j=i+1;j<n;j++){

      				if( mat[i][j] > mat[i][k] + mat[k][j] && 
          				myabs( (x[i]-x[j]) * (y[j]-y[k]) - (y[i]-y[j]) *(x[j]-x[k])) < 1e-10){

      						mat[i][j] = mat[j][i] = 1;
      				}				
      			}
      		}
    	}	  		
      	
      	count = 0;
      	for(i=0;i<n;i++){
      		for(j=i+1;j<n;j++){
      			if(mat[i][j]==INF)
      				continue;
      			for(k=j+1;k<n;k++){
      			    
	      			if(mat[i][k]==INF || mat[j][k]==INF)
    	  				continue;
          			if( myabs( (x[i]-x[j]) * (y[j]-y[k]) - (y[i]-y[j]) *(x[j]-x[k])) < 1e-10 )
						continue;
					////colinear!!
					count++;
      			}
     		}
      	}        
      	
      	
       	printf("%d\n",count);
      	
    }    
	return 0;
}    
