#include <bits/stdc++.h>

using namespace std;

int has[103];
int need_dump[103];

vector< vector<int> >station_after;
vector< vector<int> >station_before;
vector<int>after_processed;
vector<int>before_processed;

void takeinp(int n, int m){
	
	for(int i = 1; i<n+4; ++i){
		vector<int>line;
		station_before.push_back(line);
		station_after.push_back(line);
		after_processed.push_back(0);
		before_processed.push_back(0);
	}

	for(int i = 1; i<=m; ++i){
		int a,b;
		scanf("%d %d",&a,&b);
		has[a]++;
		need_dump[b]++;
		if(a>b){
			station_before[a].push_back(b);
		}
		else{
			station_after[a].push_back(b);	
		}
	}

	for(int i = 1; i<=n; ++i){
		sort(station_after[i].begin(),station_after[i].end());
		sort(station_before[i].begin(),station_before[i].end());
		reverse(station_after[i].begin(),station_after[i].end());
		reverse(station_before[i].begin(),station_before[i].end());	
	}
}

int simulate(int n, int cur, int m){
	int candie_dumped = 0;
	int cur_time = 0;
	int to_dump[103];
	for(int i = 1; i<=n; ++i){
		to_dump[i] = 0;
		after_processed[i] = 0;
		before_processed[i] = 0;
	}
	while(candie_dumped<m){
		if(before_processed[cur]<(int)station_before[cur].size() || after_processed[cur]<(int)station_after[cur].size()){
			int des;
			if(before_processed[cur]==(int)station_before[cur].size()){
				des = station_after[cur][after_processed[cur]];
				after_processed[cur]++;
			}
			else{
				des = station_before[cur][before_processed[cur]];
				before_processed[cur]++;	
			}
			to_dump[des]++;
		}
		if(to_dump[cur]>0){
			candie_dumped = candie_dumped+to_dump[cur];
			to_dump[cur] = 0;
		}
		if(candie_dumped==m)break;
		cur = cur+1;
		if(cur>n)cur = 1;
		cur_time = cur_time+1;
	}
	return cur_time;
}

int main(){
	int  n,m;
	scanf("%d %d",&n,&m);
	takeinp(n,m);
	for(int i = 1; i<=n; ++i){
		printf("%d ",simulate(n,i,m));
	}
	printf("\n");
	return 0;
}