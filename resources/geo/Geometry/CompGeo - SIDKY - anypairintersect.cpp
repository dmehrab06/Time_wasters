#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <functional>
using namespace std;

#define	MAX_EDGES	100000

const int debug = 0;
#define	DBG(x)	if(debug != 0) x

struct Point
{
	double	x;
	double	y;
};

struct Segment
{
	double	y_val;
	Point	p1;
	Point	p2;
};

typedef Segment	Edge;

double dot(const Point &p1, const Point &p2)
{
	return p1.x * p2.x + p1.y * p2.y;
}

double cross(const Point &p1, const Point &p2)
{
	return (p1.x * p2.y - p2.x * p1.y);
}

int sign(double x)
{
	if(fabs(x) < 1e-9)
		return 0;
	else if(x < 0)
		return -1;
	else
		return 1;
}

bool intersect(const Segment &s1, const Segment &s2, Point *isect)
{
	Point	n;
	Point	u,v;
	double	p,q;

	n.x = -(s2.p2.y - s2.p1.y);
	n.y = s2.p2.x - s2.p1.x;

	Point	cd;

	cd.x = s2.p2.x - s2.p1.x;
	cd.y = s2.p2.y - s2.p1.y;

//	DBG(printf("dot=%lf\n",dot(n,cd)));

	u.x = s1.p1.x - s2.p1.x;
	u.y = s1.p1.y - s2.p1.y;

	v.x = s1.p2.x - s1.p1.x;
	v.y = s1.p2.y - s1.p1.y;

	p = -dot(n,u);
	q = dot(n,v);

//	DBG(printf("%lf %lf\n",p,q));

	if(sign(p) * sign(q) < 0)
		return false;
	else
	{
		p = fabs(p);
		q = fabs(q);

		if(p < q)
		{
			double	t = p / q;

			isect->x = s1.p1.x + t * (s1.p2.x - s1.p1.x);
			isect->y = s1.p1.y + t * (s1.p2.y - s1.p1.y);

			return true;
		}
		else
			return false;
	}
}

enum EVENT_TYPE {LEFT_END, CROSSING, RIGHT_END};

struct Event
{
	double	x;
	EVENT_TYPE type;
	int	e1,e2;

	bool operator < (const Event &event) const
	{
		if(x == event.x)
		{
			if(type != event.type)
				return type < event.type;
			else
			{
				if(e1 != event.e1)
					return e1 < event.e1;
				else
					return e2 < event.e2;
			}
		}
		else
			return x < event.x;
	}
};

set <Event> event;
Edge	edges[MAX_EDGES];
int	total_edges;

double curx;

double update(int edge, double x)
{
	double	t = (x - edges[edge].p1.x) / (edges[edge].p2.x - edges[edge].p1.x);
	return edges[edge].p1.y + (edges[edge].p2.y - edges[edge].p1.y) * t;
}

class SweepCompare
{
	public:
		bool operator()(const int &a, const int &b) const
		{
			double	n,m;
			n = update(a,curx);
			m = update(b,curx);

			//DBG(printf("a=%d; b=%d; n=%lf; m=%lf\n",a,b,n,m));

			if(fabs(n - m) < 1e-8)
				return a < b;
			else
				return n < m;
		}
};

bool sweep_compare(int a,int b)
{
	double	n,m;
	n = update(n,curx);
	m = update(m,curx);

	if(fabs(n - m) < 1e-8)
		return a < b;
	else
		return n < m;
}

set <int,SweepCompare> sweepLine;

void showSweep()
{
	set <int>::iterator	iter;

	for(iter = sweepLine.begin(); iter != sweepLine.end(); iter++)
		printf("%d ",*iter);
	printf("\n");
}

