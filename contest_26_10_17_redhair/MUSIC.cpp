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

struct seg{

    int l; int r;
    int type; //1 for actor , //2 for parts
    int id;
    seg(int _l=0, int _r=0, int _type=0, int _id=0){
        l = _l; r = _r; type = _type, id = _id;
    }
};

bool cmp(seg &a, seg &b){
    if(a.l==b.l)return a.type<b.type;
    return a.l<b.l;
}

seg allseg[200005];

int power[100005];
int assigned[100005];

set<PII>curactors;

PII takeinp(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int l,r;
        scanf("%d %d",&l,&r);
        allseg[i] = seg(l,r,2,i);
    }
    int m;
    scanf("%d",&m);
    FREP(i,1,m){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        allseg[i+n] = seg(l,r,1,i);
        power[i] = k;
    }
    return make_pair(n,m);
}

bool can(int n,int m){
    sort(allseg+1,allseg+1+n+m,cmp);
    FREP(i,1,(n+m)){
        seg cur = allseg[i];
        //cout<<cur.type<<" "<<cur.l<<" "<<cur.r<<" "<<cur.id<<"\n";
        if(cur.type==1){
            curactors.insert(make_pair(cur.r,cur.id));
        }
        else if(cur.type==2){
            //cout<<"assigning\n";
            int rhere = cur.r;
            //l already satisfied
            int idhere = cur.id;
            PII dummy = make_pair(rhere,-1);
            set<PII>::iterator it = curactors.lower_bound(dummy);
            if(it==curactors.end())return false;
            else{
                //assign this part to it actor
                PII actorhere = *it;
                //cout<<actorhere.first<<" "<<actorhere.second<<"\n";
                assigned[idhere] = actorhere.second;
                power[actorhere.second]-=1;
                if(power[actorhere.second]==0){
                    curactors.erase(it);
                }
            }
        }
    }
    return true;
}

int main(){
    PII oka = takeinp();
    if(can(oka.first,oka.second)){
        printf("YES\n");
        FREP(i,1,oka.first){
            printf("%d ",assigned[i]);
        }
        printf("\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
