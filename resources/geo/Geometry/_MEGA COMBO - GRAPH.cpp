#pragma warning (disable:4786)

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<assert.h>

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

#define _abs(x)		(((x)>0)?(x):-(x))
#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

#define For3(i,a,b)	for(i=(a);i<(b);i++)
#define For2(i,a)	for(i=0;i<(a);i++)
#define For(i)		for(i=0;i<n;i++)

#define EPS 1e-10

#define S(x)	((x)*(x))
#define Z(x)	(_abs(x) < EPS)
#define N(x)	(x < 0 && !Z(x))
#define P(x)	(x > 0 && !Z(x))
#define ZN(x)	(x < 0 || Z(x))
#define ZP(x)	(x > 0 || Z(x))

#define E(x,y)	(Z((x)-(y)))

#define D2(a,b)	(S(a.first-b.first) + S(a.second-b.second))
#define D1(a,b)	(sqrt(D2(a,b)))

#define T2(a,b,c)	((a.first*b.second+b.first*c.second+c.first*a.second) - (a.second*b.first+b.second*c.first+c.second*a.first))

template<class Class1,class Class2,class Class3> struct triple{
	Class1 first;Class2 second;Class3 third;triple(){}
	triple(Class1 _first,Class2 _second,Class3 _third){	first = _first;	second = _second;third = _third;}
	friend bool operator==(const triple &t1,const triple &t2){return t1.first == t2.first && t1.second == t2.second && t1.third == t2.third;}
	friend bool operator!=(const triple &t1,const triple &t2){return !(t1 == t2);}
	friend bool operator<(const triple &t1,const triple &t2){if(t1.first != t2.first)return t1.first < t2.first;if(t1.second != t2.second)return t1.second < t2.second;return t1.third < t2.third;}
};
typedef triple<int,int,int> TI;
typedef pair<int,int> PII;
typedef pair<int,int> Point;

/************
*	GRAPH	*
************/

#define MAX 105
#define MAX_BPM 3000
#define INF 1000000000

int N;	//running tescase, from 1

int n;	//graph nodes [not for bpm]
//nodes are 0-indexed
vector<PII> a[MAX];		//input - dijkstra - adjacency list of <nodeIndex,cost>
vector<int> b[MAX];		//input - bfs/articulationPoints - adjacency list of <nodeIndex>
int mat[MAX][MAX];		//input - apsp - adjacency matrix
int sp[MAX];			//output - bfs/dijkstra - shortest path
vector<int> artnode;	//output - articulation points
//bpm
int graph[MAX_BPM][MAX_BPM];	//put testcase, i.e. = N if there is a EDGE
bool seen[MAX_BPM];
int matchL[MAX_BPM], matchR[MAX_BPM];
int nleftbpm, nrightbpm;



int bmp();			//bpm - igor's code ?
void apsp();		//floyd warshall V^3
void spSet(int);	//dijkstra VlogV
void bfs(int);		//bfs V+E
void artPoints();	//articulation points V+E



int main(){

	
	return 0;

}



//bpm : credit - IGOR
//0 indexing: 0,1,2,...,nleftbpm-1  and  0,1,2,...,nrightbpm-1
/*
	precondition:
	graph[i][j] = N if there is a edge
*/
bool bpmDfs( int u ){
    for( int v = 0; v < nrightbpm; v++ ) if( graph[u][v]==N ){
        if( seen[v] )
			continue;
        seen[v] = true;
        if( matchR[v] < 0 || bpmDfs( matchR[v] ) ){
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int bpm(){
	memset( matchL, -1, sizeof( matchL ) );
	memset( matchR, -1, sizeof( matchR ) );
	static int cnt,i;
	for(cnt = i = 0; i < nleftbpm; i++ ){
		memset( seen, 0, sizeof( seen ) );
		if( bpmDfs( i ) )
			cnt++;
	}
	return cnt;
/*	//etao kaaj kore
	memset( matchL, -1, sizeof( matchL ) );
	memset( matchR, -1, sizeof( matchR ) );
	static int cnt,i;
	memset( seen, 0, sizeof( seen ) );
	for(cnt = i = 0; i < nleftbpm; i++ ){
		if( bpmDfs( i ) ){
			cnt++;
			memset( seen, 0, sizeof( seen ) );
		}
	}
	return cnt;
*/
}


//floyd warshall V^3
void apsp(){
	static int i,j,k;
	for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)if(mat[i][j] > mat[i][k]+mat[k][j])
		mat[i][j] = mat[i][k]+mat[k][j];
}

//dijkstra VlogV+E, worst case e, ElogV
set<PII> sps;
void spSet(int s){
	static int x,i,j,c;
	static PII now;

	for(i=0;i<n;i++)
		sp[i] = INF;

	sp[s] = 0;
	sps.clear();
	sps.insert(PII(sp[s],s));	//pair(distance,node)

	while(!sps.empty()){
		now = *sps.begin();
		sps.erase(now);

		x = now.second;

		for(j=0;j<a[x].size();j++){
			i = a[x][j].first;
			c = a[x][j].second;

			if(sp[x] + c < sp[i]){
				sps.erase ( PII(sp[i],i) );
				sp[i] = sp[x]+c;
				sps.insert( PII(sp[i],i) );
			}
		}
	}
}

//bfs V+E
void bfs(int s){
	static queue<int> Q;
	static int x,i,j;

	for(i=0;i<n;i++)
		sp[i] = INF;
	while(!Q.empty())
		Q.pop();

	sp[s] = 0;
	Q.push(s);
	while(!Q.empty()){
		x = Q.front();
		Q.pop();
		for(j=0;j<b[x].size();j++){
			i = b[x][j];
			if(sp[x]+1 < sp[i]){
				sp[i]=sp[x]+1;
				Q.push(i);
			}
		}
	}
}

//articulation points V+E
int root,artcol,acol[MAX];
char adone[MAX];
int artDfs(int x){
	int i,j,colback,colchi,colchi1,nchi;

	colback = INF;
	colchi = INF;
	nchi = 0;
	for(j=0;j<b[x].size();j++){
		i = b[x][j];
		if(acol[i]){				//if already colored
			if(acol[i] < acol[x])
				colback = _min(colback, acol[i]);
		}	
		else{						//if not
			acol[i] = artcol++;
			colchi1 = artDfs(i);
			if(x==root) nchi++;
			else if(acol[x] == colchi1 && !adone[x]){
				artnode.push_back(x);
				adone[x]=1;
			}
			colchi = _min(colchi,colchi1);		
		}
	}
	if(x==root && nchi>1){
		artnode.push_back(x);
		adone[x]=1;
	}
	return _min(colback,colchi);
}
void artPoints(){
	static int i;

	for(i=0;i<n;i++)
		adone[i] = acol[i] = 0;
	artnode.clear();

	for(i=0;i<n;i++)if(acol[i]==0){
		artcol = 1;
		acol[i] = artcol++;
		root = i;
		artDfs(i);
	}
}
