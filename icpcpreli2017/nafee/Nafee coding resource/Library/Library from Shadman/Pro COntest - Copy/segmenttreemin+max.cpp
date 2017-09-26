#include <bits/stdc++.h>
#define mx 100023
using namespace std;
int arr[mx],arr1[mx];
int tree[mx * 3][2];
int n;
struct hi
{
    int m;
    int n;
}hol[100002]
;
bool comp(hi a,hi b)
{
    if(a.m!=b.m)
        return a.m<b.m;
    return a.n<b.n;
}
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node][0] =1000000;
        tree[node][1]=-1;



        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node][0] = min(tree[Left][0],tree[Right][0]);
    tree[node][1] = max(tree[Left][1],tree[Right][1]);
}
int query(int node, int b, int e, int l,int i, int j)
{   int res;
    if ((i > e || j < b) && l==2)
        return 0;
    if ((i > e || j < b) && l==1)
        return 1000000;     //বাইরে চলে গিয়েছে
    if (b >= i && e <= j && l==1)
        return tree[node][0]; //রিলেভেন্ট সেগমেন্ট
    if (b >= i && e <= j && l==2)
        return tree[node][1]; //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, l,i, j);
    int p2 = query(Right, mid + 1, e, l,i, j);
    if(l==1)
    {
        res=min(p1,p2);
    }
    else
        res=max(p1,p2);
    return res;

     //বাম এবং ডান পাশের যোগফল
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) {
            tree[node][0]=newvalue;
            tree[node][1]=newvalue;
        return;
    }
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i,newvalue);
    update(Right, mid + 1, e, i,newvalue);
    tree[node][0] = min(tree[Left][0],tree[Right][0]);
    tree[node][1]= max(tree[Left][1],tree[Right][1]);
}
int y[100001][3];
map<int,int>m;
int main()

{  int a,b,c,d,e,i,j,p,q;
   int arr[100001],z[100001];

   cin>>a;
   for(i=1;i<=a;i++)
   {
       scanf("%d",&arr[i]);
       hol[i].m=arr[i];
       hol[i].n=i;


   }

   sort(hol+1,hol+a+1,comp);

   for(i=1;i<=a;i++)
   {   m[i]=hol[i].m;
       arr[hol[i].n]=i;

   }


   init(1,1,a);

   update(1,1,a,arr[1],arr[1]);


   for(i=2;i<=a;i++)
   {
       d=arr[i];
       p=query(1,1,a,2,1,d);
       q=query(1,1,a,1,d,mx*3);

       if(p!=0 && y[p][2]==0)
       {
           y[p][2]=1;
           z[d]=p;

           update(1,1,a,d,d);
           continue;

       }
       q=query(1,1,a,1,d+1,a);
       y[q][1]=1;
       z[d]=q;
       update(1,1,a,d,d);


   }
   for(i=2;i<=a;i++)
   {
       printf("%d ",m[z[arr[i]]]);
   }
   return 0;
}
