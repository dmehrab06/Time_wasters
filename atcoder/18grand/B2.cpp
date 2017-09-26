/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

pair<PII,int> difpos[501];

int poscnt[501][501];
int firstpos[501];

int personpref[501][501];

vector<int>ans;

PII solve(int n, int m){
    int participant[501];
    memset(participant,0,sizeof(participant));
    FREP(i,1,n){
        int cursport = m+2;
        int curpos = m+2;
        FREP(j,0,ans.size()-1){
            if(personpref[i][ans[j]]<curpos){
                cursport = ans[j];
                curpos = personpref[i][ans[j]];
            }
        }
        participant[cursport]++;
    }
    int mxx = 0;
    int mxi = -1;
    FREP(i,1,m){
        if(participant[i]>mxx){
            mxx = participant[i];
            mxi  = i;
        }
    }
    return make_pair(mxx,mxi);
}

int realsolve(int n, int m){
    FREP(i,1,m)ans.PB(i);
    PII curans = solve(n,m);
    int minans = curans.first;
    while(ans.size()>1){
        int sp = curans.second;
        ans.erase(remove(ans.begin(),ans.end(),sp));
        curans = solve(n,m);
        minans = min(curans.first,minans);
    }
    return minans;
}

int main(){
    FREP(i,1,500){
        firstpos[i]=100000;
    }
    int n,m;
    cin>>n>>m;
    FREP(i,1,n){
        FREP(j,1,m){
            int s;
            cin>>s;
            poscnt[s][j]++;
            personpref[i][s]=j;
            firstpos[s]=min(firstpos[s],j);
        }
    }
    FREP(i,1,m){
        int diff = 0;
        FREP(j,1,m){
            if(poscnt[i][j]){
                diff++;
            }
        }
        difpos[i]=make_pair(make_pair(-diff,-firstpos[i]),i);
    }
    sort(difpos+1,difpos+1+m);
    cout<<realsolve(n,m)<<"\n";
    return 0;
}
