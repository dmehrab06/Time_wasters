#include<bits/stdc++.h>
#define MOD 1000000007
#define MX 100010
#define ll long long
#define sc(n) scanf("%d",&n)
#define pr(m) printf("%d\n",m)
#define pi acos(-1.0)

using namespace std;

struct bot{
    int a;
    int b;
    int c;
};

bool cmp(struct bot p,struct bot q)
{
    if(p.b==q.b)return p.a>q.a;
    return p.b>q.b;
}
int main()
{
    int n;
    cin>>n;

    struct bot botArr[105];
    for(int i=0;i<n;i++)cin>>botArr[i].a;
    for(int i=0;i<n;i++)cin>>botArr[i].b;
  //  for(int i=0;i<n;i++)botArr[i].a=botArr[i].b-botArr[i].a;
    sort(botArr,botArr+n,cmp);
    int ans=0,time=0;
    int cnt=0;
    for(int i=0;i<n;i++){
       // if(botArr[i].a==0)break;
        for(int j=n-1;j>i;j--){
            if(j==i)continue;
            if((botArr[i].b-botArr[i].a)==0)break;
            if(botArr[j].a <= (botArr[i].b-botArr[i].a)){
                    botArr[i].a+=botArr[j].a;
                    time+=botArr[j].a;
                    botArr[j].a=0;
            }
            else {
                botArr[j].a-=(botArr[i].b-botArr[i].a);
                time+=(botArr[i].b-botArr[i].a);
                botArr[i].a=botArr[i].b;

            }
        }
        //cnt++;

    }

    for(int i=0;i<n;++i){
        if(botArr[i].a!=0)cnt++;

    }

    cout<<cnt<<" "<<time<<endl;
    return 0;
}
