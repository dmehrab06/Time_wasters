#include <bits/stdc++.h>

using namespace std;

int twopow[32];

void gen(){
	twopow[0] = 1;
	for(int i = 1; i<=30; ++i){
		twopow[i] = twopow[i-1]*2;
		//cout<<twopow[i]<<"\n";
	}

}

vector<int>twopows;

void gettwo(int n){

	for(int i = 30; i>=0; i--){
		if(n>=twopow[i]){
			twopows.push_back(twopow[i]);
			n-=twopow[i];
		}
	}

}

int main(){
	gen();
	int n,k;
	cin>>n>>k;
	gettwo(n);
	int minl = (int)twopows.size();
	int maxl = n;
	if(k>=minl && k<=maxl){
		cout<<"YES\n";
		int ase = minl;
		int need = k;
		int extra = need-ase;
		for(int i = 0; i<(int)twopows.size();++i){
			//cout<<"at i: "<<i<<" val: "<<twopows[i]<<"\n";
			int curval = twopows[i];
			if((curval-1)<=extra){
				for(int j = 0; j<curval; ++j){
					cout<<"1 \n";
				}
				extra-=(curval-1);
			}
			else if(extra>0){
				int temp = curval;
				while(true){
					if((temp-1)<=extra){
						for(int j = 0; j<temp; ++j){
							cout<<"1 \n";
						}
						extra-=(temp-1);
						break;
					}
					else{
						temp = temp/2;
						cout<<temp<<" \n";
						extra = extra - 1;
						if(extra==0){
							cout<<temp<<" \n";
							break;
						}
					}

				}
			}
			else{
				cout<<twopows[i]<<" \n";
			}
		}
		cout<<"\n";
	}
	else{
		cout<<"NO\n";
	}
}