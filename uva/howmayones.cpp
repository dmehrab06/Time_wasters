#include <bits/stdc++.h>
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


//long long int chess[1003][1003];
int getclosest(int n){
    long long int ss=1;
    long long int nextjump=2;
    if(n<=1)return n;
    while(1){
        if((ss+nextjump)>n){
            return ss;
        }
        ss+=nextjump;
        nextjump*=2;
    }
}
map<int ,long long int>twopowones;
vector<int>twopows;
int twolen=0;
long long int findone2(int n){
    int left=n;
    long long int ans=0;
    for(int i=twolen-1;i>=0;--i){
        if(left<=0)break;
        if(twopows[i]<=left){
            ans+=twopowones[twopows[i]];
            ans+=(left-twopows[i]);
            left=left-twopows[i]-1;
        }
    }
    return ans;
}
long long int findone(int n){
    if(twopowones.find(n)!=twopowones.end()){
        return twopowones[n];
    }
    else{
        int closest=getclosest(n);
        int further=n-closest;
        long long int partans=twopowones[closest];
        return partans+(long long int)further+findone(further-1);
    }
}

int main(){
    int cs=1;
    twopowones[0]=0;
    twopows.push_back(0);
    twopowones[1]=1;
    twopows.push_back(1);
    twopowones[3]=4;
    twopows.push_back(3);
    twolen=3;
    int prev=3;
    int now=7;
    int nextjump=8;
    while(now<=2000000000){
        int frontones=now-prev;
        long long int prevones=twopowones[prev];
        long long int thisone=frontones+prevones;
        twopowones[now]=thisone+prevones;
        twopows.push_back(now);
        prev=now;
        now=now+nextjump;
        nextjump*=2;
        twolen++;
    }
   /* map<long long int,long long int>::iterator it;
    for(it=twopowones.begin();it!=twopowones.end();++it){
        cout<<it->first<<" "<<it->second<<"\n";
    }*/
     int a,b;
    while(scanf("%d %d",&a,&b)==2 && !(a==0 && b==0)){
        if(a==0){
            a++;
        }
        long long int ans2=findone2(b);
        long long int ans1=findone2(a-1);
        printf("Case %d: %lld\n",cs++,ans2-ans1);
    }
    return 0;
}
