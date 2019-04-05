#include <bits/stdc++.h>
#define MXVAL 2000

using namespace std;

int arr[2005];

int cum[2005][2005];
int cum_sm[2005][2005];
int cum_lg[2005][2005];

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
    for(int i = 1; i<=MXVAL; ++i){
        for(int j = 1; j<=n; ++j){
            if(arr[j]<i){
                cum_sm[j][i] = 1;
            }
            else{
                cum_sm[j][i] = 0;
            }
            cum_sm[j][i] = cum_sm[j-1][i]+cum_sm[j][i];
        }
    }
    for(int i = 1; i<=MXVAL; ++i){
        for(int j = 1; j<=n; ++j){
            if(arr[j]>i){
                cum_lg[j][i] = 1;
            }
            else{
                cum_lg[j][i] = 0;
            }
            cum_lg[j][i] = cum_lg[j-1][i]+cum_lg[j][i];
        }
    }
}

int sml_query(int l, int r, int pivot){
    return cum_sm[r][pivot]-cum_sm[l-1][pivot];
}

int lrg_query(int l, int r, int pivot){
    return cum_lg[r][pivot]-cum_lg[l-1][pivot];
}

bool bin_search(int l, int r, int n, int m, int k){
    int loval = 1;
    int hival = MXVAL;
    int len = (r-l+1);
    int vv = -1;
    while(true){
        int mval = loval+(hival-loval)/2;
        int choto = m*sml_query(l,r,mval);
        int boro = m*lrg_query(l,r,mval);
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
        precalc(n);
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