#include <bits/stdc++.h>

using namespace std;

vector< pair< int, pair<int,int> > >foods;

int foodremain[100005];
int foodcost[100005];

int idx[100005];

int cheapcur = 0;

long long serve(int id, int amount){
	int pos = idx[id];
	pair<int, pair<int,int> >ff = foods[pos];
	int cst = ff.first;
	int rem = ff.second.second;
	int typ = ff.second.first;
	if(rem>=amount){
		//cout<<"served food "<<typ<<" amount "<<amount<<" at cost "<<cst*amount<<"\n";
		foods[pos].second.second -= amount;
		return (long long)amount*(long long)cst;
	}
	else{
		long long init_cost = (long long)rem*(long long)cst;
		foods[pos].second.second = 0;
		amount-=rem;
		//cout<<"served food "<<typ<<" amount "<<rem<<" at cost "<<cst*rem<<"\n";
		while(true){
			if(amount<=0)return init_cost;
			if(cheapcur>=(int)foods.size())return 0;
			pair<int, pair<int,int> >ffcheap = foods[cheapcur];
			int cstcheap = ffcheap.first;
			int remcheap = ffcheap.second.second;
			int typcheap = ffcheap.second.first;
			if(remcheap>=amount){
				//cout<<"served food "<<typcheap<<" amount "<<amount<<" at cost "<<cstcheap*amount<<"\n";
				foods[cheapcur].second.second -= amount;
				return (long long)amount*(long long)cstcheap+init_cost;
			}
			else{
				//cout<<"served food "<<typcheap<<" amount "<<remcheap<<" at cost "<<cstcheap*remcheap<<"\n";
				amount -= remcheap;
				init_cost += (long long)remcheap*(long long)cstcheap;
				foods[cheapcur].second.second = 0;
				cheapcur++;
			}
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n; ++i){
		scanf("%d",&foodremain[i]);
	}
	for(int i = 1;i<=n; ++i){
		scanf("%d",&foodcost[i]);
	}
	for(int i = 1; i<=n; ++i){
		pair<int, pair<int,int>  >curfood = make_pair(foodcost[i],make_pair(i,foodremain[i]));
		foods.push_back(curfood);
	}
	sort(foods.begin(),foods.end());
	for(int i = 0; i<(int)foods.size(); ++i){
		int id = foods[i].second.first;
		idx[id] = i;
	}
	long long s = 0;
	for(int i = 1; i<=m; ++i){
		int id,amount;
		//cout<<" customer "<<i<<"\n";
		scanf("%d %d",&id,&amount);
		long long cost = serve(id,amount);
		printf("%lld\n",cost);
	}
	//printf("%lld\n",s);
	return 0;
}