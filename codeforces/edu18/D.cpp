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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI leveljump[80];

map<LLI,LLI>par;

int main(){
    LLI n,q;
    cin>>n>>q;
    LLI root=(n+1)/2;
    LLI nxtjump=root/2;
    FREP(i,1,70){
        leveljump[i]=nxtjump;
        nxtjump/=2;
    }
    while(q--){
        par.clear();
        LLI start;
        cin>>start;
        int curlevel=1;
        LLI curnode=root;
        par[root]=root;
        while(curnode!=start){
            LLI tmp=curnode;
            if(start<curnode){
                curnode-=leveljump[curlevel];
                par[curnode]=tmp;
            }
            else{
                curnode+=leveljump[curlevel];
                par[curnode]=tmp;
            }
            curlevel++;
        }
        string oka;
        cin>>oka;
        int ll=oka.size();
        FREP(i,0,(ll-1)){
            if(oka[i]=='L'){
                LLI go=leveljump[curlevel];
                if(go>=1){
                    LLI tmp=curnode;
                    curnode-=go;
                    par[curnode]=tmp;
                    curlevel++;
                }
            }
            else if(oka[i]=='R'){
                LLI go=leveljump[curlevel];
                if(go>=1){
                    LLI tmp=curnode;
                    curnode+=go;
                    par[curnode]=tmp;
                    curlevel++;
                }
            }
            else if(oka[i]=='U'){
                if(curnode!=root){
                    curnode=par[curnode];
                    curlevel--;
                }
            }
        }
        cout<<curnode<<"\n";

    }
}
