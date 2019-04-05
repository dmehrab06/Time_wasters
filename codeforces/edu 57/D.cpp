#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

char s[100005];
int pref[100005];
int suff[100005];
int cost[100005];

void calcpref(int n){
	long long int h = 0;
	long long int ha = 0;
	long long int har = 0;
	long long int hard = 0;
	for(int i = 0; i<n; ++i){
		if(s[i]=='h'){
			h++;
			if(h>0)pref[i] = 1;
		}
		else if(s[i]=='a'){
			ha = ha+h;
			if(ha>0)pref[i] = 1;
		}
		else if(s[i]=='r'){
			har = har+ha;
			if(har>0)pref[i] = 1;
		}
		else if(s[i]=='d'){
			hard = hard + har;
			if(hard>0)pref[i] = 1;
		}
	}
}

void calcsuff(int n){
	long long int d = 0;
	long long int rd = 0;
	long long int ard = 0;
	long long int hard = 0;
	for(int i = (n-1); i>=0; --i){
		if(s[i]=='d'){
			d++;
			if(d>0)suff[i] = 1;
		}
		else if(s[i]=='r'){
			rd = rd+d;
			if(rd>0)suff[i] = 1;
		}
		else if(s[i]=='a'){
			ard = ard+rd;
			if(ard>0)suff[i] = 1;
		}
		else if(s[i]=='h'){
			hard = hard + ard;
			if(hard>0)suff[i] = 1;
		}
	}
}

long long calc_char_cost(int n, char c){
	long long tot = 0;
	for(int i = 0; i<n; ++i){
		if(s[i]==c && pref[i]==1 && suff[i]==1){
			tot = tot+cost[i];
		}
	}
	return tot;
}

int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i = 0; i<n; ++i){
		scanf("%d",&cost[i]);
	}
	calcpref(n);
	calcsuff(n);
	long long cost1 = calc_char_cost(n,'h');
	long long cost2 = calc_char_cost(n,'a');
	long long cost3 = calc_char_cost(n,'r');
	long long cost4 = calc_char_cost(n,'d');
	cout<<min(cost1,min(cost2,min(cost3,cost4)))<<"\n";
	return 0;
}