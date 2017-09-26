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

struct seg{
    int l;
    int r;
    seg(int _l=0, int _r=0){
        l=_l;
        r=_r;
    }
    bool operator<(const seg &a){
        return r<a.l;
    }
    bool operator=(const seg &b){
        return (l<=b.l && b.r<=r);
    }
};

int main(){
    set<PII>someseg;
    someseg.insert(make_pair(1,3));
    someseg.insert(make_pair(8,11));
    someseg.insert(make_pair(5,7));
    set<PII>::iterator it;
    for(it=someseg.begin();it!=someseg.end();++it){
        PII nw=*it;
        cout<<nw.first<<" "<<nw.second<<"\n";
    }
    while(1){
        int get;
        cin>>get;
        PII gg=make_pair(get,get);
        it=someseg.lower_bound(gg);
        if(it!=someseg.end()){
            PII ok=*it;
            cout<<ok.first<<" "<<ok.second<<"\n";
        }
    }
    return 0;
}
