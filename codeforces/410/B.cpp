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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<string>all;
vector<string>all2;

string change(string s){
    int l=s.size();
    FREP(i,0,(l-2)){
        s.PB(s[i]);
    }
    return s;
}

bool match(string tomatch, int stringidx, int pos, int l){
    FREP(i,0,(l-1)){
        if(tomatch[i]!=all[stringidx][pos+i]){
            return false;
        }
    }
    return true;
}

int cst(int curidx, string tomatch){
    int l=all[curidx].size();
    int ll=tomatch.size();
    FREP(pos,0,(l-1)){
        if(match(tomatch,curidx,pos,ll)){
            return pos;
        }
    }
    return 10000000;
}

LLI getmincost(){
    int sz=all.size();
    LLI mnn=10000000000;
    FREP(i,0,sz-1){
        string tomatch=all2[i];
        LLI totcost=0;
        FREP(j,0,sz-1){
            totcost+=cst(j,tomatch);
        }
        mnn=min(totcost,mnn);
    }
    return mnn;
}

int main(){
    int n;
    cin>>n;
    FREP(i,1,n){
        string s;
        cin>>s;
        all2.PB(s);
        s=change(s);
        //cout<<s<<"\n";
        all.PB(s);
    }
    LLI ans=getmincost();
    if(ans>=10000000){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<"\n";
    }
    return 0;
}
