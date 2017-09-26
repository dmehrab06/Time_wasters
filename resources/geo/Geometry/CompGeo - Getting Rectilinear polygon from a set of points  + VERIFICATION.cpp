//acm11106
#pragma warning (disable:4786)
#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 100005
#define all(x)	x.begin(),x.end()

typedef long long LL;
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef map<int,int> MII;
typedef vector<int> VI;

int n;
VI x,y,px,py,ux,uy;
MII mx,my;
map<PII,int> mp;

VI atx[MAX],aty[MAX];

VI a[MAX];
queue<int> Q;

char col[MAX];

int main(){

	int xx;
	LL len;

	int i,j;
	int T;
	int X,Y;
	char flag;

	scanf("%d",&T);
	while(T--){
	
		scanf("%d",&n);

		x.clear();
		y.clear();
		px.clear();
		py.clear();
		mp.clear();

		for(i=0;i<n;i++){
			scanf("%d%d",&X,&Y);
			a[i].clear();
			x.push_back(X);
			y.push_back(Y);
			px.push_back(X);
			py.push_back(Y);
			mp[(PII(px[i],py[i]))] = i;
		}

		for(i=0;i<n;i++)
			assert( mp[(PII(px[i],py[i]))] == i );

		X = 0;
		sort(all(x));
		ux.clear();
		ux.push_back(x[0]);
		for(i=1;i<n;i++)if(x[i]!=x[i-1])
			ux.push_back(x[i]);

		mx.clear();
		for(i=0;i<ux.size();i++)
			mx[ux[i]] = X++;
			
		Y = 0;
		sort(all(y));
		uy.clear();
		uy.push_back(y[0]);
		for(i=1;i<n;i++)if(y[i]!=y[i-1])
			uy.push_back(y[i]);

		my.clear();
		for(i=0;i<uy.size();i++)
			my[uy[i]] = Y++;

		for(i=0;i<X;i++)
			atx[i].clear();
		for(i=0;i<Y;i++)
			aty[i].clear();

		for(i=0;i<n;i++){
			atx[mx[px[i]]].push_back(py[i]);
			aty[my[py[i]]].push_back(px[i]);
		}

		flag = 1;
		len = 0;
		for(i=0;i<X;i++)if(atx[i].size()>0){
			if(atx[i].size()%2==1){
				flag = 0;
				break;
			}
			sort(all(atx[i]));

			for(j=0;j+1<atx[i].size();j+=2){
				len += atx[i][j+1] - atx[i][j];
				a[mp[PII(ux[i] , atx[i][j])]].push_back(mp[PII(ux[i] , atx[i][j+1])]);
				a[mp[PII(ux[i] , atx[i][j+1])]].push_back(mp[PII(ux[i] , atx[i][j])]);
			}
		}
		if(!flag){
			printf("-1\n");
			continue;		
		}

		for(i=0;i<Y;i++)if(aty[i].size()>0){
			if(aty[i].size()%2==1){
				flag = 0;
				break;
			}
			sort(all(aty[i]));

			for(j=0;j+1<aty[i].size();j+=2){
				len += aty[i][j+1] - aty[i][j];
				a[mp[PII(aty[i][j],uy[i])]].push_back(mp[PII(aty[i][j+1],uy[i])]);
				a[mp[PII(aty[i][j+1],uy[i])]].push_back(mp[PII(aty[i][j],uy[i])]);
			}
		}
		if(!flag){
			printf("-1\n");
			continue;		
		}

		for(i=0;i<n;i++)
			assert(a[i].size()==2);

		memset(col,0,sizeof(col));

		while(!Q.empty())
			Q.pop();
		Q.push(0);
		col[0] = 1;

		while(!Q.empty()){
			xx = Q.front();
			Q.pop();

			for(j=0;j<a[xx].size();j++){
				i = a[xx][j];
				if(!col[i]){
					col[i] = 1;
					Q.push(i);
				}
			}
		}

		for(i=0;i<n;i++)if(!col[i])
			break;

		if(i==n)
			printf("%lld\n",len);
		else
			printf("-1\n");
	}
	return 0;
}