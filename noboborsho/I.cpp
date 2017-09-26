#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


struct segnode{
    int sum;
    int mnval;
    int mxval;
    segnode(){
        sum=0;
        mnval=0;
        mxval=0;
    }
    segnode(int a, int b, int c){
        sum=a;
        mnval=b;
        mxval=c;
    }
};



segnode segtree[400005];
int arr[100005];

void init(int b, int e, int node){
    if(b==e){
        segtree[node].sum=arr[b];
        segtree[node].mnval=arr[b];
        segtree[node].mxval=arr[b];

    }
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(b,mid,left);
    init(mid+1,e,right);
    segtree[node].sum=segtree[left].sum+segtree[right].sum;
    //cout<<"setting from range "<<b<<" "<<e<<" segtree sum "<<segtree[node].sum<<"\n";
    segtree[node].mnval=min(segtree[left].mnval,segtree[right].mnval);
    segtree[node].mxval=max(segtree[left].mxval,segtree[right].mxval);

    }
}

int query(int i, int j, int b, int e, int node, int queryval){

    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        int thismnval=segtree[node].mnval;
        int thismxval=segtree[node].mxval;
        //cout<<"in relevant range "<<b<<" "<<e<<"\n";
        //cout<<"min "<<thismnval<<" max "<<thismxval<<"\n";
        //cout<<"sum "<<segtree[node].sum<<"\n";
        if(thismxval<=queryval){
          //  cout<<"from range "<<b<<" "<<e<<" returning segtree sum "<<segtree[node].sum<<"\n";
            return segtree[node].sum;
        }
        else if(thismnval>=queryval){
            return (e-b+1)*queryval;
            //cout<<"from range "<<b<<" "<<e<<" returning min sum "<<(e-b+1)*queryval<<"\n";
        }

        int thisl=node*2;
        int thisr=thisl+1;
        int thismid=(b+e)/2;
        int this1=query(i,j,b,thismid,thisl,queryval);
        int this2=query(i,j,thismid+1,e,thisr,queryval);
        return this1+this2;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int min1=query(i,j,b,mid,left,queryval);
    int min2=query(i,j,mid+1,e,right,queryval);
    return min1+min2;
}

/*void update(int i, int j, int b, int e, int node, int toadd){
    if(b>=i && e<=j){
        segtree[node]=segtree[node]+toadd;
        return;
    }
    if(e<i || b>j){
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(i,j,b,mid,left,toadd);
    update(i,j,mid+1,e,right,toadd);
    segtree[node]=segtree[left]+segtree[right];
}*/

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int N,Q;
        scanf("%d %d",&N,&Q);
        for(int i=1;i<=N;++i){
            scanf("%d",arr+i);
        }
        init(1,N,1);
        printf("Case #%d:\n",cs++);
        for(int i=1;i<=Q;++i){
            int x,y,val;
            scanf("%d %d %d",&x,&y,&val);
            int ans=query(x,y,1,N,1,val);
            printf("%d\n",ans);
        }

    }
    return 0;
}
