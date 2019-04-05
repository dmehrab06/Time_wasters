#include <bits/stdc++.h>
using namespace std;

vector<int>occurence;

vector<int>makeoccurence;

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    occurence.clear();
	    makeoccurence.clear();
	    string s;
	    cin>>s;
	    char occ[26]; memset(occ,0,sizeof(occ));
	    for(int i = 0; i<(int)s.size(); ++i)occ[s[i]-'A']++;
	    for(int i = 0; i<26; ++i){
	    	if(occ[i]>0){
	    		occurence.push_back(occ[i]);
	    		makeoccurence.push_back(0);
	    	}
	    }
	    int len = (int)s.size(); int present_size = occurence.size();
	    int mnnchange = 20000000;
	    for(int div = 1; div<=26; ++div){
	    	if(len%div==0){
	    		int each = len/div;
	    		cout<<"testing with div: "<<div<<"\n";
	    		if(div<=present_size){
	    			cout<<"reduce letter\n";
	    			for(int j = 0; j<present_size; ++j){
	    				if(j<div){
	    					makeoccurence[j] = each;
	    				}
	    				else{
	    					makeoccurence[j] = 0;
	    				}
	    			}
	    			int tot_dif = 0;
	    			sort(occurence.begin(),occurence.end());
	    			reverse(occurence.begin(),occurence.end());
	    			for(int j = 0; j<present_size; ++j){
	    				cout<<"occ: "<<occurence[j]<<" make: "<<makeoccurence[j]<<"\n";
	    				tot_dif = tot_dif + abs(occurence[j]-makeoccurence[j]);
	    			}
	    			cout<<"tot_change: "<<tot_dif<<" need to make "<<tot_dif/2<<" changes\n";
	    			mnnchange = min(mnnchange,tot_dif/2);
	    		}
	    		else{
	    			cout<<"increase letter\n";
	    			int extra = div - (int)occurence.size();
	    			for(int i = 0; i<extra; ++i){
	    				occurence.push_back(0);
	    				makeoccurence.push_back(0);
	    			}
	    			for(int i = 0; i<(int)makeoccurence.size(); ++i){
	    				makeoccurence[i] = each;
	    			}
	    			int tot_dif = 0;
	    			//sort(occurence.begin(),occurence.end());
	    			//reverse(occurence.begin(),occurence.end());
	    			for(int j = 0; j<(int)occurence.size(); ++j){
	    				cout<<"occ: "<<occurence[j]<<" make: "<<makeoccurence[j]<<"\n";
	    				tot_dif = tot_dif + abs(occurence[j]-makeoccurence[j]);
	    			}
	    			cout<<"tot_change: "<<tot_dif<<" need to make "<<tot_dif/2<<" changes\n";
	    			mnnchange = min(mnnchange,tot_dif/2);	
	    		}
	    	}
	    }
	    printf("%d\n",mnnchange);
	}
	return 0;
}
