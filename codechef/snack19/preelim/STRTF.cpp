#include <bits/stdc++.h>
#define MXN 200003
#define MXLOG 20
using namespace std;

int arr[MXLOG][MXLOG][MXN];
//arr[0][0] te original array
//arr[0][i] te ibar chalanor por je array seta
//arr[k][i] te 

void init(int n){
	for(int i = 1; i<=n ; ++i)scanf("%d",&arr[0][0][i]);
	
	int kopa = 1;
	for(int i = 1; i<MXLOG; ++i){
		for(int j = 1; j<=n; ++j){
			arr[0][i][j] = arr[0][0][j] + ((j+kopa)<=n)?arr[0][0][j+kopa]:0;
		} 
		kopa = kopa<<1;
	}
	int kopa = 1;
	for(int i = 1; i<MXLOG; ++i){
		for(int j=(i-1); j<i; ++j){
			for(int k = 1; k<=n; ++k){

			}
		}
		kopa = kopa<<1;
	}
}

int main(){
	
	return 0;
}