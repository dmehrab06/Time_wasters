#include <bits/stdc++.h>
using namespace std;

char a[26];
char food[2003];

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    memset(a,0,sizeof(a));
	    int n;
	    scanf("%d",&n);
	    for(int i = 1; i<=n; ++i){
	        scanf("%s",food);
	        int l = strlen(food);
	        char tempa[26];
	        memset(tempa,0,sizeof(tempa));
	        for(int j = 0; j<l; ++j){
	            tempa[food[j]-'a'] = 1;
	        }
	        for(int j = 0; j<26; ++j){
	            if(tempa[j]==1){
	                a[j] += 1;
	            }
	        }
	    }
	    int cnt = 0;
	    for(int i = 0; i<26; ++i){
	        if(a[i]==n){
	            cnt++;
	        }
	    }
	    printf("%d\n",cnt);
	}
	return 0;
}
