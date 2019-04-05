#include <bits/stdc++.h>
using namespace std;

int smallestprime[1000005];
int siever[1000005];
long long divcnt[1000005];
//int maxdiv[1000005];

long long divsum[8][300005];
pair<long long ,int> segtree[900005];
int lazy[900005];

void sieve(){
    for(int i=2;i<=1000004;++i){
        if(siever[i]==0){
            smallestprime[i] = i;
            for(int j = (i+i);  j<=1000004; j+=i){
                if(smallestprime[j]==0){
                    smallestprime[j] = i;
                }
                siever[j]  = 1;
            }
        }
    }
}

void cntdiv(int p){
    int t = p;
    long long s = 1;
    while(p>1){
        int dd = smallestprime[p];
        //cout<<dd<<"\n";
        int hh = 0;
        while((p%dd)==0){
            p/=dd;
            hh++;
        }
        //cout<<p<<"\n";
        s = s*(hh+1);
    }
    divcnt[t] = s;
}



void precalc(){
    sieve();
    //cout<<"sieve done\n";
    //int mxx = -1;
    //int mxi = 0;
    for(int i  =1;i<=1000000;++i){
        cntdiv(i);
        //cout<<"did for "<<i<<"\n";
    }
    //cout<<"cnting divisor done\n";
    /*for(int i  =1;i<=1000000;++i){
        getmaxdivcnt(i);
        if(maxdiv[i]>mxx){
            mxx = maxdiv[i];
            mxi  =i;
        }
    }

    cout<<"got "<<mxx<<" for "<<mxi<<"\n";*/
}

/*void getmaxdivcnt(int p){
    int cnt = 0;
    int cur = p;
    while(true){
        int nxt = divcnt[cur];
        //cout<<cur<<" "<<nxt<<"\n";
        if(nxt==cur){
            break;
        }
        cnt++;
        cur  = nxt;
    }
    maxdiv[p] = cnt;
}*/

void takearr(int n){
    for(int i = 1;i<=n;++i){
        cin>>divsum[0][i];
    }
    for(int i = 1;i<=7;++i){
        for(int j = 1;j<=n;++j){
            divsum[i][j] = divcnt[divsum[i-1][j]];
            //cout<<divsum[i][j]<<" ";
        }
        //cout<<"\n";
    }
    for(int i = 0;i<=7;++i){
        for(int j = 1;j<=n;++j){
            divsum[i][j] = divsum[i][j-1]+divsum[i][j];
        }
    }
}

void propagate(int node, int b, int e){
    if(b>=e || (lazy[node]==0))return;
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    segtree[ln].second = segtree[ln].second+lazy[node]; segtree[rn].second = segtree[rn].second+lazy[node];
    lazy[ln] = lazy[ln]+lazy[node]; lazy[rn] = lazy[rn]+lazy[node];
    segtree[ln].second = min(7,segtree[ln].second);
    segtree[ln].first = divsum[segtree[ln].second][mid]-divsum[segtree[ln].second][b-1];
    segtree[rn].second = min(7,segtree[rn].second);
    segtree[rn].first = divsum[segtree[rn].second][e]-divsum[segtree[rn].second][mid];
    segtree[node].first = segtree[ln].first+segtree[rn].first;
    lazy[ln] = min(7,lazy[ln]); lazy[rn] = min(7,lazy[rn]);
    lazy[node] = 0;
}

void printtree(int node, int b, int e){
    if(b>e)return;
    if(b==e){
        cout<<"range "<<b<<" to "<<e<<" contains "<<segtree[node].first<<" "<<segtree[node].second<<" and has lazy "<<lazy[node]<<"\n";
        return;
    }
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    printtree(ln,b,mid); printtree(rn,mid+1,e);
    //segtree[node].first = segtree[ln].first+segtree[rn].first;
    cout<<"range "<<b<<" to "<<e<<" contains "<<segtree[node].first<<" "<<segtree[node].second<<" and has lazy "<<lazy[node]<<"\n";
}

void init(int node, int b, int e){
    if(b>e)return;
    if(b==e){
        segtree[node].first = divsum[0][e]-divsum[0][b-1];
        return;
    }
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    init(ln,b,mid); init(rn,mid+1,e);
    segtree[node].first = segtree[ln].first+segtree[rn].first;
    //cout<<"for "<<b<<" to "<<e<<" ans is "<<segtree[node].first<<"\n";
}

void update(int node, int b, int e, int l, int r){
    if(b>r || e<l)return;
    if(b>=l && e<=r){
        segtree[node].second+=1;
        segtree[node].second = min(segtree[node].second,7);
        lazy[node]+=1;
        lazy[node] = min(7,lazy[node]);
        segtree[node].first = divsum[segtree[node].second][e]-divsum[segtree[node].second][b-1];
        return;
    }
    propagate(node,b,e);
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    update(ln,b,mid,l,r); update(rn,mid+1,e,l,r);
    segtree[node].first = segtree[ln].first+segtree[rn].first;
}

long long query(int node, int b, int e, int l, int r){
    if(b>r || e<l)return 0;
    if(b>=l && e<=r){
        return segtree[node].first;
    }
    propagate(node,b,e);
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    long long q1 = query(ln,b,mid,l,r); long long q2  = query(rn,mid+1,e,l,r);
    return q1+q2;
}

int main(){
    precalc();
    int n,m;
    cin>>n>>m;
    takearr(n);
    init(1,1,n);
    for(int i=1;i<=m;++i){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            update(1,1,n,l,r);
            //printtree(1,1,n);
        }
        else{
            long long ans = query(1,1,n,l,r);
            //printtree(1,1,n);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
