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

int xx[100005];
int yy[100005];

int lc[100005];int rc[100005];
int tc[100005];int bc[100005];

pair<PII,PII> sofas[100005];

void upd(int sofa){
    FREP(i,1,sofa){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int mnx = min(x1,x2); int mxx = max(x1,x2);
        int mny = min(y1,y2); int mxy = max(y1,y2);
        xx[mnx]+=1;  xx[mxx+1]-=1;
        yy[mny]+=1;  yy[mxy+1]-=1;
        sofas[i] = make_pair(make_pair(x1,y1),make_pair(x2,y2));
    }
    xx[0]=0;
    yy[0]=0;
    FREP(i,1,100004){
        xx[i]=xx[i-1]+xx[i];
        yy[i]=yy[i-1]+yy[i];
    }
    FREP(i,1,100004){
        xx[i]=xx[i-1]+xx[i];
        yy[i]=yy[i-1]+yy[i];
    }
    /*FREP(i,1,10){
        cout<<xx[i]<<" ";
    }
    cout<<"\n";
    FREP(i,1,10){
        cout<<yy[i]<<" ";
    }
    cout<<"\n";*/
    FREP(i,1,sofa){
        int right = max(sofas[i].first.first,sofas[i].second.first);
        int lcc = xx[right-1];
        int lft = min(sofas[i].first.first,sofas[i].second.first);
        int c1 = xx[lft]; int c2 = xx[100004];
        int rcc = c2-c1;
        if(lft!=right){rcc--;lcc--;}
        int tp = min(sofas[i].first.second,sofas[i].second.second);
        int c3 = yy[tp]; int c4 = yy[100004];
        int bcc =  c4-c3;
        int bot = max(sofas[i].first.second,sofas[i].second.second);
        int tcc = yy[bot-1];
        if(tp!=bot){tcc--;bcc--;}
        lc[i]=max(0,lcc);  rc[i]=max(0,rcc); bc[i]=max(0,bcc); tc[i]=max(0,tcc);
    }
}

int getidx(int sofa, int l, int r, int t, int b){
    int idx = -1;
    FREP(i,1,sofa){
        cout<<"sofa no: "<<i<<"\n";
        cout<<lc[i]<<" "<<rc[i]<<" "<<tc[i]<<" "<<bc[i]<<"\n";
        if(lc[i]==l && rc[i]==r && tc[i]==t && bc[i]==b){
            idx = i;
            break;
        }
    }
    return idx;
}

int main(){
    int sofa ;
    scanf("%d",&sofa);
    int n,m;
    scanf("%d %d",&n,&m);
    upd(sofa);
    int l,r,t,b;
    cin>>l>>r>>t>>b;
    int ans = getidx(sofa,l,r,t,b);
    cout<<ans<<"\n";
    return 0;
}
