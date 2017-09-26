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


int myarr[100007];
map<int,int>ptocmprs;
map<int,int>cmprstop;

int binlow(int x, int n){ //find smallest element>=x
    int l=0;
    int h=(n+1);
    while(true){
        int m=(l+h)/2;
        if(myarr[m]>=x){
            if(m>0 && myarr[m-1]>=x){
                h=m;
            }
            else{
                return m;
            }
        }
        else{
            l=m+1;
        }
    }
}

int binhigh(int x, int n){ //find largest element<=x
    int l=0;
    int h=(n+1);
    while(true){
        int m=(l+h)/2;
        if(myarr[m]<=x){
            if(m<=n && myarr[m+1]<=x){
                l=m+1;
            }
            else{
                return m;
            }
        }
        else{
            h=m;
        }
    }
}

int freq[100008];

ifstream fin("haybales.in");
ofstream fout("haybales.out");

int main(){
    int n,q;
    fin>>n>>q;
    int st=1;
    FREP(i,1,n){
        fin>>myarr[i];
    }
    myarr[0]=-2;
    myarr[n+1]=1000000009;
    ptocmprs[-2]=0;
    cmprstop[0]=-2;
    sort(myarr+1,myarr+1+n);
    set<int>tmp;
    FREP(i,1,n){
        tmp.insert(myarr[i]);
    }
    SI::iterator it;
    for(it=tmp.begin();it!=tmp.end();++it){
        ptocmprs[*it]=st;
        cmprstop[st++]=*it;
    }
    ptocmprs[1000000009]=st;
    cmprstop[st]=1000000009;
    FREP(i,1,n){
        freq[ptocmprs[myarr[i]]]++;
    }
    freq[0]=0;
    FREP(i,1,n){
        freq[i]=freq[i-1]+freq[i];
    }
    FREP(i,1,q){
        int l,r;
        fin>>l>>r;
        int lidx=binlow(l,n);
        int ridx=binhigh(r,n);
        int lnum=myarr[lidx];
        int rnum=myarr[ridx];
        if(rnum<lnum){
            fout<<"0\n";
        }
        else{
            int lcmp=ptocmprs[lnum];
            int rcmp=ptocmprs[rnum];
            int ans=freq[rcmp]-freq[lcmp-1];
            fout<<ans<<"\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}

