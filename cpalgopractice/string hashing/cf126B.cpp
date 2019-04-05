#include <bits/stdc++.h>
#define MDD2 1000000007
#define MDD1 1000000007  
#define PRM1 2
#define PRM2 2
#define MXLEN 1000004
using namespace std;

long long int prefix_hash[MXLEN][2];
long long int suffix_hash[MXLEN][2];
char s[MXLEN];

void calc_prefix_hash(int n){
	long long int b1 = 1, b2 = 1;
	for(int i = 0; i<n; ++i){
		long long int cc1 = (s[i]-'a'+1)*b1;
		long long int cc2 = (s[i]-'a'+1)*b2;
		if(i>0){
			prefix_hash[i][0] = (cc1 + prefix_hash[i-1][0])%MDD1;
			prefix_hash[i][1] = (cc2 + prefix_hash[i-1][1])%MDD2;
		}
		else{
			prefix_hash[i][0] = cc1 % MDD1;
			prefix_hash[i][1] = cc2 % MDD2;
		}
		b1 = (b1*PRM1)%MDD1;
		b2 = (b2*PRM2)%MDD2;
	}
	//cout<<"prefix hoise\n";
}

void calc_suffix_hash(int n){
	for(int i = (n-1); i>=0; --i){
		int cc = (s[i]-'a'+1);
		if(i<(n-1)){
			suffix_hash[i][0] = (suffix_hash[i+1][0]*PRM1+cc)%MDD1;
			suffix_hash[i][1] = (suffix_hash[i+1][1]*PRM2+cc)%MDD2;
		}
		else{
			suffix_hash[i][0] = cc;
			suffix_hash[i][1] = cc;
		}
	}
}

bool hash_found(int n, int window_size, int h1, int h2){
	long long int pw1 = 1, pw2 = 1;
	for(int i = 1; i<window_size; ++i){
		pw1 = pw1*PRM1; pw1%=MDD1;
		pw2 = pw2*PRM2; pw2%=MDD2;
	}
	long long int ih1 = 0, ih2 = 0;
	for(int i = (n-1); i>(n-1-window_size);--i){
		ih1 = (ih1*PRM1 + (s[i]-'a'+1))%MDD1;
		ih2 = (ih2*PRM2 + (s[i]-'a'+1))%MDD2;
	}

	for(int i = (n-1-window_size); i>0; --i){
		ih1 = (ih1-(s[i+window_size]-'a'+1)*pw1); while(ih1<0)ih1 = ih1+MDD1;
		ih2 = (ih2-(s[i+window_size]-'a'+1)*pw2); while(ih2<0)ih2 = ih2+MDD2;
		ih1 = (ih1*PRM1)%MDD1;
		ih2 = (ih2*PRM2)%MDD2;
		ih1 = (ih1 + (s[i]-'a'+1))%MDD1;
		ih2 = (ih2 + (s[i]-'a'+1))%MDD2;
		if(ih1==h1 && ih2==h2){
			return true;
		}
	}
	return false;
}

vector<int>possible;

int main(){
	scanf("%s",s);
	int l = strlen(s);
	calc_prefix_hash(l);
	calc_suffix_hash(l);
	for(int i = 0; i<l; ++i){
		int ph1 = prefix_hash[i][0]; int ph2 = prefix_hash[i][1];
		int sh1 = suffix_hash[l-i-1][0]; int sh2 = suffix_hash[l-i-1][1];
		if(ph1==sh1 && ph2==sh2){
			possible.push_back(i);
		}
	}
	if((int)possible.size()==0){
		printf("Just a legend\n");
	}
	else{
		int lo = 0;
		int hi = (int)possible.size()-1;
		/*for(int i = 0; i<hi;++i){
			cout<<possible[i]<<"\n";
		}*/
		while((lo+1)<hi){
			int mid = lo+(hi-lo)/2;
			int cur = possible[mid];
			int h1 = prefix_hash[cur][0];
			int h2 = prefix_hash[cur][1];
			if(hash_found(l,cur+1,h1,h2)){
				lo = mid;
			}
			else{
				hi = mid;
			}
			//cout<<lo<<" "<<hi<<"\n";
		}
		int curlo = possible[lo];
		int curhi = possible[hi];
		if(hash_found(l,curhi+1,prefix_hash[curhi][0],prefix_hash[curhi][1])){
			for(int i = 0; i<=curhi; ++i){
				printf("%c",s[i]);
			}
			printf("\n");
		}
		else if(hash_found(l,curlo+1,prefix_hash[curlo][0],prefix_hash[curlo][1])){
			for(int i = 0; i<=curlo; ++i){
				printf("%c",s[i]);
			}
			printf("\n");
		}
		else{
			printf("Just a legend\n");
		}
	}
		
	return 0;
}