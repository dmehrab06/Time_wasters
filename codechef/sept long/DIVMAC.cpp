#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

int sieve[1000007];
int smallest[1000007];

void calcsieve(){
    FREP(i,0,1000006){
        sieve[i]=1;
        smallest[i]=-1;
    }
    FREP(i,2,1000006){
        if(sieve[i]){
            smallest[i]=i;
            for(int j=(i+i);j<=1000006;j+=i){
                if(smallest[j]==-1){
                    smallest[j]=i;
                }
                sieve[j]=0;
            }
        }
    }
}

struct info{
    int val;
    int mxtot;
    int nowtot;
    int leastprime;
    int factor[50];
    void setleastprime(){
        if(nowtot==0){
            leastprime=1;
        }
        else{
            leastprime=factor[mxtot-nowtot+1];
        }
    }
};

info segtree[600005];
int arr[200005];
//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        int v=arr[b];
        segtree[node].val=v;
        int sz=1;
        //printf("factoring arr[%d]=%d\n",b,v);
        while(v>1){
            int sml=smallest[v];
            segtree[node].factor[sz]=sml;
            sz++;
            v/=sml;
        }
        segtree[node].mxtot=sz-1;
        segtree[node].nowtot=sz-1;
        segtree[node].setleastprime();
        //printf("%d\n",segtree[node].leastprime);
        return;
    }
    if(b>e)return;
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt);
        init(mid+1,e,rt);
        int mx1=max(segtree[lt].nowtot,segtree[rt].nowtot);
        int mx2=max(segtree[lt].leastprime,segtree[rt].leastprime);
        segtree[node].nowtot=mx1;
        segtree[node].leastprime=mx2;
        return;
    }
}

int query(int i, int j, int b, int e, int node){
    //int cur=0;
    if(b>=i && e<=j){
        //cur=segtree[node];
        return segtree[node].leastprime;
    }
    if(e<i || b>j){
        return 0;
    }
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    int leftinfo=query(i,j,b,mid,lt);
    int rightinfo=query(i,j,mid+1,e,rt);
    return max(leftinfo,rightinfo);
}

void update(int i, int j, int b,int e, int node){
    if(e<i || b>j){
        return;
    }
    if(b==e){
        if(segtree[node].nowtot>0){
            segtree[node].nowtot--;
           // segtree[node].leastprime=segtree[node].factor[]
           segtree[node].setleastprime();
        }
        return;
    }

    //if(b1>e1 || b2>e2)return;
    if(b>=i && e<=j && segtree[node].nowtot==0){
        segtree[node].leastprime=1;
        return;
    }
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(i,j,b,mid,lt);
    update(i,j,mid+1,e,rt);
    //segtree[node]=segtree[left]+segtree[right];
    int mx1=max(segtree[lt].nowtot,segtree[rt].nowtot);
    int mx2=max(segtree[lt].leastprime,segtree[rt].leastprime);
    segtree[node].nowtot=mx1;
    segtree[node].leastprime=mx2;
    return;
}

int main(){
    calcsieve();
    int t;
    scanf("%d",&t);
    while(t--){
        int N,Q;
        scanf("%d %d",&N,&Q);
        FREP(i,1,N){
            scanf("%d",&arr[i]);
        }
        init(1,N,1);
        int did=0;
        FREP(i,1,Q){
            int type,l,r;
            scanf("%d %d %d",&type,&l,&r);
            if(type==0){
                update(l,r,1,N,1);
            }
            else if(type==1){
                int ans=query(l,r,1,N,1);
                if(did)printf(" ");
                printf("%d",ans);
                did++;
            }
        }
        printf("\n");
    }
    return 0;
}
