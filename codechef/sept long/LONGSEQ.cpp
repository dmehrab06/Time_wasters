#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

string chk;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>chk;
        int z=0;
        int o=0;
        int l=chk.size();
        FREP(i,0,(l-1)){
            if(chk[i]=='1'){
                o++;
            }
            else{
                z++;
            }
        }
        if(z==0){
            if(o==1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else if(o==0){
            if(z==1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            if(o==1 || z==1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
