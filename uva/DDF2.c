#include <stdio.h>
#include <math.h>
int nxt[6005];
int length[6005];
int dn(int n){
    int t=n;
    int s=0;
    while(t){
        s+=t%10;
        t/=10;
    }
    return s;
}
void init(int n){
    int sqrn=sqrt(n);
    int s=0;
    int i;
    for(i=1;i<=sqrn;++i){
        if(n%i==0){
            s+=dn(i);
            int j=n/i;
            if(i!=j){
                s+=dn(j);
            }
        }
    }
    if(n==s){
        length[n]=1;
        nxt[n]=n;
    }
    else{
        nxt[n]=s;
        if(length[s]!=0){
            length[n]=1+length[s];
        }
        else{
            init(s);
            length[n]=1+length[s];
        }
    }
}


struct xx{
    int val;
    int len;

};
typedef struct xx segnode;



segnode segtree[9005];

void init2(int b, int e, int node){
    if(b==e){
        segtree[node].val=b;
        segtree[node].len=length[b];
    }
    else{
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init2(b,mid,left);
    init2(mid+1,e,right);
    if(segtree[left].len>=segtree[right].len){
        segtree[node].val=segtree[left].val;
        segtree[node].len=segtree[left].len;
    }
    else{
        segtree[node].val=segtree[right].val;
        segtree[node].len=segtree[right].len;
    }

    }
}

segnode query(int i, int j, int b, int e, int node){

    if(e<i || b>j){
        segnode a;
        a.val=0;
        a.len=0;
        return a;
    }
    if(b>=i && e<=j){

        return segtree[node];
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    segnode mx1=query(i,j,b,mid,left);
    segnode mx2=query(i,j,mid+1,e,right);
    if(mx1.len>=mx2.len){
        return mx1;
    }
    else{
        return mx2;
    }
}
int main(){

    int ii;
    for(ii=1;ii<=3000;++ii){
        if(length[ii]==0){
            init(ii);
        }
    }
    init2(1,3000,1);
    int cs=1;
    int l,r;
    while(scanf("%d %d",&l,&r)==2){
        printf("Input%d: %d %d\n",cs,l,r);
        if(l>r){
            int t=l;
            l=r;
            r=t;
        }
        segnode ans=query(l,r,1,3000,1);
        int mxi=ans.val;
        printf("Output%d: %d",cs++,mxi);
        while(nxt[mxi]!=mxi){
            mxi=nxt[mxi];
            printf(" %d",mxi);
        }
        printf("\n");

    }
    return 0;
}
