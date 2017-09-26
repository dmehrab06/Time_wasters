#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005

int subtreesize[MAXN];
int centroids[MAXN];
int par[MAXN];
vector< vector<int> >graph;
/* method to add edge between to nodes of the undirected tree */
void dfs(int node){
    int cur=1;
    int deg=graph[node].size();
    for(int i=0;i<deg;++i){
        int child=graph[node][i];
        dfs(child);  //sob gula subtree er size ber korlam
        cur+=subtreesize[child];
    }
    subtreesize[node]=cur;
}

void calc(int node){
    //leaf gular centroid o nijei
    centroids[node]=node; //prothome ok nijekei dhore nilam, erpor aste aste nicher child er gula ke dekhbo
    int deg=graph[node].size();
    for(int i=0;i<deg;++i){
        int child=graph[node][i];
        calc(child);
        if(subtreesize[child]*2>subtreesize[node]){ //taile ei child or centroid hoite pare
        //child er subtree size jodi 1/2 er kom hoy taile eida katar por upore 1/2 er besi pore jabe
            centroids[node]=centroids[child];
            //erpor o uporer part e 1/2 er besi node pore jete pare //seita prevent korte hobe
            while(1){
                int y=subtreesize[node]-subtreesize[centroids[node]];
                if(y*2>subtreesize[node]){
                    centroids[node]=centroids[par[node]]; //arektu upore gelam jate uporer subtree er depth arektu kome
                    if(centroids[node]==node){
                        break; //er upore ar jawa jabe na
                    }
                }
                else{
                    break;
                }
            }
        }
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    vector<int>line;
    for(int i=0;i<=(n+2);++i){
        graph.push_back(line);
    }
    for(int i=2;i<=n;++i){
        int a;
        scanf("%d",&a);
        graph[a].push_back(i);
        par[i]=a;
    }
    dfs(1);
    calc(1);
    for(int i=1;i<=q;++i){
        int a;
        scanf("%d",&a);
        printf("%d\n",centroids[a]);
    }
    return 0;
}
