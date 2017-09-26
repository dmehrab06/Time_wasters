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

priority_queue< pair<int,int> > playah;

bool alleq(priority_queue< pair<int,int> > playah){
    priority_queue<PII>g=playah;
    int a = g.top().first;
    while(!g.empty()){
        if(a!=g.top().first)return false;
        g.pop();
    }
    return true;
}

vector <PII> plays;

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int rate;
        scanf("%d",&rate);
        playah.push(make_pair(rate,i));
    }
    while(true){
        if(alleq(playah)){
            break;
        }
        PII mx1 = playah.top();playah.pop();
        PII mx2 = playah.top();playah.pop();
        if(mx1.first>0)mx1.first--;if(mx2.first>0)mx2.first--;
        plays.PB(make_pair(mx1.second,mx2.second));
        playah.push(mx1); playah.push(mx2);
    }
    cout<<playah.top().first<<"\n";
    cout<<plays.size()<<"\n";
    FREP(i,0,plays.size()-1){
        PII nw = plays[i];
        int pl1 = nw.first; int pl2 = nw.second;
        FREP(k,1,n){
            if(k==pl1){
                cout<<"1";
            }
            else if(k==pl2){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        cout<<"\n";
    }
    return 0;
}
