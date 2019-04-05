#include <bits/stdc++.h>
#define MAXN 200
#define MAXK 1000000000
#define MXVAL 2000
using namespace std;

int main(){
	srand(time(0));
	ofstream fout("in.txt");
	fout<<5<<"\n";
	for(int tc = 1; tc<=5; ++tc){
		int n = MAXN;
		int k = rand()%MAXK+1;
		fout<<n<<" "<<k<<"\n";
		for(int i = 1; i<=n; ++i){
			fout<<rand()%MXVAL+1<<" ";
		}
		fout<<"\n";
	}
	fout.close();
}