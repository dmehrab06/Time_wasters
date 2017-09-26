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

double berber[1000007];

void init(){
    FREP(i,1,1000006){
        berber[i]=log10((double)i);
        berber[i]=berber[i-1]+berber[i];
    }
    FREP(i,1,1000006){
        berber[i]=(int)(berber[i])+1;
    }

}

int main(){
    string f;
    cin>>f;
    init();
    if(f=="1"){
        printf("1\n");
    }
    else if(f=="2"){
        printf("2\n");
    }
    else if(f=="6"){
        printf("3\n");
    }
    else if(f=="120"){
        printf("5\n");
    }
    else if(f=="720"){
        printf("6\n");
    }
    else{
        int l=f.size();
        int ans=-1;
        FREP(i,1,1000006){
            if((int)berber[i]==l){
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

