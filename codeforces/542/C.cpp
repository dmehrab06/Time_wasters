#include <bits/stdc++.h>

using namespace std;

int vis[53][53];

int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};

char grid[53][53];

vector< pair<int,int> >comp1;
vector< pair<int,int> >comp2;

void bfs_1(int n, int srcx, int srcy, int type){
	memset(vis,0,sizeof(vis));
	queue< pair<int,int> >bq;
	bq.push(make_pair(srcx,srcy));
	if(type==1){
		comp1.push_back(make_pair(srcx,srcy));
	}
	else{
		comp2.push_back(make_pair(srcx,srcy));	
	}
	vis[srcx][srcy] = 1;
	while(!bq.empty()){
		pair<int,int>tcell = bq.front();
		bq.pop();
		for(int i = 0; i<4; ++i){
			int nx = tcell.first+dirx[i];
			int ny = tcell.second+diry[i];
			if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0 && grid[nx][ny]=='0'){
				bq.push(make_pair(nx,ny));
				if(type==1){
					comp1.push_back(make_pair(nx,ny));
				}
				else{
					comp2.push_back(make_pair(nx,ny));	
				}
				vis[nx][ny] = 1;
			}
		}
	}
}

int solve(int n, int srcx, int srcy, int desx, int desy){
	bfs_1(n,srcx,srcy,1);
	bfs_1(n,desx,desy,2);
	int mnn = 1000000000;
	for(auto a: comp1){
		for(auto b: comp2){
			printf("%d %d with %d %d\n",a.first,a.second,b.first,b.second);
			int difx = a.first-b.first;
			int dify = a.second-b.second;
			int cost = difx*difx+dify*dify;
			mnn = min(mnn,cost);
		}
	}
	return mnn;
}

int main(){
	int n;
	scanf("%d",&n);
	int sx, sy, dx,dy;
	scanf("%d %d %d %d",&sx,&sy,&dx,&dy);
	for(int i = 0; i<n; ++i){
		scanf("%s",grid[i]);
	}
	int ans = solve(n,sx-1,sy-1,dx-1,dy-1);
	printf("%d\n",ans);
	return 0;
}