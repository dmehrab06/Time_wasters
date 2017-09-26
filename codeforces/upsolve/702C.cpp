//algo: binary search
//educational round 702C
#include <bits/stdc++.h>
#define LLI long long int
#define MXX 10000000000
#define MNN -10000000000
using namespace std;

LLI tower[100005];

LLI cities[100005];

int binsearch(LLI city, int l, int h){
  //  cout<<l<<" "<<h<<"\n";
    int mid=(l+h)/2;
    //cout<<mid<<"\n";
    if(city>=tower[mid] && city<=tower[mid+1]){
        return mid;  //eikhane age mid-1 use kore seg fault khaitesilam
        //mid=(l+h)/2 converges left, so i must make something to converge right
        //so mid+1 not mid-1
    }
    else if(city>=tower[mid+1]){
        return binsearch(city,mid+1,h);
    }
    else if(city<=tower[mid]){
        return binsearch(city,l,mid);
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        cin>>cities[i];
    }
    for(int i=2;i<=m+1;++i){
        cin>>tower[i];
    }
    tower[0]=2*MNN;
    tower[1]=MNN;
    tower[m+2]=MXX;
    tower[m+3]=2*MXX;
    LLI dis=-9;
    for(int i=1;i<=n;++i){
        int k=binsearch(cities[i],0,m+3);
      // cout<<k<<"\n";
        LLI curdis=min(abs(cities[i]-tower[k]),abs(cities[i]-tower[k+1]));
        //cout<<curdis<<"\n";
        dis=max(curdis,dis);
    }
    cout<<dis<<"\n";
}
