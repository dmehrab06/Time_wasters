//ds--set
//algo--dfs

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
#define VS vector<string>
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

set<int>U;
set<int>V;
set<int>ans;
vector<VI>edges;
int visited[100005];
void dfs(int cur){
    visited[cur]=1;
    if(V.find(cur)!=V.end())ans.insert(cur);
    int d=edges[cur].size();
    FREP(i,0,d-1){
        int nxt=edges[cur][i];
        if(!visited[nxt])dfs(nxt);
    }
    return;

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans.clear();
        edges.clear();
        FREP(i,0,100004){
            visited[i]=0;
        }
        V.clear();
        U.clear();
        map<string,int>nodes;
        string name;
        string a,b;
        VS names;
        VS finans;
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        int tot=(u+v+w+w+5);
        VI line;
        FREP(i,1,tot){
            edges.PB(line);
        }
        int nd=1;
        FREP(i,1,u){
            cin>>name;
            if(nodes.find(name)==nodes.end()){
                nodes[name]=nd;
                names.PB(name);
                nd++;
            }
            U.insert(nodes[name]);
        }
        FREP(i,1,v){
            cin>>name;
            if(nodes.find(name)==nodes.end()){
                nodes[name]=nd;
                names.PB(name);
                nd++;
            }
            V.insert(nodes[name]);
        }
        set<int>::iterator it;
        for(it=V.begin();it!=V.end();++it){
            int a=*it;
            if(U.find(a)!=U.end()){
                ans.insert(a);
            }
        }
        FREP(i,1,w){
            cin>>a>>b;
            int u,v;
            if(nodes.find(a)==nodes.end()){
                nodes[a]=nd;
                names.PB(a);
                nd++;
            }
            if(nodes.find(b)==nodes.end()){
                nodes[b]=nd;
                names.PB(b);
                nd++;
            }
            u=nodes[a];
            v=nodes[b];
            edges[u].PB(v);
        }
        for(it=U.begin();it!=U.end();++it){
            int go=*it;
            if(!visited[go]){
                dfs(go);
            }
        }
        for(it=ans.begin();it!=ans.end();++it){
            int go=*it;
            finans.PB(names[go-1]);
        }
        sort(finans.begin(),finans.end());
        int l=finans.size();
        FREP(i,0,(l-1)){
            cout<<finans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
