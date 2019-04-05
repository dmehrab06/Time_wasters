#include <iostream>
#include <fstream>
#include <cstdio> 
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace  std;

int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int t;
	int tt=1;
	int *allvalues;
	int *coinvalues;
 	//scanf("%d",&t);
 	fin>>t;
	while(t--){
		int C,V,D;
		//scanf("%d %d %d",&C,&D,&V);
		fin>>C>>D>>V;
		allvalues=new int[V+1];
		allvalues[0]=1;
		for(int i=1;i<=V;++i){
			allvalues[i]=0;
		}
		coinvalues=new int[D+1];
		for(int i=1;i<=D;++i){
			fin>>coinvalues[i];
		}
		for(int i=1;i<=D;++i){
			int a=coinvalues[i];
			for(int j=1;j<=C;++j){
				for(int k=V;k>=1;--k){
					if((k-a)>=0){
						int p= allvalues[k];
						int q=allvalues[k-a];
						if(q==1 && p==0){
							allvalues[k]=1;
						}
					}
				}
			}
		}
		int i=1;
		int extra=0;
		while(i<=V){
			if(allvalues[i]==0){
				extra++;
				for(int j=1;j<=C;++j){
					for(int k=V;k>=1;--k){
						if((k-i)>=0){
							int p= allvalues[k];
							int q=allvalues[k-i];
							if(q==1 && p==0){
								allvalues[k]=1;
							}
						}
					}
				}
			}
			i++;
		}
		fout<<"Case #"<<tt<<": "<<extra<<"\n";
		tt++;
		delete[] allvalues;
		delete[] coinvalues;
	}
	fin.close();
	fout.close();
	return 0;
}