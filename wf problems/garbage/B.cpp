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

vector< stack <char> > oka;

void init(){
	oka.clear();
	stack<char>line;
	for(int i=0;i<26;++i){
		oka.PB(line);
		oka[i].push('a');
	}
}

int main(){
	int t;
	//scanf("%d",&t);
	int cs=1;
	string cont;
	while(cin>>cont){
		if(cont=="end")break;
		init();
		//cin>>cont;
		int l=cont.size();
		int need=0;
		FREP(i,0,(l-1)){
			FREP(j,0,25){
				if(oka[j].top()>=cont[i]){
					if(oka[j].top()=='a')need++;
					oka[j].push(cont[i]);
					break;
				}
			}
		}
		printf("Case %d: %d\n",cs++,need);
	}
    return 0;
}
