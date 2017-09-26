/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

map< pair < string,string > ,int >codefreq;
vector< pair < string,string > >codes;
ifstream fin("citystate.in");
ofstream fout("citystate.out");

int main(){
    int n;
    fin>>n;
    FREP(i,1,n){
        string f,s;
        fin>>f>>s;
        string ff="";
        ff.PB(f[0]);
        ff.PB(f[1]);
        pair<string,string>oka=make_pair(ff,s);
        codefreq[oka]++;
        codes.PB(oka);
    }
    LLI total=0;
    FREP(i,1,n){
        pair<string,string>nw=codes[i-1];
        pair<string,string>ulta=make_pair(nw.second,nw.first);
        int ase=codefreq[ulta];
        if(nw==ulta){
            ase=0;
        }
        total+=ase;
    }
    fout<<total/2<<"\n";
    fin.close();
    fout.close();
    return 0;
}

