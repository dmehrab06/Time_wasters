/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

//VI div;

int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int n;
    scanf("%d",&n);
    int tot=0;
    FREP(a,1,n){
        FREP(b,(a+1),n){
            int g=gcd(a,b);
            if(n%g)continue;
            int y=1;
            int f=0;
            while(true){
                int oka=b*y;
                if(oka>=n)break;
                else if((n-oka)%a==0){
                    f=1;
                    break;
                }
                y++;
            }
            if(f){
                cout<<a<<" "<<b<<"\n";
                tot++;
            }
        }
    }
    cout<<tot<<"\n";
}
