/*-------property of the half blood prince-----*/

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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

map<string,int>vis;
map<string,int>forbid;

string src;
string dst;

string fi,sc,th;

int bfs(string src,string dst){
    queue<string>hell;
    if(vis.find(src)==vis.end() && forbid.find(src)==forbid.end()){
        vis[src]=0;
        hell.push(src);
    }
    while(!hell.empty()){
        string tp=hell.front();
        hell.pop();
        int dd=vis[tp];
        if(tp==dst)return dd;
        FREP(i,0,2){
            for(int k=-1;k<=1;k+=2){
                string cur="";
                cur.PB(tp[0]);
                cur.PB(tp[1]);
                cur.PB(tp[2]);
                cur[i]=cur[i]+k;
                if(cur[i]<'a')cur[i]='z';
                if(cur[i]>'z')cur[i]='a';
                if(vis.find(cur)==vis.end() && forbid.find(cur)==forbid.end()){
                    vis[cur]=dd+1;
                    hell.push(cur);
                }
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        vis.clear();
        forbid.clear();
        cin>>src;
        cin>>dst;
        int n;
        cin>>n;
        FREP(i,1,n){
            cin>>fi>>sc>>th;
            int lf=fi.size();
            int ls=sc.size();
            int ts=th.size();
            FREP(j,0,(lf-1)){
                FREP(k,0,(ls-1)){
                    FREP(m,0,(ts-1)){
                        string cur="";
                        cur.PB(fi[j]);
                        cur.PB(sc[k]);
                        cur.PB(th[m]);
                        forbid[cur]=1;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++,bfs(src,dst));
    }
    return 0;
}
