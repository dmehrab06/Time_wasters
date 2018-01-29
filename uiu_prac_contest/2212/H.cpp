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

map<string,int>namemap;
map<int,string>namemap2;

int adjmat[18][18];

void init(){
    namemap.clear();
    MSET(adjmat,0);
}

int cntmask(int mask, int sz){
    int msk = 1;
    int cnt = 0;
    FREP(i,1,sz){
        if(mask&msk)cnt++;
        msk<<=1;
    }
    return cnt;
}

void takenames(int n){
    FREP(i,1,n){
        string s;
        cin>>s;
        namemap[s]=(i-1);
        namemap2[i-1]=s;
    }
}

void takeenemy(int m){
    FREP(i,1,m){
        string a,b;
        cin>>a>>b;
        int ia = namemap[a];
        int ib = namemap[b];
        adjmat[ia][ib]=1;
        adjmat[ib][ia]=1;
    }
}

bool isok(int mask, int sz){
    vector<int>ase;
    int msk = 1;
    FREP(i,1,sz){
        if(mask&msk){
            ase.PB((i-1));
        }
        msk<<=1;
    }
    FREP(i,0,ase.size()-1){
        FREP(j,(i+1),ase.size()-1){
            if(adjmat[ase[i]][ase[j]])return false;
        }
    }
    return true;
}

void solve(int sz){
    int mxmask = (1<<sz)-1;
    int mxx = 0;
    int ansmask = 0;
    FREP(i,0,mxmask){
        if(isok(i,sz)){
            if(cntmask(i,sz)>mxx){
                mxx = cntmask(i,sz);
                ansmask = i;
            }
        }
    }
    vector<string>all;
    int msk = 1;
    FREP(i,1,sz){
        if(ansmask&msk){
            all.PB(namemap2[i-1]);
        }
        msk<<=1;
    }
    SORTV(all);
    cout<<mxx<<"\n";
    FREP(i,0,all.size()-1){
        cout<<all[i]<<"\n";
    }
}

int main(){
    init();
    int n,m;
    scanf("%d %d",&n,&m);
    takenames(n);
    takeenemy(m);
    solve(n);
}
