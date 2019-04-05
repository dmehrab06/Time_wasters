#include <bits/stdc++.h>

using namespace std;

int posdiagonal[703][405];
int posdiagsize[703];
int negdiagonal[703][405];
int negdiagsize[703];

int house[303][303];
int ans[703];
char hh[303];

void init(){
	memset(posdiagonal,0,sizeof(posdiagonal));
	memset(negdiagonal,0,sizeof(negdiagonal));
	memset(ans,0,sizeof(ans));
	memset(posdiagsize,0,sizeof(posdiagsize));
	memset(negdiagsize,0,sizeof(negdiagsize));
}

int posdiagquery(int r1, int c1, int r2, int c2, int n, int m){
	//r1, c1 is lower bound
	//r2, c2 is upper bound
	//cout<<"r1: "<<r1<<" c1: "<<c1<<" r2: "<<r2<<" c2: "<<c2<<"\n";
	int posdiagidx = (r1+c1); //or r2+c2 // whatever
	if(posdiagidx<0 || posdiagidx>(n+m+2))return 0;
	//cout<<posdiagidx<<"\n";
	int sz = posdiagsize[posdiagidx];
	/*for(int i = 0; i<=sz; ++i){
		cout<<i<<": "<<posdiagonal[posdiagidx][i]<<" ";
	}
	cout<<"\n";*/
	int st, ed;
	if(posdiagidx<n){
		st = max(0,c1);
		ed = min(sz,c2);
	}
	else{
		st = max(0,(n-1-r1));
		ed = min(sz,(n-1-r2));
	}
	//cout<<"adjusted st: "<<st<<" ed: "<<ed<<"\n";
	
	int ret;
	if(st>ed)ret =  0;
	else if(st==0)ret = posdiagonal[posdiagidx][ed];
	else ret =  posdiagonal[posdiagidx][ed]-posdiagonal[posdiagidx][st-1];

	//cout<<"returning "<<ret<<"\n";

	return ret;
}

int negdiagquery(int r1, int c1, int r2, int c2, int n, int m){
	//r1, c1 is lower bound
	//r2, c2 is upper bound
	int negdiagidx = (r1>=c1)?(r1-c1):(n-1+(c1-r1)); //or r2+c2 // whatever
	//cout<<"r1: "<<r1<<" c1: "<<c1<<" r2: "<<r2<<" c2: "<<c2<<"\n";
	if(negdiagidx<0 || negdiagidx>(n+m+2))return 0;
	int sz = negdiagsize[negdiagidx];
	//cout<<negdiagidx<<"\n";
	/*for(int i = 0; i<=sz; ++i){
		cout<<i<<": "<<negdiagonal[negdiagidx][i]<<" ";
	}
	cout<<"\n";*/
	int st,ed;
	if(negdiagidx<n){
		if(r1<c1)return 0;
		st = max(0,c1);
		ed = min(sz,c2);
	}
	else{
		if(r1>=c1)return 0;
		st = max(0,r1);
		ed = min(sz,r2);
		
	}
	int ret;
	//cout<<"adjusted st: "<<st<<" ed: "<<ed<<"\n";
	
	if(st>ed)ret = 0;
	else if(st==0)ret = negdiagonal[negdiagidx][ed];
		
	else ret = negdiagonal[negdiagidx][ed]-negdiagonal[negdiagidx][st-1];

	//cout<<"returning "<<ret<<"\n";

	return ret;
}

