/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < VI > arr;
vector < VI > dp1;
vector < VI > dp2;
vector < VI > dp3;
vector < VI > vis;
vector < VI > vis2;
VI lsum, rsum;
VI lrng, rrng;
vector < vector <PII> >rngs;

void init(int n, int m){
    //cout<<"aschi\n";
    FREP(i,1,(n+3)){
        VI line;
        vector <PII> line2;
        arr.PB(line);
        dp1.PB(line);dp2.PB(line);dp3.PB(line);
        vis.PB(line);
        vis2.PB(line);
        rngs.PB(line2);
        FREP(j,1,m+2){
            arr[i-1].PB(0);
            dp1[i-1].PB(0); dp2[i-1].PB(0); dp3[i-1].PB(0);
            vis[i-1].PB(-1); vis2[i-1].PB(-1);
            rngs[i-1].PB(make_pair(0,0));
        }
    }
    FREP(j,1,(m+3))lsum.PB(0);
    FREP(j,1,(m+3))rsum.PB(0);
    FREP(j,1,(m+3))lrng.PB(0);
    FREP(j,1,(m+3))rrng.PB(0);
}

void takeinp(int n, int m){
    FREP(i,1,n)FREP(j,1,m)scanf("%d",&arr[i][j]);
}

void calcrightmax(int row, int m){
    FREP(j,1,m){
        rsum[j]=arr[row][j];
        rrng[j]=j;
    }
    RFREP(j,m-1,1){
        if((arr[row][j]+rsum[j+1])>rsum[j]){
            rsum[j] = arr[row][j]+rsum[j+1];
            rrng[j] = rrng[j+1];
        }
        else if((arr[row][j]+rsum[j+1])==rsum[j]){
            if(rrng[j+1]>rrng[j]){
                rrng[j]  = rrng[j+1];
            }
        }
    }
}

void calcleftmax(int row, int m){
    FREP(j,1,m){
        lsum[j] = 0; lrng[j] = j;
    }
    FREP(j,2,m){
        if((arr[row][j-1]+lsum[j-1])>lsum[j]){
            lsum[j] = arr[row][j-1]+lsum[j-1];
            lrng[j] = lrng[j-1];
        }
        else if((arr[row][j-1]+lsum[j-1])==lsum[j]){
            if(lrng[j-1]<lrng[j]){
                lrng[j]  = lrng[j-1];
            }
        }
    }
}

void calcrowvals(int row, int m){
    calcleftmax(row,m);
    calcrightmax(row,m);
    FREP(j,1,m){
        dp1[row][j] = lsum[j]+rsum[j];
        rngs[row][j] = make_pair(lrng[j],rrng[j]);
        //cout<<dp1[row][j]<<", ranges "<<rngs[row][j].first<<" "<<rngs[row][j].second<<"\n";
    }
    //cout<<"\n\n";
}

int solve1(int x, int y){
    if(x==1)return dp2[x][y] = dp1[x][y];
    if(vis[x][y]!=-1)return dp2[x][y];
    int ll = rngs[x][y].first; int rr = rngs[x][y].second;
    int mxx = -1000000009;
    int ss = dp1[x][y];
    FREP(j,ll,rr)mxx = max(mxx,solve1(x-1,j));
    dp2[x][y] = mxx+ss;
    vis[x][y] = 1;
    return dp2[x][y];
}

int solve2(int x, int y, int n){
    if(x==n)return dp3[x][y] = dp1[x][y];
    if(vis2[x][y]!=-1)return dp3[x][y];
    int ll = rngs[x][y].first; int rr = rngs[x][y].second;
    int mxx = -1000000009;
    int ss = dp1[x][y];
    FREP(j,ll,rr)mxx = max(mxx,solve2(x+1,j,n));
    dp3[x][y] = mxx+ss;
    vis2[x][y] = 1;
    return dp3[x][y];
}

int solve3(int x, int y, int m){
    if(vis[x][y]!=-1)return dp2[x][y];
    if(x==1){
        int mxx = -1000000009;
        FREP(j,1,m){
            int l = rngs[x][j].first;
            int r = rngs[x][j].second;
            if(y>=l && y<=r)mxx = max(mxx,dp1[x][j]);
        }
        vis[x][y] = 1;
        return dp2[x][y]=mxx;
    }
    int mxx = -1000000009;
    vector<int>mycols;
    FREP(j,1,m){
        int l = rngs[x][j].first;
        int r = rngs[x][j].second;
        if(y>=l && y<=r){
            mycols.PB(j);
        }
    }
    FREP(i,0,mycols.size()-1){
        //FREP(j,0,mycols.size()-1){
            mxx = max(mxx,solve3(x-1,y,m)+dp1[x][mycols[i]]);
        //}
    }
    vis[x][y] = 1;
    return dp2[x][y] = mxx;
}

void solve4(int n, int m){
    FREP(i,1,n)FREP(j,1,m)dp2[i][j]=-1000000009;
    FREP(j,1,m)dp2[1][j] = dp1[1][j];
    FREP(i,2,n){
        FREP(j,1,m){
            FREP(k,1,m){
                if(j>=rngs[i][k].first && j<=rngs[i][k].second){
                    dp2[i][k] = max(dp2[i][k],dp1[i][k]+dp2[i-1][j]);
                    dp2[i][j] = max(dp2[i][j],dp1[i][k]+dp2[i-1][k]);
                }
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init(n,m);
    //cout<<"init hoise\n";
    takeinp(n,m);
    FREP(i,1,n)calcrowvals(i,m);
    //int mxx = -1000000009;
    /*FREP(i,1,n){
        FREP(j,1,m){
            cout<<dp1[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    //cout<<"\n\n";
    /*FREP(j,1,m)mxx = max(mxx,solve1(n,j));
    FREP(i,1,n){
        FREP(j,1,m){
            cout<<dp2[i][j]<<" ";
        }
        cout<<"\n";
    }
    FREP(j,1,m)mxx = max(mxx,solve2(1,j,n));
    cout<<"\n\n";
    FREP(i,1,n){
        FREP(j,1,m){
            cout<<dp3[i][j]<<" ";
        }
        cout<<"\n";
    }
    FREP(j,1,m)mxx = max(mxx,solve3(n,j,m));
    FREP(i,1,n){
        FREP(j,1,m){
            cout<<dp2[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    solve4(n,m);
    FREP(i,1,n){
        FREP(j,1,m){
            cout<<dp2[i][j]<<" ";
        }
        cout<<"\n";
    }
    //printf("%d\n",mxx);
    int mxx = -1000000009;
    FREP(j,1,m)mxx = max(mxx,dp2[n][j]);
    printf("%d\n",mxx);
}
