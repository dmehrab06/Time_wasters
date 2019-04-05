#include <bits/stdc++.h>

using namespace std;

string a,b;

int main(){
	int l;
	cin>>l>>a>>b;
	for(int i = 0;i<l;++i){
		if(a[i]!=b[i]){
			b[i] = '#';
		}
	}
	for(int i = 0;i<l-1;){
		if(b[i]=='#' && b[i+1]=='#'){
			if(a[i]!=a[i+1]){
				b[i] = '*'; b[i+1] = '*';
				i+=2;
			}
			else{
				i++;
			}
		}
		else{
			i++;
		}
	}
	int st = 0;
	int hs = 0;
	for(int i = 0;i<l;++i){
		if(b[i]=='*')st++;
		else if(b[i]=='#')hs++;
	}
	printf("%d\n",st/2+hs);
	return 0;
}