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

set<PII>oka;

int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int n;
    scanf("%d",&n);
    //int tot=0;
    FREP(a,1,n){
        for(int aa=a;aa<=n;aa+=a){
            int by=n-aa;
            int sq=sqrt(by);
            FREP(bb,1,sq){
                if(by%bb==0){
                    if(bb>a){
                        //cout<<a<<" "<<bb<<"\n";
                        //tot++;
                        oka.insert(make_pair(a,bb));

                    }
                    int jj=by/bb;
                    if(jj>a && jj!=bb){
                        //cout<<a<<" "<<jj<<"\n";
                        oka.insert(make_pair(a,jj));
                    }
                }
            }
        }
    }
    cout<<oka.size()<<"\n";
}
