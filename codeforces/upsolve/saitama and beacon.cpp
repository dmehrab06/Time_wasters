#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

//ALGO used: dp and binary search
//solution idea:
//dp[i] denotes the number of beacons that can be destroyed activating beacon at position i at first
//base case dp[1]=0
//for each i find the rightmost survivor k then dp[i]=dp[k]+(i-(k+1))
//then from right to left destroy one by one increase count
//ans=min(ans,count+dp[cur-1])
//not sorted -_- aiccha eijonno WA khaisi
vector<PII>beacon;
//int beacon[100006];
//int power[100006];
int dp[100006];
int binsearch(int l, int r, int z){ //z is the leftmost beacon that can be destroyed
    int mid=(l+r)/2;
    if(beacon[mid].first<z){
        if(beacon[mid+1].first>=z){
            return mid;
        }
        else{
            return binsearch(mid+1,r,z);
        }
    }
    return binsearch(l,mid,z);
}

int solve(int n){
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;++i){
        int k=binsearch(0,i+1,beacon[i].first-beacon[i].second);
        dp[i]=dp[k]+(i-(k+1));
    }
    //for(int i=1;i<=n;++i){
      //  cout<<dp[i]<<" ";
    //}
   // cout<<"\n";
    int cnt=1;
    int ans=dp[n];
    for(int i=n;i>=1;--i){
        ans=min(ans,cnt+dp[i-1]);
        cnt++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    beacon.push_back(make_pair(MNN,0));
    for(int i=1;i<=n;++i){
        int b,p;
        scanf("%d %d",&b,&p);
        beacon.push_back(make_pair(b,p));
    }
    sort(beacon.begin(),beacon.end());

   cout<<solve(n)<<"\n";
    return 0;
}
