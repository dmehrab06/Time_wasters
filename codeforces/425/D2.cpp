
#include <bits/stdc++.h>
#define LLI long long int
#define REP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
using namespace std;

int par[100005][60]; // initially all -1
int h[100005];
int dis[100005];

vector< vector <int> > adj;

void init(int n){
    memset(par,-1,sizeof(par));
    adj.clear();
    REP(i,1,n+4){
        vector<int>ln;
        adj.push_back(ln);
    }
}

void takeinp(int n){
    REP(i,1,n-1){
        int u;
        scanf("%d",&u);
        adj[i+1].push_back(u);
        adj[u].push_back(i+1);
    }
}

void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1){
		h[v] = h[p] + 1;
		dis[v] = dis[p] + 1;
    }
    else{
        dis[v] = 0;
    }
	for(int i = 1;i < 60;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v])	if(p - u)
		dfs(u,v);
}

int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = 60 - 1;i >= 0;i --)
		if((par[v][i] + 1) && (h[par[v][i]] >= h[u])){
            v = par[v][i];
            //cout<<v<<"\n";
		}

	// now h[v] = h[u]
	//cout<<"bair hoisi\n";
	//cout<<v<<"\n";
	if(v == u)
		return v;
	for(int i = 60 - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
    //cout<<"bair hoisi2\n";
    //cout<<v<<"\n";
	return par[v][0];
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    init(n);
    takeinp(n);
    //cout<<"inp nisi\n";
    dfs(1);
    //cout<<"dfs sesh\n";
    REP(i,1,q){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int lca1 = LCA(a,b);//cout<<"lca1 "<<lca1<<"\n";
        int lca2 = LCA(b,c);//cout<<"lca2 "<<lca2<<"\n";
        int lca3 = LCA(c,a);//cout<<"lca3 "<<lca3<<"\n";
        pair<int, pair<int,int> >pp1 = make_pair(lca1,make_pair(a,b));
        pair<int, pair<int,int> >pp2 = make_pair(lca2,make_pair(b,c));
        pair<int, pair<int,int> >pp3 = make_pair(lca3,make_pair(c,a));
        if(lca1==lca2 && lca1==lca3){
            int d1 = dis[a]-dis[lca1];
            int d2 = dis[b]-dis[lca1];
            int d3 = dis[c]-dis[lca1];
            printf("%d\n",1+max(d1,max(d2,d3)));
        }
        else{
            if(pp1.first==pp2.first){
                //pp3 different
                if(pp1.first==b){
                    //ekta case
                    int d1 = dis[pp3.first]-dis[b];
                    int d2 = dis[a]-dis[pp3.first];
                    int d3 = dis[c]-dis[pp3.first];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
                else{
                    int lcc = LCA(b,pp3.first);
                    int d1 = (dis[pp3.first]-dis[lcc])+(dis[b]-dis[lcc]);
                    int d2 = dis[a]-dis[pp3.first];
                    int d3 = dis[c]-dis[pp3.first];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
            }
            else if(pp2.first == pp3.first){
                //pp1 different
                //ei case ta vabsi
                if(pp2.first==c){
                    //ekta case
                    int d1 = dis[pp1.first]-dis[c];
                    int d2 = dis[a]-dis[pp1.first];
                    int d3 = dis[b]-dis[pp1.first];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
                else{
                    int lcc = LCA(c,pp1.first);
                    int d1 = (dis[pp1.first]-dis[lcc])+(dis[c]-dis[lcc]);
                    int d2 = dis[a]-dis[pp1.first];
                    int d3 = dis[b]-dis[pp1.first];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
            }
            else{
                //pp2 different
                if(pp1.first==a){
                    //ekta case
                    int d1 = dis[pp2.first]-dis[a];
                    int d2 = dis[b]-dis[pp2.first];
                    int d3 = dis[c]-dis[pp2.first];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
                else{
                    int lcc = LCA(a,pp2.first);
                    int d1 = (dis[pp2.first]-dis[lcc])+(dis[a]-dis[lcc]);
                    int d2 = dis[b]-dis[pp2.first];
                    int d3 = dis[c]-dis[pp2.first];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
            }
        }
    }
    return 0;
}
