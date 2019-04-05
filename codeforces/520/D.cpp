/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define MDD 1000000007
using namespace std;

int sieve[1000005];

vector<int>twopw;

void sv(){
    for(int i = 2; i<=1000000; ++i){
        if(sieve[i]==0){
            sieve[i] = i;
            for(int j = (i+i); j<=1000000; j+=i){
                if(sieve[j]==0){
                    sieve[j] = i; 
                }
            }    
        }
        
    }
    int t = 1;
    for(int i = 0; i<32; ++i){
        twopw.push_back(t);
        t = t<<1;
    }
}

long long solve(int n){
    int sq = sqrt(n);
    long long int s = 0;
    int smallest = -1;
    for(int i = 2; i<=sq; ++i){
        if((n%i)==0){
            if(smallest==-1){
                smallest = i;
            }
            else{
                smallest = min(smallest,i);
            }
            s = s+i;
            int j = n/i;
            if(i!=j){
                s = s+j;
            }
        }
    }
    if(smallest==-1)return 0;
    s = s*4;
    //cout<<s<<"\n";
    int div = (n-1)/smallest;
    //cout<<div<<"\n";
    long long another = div*(div+1)/2;
    s = s+(another-1)*4;
    return s;
}

int main(){
    int n;
    scanf("%d",&n);
    long long ans = solve(n);
    cout<<ans<<"\n";
    return 0;
}