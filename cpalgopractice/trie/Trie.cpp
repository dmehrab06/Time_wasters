#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int trie[MAXN][26];
int finish[MAXN];

int available = 1;

void add_String(string s){
	int cur = 0;
	for(char c: s){
		if(trie[cur][c-'a']==0){
			trie[cur][c-'a'] = available;
			available++;
		}
		cur = trie[cur][c-'a'];
	}
	finish[cur] = 1;
}

bool find_String(string s){
	int cur = 0;
	for(char c: s){
		if(trie[cur][c-'a']==0){
			return false;
		}
		cur = trie[cur][c-'a'];
	}
	return true;
}

int main(){
	vector<string>allword;
	allword.push_back("hello");
	allword.push_back("banana");
	allword.push_back("ban");
	allword.push_back("git");
	allword.push_back("helloworld");
	allword.push_back("github");
	for(string s: allword){
		add_String(s);
	}
	int n;
	cin>>n;
	for(int i = 0; i<n; ++i){
		string a;
		cin>>a;
		cout<<find_String(a)<<"\n";
	}
	return 0;
}