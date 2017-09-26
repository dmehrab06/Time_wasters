#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#define VALID(A,N) (((A)>=1 && (A)<=N))
using namespace std;
double pi=acos(-1.0);
double firstradi=sqrt(50.0/pi);

int main(){
    for(int i=0;i<10005;++i){
        sieve[i]=0;
    }
    sieve[1]=1;
    sieve[0]=1;
    vector<int>primes;
    for(int i=2;i<10005;++i){
        if(sieve[i]==0){
            primes.push_back(i);
            for(int j=i+i;j<10005;j+=i){
                sieve[j]=1;
            }
        }
    }

    int n;
    int l=primes.size();
    while(cin>>n && n!=0){
        int fp=-1;
        int bp=0;
        int s=0;
        int way=0;
        while(1){
            int f=0;
            while(s<=n && (fp+1)<l){
                s+=primes[++fp];
                if(s==n){
                    way++;

                }
                f=1;
            }
            while(s>=n && bp<l){
                s-=primes[bp++];
                if(s==n){
                    way++;

                }

                f=1;
            }
            if(!f){
                break;
            }
        }
        cout<<way<<"\n";
    }
    return 0;
}
