/*-------property of the half blood prince-----*/
//dmehrab06
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
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

pair<PII,double>avg[200005];

int arr[200005];

ifstream fin("approximation.in");
ofstream fout("approximation.out");

int main(){
    int n;
    fin>>n;
    FREP(i,1,n){
        fin>>arr[i];
    }
    avg[0].ff.ff=0;
    avg[0].ff.ss=0;
    avg[0].ss=0.0;
    int avgcur=1;
    FREP(i,1,n){
        avg[avgcur].ff.ff=i;
        avg[avgcur].ff.ss=i;
        avg[avgcur].ss=(double)arr[i];
        while(avg[avgcur].ss<avg[avgcur-1].ss){
            double ltot=avg[avgcur-1].ss*(avg[avgcur-1].ff.ss-avg[avgcur-1].ff.ff+1);
            double rtot=avg[avgcur].ss*(avg[avgcur].ff.ss-avg[avgcur].ff.ff+1);
            double tot=ltot+rtot;
            double av=tot/(double)(avg[avgcur].ff.ss-avg[avgcur-1].ff.ff+1);
            avg[avgcur-1].ff.ss=avg[avgcur].ff.ss;
            avg[avgcur-1].ss=av;
            avgcur--;
        }
        avgcur++;
    }
    FREP(i,1,avgcur-1){
        int ll=avg[i].ff.ff;
        int rr=avg[i].ff.ss;
        FREP(k,ll,rr){
            fout<<setprecision(10)<<avg[i].ss<<" ";
        }
    }
    fout<<"\n";
    return 0;
}