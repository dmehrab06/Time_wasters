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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
int poss[5]={1,10,100,1000,10000};
int main(){
    int player,round;
    while(scanf("%d %d",&player,&round)==2){
        LLI laav=0;
        LLI paise=0;
        FREP(i,1,round){
            LLI budget;
            cin>>budget;
            LLI sum=0;
            LLI his;
            LLI sum2=0;
            FREP(i,1,player){
                int val;
                scanf("%d",&val);
                sum2+=val;
                if(i==1){
                    his=val;
                }
                if(i!=1){
                    sum+=val;
                }
            }
            if(sum2<=budget){
                paise+=his;
            }
            if(sum<budget){
                int idx=0;
                FREP(i,1,4){
                    if((sum+poss[i])>budget){
                        break;
                    }
                    else{
                        idx=i;
                    }
                }
                laav+=poss[idx];
            }

        }
        printf("%lld\n",(laav-paise));
    }
    return 0;
}
