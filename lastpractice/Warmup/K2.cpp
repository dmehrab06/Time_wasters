#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int Maxn=1000005;
int s[Maxn],n,p,c,h,i,a[Maxn],b[Maxn],dig[Maxn],max1,max2,cnt,ext,ans;

bool Judge(int pos){
  int k=s[h]-cnt;
  if (k<=0) k+=ext;
  return !(s[max1]>=k || s[max2]>=k || (b[1]!=h && s[b[1]]>=k));
}

int main(){
  //freopen("kabaleo.in","r",stdin);
  //freopen("kabaleo.out","w",stdout);
  scanf("%d%d%d%d",&n,&p,&c,&h);
  for (i=1;i<=n;i++){
    scanf("%d",&a[i]);
    s[a[i]]++;
  }
  for (i=1,cnt=p-1;i<=p;i++){
    scanf("%d",&b[i]);
    if (i>1 && b[i]!=h) s[b[i]]++;
    if (i>1 && b[i]==h) cnt--;
  }
  if (n==1){
    if (b[p]!=h) printf("0\n");
      else printf("1\n1\n");
    return 0;
  }
  ext=(b[p]==h);
  for (i=1;i<=c;i++)
  if (i!=h){
    if (s[i]>s[max1]) max2=max1, max1=i;
    else if (s[i]>s[max2]) max2=i;
  }
  //cout<<max1<<" "<<max2<<"\n";
  //for(int i=1;i<=c;++i){
    //cout<<s[i]<<" ";
  //}
  //cout<<"\n";
  s[b[1]]++;
  for (i=1,ans=0;i<=n;i++){
    s[a[i]]--;
    if (Judge(i)) dig[ans++]=i;
    s[a[i]]++;
  }
  printf("%d\n",ans);
  for (i=0;i<ans;i++)
    printf("%d\n",dig[i]);
  return 0;
}
