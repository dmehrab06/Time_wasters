#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define mx 160003
using namespace std;

struct vo
{
    int sum;
    int prop;
} tree[mx * 3];;
int n;
map<int,int>m;
vector<int>v;


int query(int node, int b, int e, int i, int j,int cr=0)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node].sum+cr*(e-b+1); //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j,cr+tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j,cr+tree[node].prop);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল
}
void update(int node, int b, int e, int i,int j, int newvalue)
{
    if (i > e || j < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j) {
           //রিলেভেন্ট সেগমেন্ট
                 tree[node].sum=tree[node].sum+newvalue;

                  tree[node].prop+=1;
        return;
    }

    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, newvalue);
    update(Right, mid + 1, e, i, j, newvalue);
    tree[node].sum = (tree[Left].sum + tree[Right].sum+tree[node].prop);
}
int main()
{
    int a,b,c,d,e,f,i,j,T,p,q;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {    m.clear();
         memset(tree,0,sizeof(tree));
         memset(arr,-1,sizeof(arr));
         memset(bhol,0,sizeof(bhol));


        scanf("%d %d",&a,&b);



     for(j=1;j<=a;j++)
     {
         scanf("%d %d",&arr[j][0],&arr[j][1]);

         v.push_back(arr[j][0]);
         v.push_back(arr[j][1]);

     }
     for(j=1;j<=b;j++)
     {
       scanf("%d",&e);
       bhol[j]=e;
       v.push_back(e);

     }

     sort(v.begin(),v.end());
     e=v.size();
     p=1;
     for(j=0;j<e;j++)
     {   if(v[j]==v[j-1])
           {
               m[v[j]]=m[v[j-1]];
           }
        else
         {m[v[j]]=p;
          p++;
         }
     }

     for(j=1;j<=a;j++)
     {
         update(1,1,mx,m[arr[j][0]],m[arr[j][1]],1);
     }
     printf("Case %d:\n",i+1);


     for(j=1;j<=b;j++)
     {

       printf("%d\n",query(1,1,mx,m[bhol[j]],m[bhol[j]]));
     }

    }

    return 0;
}
