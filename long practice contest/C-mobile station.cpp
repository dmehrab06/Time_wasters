#include <cstdio>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

int segtree[4000005];
//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
void init(int b1, int b2, int e1, int e2, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b1==e1 && b2==e2){
        segtree[node]=0;
        return;
    }
    if(b1>e1 || b2>e2)return;
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
        int right1=node*4;
        int right2=right1+1;
        int left1=right1-2;
        int left2=right1-1;
        int mid1=(b1+e1)/2;
        int mid2=(b2+e2)/2;
        init(b1,b2,mid1,mid2,left1);
        init(b1,mid2+1,mid1,e2,left2);
        init(mid1+1,b2,e1,mid2,right1);
        init(mid1+1,mid2+1,e1,e2,right2);
        segtree[node]=0;
        return;
    }
}

int query(int i1, int j1, int i2, int j2, int b1,int b2, int e1, int e2, int node){
    //int cur=0;
    if(b1>=i1 && e1<=i2 && b2>=j1 && e2<=j2){
        //cur=segtree[node];
        return segtree[node];
    }
    if(e1<i1 || b1>i2 || e2<j1 || b2>j2){
        return 0;
    }
    if(b1>e1 || b2>e2)return 0;
    int right1=node*4;
    int right2=right1+1;
    int left1=right1-2;
    int left2=right1-1;
    int mid1=(b1+e1)/2;
    int mid2=(b2+e2)/2;
    int a=query(i1,j1,i2,j2,b1,b2,mid1,mid2,left1);
    int b=query(i1,j1,i2,j2,b1,mid2+1,mid1,e2,left2);
    int c=query(i1,j1,i2,j2,mid1+1,b2,e1,mid2,right1);
    int d=query(i1,j1,i2,j2,mid1+1,mid2+1,e1,e2,right2);
    return a+b+c+d;
}

void update(int i1, int j1, int i2, int j2, int b1,int b2, int e1, int e2, int node,int toadd){
    if(b1>=i1 && e1<=i2 && b2>=j1 && e2<=j2){
        segtree[node]=segtree[node]+toadd;
        return;
    }
    if(e1<i1 || b1>i2 || e2<j1 || b2>j2){
        return;
    }
    if(b1>e1 || b2>e2)return;
    int right1=node*4;
    int right2=right1+1;
    int left1=right1-2;
    int left2=right1-1;
    int mid1=(b1+e1)/2;
    int mid2=(b2+e2)/2;
    update(i1,j1,i2,j2,b1,b2,mid1,mid2,left1,toadd);
    update(i1,j1,i2,j2,b1,mid2+1,mid1,e2,left2,toadd);
    update(i1,j1,i2,j2,mid1+1,b2,e1,mid2,right1,toadd);
    update(i1,j1,i2,j2,mid1+1,mid2+1,e1,e2,right2,toadd);
    //segtree[node]=segtree[left]+segtree[right];
    segtree[node]=segtree[left1]+segtree[left2]+segtree[right1]+segtree[right2];
    return;
}

int main(){
    int type;
    int S;
    while(scanf("%d",&type)==1 && type!=3){
        if(type==0){
           // int S;
            scanf("%d",&S);
            init(1,1,S,S,1);
        }
        else if(type==1){
            int X,Y,A;
            scanf("%d %d %d",&X,&Y,&A);
            update(X+1,Y+1,X+1,Y+1,1,1,S,S,1,A);
        }
        else if(type==2){
            int L,B,R,T;
            scanf("%d %d %d %d",&L,&B,&R,&T);
            int ans=query(L+1,B+1,R+1,T+1,1,1,S,S,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
