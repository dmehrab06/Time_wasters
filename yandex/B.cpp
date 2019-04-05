#include <bits/stdc++.h>

using namespace std;

int mat[103][103];

vector< vector <int> >keys;

void insertrow(int pos, vector<int>myrow){
	int sz = myrow.size();
	for(int i = 0;i<sz;++i){
		mat[pos][i+1] = myrow[i];
	}
}

void makemat(){
	int tot = keys.size();
	std::vector<int> pivot = keys[0];
	int ase[10003]; memset(ase,0,sizeof(ase));
	for(int i = 0;i<(int)pivot.size();++i)ase[pivot[i]] = i+1;
	for(int i = 1; i<tot; ++i){
		vector<int>curv = keys[i];
		for(int j = 0; j<(int)curv.size(); ++j){
			if(ase[curv[j]]){
				int pos = ase[curv[j]];
				insertrow(pos,curv);
			}
		}	
	}
}

void print(int n){
	for(int i = 1;i<=n;++i){
		for(int j = 1; j<=n; ++j){
			printf("%d ",mat[i][j]);
		}
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int tot = 2*n;
	for(int i=1;i<=tot;++i){
		std::vector<int> v;
		for(int j = 1;j<=n;++j){
			int a;
			cin>>a;
			v.push_back(a);
		}
		keys.push_back(v);
	}
	makemat();
	print(n);
	return 0;
}