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

char p[MXLEN];

long long int pwcalc[MXLEN][2];

void pre(){
	pwcalc[0][0] = 1; pwcalc[0][1] = 1;
	for(int i = 1; i<MXLEN; ++i){
		pwcalc[i][0] = pwcalc[i-1][0]*PRM1; pwcalc[i][0]%=MDD1;
		pwcalc[i][1] = pwcalc[i-1][1]*PRM2; pwcalc[i][1]%=MDD2;
	}
}

pair<long long int,long long int> calc_hash(){
	int l = strlen(p);
	long long int h1 = 0, h2 = 0;
	for(int i = (l-1); i>=0; --i){
		int cc = (p[i]-'0'+1);
		h1 = (h1*PRM1+cc)%MDD1;
		h2 = (h2*PRM2+cc)%MDD2;
	}
	return make_pair(h1,h2);
}

void hash_found(int n, int window_size, int h1, int h2){
	long long int pw1 = pwcalc[window_size-1][0];
	long long int pw2 = pwcalc[window_size-1][1];
	long long int ih1 = 0, ih2 = 0;
	for(int i = (n-1); i>(n-1-window_size);--i){
		ih1 = (ih1*PRM1 + (s[i]-'0'+1))%MDD1;
		ih2 = (ih2*PRM2 + (s[i]-'0'+1))%MDD2;
	}

	vector<int>pos;

	if(ih1==h1 && ih2==h2)pos.push_back(n-window_size);

	for(int i = (n-1-window_size); i>=0; --i){
		//cout<<"at i: "<<i<<"\n";
		ih1 = (ih1-(s[i+window_size]-'0'+1)*pw1); while(ih1<0)ih1 = ih1+MDD1;
		ih2 = (ih2-(s[i+window_size]-'0'+1)*pw2); while(ih2<0)ih2 = ih2+MDD2;
		ih1 = (ih1*PRM1)%MDD1;
		ih2 = (ih2*PRM2)%MDD2;
		ih1 = (ih1 + (s[i]-'0'+1))%MDD1;
		ih2 = (ih2 + (s[i]-'0'+1))%MDD2;
		if(ih1==h1 && ih2==h2)pos.push_back(i);
	}
	sort(pos.begin(),pos.end());
	for(int i = 0; i<(int)pos.size(); ++i){
		printf("%d\n",pos[i]);
	}
}

int main(){
	pre();
	int nl;
	int c = 0;
	while(scanf("%d",&nl)==1){
		scanf("%s",p);
		pair<int,int>pp = calc_hash();
		//cout<<"ho\n";
		scanf("%s",s);
		int l = strlen(s);
		if(c>0){
			printf("\n");
		}
		hash_found(l,nl,pp.first,pp.second);
		c++;
	}
	return 0;
}