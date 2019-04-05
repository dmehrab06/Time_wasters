#include <bits/stdc++.h>
#define MAXN 2600000
using namespace std;
 
int getval(char c){
    if(c=='A')return 0;
    else if(c=='C')return 1;
    else if(c=='G')return 2;
    else if(c=='T')return 3;
    else return -1;
}
 
int trie[MAXN][4];
int endmark[MAXN];
int cnt[MAXN];
int used = 0;
 
void init(){
    memset(trie,-1,sizeof(trie));
    used = 0;
    memset(endmark,0,sizeof(endmark));
}
 
void buildtrie(string &s){
    int cur = 0;
    for(int i = 0; i<(int)s.size(); ++i){
        char cc = s[i];
        int v = getval(cc);
        if(trie[cur][v]==-1){
            trie[cur][v] = ++used;
        }
        cur = trie[cur][v];
    }
    endmark[cur] = endmark[cur]+1;
}
 
void setcnt(int cur){
    cnt[cur] = endmark[cur];
    for(int i = 0; i<4; ++i){
        int nxt = trie[cur][i];
        if(nxt!=-1){
            setcnt(nxt);
            cnt[cur] = cnt[cur]+cnt[nxt];
        }
    }
}
 
int getmx(int cur, int d){
    int curmx = d*cnt[cur];
    for(int i = 0; i<4; ++i){
        int nxt = trie[cur][i];
        if(nxt!=-1){
            curmx = max(curmx,getmx(nxt,d+1));
        }
    }
    return curmx;
}
 
int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int n;
        scanf("%d",&n);
        init();
        for(int i = 1; i<=n; ++i){
            string s;
            cin>>s;
            buildtrie(s);
        }
        setcnt(0);
        for(int c = 0; c<used; ++c){
            cout<<cnt[c]<<"\n";
        }
        printf("Case %d: %d\n",cs,getmx(0,0));
    }
    return 0;
}