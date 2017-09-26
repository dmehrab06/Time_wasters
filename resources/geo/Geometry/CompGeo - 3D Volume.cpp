#include<stdio.h>
#include<math.h>

#define MAX		100
#define S(x)	((x)*(x))

struct Vector{
	double x,y,z;

	void scan(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}

	Vector(double _x=0,double _y=0,double _z=0){
		x=_x;y=_y;z=_z;
	}

	double Mag(){
		return sqrt(S(x)+S(y)+S(z));
	}

	double Dot(Vector &p){
		return x*p.x + y*p.y + z*p.z;
	}

	Vector Cross(Vector &p){
		return Vector( y*p.z - z*p.y , z*p.x - x*p.z , x*p.y - y*p.x );
	}
};

double Box(Vector &a,Vector &b,Vector &c){
	return a.Dot(b.Cross(c));
}

Vector operator-(Vector &a,Vector &b){
	return Vector(a.x-b.x , a.y-b.y , a.z-b.z);
}

Vector operator+(Vector &a,Vector &b){
	return Vector(a.x+b.x,a.y+b.y,a.z+b.z);
}

int nface;
struct Face{
	int n;
	Vector	v[MAX];

	void scan(){
		int i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			v[i].scan();
	}

	void translate(Vector &d){
		int i;
		for(i=0;i<n;i++)
			v[i] = v[i] + d;
	}
}f[MAX];

int main(){

	int i,j;
	double vol;

	while(scanf("%d",&nface)==1 && nface){
		
		for(i=0;i<nface;i++)
			f[i].scan();

		vol = 0;
		for(i=0;i<nface;i++)
			for(j=1;j<f[i].n-1;j++)
				vol += Box(f[i].v[0] , f[i].v[j] , f[i].v[j+1]);
		vol /= 6.;

		printf(">> %lf\n",vol);


		for(i=0;i<nface;i++)
			f[i].translate( Vector(10000,-100,43) );

		vol = 0;
		for(i=0;i<nface;i++)
			for(j=1;j<f[i].n-1;j++)
				vol += Box(f[i].v[0] , f[i].v[j] , f[i].v[j+1]);
		vol /= 6.;

		printf(">> %lf\n",vol);

	}

	return 0;
}