#include <bits/stdc++.h>
#define MXVAL 2000

using namespace std;

int arr[2005];
vector<int>segtree[100005];

int cum[2005][2005];

void precalc(int n){
    for(int i = 1; i<=MXVAL; ++i){
        for(int j = 1; j<=n; ++j){
            if(arr[j]==i){
                cum[j][i] = 1;
            }
            else{
                cum[j][i] = 0;
            }
            cum[j][i] = cum[j-1][i]+cum[j][i];
        }
    }
}

void merge(int nd, vector<int> ln, vector<int> rn){
    int lsz = (int)ln.size();
    int rsz = (int)rn.size();
    int il = 0, ir = 0;
    while(il<lsz || ir<rsz){
        if(il==lsz){
            segtree[nd].push_back(rn[ir]);
            ir++;
        }
        else if(ir==rsz){
            segtree[nd].push_back(ln[il]);
            il++;
        }
        else{
            int lval = ln[il];
            int rval = rn[ir];
            if(lval<rval){
                segtree[nd].push_back(lval);
                il++;
            }
            else{
                segtree[nd].push_back(rval);
                ir++;
            }
        }
    }
    return;
}

void init(int b, int e, int node){
    if(b==e){
        segtree[node].push_back(arr[b]);
        return;
    }
    else if(b>e){
        return;
    }
    int ln = node<<1; int rn = ln+1;
    int m = b+(e-b)/2;
    init(b,m,ln);
    init(m+1,e,rn);
    merge(node,segtree[ln],segtree[rn]);
}

int sml_query(int b, int e, int node, int l, int r, int pivot){
    if(b>=l && e<=r){
        return (int)(lower_bound(segtree[node].begin(),segtree[node].end(),pivot)-segtree[node].begin());
    }
    if(b>r || e<l){
        return 0;
    }
    int ln = node<<1; int rn = ln+1;
    int m = b+(e-b)/2;
    int lans = sml_query(b,m,ln,l,r,pivot);
    int rans = sml_query(m+1,e,rn,l,r,pivot);
    return lans+rans;
}

int lrg_query(int b, int e, int node, int l, int r, int pivot){
    if(b>=l && e<=r){
        return (int)segtree[node].size()-(int)(upper_bound(segtree[node].begin(),segtree[node].end(),pivot)-segtree[node].begin());
    }
    if(b>r || e<l){
        return 0;
    }
    int ln = node<<1; int rn = ln+1;
    int m = b+(e-b)/2;
    int lans = lrg_query(b,m,ln,l,r,pivot);
    int rans = lrg_query(m+1,e,rn,l,r,pivot);
    return lans+rans;
}

bool bin_search(int l, int r, int n, int m, int k){
    int loval = 1;
    int hival = MXVAL;
    int len = (r-l+1);
    int vv = -1;
    while(true){
        int mval = loval+(hival-loval)/2;
        int choto = m*sml_query(1,n,1,l,r,mval);
        int boro = m*lrg_query(1,n,1,l,r,mval);
        int lrange = choto+1;
        int rrange = m*len-boro;
        if(lrange>rrange){
            //or vitore m nai e
            if(choto>=k){
                hival = mval - 1;
            }
            else{
                loval = mval + 1;
            }
        }
        else{
            if(k>=lrange && k<=rrange){
                vv = mval;
                break;
            }
            else if(k<lrange){
                hival = mval - 1;
            }
            else{
                loval = mval+1;
            }
        }
    }
    int occ = cum[r][vv] - cum[l-1][vv];
    int occ_occ = cum[r][occ]-cum[l-1][occ];
    return occ_occ>0;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i = 1; i<=n; ++i){
            scanf("%d",&arr[i]);
        }
        for(int i = 1; i<=10004; ++i)segtree[i].clear();
        init(1,n,1);
        precalc(n);
        cout<<"checkpoint one\n";
        int cnt = 0;
        for(int l = 1; l<=n; ++l){
            for(int r = l; r<=n; ++r){
                //subarray l and r
                int ll = (r-l+1);
                int md = k%ll;
                int m = k/ll+(md==0?0:1);
                if(bin_search(l,r,n,m,k)){
                    //cout<<"subarray "<<l<<" "<<r<<"\n";
                    cnt++;
                } 
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}