#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b){
    if(a==0)return b;
    return gcd(b%a,a);
}

long long int howManyTimes(long long int bigNumerator,long long int bigDenominator ,long long int smallNumerator,long long int smallDenominator)
{
    //cout<<"ekhane\n";

   cout<<bigNumerator<<" "<<bigDenominator<<" "<<smallNumerator<<" "<<smallDenominator<<"\n";
   if(bigDenominator==1 && smallDenominator==1){
    if(bigNumerator==smallNumerator){
        return -1;
    }
    else{
        return 1;
    }
   }
   else if(bigDenominator==1){
    return smallDenominator;
   }
   else if(smallDenominator==1){
    return -1;
   }
    long long int LCM_deno=(smallDenominator*bigDenominator)/gcd(smallDenominator,bigDenominator);

    bigNumerator %= bigDenominator;
    smallNumerator %= smallDenominator;

    bigNumerator *= (LCM_deno/bigDenominator);
    smallNumerator *= (LCM_deno/smallDenominator);
    long long int smallNumer2=LCM_deno-smallNumerator;

    if(bigNumerator%smallNumerator==0)
        return bigNumerator/smallNumerator;
    else if(bigNumerator%smallNumer2==0)
        return bigNumerator/smallNumer2;
    else
        return -1;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int N,SUM;
        cin>>N>>SUM;
        long long int A=N;
        long long int B=N*(N-1)/2;
        if(B==0){
            cout<<"Yes\n";
            continue;
        }
        long long int C=SUM;
        //long long int G=gcd(A,gcd(B,C));
        //A/=G;
        //B/=G;
        //C/=G;
     //   cout<<A<<" "<<B<<" "<<C<<"\n";
        //long long int G2=gcd(A,B);
        if(false){
            cout<<"No\n";
        }
        else if(C<max(A,B)){
            cout<<"No\n";
        }
        else{
            long long int Xleft=C/A;
            //if(Xleft)
            long long int Ytoplob=C/(gcd(C,B));
            long long int Ytophor=B/(gcd(C,B));
            long long int declob=A/gcd(A,B);
            long long int dechor=B/gcd(A,B);
            long long int nn=howManyTimes(Ytoplob,Ytophor,declob,dechor);
            cout<<nn<<"\n";
            if(nn==-1 || nn>Xleft){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
        }
        //X ar Y ber korte hobe

    }
    return 0;
}
