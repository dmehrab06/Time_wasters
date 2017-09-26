#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define LLI long long int
#define VLLI vector<long long int>
#define PB push_back
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

class SubrectanglesOfTable {
public:
	VLLI getQuantity(vector <string>);
};

VLLI SubrectanglesOfTable::getQuantity(vector <string> table) {
	LLI cnt[26];
	LLI g[203][203];
	char g2[203][203];
	vector< vector <string> >mat;
	vector<string>line;
	int ll=table.size();
	int sz=table[0].size();
	int ss=sz;
	FREP(i,0,(2*ll-1)){
		mat.PB(line);
		FREP(j,0,1){
			mat[i].PB(table[i%ll]);
		}
	}	
	//cout<<"hello\n";
	FREP(i,1,2*ll){
		FREP(j,0,1){
			FREP(k,0,(ss-1)){
				g2[i][k+j*ss+1]=mat[i-1][j][k];
			}
		}
	}
	int cc=1;
	RFREP(j,2*ss,1){
		g[2*ll][j]=cc;
		cc++;
	}
	int mul=2;
	RFREP(i,2*ll-1,1){
		FREP(j,1,2*ss){
			g[i][j]=g[2*ll][j]*mul;
		}
		mul++;
	}
	FREP(i,1,2*ll){
		FREP(j,1,2*ss){
			g[i][j]=g[i][j]*(i*j);
		}
	}	
	memset(cnt,0,sizeof(cnt));
	FREP(i,1,2*ll){
		FREP(j,1,2*ss){
			char curchar=g2[i][j];
			LLI goes=g[i][j];
			cnt[curchar-'A']+=goes;
		}
	}
	VLLI ans;
	FREP(i,0,25){
		ans.PB(cnt[i]);
	}
	return ans;
}


