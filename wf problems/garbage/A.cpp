/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

map<string,int>btoint;
map<int,string>inttob;

map<string,int>gtoint;
map<int,string>inttog;

vector< set<PII> >bloodcomp(12);

int main(){
	btoint["A+"]=1;
	btoint["A-"]=2;
	btoint["B+"]=3;
	btoint["B-"]=4;
	btoint["O+"]=7;
	btoint["O-"]=8;
	map<string,int>::iterator it;
	for(it=btoint.begin();it!=btoint.end();++it){
		inttob[it->second]=it->first;
		gtoint[it->first]=it->second;
		inttog[it->second]=it->first;
	}
	gtoint["AB+"]=5;
	gtoint["AB-"]=6;
	inttog[6]="AB-";
	inttog[5]="AB+";
	FREP(i,1,8){
		if(i==5 || i==6) continue;
		FREP(j,1,8){
			if(j==5 || j==6)continue;
			else if(i==1){
				if((j==3 || j==4)){
					bloodcomp[gtoint["AB+"]].insert(make_pair(i,j));
				}
				else{
					bloodcomp[gtoint["A+"]].insert(make_pair(i,j));
				}
			}
			else if(i==2){
				if((j==3 || j==4)){
					if(j%2)bloodcomp[gtoint["AB+"]].insert(make_pair(i,j));
					else bloodcomp[gtoint["AB-"]].insert(make_pair(i,j));
				}
				else{
					if(j%2) bloodcomp[gtoint["A+"]].insert(make_pair(i,j));
					else bloodcomp[gtoint["A-"]].insert(make_pair(i,j));
				}	
			}
			else if(i==3){
				if((j==1 || j==2)){
					bloodcomp[gtoint["AB+"]].insert(make_pair(i,j));
					//else bloodcomp[gtoint["AB-"]].insert(make_pair(i,j));
				}
				else{
					bloodcomp[gtoint["B+"]].insert(make_pair(i,j));
					//else bloodcomp[gtoint["A-"]].insert(make_pair(i,j));
				}	
			}
			else if(i==4){
				if((j==1 || j==2)){
					if(j%2) bloodcomp[gtoint["AB+"]].insert(make_pair(i,j));
					else bloodcomp[gtoint["AB-"]].insert(make_pair(i,j));
				}
				else{
					if(j%2) bloodcomp[gtoint["B+"]].insert(make_pair(i,j));
					else bloodcomp[gtoint["B-"]].insert(make_pair(i,j));
				}	
			}
			else if(i==7){
				if(j==7 || j==8){
					bloodcomp[gtoint["O+"]].insert(make_pair(i,j));
				}
			}
			else if(i==8){
				if(j==8) bloodcomp[gtoint["O-"]].insert(make_pair(i,j));
				else if(j==7) bloodcomp[gtoint["O+"]].insert(make_pair(i,j));
			}
			
		}
	}
	FREP(i,1,8){
		//int l=bloodcomp[i].size()
		set<PII>rev;
		set<PII>::iterator it2;
		for(it2=bloodcomp[i].begin();it2!= bloodcomp[i].end();++it2){
			PII oka=*it2;
			swap(oka.first,oka.second);
			rev.insert(oka);
		}
		for(it2=rev.begin();it2!= rev.end();++it2){
			PII oka=*it2;
			//swap(oka.first,oka.second);
			bloodcomp[i].insert(oka);
		}
	}
	//ekta print dia dekhi;
	FREP(i,1,8){
		cout<<"printing for "<<inttog[i]<<"\n";
		set<PII>::iterator it2;
		for(it2=bloodcomp[i].begin(); it2!= bloodcomp[i].end();++it2){
			PII oka=*it2;
			cout<<"("<<inttob[oka.first]<<","<<inttob[oka.second]<<")\n";
		}
	}
	//thik ache child er jonno khujle ekhan theke
	return 0;
}