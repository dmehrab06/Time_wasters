/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 107;

class Point3D{
    public:
        double x;
        double y;
        double z;
    Point3D(double _x = 0.0, double _y = 0.0, double _z = 0.0){
        x = _x; y = _y; z = _z;
    }
};

Point3D v[MAXN];

typedef vector<Point3D> Pointvector;

inline double Comb(Point3D& a, Point3D& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

#define	SQR(X)  ((X)*(X))

inline double Dist(Point3D& a, Point3D& b)
{
	return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y) + SQR(a.z - b.z));
}

inline void Intersect(Point3D& a, Point3D& b, Point3D& c, Point3D& res)
{
	double t = -(c.x*a.x + c.y*a.y + c.z*a.z) / (c.x*(b.x - a.x) + c.y*(b.y - a.y) + c.z*(b.z - a.z));
	res.x = a.x + t*(b.x - a.x);
	res.y = a.y + t*(b.y - a.y);
	res.z = a.z + t*(b.z - a.z);
}

//hpi template credit: xoptutorials

bool HalfPlaneNotEmpty(Pointvector curlines)
{
	Pointvector current;
	current.push_back(Point3D(1,0,0));
    current.push_back(Point3D(0,1,0));
    current.push_back(Point3D(0,0,1));

	int i;
	for (i = 0; i < curlines.size(); i++){

        Pointvector nw;
        Point3D c;

        int j;
        c.x = (curlines[p].x - curlines[i].x) / (curlines[p].x*curlines[i].x);
        c.y = (curlines[p].y - curlines[i].y) / (curlines[p].y*curlines[i].y);
        c.z = (curlines[p].z - curlines[i].z) / (curlines[p].z*curlines[i].z);

        j = 0;
        while ((j < current.size()) && (Comb(c, current[j]) <= EPS))
            j++;
        if (j == current.size())
            break;

        int r = 0;
        while (r<current.size()){
            if (Comb(c, current[j])>EPS){
                nw.push_back(current[j]);
                j = (j + 1) % current.size();
                r++;
            }
            else{
                int k = (j + 1) % current.size();
                int l = 0;
                r++;
                while ((l < current.size() + 1) && (Comb(c, current[k]) <= EPS)){
                    k = (k + 1) % current.size();
                    l++;
                    r++;
                }
                if (l < current.size() + 1){
                    Point3D nwPoint;
                    Intersect(nw[nw.size() - 1], current[j], c, nwPoint);
                    nw.push_back(nwPoint);
                    Intersect(current[(k + current.size() - 1) % current.size()], current[k], c, nwPoint);
                    nw.push_back(nwPoint);
                }
                j = k;
            }
        }
        current = nw;
    }

	if (i != curlines.size())
	{
		return false;
	}
	else
	{
		double d = -1.0;
		for (int i = 0; i < current.size() - 1; i++)
			for (int j = i + 1; j < current.size() - 1; j++)
				if (Dist(current[i], current[j]) > d)
					d = Dist(current[i], current[j]);
		return d > EPS;
	}
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n)scanf("%lf %lf %lf",&v[i].x,&v[i].y,&v[i].z);
    FREP(i,1,n){
        Pointvector curlines;
        FREP(j,1,n){
            if(j!=i)curlines.PB(v[j]);
        }
        if(HalfPlaneNotEmpty(curlines)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}
