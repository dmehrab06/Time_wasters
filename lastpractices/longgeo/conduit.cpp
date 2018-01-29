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


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int rep[10003];

int findrep(int x){
    if(rep[x]==x)return rep[x];
    else {
        int xx = findrep(rep[x]);
        return rep[x] = xx;
    }
}

void union_nodes(int x, int y){
    int px = findrep(x);
    int py = findrep(y);
    if(px!=py)rep[px] = py;
}

struct pt2d{
    int x;
    int y;
    pt2d(int _x=0, int _y=0){
        x=_x; y=_y;
    }
};

pair<LLI,PII>getabc(pt2d st, pt2d ed){
    int a = st.y - ed.y;
    int b = ed.x - st.x;
    LLI c = (LLI)(-1)*((LLI)st.y*((LLI)b)+(LLI)st.x*((LLI)a) );
    return make_pair(c,make_pair(a,b));
}

pair<LLI,PII> mylines[10004];

bool issame(int i, int j){
    LLI ci = mylines[i].first; LLI cj = mylines[j].first;
    LLI ai = mylines[i].second.first; LLI bi = mylines[i].second.second;
    LLI aj = mylines[j].second.first; LLI bj = mylines[j].second.second;

    LLI v1 = (ai*bj)-(aj*bi);
    LLI v2 = (ai*cj)-(aj*ci);

    return (v1==0) && (v2==0);
}


int main(){
    int n;
    //int cs = 1;
    while(scanf("%d",&n)==1){
        //cout<<n<<"\n";
        if(n==0)break;
        FREP(i,1,n){
            double x1,y1,x2,y2;
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            int X1 = (round)(x1*100.00); int Y1 = (round)(y1*100.0);
            int X2 = (round)(x2*100.00); int Y2 = (round)(y2*100.0);
            pair<LLI,PII> myline = getabc(pt2d(X1,Y1),pt2d(X2,Y2));
            mylines[i] = myline;
        }
        FREP(i,1,n)rep[i]=i;
        FREP(i,1,n){
            FREP(j,(i+1),n){
                if(issame(i,j)){
                    union_nodes(i,j);
                }
            }
        }
        FREP(k,1,10){
            FREP(i,1,n){
                findrep(i);
            }
        }
        set<int>allreps;
        FREP(i,1,n){
            allreps.insert(rep[i]);
        }
        printf("%d\n",(int)allreps.size());
    }
    return 0;
}