void formpositivediagonal(int n, int m){
	for(int r = 0; r<n; ++r){
		int ed = 0;
		for(int c = 0; (c<m && (r-c)>=0) ; ++c){
			posdiagonal[r][c] = house[r-c][c];
			//cout<<"traversing "<<r-c<<" "<<c<<"\n";
			ed = c;
		}
		//cout<<"pos diag no: "<<r<<" and size "<<ed<<"\n";
		//cout<<"\n";
		for(int i = 1; i<=ed; ++i) posdiagonal[r][i] += posdiagonal[r][i-1];
		posdiagsize[r] = ed;
	}
	//remaining poss from last row
	for(int c = 1; c<m; ++c){
		int ed = 0;
		for(int ii = c; (ii<m  && (n-1-ii+c)>=0); ++ii){
			posdiagonal[n-1+c][ii-c] = house[n-1-ii+c][ii];
			//cout<<"traversing "<<n-1-ii+c<<" "<<ii<<"\n";
			ed = ii-c;
		}
		//cout<<"pos diag no: "<<n-1+c<<" and size "<<ed<<"\n";
		//cout<<"\n";
		for(int i = 1; i<=ed; ++i) posdiagonal[n-1+c][i] += posdiagonal[n-1+c][i-1];
		posdiagsize[n-1+c] = ed;
	}
}

void formnegativediagonal(int n, int m){
	for(int r = 0; r<n; ++r){
		int ed = 0;
		for(int c = 0; (c<m && (r+c)<n); ++c){
			negdiagonal[r][c] = house[r+c][c];
			//cout<<"traversing "<<r+c<<" "<<c<<"\n";
			ed = c;
		}
		//cout<<"neg diag no: "<<r<<" and size "<<ed<<"\n";
		//cout<<"\n";
		for(int i = 1; i<=ed; ++i) negdiagonal[r][i] += negdiagonal[r][i-1];
		negdiagsize[r] = ed;
	}
	//remaining upper half negative diag
	for(int c = 1; c<m; ++c){
		int ed = 0;
		for(int ii = c; (ii<m && (ii-c)<n); ++ii){
			negdiagonal[n-1+c][ii-c] = house[ii-c][ii];
			//cout<<"traversing "<<ii-c<<" "<<ii<<"\n";
			ed = ii-c;
		}
		//cout<<"neg diag no: "<<n-1+c<<" and size "<<ed<<"\n";
		//cout<<"\n";
		for(int i = 1; i<=ed; ++i) negdiagonal[n-1+c][i] += negdiagonal[n-1+c][i-1];
		negdiagsize[n-1+c] = ed;
	}
}


int findneighbor(int x, int y, int n, int m, int d){
	int ly = y-d;
	int ux = x-d;

	int dx = x+d;
	int ry = y+d;

	int ans1 = posdiagquery(x,ly,ux,y,n,m);
	int ans2 = posdiagquery(dx,y,x,ry,n,m);

	int ans3 = negdiagquery(ux+1,y+1,x-1,ry-1,n,m);
	int ans4 = negdiagquery(x+1,ly+1,dx-1,y-1,n,m);

	return ans1+ans2+ans3+ans4;
}

void solve(int x, int y, int n, int m){
	//cout<<"for x: "<<x<<" y: "<<y<<"\n";
	for(int d = 1; d<=(n+m-2); ++d){
		//cout<<"searching at distance: "<<d<<"\n";
		ans[d] = ans[d] + findneighbor(x,y,n,m,d);
		//cout<<ans[d]<<"\n";
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 0; i<n; ++i){
			scanf("%s",hh);
			for(int j = 0; j<m; ++j)house[i][j] = hh[j] - '0';
		}
		//form the cumsum array in posdiag and negdiag
		//pos diagonal
		formpositivediagonal(n,m);
		//neg diagonal
		formnegativediagonal(n,m);

		/*cout<<"positive diag\n";
		for(int i = 0; i<(n+m); ++i){
			cout<<"diagonal "<<i<<"\n";
			for(int s = 0; s<=posdiagsize[i]; ++s){
				cout<<posdiagonal[i][s]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n\n";
		cout<<"negative diag\n";
		for(int i = 0; i<(n+m); ++i){
			cout<<"diagonal "<<i<<"\n";
			for(int s = 0; s<=negdiagsize[i]; ++s){
				cout<<negdiagonal[i][s]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n\n\n";*/

		for(int i = 0; i<n; ++i){
			for(int j = 0; j<m; ++j){
				if(house[i][j]==1){
					solve(i,j,n,m);
				}
			}
		}

		for(int d = 1; d<= (n+m-2); ++d){
			printf("%d ",ans[d]/2);
		}
		printf("\n");

	}
	return 0;
}