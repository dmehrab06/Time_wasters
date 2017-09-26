/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<PII>rating;

int main(){
    int n;
    string dir;
    cin>>n;
    int x=0;
    int innorth=1;
    int insouth=0;
    int offset;
    string sth="South";
    string nth="North";
    int f=1;
    FREP(i,1,n){
        cin>>offset>>dir;
        if(innorth){
            if(dir!=sth){
                f=0;
               // break;
            }
        }
        else if(insouth){
            if(dir!=nth){
                f=0;
               // break;
            }
        }
        if(dir==nth){
            x-=offset;
            if(x<0){
                f=0;
              //  break;
            }
        }
        if(dir==sth){
            x+=offset;
            if(x>20000){
                f=0;
              //  break;
            }
        }
        if(x==0){
            innorth=1;
            insouth=0;
        }
        else if(x==20000){
            insouth=1;
            innorth=0;
        }
        else{
            innorth=0;
            insouth=0;
        }
    }
    if(f && innorth){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}


