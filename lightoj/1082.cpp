#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
 
 
using namespace std;
 
int GCD(int a,int b){
    return a==0?b:GCD(b%a,a);
}
 
string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;
 
}
 
struct myitem{
    int h;
    int w;
    myitem(int a, int b){
        h=a;
        w=b;
        if(h>w){
            int t=h;
            h=w;
            w=t;
        }
    }
};
 
bool mycompare (myitem a, myitem b){
    if(a.h==b.h)return a.w<b.w;
    return a.h<b.h;
}
int arr[100005];
int tree[300020];
void init(int node, int b, int e){
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int l=2*node;
    int r=l+1;
    int m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[node]=min(tree[l],tree[r]);
}
int query(int node, int b, int e, int i, int j){
    if(i<=b && e<=j){
        return tree[node];
    }
    if(e<i || b>j)return 2000000;
    int l=2*node;
    int r=l+1;
    int m=(b+e)/2;
    int m1=query(l,b,m,i,j);
    int m2=query(r,m+1,e,i,j);
    return min(m1,m2);
 
}
int main(){
    int t;
    int c=1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;++i){
            int a;
            scanf("%d",&arr[i]);
        }
        printf("Case %d:\n",c++);
        init(1,1,n);
        while(q--){
            int i,j;
            scanf("%d %d",&i,&j);
            int m=query(1,1,n,i,j);
            printf("%d\n",m);
        }
    }
    return 0;
 
}
