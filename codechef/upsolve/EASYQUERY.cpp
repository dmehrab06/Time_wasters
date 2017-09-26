#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


int arr[100005];





int segtree[400005];

void init(int b, int e, int node){
    if(b==e){
        segtree[node]=arr[b];
    }
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(b,mid,left);
    init(mid+1,e,right);
    if(segtree[left]<segtree[right]){
        segtree[node]=segtree[left];
    }
    else{
        segtree[node]=segtree[right];
    }
    //cout<<"setting from range "<<b<<" "<<e<<" segtree sum "<<segtree[node].sum<<"\n";

    }
}

int query(int i, int j, int b, int e, int node){

    if(e<i || b>j){
        return 1000000007;
    }
    if(b>=i && e<=j){

        return segtree[node];
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int mx1=query(i,j,b,mid,left);
    int mx2=query(i,j,mid+1,e,right);
    return min(mx1,mx2);
}
int main(){
    //ios_base::sync_with_stdio(false);
    int N,Q;
    scanf("%d %d",&N,&Q);
    int prevans=0;
    for(int i=1;i<=N;++i){
        scanf("%d",&arr[i]);
    }
    init(1,N,1);
    while(Q--){
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int l,r;
        l = (a * max(prevans, 0) + b)%N + 1;
        r = (c * max(prevans, 0) + d)%N + 1;
        if(l>r){
            swap(l,r);
        }
        int ans=0;
        if(k==1){
            ans=query(l,r,1,N,1);
        }
        else{
            set<int>temp;
            for(int k=l;k<=r;++k){
                temp.insert(arr[k]);
            }
            vector<int>temp2;
            set<int>::iterator it;
            for(it=temp.begin();it!=temp.end();++it){
                temp2.push_back(*it);
            }
            //printf("%d\n",query(l,r,1,N,1));
            int l=temp2.size();
            if(k<=l)
            ans=temp2[k-1];
            else{
                ans=-1;
            }
        }
        prevans=ans;
        printf("%d\n",ans);

    }
    return 0;
}
