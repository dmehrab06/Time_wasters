/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector< vector<int> >topog;
int indeg[100005];
int vproc[100005];


vector<int>topo_order;

int vidx[100005];

vector< pair< int, pair<int, pair< int,int > > > >alledge;

void setidx(int n){
    for(int i = 0; i<n; ++i){
        int v = topo_order[i];
        vidx[v] = i;
    }
}

bool toposort(int n, int mid){
    //cout<<"toposort shuru\n";
    topog.clear();
    topo_order.clear();
    memset(indeg,0,sizeof(indeg));
    memset(vproc,0,sizeof(vproc));
    
    for(int i = 0; i< n+3; ++i){
        vector<int>line;
        topog.push_back(line);
    }
    
    for(int i = mid+1; i<(int)alledge.size();++i){
        pair< int, pair<int, pair< int,int > > >pp = alledge[i];
        int u = pp.second.second.first;
        int v = pp.second.second.second;
        topog[u].push_back(v);
        indeg[v]++;
    }
    
    set< pair<int,int> >degset;
    
    for(int i = 1; i<=n; ++i){
        pair<int,int>halo = make_pair(indeg[i],i);
        degset.insert(halo);
    }
    
    int vprocessed = 0;
    while(vprocessed<n){
        pair<int,int>cur = *(degset.begin());
        degset.erase(cur);
        int deg = cur.first;
        int v = cur.second;
        if(vproc[v]){
            continue;
        }
        if(deg!=0)return false;
        vproc[v] = 1;
        vprocessed++;
        topo_order.push_back(v);
        for(int vv: topog[v]){
            indeg[vv]--;
            pair<int,int>halo = make_pair(indeg[vv],vv);
            degset.insert(halo);
        }
    }
    //cout<<"toposort sesh\n";
    return true;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i<=m; ++i){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        pair< int, pair<int, pair< int,int > > > pp = make_pair(w,make_pair(i,make_pair(u,v)));
        alledge.push_back(pp);
    }
    sort(alledge.begin(),alledge.end());
    if(toposort(n,-1)){
        printf("0 0\n");
        return 0;
    }
    int lo = 0;
    int hi = (int)alledge.size()-1;
    while(lo+1<hi){
        int mid = lo+(hi-lo)/2;
        if(toposort(n,mid)){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    int val = -1, upto = -1;
    if(toposort(n,lo)){
        val = alledge[lo].first;
        upto = lo;
    }
    else{
        toposort(n,hi);
        val = alledge[hi].first;
        upto = hi;
    }
    setidx(n);
    vector<int>torev;
    for(int i = 0; i<=upto; ++i){
        pair< int, pair<int, pair< int,int > > >pp = alledge[i];
        int u = pp.second.second.first;
        int v = pp.second.second.second;
        int id = pp.second.first;
        int ordu = vidx[u];
        int ordv = vidx[v];
        if(ordu>ordv){
            torev.push_back(id);
        }
    }
    printf("%d %d\n",val,(int)torev.size());
    for(int a: torev){
        printf("%d ",a);
    }
    printf("\n");
}