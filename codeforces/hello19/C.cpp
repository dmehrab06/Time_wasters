#include <bits/stdc++.h>

using  namespace std;

int first[100005];
int second[100005];

char bracket[500005];

void process(int idx){
	int l = strlen(bracket);
	int s = 0;
	stack<int>bck;
	for(int i = 0; i<l; ++i){
		if(bracket[i]=='('){
			bck.push(1);
		}
		else{
			if((int)bck.size()==0){
				s++;
			}
			else{
				bck.pop();
			}
		}
	}
	int f = (int)bck.size();
	first[idx] = f;
	second[idx] = s;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		scanf("%s",bracket);
		process(i);
	}
	map<int,int>secondbalancemap;
	map<int,int>firstbalancemap;
	int balanced = 0;
	for(int i = 0; i<n; ++i){
		if(first[i]==0 && second[i]==0){
			balanced++;
		}
		else if(first[i]>0 && second[i]>0){
			//eder k pair korar upay nai
		}
		else if(first[i]>0 && second[i]==0){
			firstbalancemap[first[i]]++;
		}
		else if(first[i]==0 && second[i]>0){
			secondbalancemap[second[i]]++;
		}
	}
	map<int,int>::iterator it;
	int pair = 0;
	for(it = firstbalancemap.begin(); it!=firstbalancemap.end(); ++it){
		int imb = it->first; int ase = it->second;
		if(secondbalancemap.find(imb)!=secondbalancemap.end()){
			int ase2 = secondbalancemap[imb];
			pair = pair+min(ase,ase2);
		}
	}
	printf("%d\n",pair+balanced/2);
	return 0;
}