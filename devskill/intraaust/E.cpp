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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int init_pos[50005];

int lowidx(int lowtime, int n){
    int l=1;
    int r=n;
    //cout<<"in lo\n";
    while(true){
        int mid=(l+r)/2;
        //cout<<mid<<"\n";
        int thattime=init_pos[mid];
        if(thattime>=lowtime){
            if(mid>1 && init_pos[mid-1]>=lowtime){
                r=mid;
            }
            else{
                return mid;
            }
        }
        else{
            l=mid+1;
        }
    }
}

int hiidx(int hitime, int n){
    int l=1;
    int r=n;
    //cout<<"in hi\n";
    while(true){
        int mid=(l+r)/2;
        //cout<<mid<<"\n";
        int thattime=init_pos[mid];
        if(thattime<=hitime){
            if(mid<n && init_pos[mid+1]<=hitime){
                l=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            r=mid;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(i,1,t){
        int n,q;
        scanf("%d %d",&n,&q);
        FREP(k,1,n){
            scanf("%d",&init_pos[k]);
        }
        sort(init_pos+1,init_pos+1+n);
        printf("Case %d:\n",i);
        FREP(qq,1,q){
            int l,r,t;
            scanf("%d %d %d",&l,&r,&t);
            int ll=min(l,r);
            int rr=max(l,r);
            int lotime=ll-t;
            int hitime=rr-t;
            if(init_pos[n]<lotime || init_pos[1]>hitime){
                printf("0\n");
            }
            else{
                int lidx=lowidx(lotime,n);
                int ridx=hiidx(hitime,n);
                int tot=max(0,ridx-lidx+1);
                printf("%d\n",tot);
            }
        }
    }
    return 0;
}
