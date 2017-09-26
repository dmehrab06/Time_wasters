#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class LinearPolyominoCovering {
public:
	string findCovering(string);
};

string LinearPolyominoCovering::findCovering(string region) {
	region.push_back('.');
	int l=region.size();
	int st=-1;
	int fin=-1;
	for(int i=0;i<l;++i){
		if(region[i]=='.'){
			if(st!=-1){
				int curlen=fin-st+1;
				if(curlen%2){
					return "impossible";
				}
				else if(curlen==2){
					for(int k=st;k<=fin;++k){
						region[k]='B';
					}
				}
				else if(curlen%4==2){
					for(int k=st;k<=fin-2;++k){
						region[k]='A';
					}
					region[fin-1]='B';
					region[fin]='B';
				}
				else if(curlen%4==0){
					for(int k=st;k<=fin;++k){
						region[k]='A';
					}
				}
				st=-1;
				fin=-1;
			}
		}
		else{
			if(st==-1){
				st=i;
			}
			fin=i;
		}
	}
	string nw="";
	for(int i=0;i<l-1;++i){
		nw.push_back(region[i]);
	}
	return nw;
}


//Powered by [KawigiEdit] 2.0!
