
#include <bits/stdc++.h>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
using namespace std;

int main(){
    long long int s = 1;
    int A,B;
    cin>>A>>B;
    int mm = min(A,B);
    FREP(i,1,mm)s=s*i;
    cout<<s<<"\n";
}
