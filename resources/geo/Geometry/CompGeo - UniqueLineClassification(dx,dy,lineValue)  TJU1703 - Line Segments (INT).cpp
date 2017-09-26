#pragma warning (disable:4786)
//#define NAF
#include<assert.h>
#include<stdio.h>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#ifdef NAF
typedef __int64 LL;
#else
typedef long long LL;
#endif

typedef pair<int,int> PII;
typedef pair<PII,int> PPI;
typedef pair<PII,LL>  PPL;
typedef pair<PII,PII> PPP;

#define OPEN  1
#define CLOSE 0

int mark;
map<PPL,int> M;
vector<PPP> v[100002];

vector<PPI> e;

LL solve(vector<PPP> &v){
	LL tot,run;
	int i,n;

	e.clear();
	n = v.size();
	for(i=0;i<n;i++){
		e.push_back( PPI( v[i].first , OPEN ) );
		e.push_back( PPI( v[i].second, CLOSE ) );
	}

	sort(e.begin(),e.end());

	tot = run = 0;
	n = e.size();
	for(i=0;i<n;i++){
		if(e[i].second == CLOSE){
			run--;
			tot += run;
		}
		else
			run++;
		assert(run >= 0);
	}
	return tot;
}

template<class Integer>
Integer gcd(Integer x,Integer y){
	if(!x)	return y;
	if(!y)	return x;
	Integer r;
	while(r=x%y){
		x=y;
		y=r;
	}
	return y;
}

int main(){

	int T,N;
	int i,g,n,dx,dy,index;
	LL  lineValue;
	LL	tot;
	PII A,B,AB;
	PPL	key;

	scanf("%d",&T);
	for(N=1;N<=T;N++){
		
		scanf("%d",&n);

		mark = 0;
		M.clear();

		for(i=0;i<n;i++){
			scanf("%d%d",&A.first,&A.second);
			scanf("%d%d",&B.first,&B.second);
			if(B < A)swap(A,B);
			dx = B.first  - A.first;
			dy = B.second - A.second;
			if(dy < 0)	g = gcd(dx,-dy);
			else		g = gcd(dx,dy);
			dx /= g;
			dy /= g;
			AB = PII(dx,dy);

			assert(dx >= 0);

			lineValue = ( ((LL)(A.first))*((LL)(B.second)) - ((LL)(A.second))*((LL)(B.first)) ) / g;
			key = PPL(AB,lineValue);

			index = M[key];
			if(!index){
				index  = ++mark;
				M[key] =   mark;
				v[index].clear();
			}
			v[index].push_back( PPP(A,B) );
		}

//		printf(">> %d\n",mark);

		tot = 0;
		for(i=1;i<=mark;i++)
			tot += solve(v[i]);

		printf("Scenario #%d:\n",N);
		#ifdef NAF
		printf("%I64d\n",tot);
		#else
		printf("%lld\n",tot);
		#endif
		printf("\n");
	}

	return 0;
}