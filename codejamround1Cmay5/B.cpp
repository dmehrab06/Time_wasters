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

double prob[203];
int freq[203];
int able[203];

void init(int n){
    FREP(i,0,n-1){
        freq[i] = 1;
        able[i] = 1;
    }
}

void normalize(int n){
    FREP(i,0,n-1){
        prob[i] = (double)freq[i]/(double)n;
    }
}

int getmin(int n, set<int>&s){
    set< pair<double,int> >flavs;
    FREP(i,0,n-1){
        if(s.find(i)==s.end()){
            continue;
        }
        else{
            if(able[i]==1){
                flavs.insert(make_pair(prob[i],i));
            }
        }
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();++it){
        freq[*it]++;
    }
    normalize(n);
    if(flavs.size()==0)return -1;
    else{
        pair<double,int>mm = *(flavs.begin());
        int idx = mm.second;
        able[idx] = 0;
        return idx;
    }
}

int main(){
    int t;
    cin>>t;
    FREP(cs,1,t){
        int n;
        scanf("%d",&n);
        init(n);
        FREP(i,1,n){
            int d;
            cin>>d;
            set<int>ss;
            FREP(k,1,d){
                int ff;
                cin>>ff;
                ss.insert(ff);
            }
            int mnn = getmin(n,ss);
            cout<<mnn<<"\n";
            fflush(stdout);
        }
    }
    return 0;
}
