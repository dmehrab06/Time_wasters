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
#define SZ(V) ((int)V.size())
using namespace std;
using namespace __gnu_pbds;

#define MXLOG 20
#define MAXN 100005

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int mxpeople = 20;

class peoplelist{
    public:
        set<int>pplidx;
        peoplelist(){

        }
        peoplelist(vector<int> &ppl){
            if(SZ(ppl)>0){
                FREP(i,0,SZ(ppl)-1){
                    pplidx.insert(-ppl[i]);
                }
            }
            rearrange();
        }
        void rearrange(){
            while(SZ(pplidx)>mxpeople){
                pplidx.erase(pplidx.begin());
            }
        }
        void push(int idx){
            pplidx.insert(-idx);
            rearrange();
        }
        peoplelist _merge(peoplelist &b){
            vector<int>av,bv;
            set<int>::iterator it;
            for(it = pplidx.begin(); it!=pplidx.end(); ++it){
                av.PB(-(*it));
            }
            for(it = b.pplidx.begin(); it!=b.pplidx.end(); ++it){
                bv.PB(-(*it));
            }
            int aidx = 0; int bidx = 0;
            SORTV(av); SORTV(bv);
            /*cout<<"nicher part e ache\n";
            if(av.size()>0){
                FREP(i,0,av.size()-1){
                    cout<<av[i]<<" ";
                }
            }
            cout<<"\n";*/
            /*cout<<"uporer part e ache\n";
            if(bv.size()>0){
                FREP(i,0,bv.size()-1){
                    cout<<bv[i]<<" ";
                }
            }
            cout<<"\n";*/
            peoplelist nw;
            //cout<<"merging two vectors of size "<<av.size()<<" and "<<bv.size()<<"\n";
            //cout<<"merge results\n";
            while(SZ(nw.pplidx)<mxpeople && (aidx<SZ(av) && bidx<SZ(bv)) ){
                //cout<<aidx<<" "<<bidx<<"\n";
                if((av[aidx]<bv[bidx])){
                    nw.push(av[aidx]);
                    //cout<<"pushing from nicher part "<<av[aidx]<<"\n";
                    aidx++;
                }
                else{
                    nw.push(bv[bidx]);
                    //cout<<"pushing from uporer part "<<bv[bidx]<<"\n";
                    bidx++;
                }
            }
            while(SZ(nw.pplidx)<mxpeople && aidx<SZ(av)){
                nw.push(av[aidx]);
                //cout<<"pushing from nicher part "<<av[aidx]<<"\n";
                aidx++;
            }
            while(SZ(nw.pplidx)<mxpeople && bidx<SZ(bv)){
                nw.push(bv[bidx]);
                //cout<<"pushing from uporer part "<<bv[bidx]<<"\n";
                bidx++;
            }
            //cout<<"merging two vectors of size "<<av.size()<<" and "<<bv.size()<<" done\n";
            return nw;
        }
        void print(int k){
            set<int>::iterator it;
            VI vv;
            for(it = pplidx.begin(); it!=pplidx.end(); ++it){
                vv.PB(-(*it));
            }
            SORTV(vv);
            int sz = min(k,SZ(vv));
            cout<<sz;
            //cout<<"people visited are :\n";
            if(sz>0){
                FREP(i,0,sz-1){
                    cout<<" "<<vv[i];
                }
            }//cout<<"hoise\n";
            cout<<"\n";
        }
        bool isempty(){
            return SZ(pplidx)==0;
        }
};

peoplelist topar[MXLOG][MAXN];
int par[MXLOG][MAXN];
int height[MAXN];

vector< VI > adj;
vector< VI > peoples;

void takeinp(int n, int m){
    adj.clear(); peoples.clear();
    memset(par,-1,sizeof(par));
    FREP(i,1,max(n+3,m+3)){
        VI line;
        adj.PB(line);
        peoples.PB(line);
    }
    FREP(i,1,(n-1)){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].PB(v); adj[v].PB(u);
    }
    FREP(i,1,m){
        int city;
        scanf("%d",&city);
        peoples[city].PB(i);
    }
}

void dfs(int cur, int pp = -1){
    //cout<<"at dfs for "<<cur<<"\n";
    if(pp+1){
        height[cur] = height[pp]+1;
    }
    par[0][cur] = cur;
    vector<int> myv = peoples[cur];
    peoplelist nn(myv);
    topar[0][cur] = nn;
    //cout<<"0th level e par bosaisi\n";
    par[1][cur] = pp;
    if(pp+1)topar[1][cur] = topar[0][cur]._merge(topar[0][pp]);
    //cout<<"1st level e par bosaisi\n";
    for(int i = 1; i<(MXLOG-1);++i){
        //cout<<"i: "<<i<<"\n";
        if((par[i][cur]+1) && (!topar[i][par[i][cur]].isempty())){
            par[i+1][cur] = par[i][par[i][cur]];
            topar[i+1][cur] = topar[i][cur]._merge(topar[i][par[i][cur]]);
        }
    }
    for(auto u: adj[cur]){
        if(u!=pp){
            dfs(u,cur);
        }
    }
}

void printpeople(int v){
    FREP(i,0,MXLOG-1){
        peoplelist his = topar[i][v];
        //cout<<"printing info for vertex "<<v<<" for travelling his parent at distance 2^"<<i-1<<"\n";
        his.print(10);
        //cout<<"level "<<i<<" done\n";
    }
}

peoplelist LCAmerge(int v,int u){
	if(height[v] < height[u])swap(v,u);

    //cout<<u<<","<<v<<"\n";

	peoplelist uset = topar[0][u];
	peoplelist vset = topar[0][v];

    //cout<<"vset now\n";
    //vset.print(10);
	RFREP(i,MXLOG-1,1){
        if((par[i][v]+1) && (height[par[i][v]]>=height[u])){
            vset = vset._merge(topar[i][v]);
            v = par[i][v];
            //cout<<"v now "<<v<<"\n";
            //cout<<"vset now\n";
            //vset.print(10);
        }
	}

	if(v == u) return vset._merge(uset);

	RFREP(i,MXLOG-1,1){
        if(par[i][v]-par[i][u]){
            vset = vset._merge(topar[i][v]); uset = uset._merge(topar[i][u]);
            v = par[i][v] ; u = par[i][u];
            //cout<<"v now "<<v<<"\n";
            //cout<<"vset now\n";
            //vset.print(10);
            //cout<<"u now "<<u<<"\n";
            //cout<<"uset now\n";
            //uset.print(10);
        }
	}
	vset = vset._merge(topar[1][v]); uset = uset._merge(topar[1][u]);
    return vset._merge(uset);
}

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    takeinp(n,m);
    dfs(1,-1);
    //cout<<"dfs done\n";

    //FREP(i,1,n)printpeople(i);


    FREP(i,1,q){
        int u,v,k;
        scanf("%d %d %d",&u,&v,&k);
        peoplelist ans = LCAmerge(v,u);
        ans.print(k);
    }
    return 0;
}