void linesweep(double startx)
{
	curx = startx;
	int	i,u,v;
	int	pe,ne;
	Event	e,active;
	set <int>::iterator	p,q,r;
	Point	point;
	set <int>::iterator	q1;
	set <Event>::iterator	pevent;
	set <int>::iterator	iter;

	for(i = 0; i < total_edges; i++)
	{
		e.x	= edges[i].p1.x;
		e.type	= LEFT_END;
		e.e1	= i;
		e.e2	= 0;
		event.insert(e);

		e.x	= edges[i].p2.x;
		e.type	= RIGHT_END;
		event.insert(e);
	}

	while(event.size() != 0)
	{
		pevent = event.begin();
		e = *pevent;
		active = e;
		event.erase(pevent);

		DBG(printf("event: %lf edge1:%d; edge2:%d\n",active.x,active.e1,active.e2));
		DBG(printf("sweep queue size: %d; curx: %lf\n",sweepLine.size(),curx));

		switch(active.type)
		{
			case LEFT_END:
				i = e.e1;
				curx = active.x;
				sweepLine.insert(e.e1);
				DBG(showSweep());
				q = sweepLine.find(e.e1);
				p = q;
				if(p != sweepLine.begin())
				{
					p--;
					pe = *p;
				}
				else
					pe = -1;

				r = q;
				r++;


				if(r != sweepLine.end())
					ne = *r;
				else
					ne = -1;

				if(pe >= 0 && ne >= 0 && intersect(edges[pe],edges[ne],&point))
				{
					if(curx < point.x)
					{
						e.x	= point.x;
						e.type	= CROSSING;
						e.e1	= pe;
						e.e2	= ne;

						pevent = event.find(e);
						event.erase(pevent);
					}
				}

				if(pe >= 0 && intersect(edges[pe],edges[i],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.type	= CROSSING;
					e.e1	= pe;
					e.e2	= i;
					event.insert(e);
				}

				if(ne >= 0 && intersect(edges[ne],edges[i],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.type	= CROSSING;
					e.e1	= i;
					e.e2	= ne;
					event.insert(e);
				}
				break;
			case CROSSING:
				int	edg1,edg2;

				printf("edges  %d and %d intersect\n",active.e1, active.e2);
				edg1 = active.e1;
				edg2 = active.e2;

				DBG(showSweep());

				q = sweepLine.find(edg1);
				q1 = sweepLine.find(edg2);

				p = q;
				if(p != sweepLine.begin())
				{
					p--;
					pe = *p;
				}
				else
					pe = -1;

				r = q1;
				r++;
				if(r != sweepLine.end())
					ne = *r;
				else
					ne = -1;

				e.type	= CROSSING;

				DBG(printf("pe=%d; ne=%d; edg1=%d; edg2=%d\n",pe,ne,edg1,edg2));

				if(pe != -1 && intersect(edges[pe],edges[edg1],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.e1	= pe;
					e.e2	= edg1;
					pevent = event.find(e);
					event.erase(pevent);
				}

				if(ne != -1 && intersect(edges[edg2],edges[ne],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.e1	= edg2;
					e.e2	= ne;
					pevent = event.find(e);
					event.erase(pevent);
				}

				if(pe != -1 && intersect(edges[pe],edges[edg2],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.e1	= pe;
					e.e2	= edg2;
					event.insert(e);
				}

				if(ne != -1 && intersect(edges[edg1],edges[ne],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.e1	= edg1;
					e.e2	= ne;
					event.insert(e);
				}

				q = sweepLine.find(edg1);
				sweepLine.erase(q);
				curx = active.x + 1e-5;
				sweepLine.insert(edg1);
				curx = active.x;
				DBG(showSweep());
				break;
			case RIGHT_END:
				i = e.e1;
				q = sweepLine.find(i);
				p = q;

				if(p == sweepLine.begin())
					pe = -1;
				else
				{
					p--;
					pe = *p;
				}

				r = q;
				r++;
				if(r == sweepLine.end())
					ne = -1;
				else
					ne = *q;

				sweepLine.erase(q);

				if(pe >= 0 && ne >= 0 && intersect(edges[pe],edges[ne],&point) && curx < point.x)
				{
					e.x	= point.x;
					e.type	= CROSSING;
					e.e1	= pe;
					e.e2	= ne;
					event.insert(e);
				}
				curx = active.x;
				break;
		}
	}
}



int main()
{
	Segment	s1,s2;
	int	i;

	while(scanf("%d",&total_edges) == 1)
	{
		for(i = 0; i < total_edges; i++)
		{
			scanf("%lf %lf %lf %lf",&edges[i].p1.x,&edges[i].p1.y,&edges[i].p2.x,&edges[i].p2.y);

		}

		linesweep(-1);
	}
	return 0;
}
