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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

string s="_";
string nw;
vector<PII>parenpairs;

int getmx(int l, int r){
    int cnt=0;
    int l1=0;
    for(int i=(l+1);i<r;){
        if(s[i]=='_'){
            if(l1>0){
                cnt++;
            }
            i++;
            l1=0;
        }
        else{
            l1++;
            i++;
        }
    }
    if(l1>0){
        cnt++;
    }
    return cnt;
}
int main(){
    int l;
    cin>>l>>nw;
    s+=nw;
    s.push_back('_');
    int sz=s.size();
    //outside
    int mx=-1;
    int l1=0;
    for(int i=0;i<sz;){
        if(s[i]=='_'){
            if(l1>mx){
                mx=l1;
            }
            i++;
            l1=0;
        }
        else if(s[i]=='('){
            int l=i;
            if(l1>mx){
                mx=l1;
            }
            l1=0;
            int r=i;
            while(s[i]!=')'){
                i++;
                r=i;
            }
            parenpairs.PB(make_pair(l,r));
            i++;
        }
        else{
            l1++;
            i++;
        }
    }
    sz=parenpairs.size();
    int mx1=0;
    FREP(i,0,(sz-1)){
        mx1+=getmx(parenpairs[i].first,parenpairs[i].second);
    }
    cout<<mx<<" "<<mx1<<"\n";
    return 0;
}
