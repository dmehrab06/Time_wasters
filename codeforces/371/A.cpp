#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define float double
#define MAXMOD 100000000
using namespace std;

int main(){
    LLI l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    if(r2<l1 || l2>r1){
        printf("0\n");
    }
    else if(l2>=l1 && r2<=r1){
        LLI ans=(r2-l2+1);
        if(k>=l2 && k<=r2){
            ans--;
        }
        cout<<ans<<"\n";
    }
    else if(l1>=l2 && r1<=r2){
        LLI ans=(r1-l1+1);
        if(k>=l1 && k<=r1){
            ans--;
        }
        cout<<ans<<"\n";
    }
    else{
        if(l2>=l1){
            LLI ans=(r1-l2+1);
            if(k>=l2 && k<=r1){
                ans--;
            }
            cout<<ans<<"\n";
        }
        else if(r2<=r1){
            LLI ans=(r2-l1+1);
            if(k>=l1 && k<=r2){
                ans--;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
