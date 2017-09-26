#include <bits/stdc++.h>
using namespace std;

vector< vector <int> >edges;

int vis[100005];

int bfs(int n, int start){
    for(int i=1;i<=(2*n+6);++i){
        vis[i]=0;
    }
    queue<int>bfsqueue;
    bfsqueue.push(start);
    vis[start]=1;
    int found=0;
    while(!bfsqueue.empty()){
        int a=bfsqueue.front();
        found++;
        bfsqueue.pop();
        int deg=edges[a].size();
        for(int i=0;i<deg;++i){
            int cur=edges[a][i];
            if(!vis[cur]){
                bfsqueue.push(edges[a][i]);
                vis[edges[a][i]]=1;
            }
        }
    }
    return found;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int>line;
        for(int i=0;i<=2*(n+3);++i){
            edges.push_back(line);
        }
        int frndno=1;
        map<string , int>frndmap;
        for(int i=1;i<=n;++i){
            string u,v;
            cin>>u>>v;
            int unumber,vnumber;
            if(frndmap.find(u)!=frndmap.end()){
                unumber=frndmap[u];
            }
            else{
                unumber=frndno;
                frndno++;
                frndmap[u]=unumber;
            }
            if(frndmap.find(v)!=frndmap.end()){
                vnumber=frndmap[v];
            }
            else{
                vnumber=frndno;
                frndno++;
                frndmap[v]=vnumber;
            }
            edges[unumber].push_back(vnumber);
            edges[vnumber].push_back(unumber);
        }
        string start;
        cin>>start;
        int stnum=frndmap[start];
        int tot=bfs(n,stnum);
        printf("Case %d: %d\n",cs++,tot);
        edges.clear();
    }
    return 0;
}
