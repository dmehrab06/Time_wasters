#include <bits/stdc++.h>

using namespace std;

vector<int> p1;
vector<int> p2;

vector < vector<int> >all;

int score[2];

int main(){
	int n;
	cin>>n;

	vector<int>ln; all.push_back(ln); all.push_back(ln);
	for(int i =0; i<n;++i){
		int a;	cin>>a; p1.push_back(a);
	}
	for(int i =0; i<n;++i){
		int a;	cin>>a; p2.push_back(a);
	}
	
	sort(p1.begin(),p1.end()); reverse(p1.begin(),p1.end());
	sort(p2.begin(),p2.end()); reverse(p2.begin(),p2.end());
	//reverse(oka.begin(),oka.end());

	all[0] = p1; all[1] = p2;
	all[0].push_back(0);all[1].push_back(0);
	int l = 0;
	int r = 0;

	int aa = 0; int bb = 0;
	for(int i = 0;i<2*n;++i){
		int ascore = all[0][l];
		int bscore = all[1][r];
		//cout<<l<<" "<<r<<"\n";
		//cout<<ascore<<" "<<bscore<<"\n";
		if(i%2==0){
			if(ascore>=bscore){
				aa+=ascore;
				l++;		
			}
			else{
				r++;			
			}		
		}		
		
		else{
			if(bscore>=ascore){
				bb+=bscore;
				r++;			
			}
			else{
				l++;			
			}		
		}
		//cout<<aa<<" "<<bb<<"\n\n";
	}
	cout<<aa-bb<<"\n";
	return 0;
}
