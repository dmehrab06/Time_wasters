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

char voter[200005];
int hasright[200005];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",voter);
    int d=0,r=0;
    FREP(i,0,(n-1)){
        if(voter[i]=='D')d++;
        else if(voter[i]=='R')r++;
        hasright[i]=1;
    }
    int dbaichaase=d;
    int rbaichaase=r;
    int lastrkatsi=-1;
    int lastdkatsi=-1;
    int cur=0;
    while(true){
      //  cout<<cur<<" "<<dbaichaase<<" "<<rbaichaase<<"\n";
        if(dbaichaase==0 || rbaichaase==0){
            break;
        }
        if(hasright[cur]==0){
            cur=(cur+1)%n;
            continue;
        }
        if(voter[cur]=='D'){
            lastrkatsi=cur;
            while(true){
                lastrkatsi=(lastrkatsi+1)%n;
                if(voter[lastrkatsi]=='R' && hasright[lastrkatsi]==1){
                    hasright[lastrkatsi]=0;
                    //lastrkatsi=lastrkatsi%n;
                //    cout<<cur<<" "<<lastrkatsi<<" re kupailo\n";
                    rbaichaase--;
                    break;
                }
            }
            cur=(cur+1)%n;
        }
        else if(voter[cur]=='R'){
            lastdkatsi=cur;
            while(true){
                lastdkatsi=(lastdkatsi+1)%n;
                if(voter[lastdkatsi]=='D' && hasright[lastdkatsi]==1){
                    hasright[lastdkatsi]=0;
                    //lastdkatsi=lastdkatsi%n;
                  //  cout<<cur<<" "<<lastdkatsi<<" re kupailo\n";
                    dbaichaase--;
                    break;
                }
            }
            cur=(cur+1)%n;
        }
    }
    if(dbaichaase>0){
        printf("D\n");
    }
    else{
        printf("R\n");
    }
    return 0;
}

