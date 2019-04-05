#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	while(1){
		int node;
		printf("Enter node number: ");
		scanf("%d",&node);
		long long int *bintree;
		bintree=new long long int[node+1];
		bintree[0]=1;
		bintree[1]=1;
		for(int n=2;n<=node;++n){
			long long int sum=0;
			for(int k=1;k<=n;++k){
				int left=k-1;
				int right=n-k;
				sum+=(bintree[left]*bintree[right]);
			}
			bintree[n]=sum;
		}
		printf("possible number of binary trees: %lld\n",bintree[node]);
		delete[] bintree;
		
	}
}