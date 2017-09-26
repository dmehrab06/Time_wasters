#include <iostream>
#include <cmath>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

unsigned long long int solve(unsigned long long int l, unsigned long long int h,unsigned long long int n){
    cout<<"in "<<l<<" "<<h<<"\n";
    unsigned long long int mid=(l+h)/2;
    unsigned long long int a=mid*(mid+1)/2;
    if(a==n){
        return a;
    }
    if(a<n){
        unsigned long long int nxt=a/mid;
        nxt=nxt*(mid+2);
        if(nxt<=n){
            return solve(mid+1,h,n);
        }
        else{
            return a;
        }
    }
    return solve(l,mid-1,n);
}

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        unsigned long long int n;
        cin>>n;
        unsigned long long int ans=solve(1,n,n);
        cout<<"Case #"<<cs++<<": "<<ans<<"\n";
    }
    return 0;
}
