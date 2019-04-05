#include <bits/stdc++.h>
#define MDD2 1500450271
#define MDD1 1000000007  
#define PRM1 31
#define PRM2 29
#define MXLEN 100004
#define MXN 1003
#define MXPLEN 2003
using namespace std;

char s[MXLEN];

char patterns[MXN][MXPLEN];

long long int pwcalc[MXPLEN][2];

void pre(){
	pwcalc[0][0] = 1; pwcalc[0][1] = 1;
	for(int i = 1; i<MXPLEN; ++i){
		pwcalc[i][0] = pwcalc[i-1][0]*PRM1; pwcalc[i][0]%=MDD1;
		pwcalc[i][1] = pwcalc[i-1][1]*PRM2; pwcalc[i][1]%=MDD2;
	}
}

pair<long long int,long long int> calc_hash(int idx){
	int l = strlen(patterns[idx]);
	long long int h1 = 0, h2 = 0;
	for(int i = (l-1); i>=0; --i){
		int cc = (patterns[idx][i]-'0'+1);
		h1 = (h1*PRM1+cc)%MDD1;
		h2 = (h2*PRM2+cc)%MDD2;
	}
	return make_pair(h1,0);
}

bool hash_found(int n, int window_size, int h1, int h2){
	long long int pw1 = pwcalc[window_size-1][0];
	long long int pw2 = pwcalc[window_size-1][1];
	long long int ih1 = 0, ih2 = 0;
	for(int i = (n-1); i>(n-1-window_size);--i){
		ih1 = (ih1*PRM1 + (s[i]-'0'+1))%MDD1;
		ih2 = (ih2*PRM2 + (s[i]-'0'+1))%MDD2;
	}

	if(ih1==h1 && ih2==h2)return true;

	for(int i = (n-1-window_size); i>=0; --i){
		ih1 = (ih1-(s[i+window_size]-'0'+1)*pw1); while(ih1<0)ih1 = ih1+MDD1;
		ih2 = (ih2-(s[i+window_size]-'0'+1)*pw2); while(ih2<0)ih2 = ih2+MDD2;
		ih1 = (ih1*PRM1)%MDD1;
		ih2 = (ih2*PRM2)%MDD2;
		ih1 = (ih1 + (s[i]-'0'+1))%MDD1;
		ih2 = (ih2 + (s[i]-'0'+1))%MDD2;
		if(ih1==h1 && ih2==h2)return true;
	}
	return false;
}

int main(){
	pre();
	scanf("%s",s);
	int l = strlen(s);
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		scanf("%s",patterns[i]);
		int ll = strlen(patterns[i]);
		pair<int,int>pp = calc_hash(i);
		if(hash_found(l,ll,pp.first,pp.second)){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
	}
	return 0;
}