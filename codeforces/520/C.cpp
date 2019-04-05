/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define MDD 1000000007
using namespace std;

char st[100005];
int arr[100005];

void init(int n){
    scanf("%s",st);
    for(int i  = 1; i<=n; ++i){
        arr[i] = st[i-1]-'0';
    }
    arr[0] = 0;
    for(int i = 1; i<=n; ++i){
        arr[i] = arr[i] + arr[i-1];
    }
    //for(int i = 1; i<=n; ++i){
      //  cout<<arr[i]<<"\n";
    //}
}

int getone(int l, int r){
    return (arr[r] - arr[l-1]);
}

long long bigmod(int pau, int mdd){
    if(pau==0)return 1;
    if(pau==1)return 2;
    long long ret = bigmod(pau/2,mdd);
    if((pau%2)==0){
        return (ret*ret)%mdd;
    }
    else{
        return (((ret*2)%mdd)*ret)%mdd;
    }
}

long long score(int oo, int zz){
    //cout<<oo<<" "<<zz<<"\n";
    long long s1 = bigmod(oo,MDD)-1;
    long long s2 = bigmod(zz,MDD)-1;
    s1 = (s1+(s1*s2)%MDD)%MDD;
    return s1;
}

int main()
{
    int n;
    int q;
    
    scanf("%d",&n);
    scanf("%d",&q);
    init(n);
    for(int i  = 1; i<=q; ++i){
        int l, r;
        scanf("%d %d",&l,&r);
        int gg = getone(l,r);
        int zz = (r-l+1)-gg;
        long long s = score(gg,zz);
        printf("%lld\n",s);
    }
    return 0;
}
