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

int par[100005];
int col[100005];

vector< VI > edg;

SI notdid;

bool colok(int node, int c){
	int l=edg[node].size();
	FREP(i,0,(l-1)){
		if(col[edg[node][i]]==c){
			return false;
		}
	}
	return true;
}

void dfs(int cur, int prev){
	par[cur]=prev;
	int l=edg[cur].size();
	FREP(i,0,(l-1)){
		int nxt=edg[cur][i];
		if(nxt!=prev){
			dfs(nxt,cur);
		}
	}
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	VI line;
	FREP(i,1,(n+3)){
		edg.PB(line);
		col[i]=0;
	}
	FREP(i,1,(n-1)){
		int u,v;
		scanf("%d %d",&u,&v);
		edg[u].PB(v);
		edg[v].PB(u);
	}
	dfs(1,0);
	SI::iterator it;
	FREP(i,1,n){
		notdid.insert(i);
	}
	cout<<"1 1\n";
	notdid.erase(1);
	int setsz=n-1;
	col[1]=1;
	int hu,hc;
	while(cin>>hu>>hc){
		if(hu==-1 && hc==-1){
			break;
		}
		col[hu]=hc;
		notdid.erase(hu);
		setsz--;
		int p=par[hu];
		if(col[p]==0){
			FREP(i,1,4){
				if(colok(p,i)){
					cout<<p<<" "<<i<<"\n";
					col[p]=i;
					notdid.erase(p);
					setsz--;
					break;
				}
			}
		}
		else{
			if(setsz==0){
				cout<<"-1 -1\n";
				break;
			}
			else{
				it=notdid.begin();
				int todo=*it;
				FREP(i,1,4){
					if(colok(todo,i)){
						col[todo]=i;
						notdid.erase(todo);
						setsz--;
						cout<<todo<<" "<<i<<"\n";
						break;
					}
				}
			}
		}
	}
	return 0;
}
