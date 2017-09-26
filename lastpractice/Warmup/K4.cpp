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
#define MEH 1
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int colorstack[1000005];
int colorplayer[1000005];
int stacks[1000005];
int playar[1000005];

int mx1 = 0, mx2 = 0;
int stackh = 0, playerh = 0;

vector<int>valids;

void init(){
    MSET(colorstack,0); MSET(colorplayer,0);
    valids.clear();
    stackh = 0; playerh = 0;
    mx1 = 0; mx2 = 0;
}

void setmaxs(int c, int h){
    int mxx1 = 0, mxx2 = 0;
    FREP(i,0,c){
        if(i!=h){
            if((colorstack[i]+colorplayer[i])==mxx1){
                mxx2 = mxx1; mx2 = i;
            }
            else if((colorstack[i]+colorplayer[i])>mxx1){ //ghapla ache
                mx1 = i; mx2 = 0;
                mxx1 = colorstack[i]+colorplayer[i];
            }
        }
    }
}

void simulate(int n, int h, int p){
    FREP(i,1,n){
        //cout<<"at stack "<<i<<"\n";
        int curh = colorstack[h];
        if(stacks[i]==h)curh--;
        if(playar[1]==h)curh++;
        int onnoderase = (p-1)-playerh;
        //cout<<"h er obostha "<<stackh<<" "<<playerh<<"\n";
        //cout<<"onno "<<onnoderase<<"\n";
        int worstcase = curh-onnoderase;
        //cout<<"tar obostha "<<curh<<" "<<worstcase<<"\n";
        if(worstcase<=1)continue;
        else{
            int mxval = colorstack[mx1]+colorplayer[mx1];
            if(stacks[i]==mx1){
                mxval--;
                if(mx2!=0){
                    mxval++;
                }
            }
            if(worstcase>mxval){
                valids.PB(i);
            }
        }
    }
    printf("%d\n",(int)valids.size());
    FREP(i,0,valids.size()-1){
        printf("%d\n",valids[i]);
    }
}

int main(){
    int n,p,c,h;
    while(scanf("%d %d %d %d",&n,&p,&c,&h)==4){
        init();
        FREP(i,1,n)scanf("%d",&stacks[i]);
        FREP(i,1,p)scanf("%d",&playar[i]);
        if(n==1){
            if(playar[p]==h)printf("1\n1\n");
            else printf("0\n");
            continue; //trivial case baad
        }
        FREP(i,1,n)colorstack[stacks[i]]++;
        FREP(i,1,p)colorplayer[playar[i]]++;

        stackh = colorstack[h]; playerh = colorplayer[h]-(playar[1]==h?1:0);
        setmaxs(c,h);
        /*cout<<mx1<<" "<<mx2<<"\n";
        for(int i=1;i<=c;++i){
            cout<<colortot[i]<<" ";
        }
        cout<<"\n";*/
        simulate(n,h,p);
    }

    return 0;
}
