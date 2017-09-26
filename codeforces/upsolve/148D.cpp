/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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

//vector< MII > dp;

double pdp[1003][1003];
double ddp[1003][1003];

void init(){

	FREP(i,0,1002)FREP(j,0,1002){
		pdp[i][j]=-1.0;
		ddp[i][j]=-1.0;
	}
}

double dsolve(int w, int b);

double psolve(int w, int b){
	if(b<0) return 0.00;

	if((w+b)==0)return pdp[w][b]=0.0;
	
	if(b==0)return pdp[w][b]=1.0;
	
	if(w==0)return pdp[w][b]=0.0;
	
	if(!(pdp[w][b]<0.0)) return pdp[w][b];
	
	double p=(double)w/(double)(w+b);
	double ret=p+(1.00-p)*dsolve(w,b-1);
	return pdp[w][b]=ret;
}

double dsolve(int w, int b){
	
	if(b<0)return 0.00;

	if((w+b)==0)return ddp[w][b]=1.0;
	
	if(b==0)return ddp[w][b]=1.0;
	
	if(w==0)return ddp[w][b]=1.0;

	if(!(ddp[w][b]<0.0)) return ddp[w][b];

	double p=(double)w/(double)(w+b);
	double ret=p+(1.00-p)*(((double)(b-1)/(double)(w+b-1))*psolve(w,b-2)+((double)(w)/(double)(w+b-1))*psolve(w-1,b-1));
	return ddp[w][b]=ret;
}

int main()
{
	/* code */

	int w,b;
	scanf("%d %d",&w,&b);
	init();
	double ans=psolve(w,b);
	printf("%.7lf\n",ans);
	return 0;
}

