#include <bits/stdc++.h>

using namespace std;

//int xpointsexist[200005];
struct edges{
    int u,v;
    edges(){
        u=0;
        v=0;
    }
    edges(int a,int b){
        u=a;
        v=b;
        if(u>v){
            swap(u,v);
        }
    }
};

bool mycompare(edges &a, edges &b){
    if(a.u==b.u)return a.v<b.v;
    return a.u<b.u;
}


typedef pair<int,int>EE;
set<EE>hello;
set<int>aria;
set<int>pari;
set<int>::iterator itaria1;
set<int>::iterator itaria2;
set<int>::iterator itpari1;
set<int>::iterator itpari2;
vector< vector < int > >alledges;

int vis[200005];
int gf=1;
void dfs(int cur, int par){
    int uu=cur;
    int vv=par;
    vis[cur]=1;
    itaria1=aria.find(uu);
    itaria2=aria.find(vv);
    itpari1=pari.find(uu);
    itpari2=pari.find(vv);
    int a1,a2,p1,p2;
    a1=(itaria1==aria.end()?0:1);
    a2=(itaria2==aria.end()?0:1);
    p1=(itpari1==pari.end()?0:1);
    p2=(itpari2==pari.end()?0:1);
    if((a1 && a2) || (p1 && p2)){
        gf=0;
        //break;
    }
    else{
        //duita ek e jon er tay nai
        if(a1){
            //then p1=0 //a2=0 karon par kore eschi
            if(!p2){
                pari.insert(vv);
            }
        }
        else if(a2){
            if(!p1){
                pari.insert(uu);
            }
        }
        else if(p1){
            if(!a2){
                aria.insert(vv);
            }
        }
        else if(p2){
            if(!a1){
                aria.insert(uu);
            }
        }
        else{
            aria.insert(uu);
            pari.insert(vv);
        }
    }
    int ll=alledges[cur].size();
    for(int i=0;i<ll;++i){
        int nxt=alledges[cur][i];
        int uu=cur;
        int vv=nxt;
        if(uu>vv){
            swap(uu,vv);
        }
        EE ee=make_pair(uu,vv);
        if(hello.find(ee)==hello.end()){
            hello.insert(ee);
            dfs(nxt,cur);
        }

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>line;
    for(int i=0;i<=(n+2);++i){
        alledges.push_back(line);
        vis[i]=0;
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        alledges[u].push_back(v);
        alledges[v].push_back(u);
    }
    //sort(alledges.begin(),alledges.end(),mycompare);
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            int deg=alledges[i].size();
            if(deg>0){
                dfs(i,0);
            }
        }
    }
    if(!gf){
        printf("-1\n");
    }
    else{
        int arisize=aria.size();
        itaria1=aria.begin();
        if(*itaria1==0){
            arisize--;
        }
        printf("%d\n",arisize);
        for(itaria1=aria.begin();itaria1!=aria.end();++itaria1){
            if(*itaria1!=0)printf("%d ",*itaria1);
        }
        printf("\n");
        int parisize=pari.size();
        itpari1=pari.begin();
        if(*itpari1==0){
            parisize--;
        }
        printf("%d\n",parisize);
        for(itpari1=pari.begin();itpari1!=pari.end();++itpari1){
            if(*itpari1!=0)printf("%d ",*itpari1);
        }
        printf("\n");
    }
    return 0;
}
