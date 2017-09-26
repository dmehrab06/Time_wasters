#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;
typedef pair<int,int> rng;

int seg[3000005];
vector<rng>post;

void init(int b, int e, int node, int K){
    if(b==e){
        seg[node]=K;
        return;
    }
    if(b>e)return;
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt,K);
        init(mid+1,e,rt,K);
       // seg[node].tot=seg[lt].tot+seg[rt].tot;
        seg[node]=K;
        return;
    }
}

void propagatebelow(int node,int b, int e){
    if(b<e){
        int ll=node<<1;
        int rr=ll+1;
        seg[ll]|=seg[node];
        seg[rr]|=seg[node];
    }
}

int update(int b,int e, int node, int load){
    if(b>e)return -1003;
    //propagatebelow(node,b,e);
    if(seg[node]<load)return -1003;
    if(b==e){
        seg[node]-=load;
        //propagatebelow(node,b,e);
        return b;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    int ans=update(b,mid,lt,load);
    if(ans<0)ans=update(mid+1,e,rt,load);
    seg[node]=max(seg[lt],seg[rt]);
    return ans;
}

int query(int i, int j, int b, int e, int node){
    if(b>e)return 0;
    propagatebelow(node,b,e);
    if(b>=i && e<=j){
        int mul=0;
        if(seg[node])mul=1;
        return (e-b+1)*mul;
    }
    if(e<i || b>j){
        return 0;
    }
    //int prop=seg[node].lazyval;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    int lans=query(i,j,b,mid,lt);
    int rans=query(i,j,mid+1,e,rt);
    return lans+rans;
}

int main(){
    int t;
    scanf("%d",&t);
    char grp[7];
    while(t--){
        int n,K;
        scanf("%d %d",&K,&n);
        init(1,n,1,K);
        //map<int,int>compress;
      //  scanf("%d",&q);
        //set<int>pts;
        int weightloaded=0;
        int maxship=0;
       // int idx=1;
        int nxtloaded;
        int i=0;
        for(;;){
            //int nowloaded;
            scanf("%s",grp);
            if(grp[0]=='b'){
                int r,v;
                scanf("%d %d",&r,&v);
                nxtloaded=r;
                if(v<=K){
                    for(int jj=1;jj<=nxtloaded;++jj){
                        maxship=max(maxship,update(1,n,1,v));
                    }
                    weightloaded+=(nxtloaded*v);
                }
            }
            else{
                int v=atoi(grp);
              //  printf("%d\n",v);
                nxtloaded=1;
                maxship=max(maxship,update(1,n,1,v));
                weightloaded+=v;
            }
            i+=nxtloaded;
            if(i>=n){
                break;
            }
        }
        printf("%lld %lld\n",(long long int)maxship,((long long int)maxship*K)-(long long int)weightloaded);

    }
    return 0;
}
