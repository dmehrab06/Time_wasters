#include <bits/stdc++.h>
#define MAXN 2000000
#define MXBIT 5
using namespace std;
 

 
int trie[MAXN][2];
int used = 0;
 
void init(){
    memset(trie,-1,sizeof(trie));
    used = 0;
    //memset(endmark,0,sizeof(endmark));
}
 
void buildtrie(int val){
    int cur = 0; int mxmsk = 1<<(MXBIT-1);
    for(int i = 0; i<MXBIT; ++i){
        int v = mxmsk&val?1:0;
        if(trie[cur][v]==-1){
            trie[cur][v] = ++used;
        }
        cur = trie[cur][v];
        mxmsk = mxmsk>>1;
    }
}
 
int getmx(int val){
    int cur = 0; int mxmsk = 1<<(MXBIT-1); int make = 0;
    for(int i = 0; i<MXBIT; ++i){
        int v = mxmsk&val?1:0;
        if(trie[cur][1-v]!=-1){
            cur = trie[cur][1-v];
            make = (make<<1)|(1-v);
        }
        else{
            cur = trie[cur][v];
            make = (make<<1)|(v);
        }
        mxmsk = mxmsk>>1;
    }
    return make;
}

int getmn(int val){
    int cur = 0; int mxmsk = 1<<(MXBIT-1); int make = 0;
    for(int i = 0; i<MXBIT; ++i){
        int v = mxmsk&val?1:0;
        if(trie[cur][v]!=-1){
            cur = trie[cur][v];
            make = (make<<1)|v;
        }
        else{
            cur = trie[cur][1-v];
            make = (make<<1)|(1-v);
        }
        mxmsk = mxmsk>>1;
    }
    return make;
}

int arr[50003];
 
int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int n;
        scanf("%d",&n);
        init();
        for(int i = 1; i<=n; ++i){
            scanf("%d",&arr[i]);
            arr[i] = arr[i-1]^arr[i];
            buildtrie(arr[i]);
        }
        
        int mxx = 0, mnn = -1;

        for(int i = 1; i<=n; ++i){
            int cur = arr[i];
            int mxhere = getmx(cur);
            int mnhere = getmn(cur);
            mxx = max(mxx,mxhere);
            if(mnn==-1 || mnhere<mnn){
                mnn = mnhere;
            }
        } 

        /*for(int c = 0; c<used; ++c){
            cout<<cnt[c]<<"\n";
        }*/
        printf("Case %d: %d %d\n",cs,mxx,mnn);
    }
    return 0;
}