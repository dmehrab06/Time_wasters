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
#define VD vector<double>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(int)(N);(i)++)
#define eps 0.0001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGEI(val,l,r) ((l)<=(val) && (val)<=(r))
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;

//-----------------------vector operations-----------------//
//---------------------------------------------------------//
//---------------------------------------------------------//

string hello;

vector<PII>zeros;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>hello;
        zeros.clear();
        int l=hello.size();
        for(int i=0;i<l;){
            if(hello[i]=='0'){
                int st = i;
                int ed = -1;
                for(int j=i;(j<l && hello[j]=='0');++j){
                    ed = j;
                }
                zeros.PB(make_pair(st,ed));
                i = ed+1;
            }
            else{
                i++;
            }
        }
        int zs=zeros.size();
        int cnt = 0;
        FREP(i,0,(zs-1)){
            int l1 = zeros[i].first-1;
            int l2 = zeros[i].second+1;
            if(l1>=0 && l2<l && hello[l1]=='1' && hello[l2]=='1'){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
