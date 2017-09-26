#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000001

using namespace std;

//0 0
//1 khub besi
//1 khub kom

int posa[10003];
int posb[10003];

void init(){
    FREP(i,1,10000){
        posa[i]=-1;
        posb[i]=-1;
    }
}

int shoes[200005];

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        init();
        scanf("%d",&n);
        FREP(i,1,(2*n)){
            int a;
            scanf("%d",&a);
            if(posa[a]==-1){
                posa[a]=i;
            }
            else{
                posb[a]=i;
            }
            shoes[i]=a;
        }
        int swap=0;
        for(int i=2;i<=(2*n);i+=2){
            if(shoes[i-1]==shoes[i]){

            }
            else{
                int milao=shoes[i];
                int ekhonase=shoes[i-1];
                int target,target1,target2;
                target1=posa[milao];
                target2=posb[milao];
                if(target1==i){
                    target=target2;
                }
                else{
                    target=target1;
                }
                int temp=shoes[i-1];
                shoes[i-1]=shoes[target];
                shoes[target]=temp;
                swap++;
                if(posa[ekhonase]==(i-1)){
                    posa[ekhonase]=target;
                }
                else{
                    posb[ekhonase]=target;
                }
                if(posa[milao]==target){
                    posa[milao]=(i-1);
                }
                else{
                    posb[milao]=(i-1);
                }
            }
        }
        printf("%d\n",swap);

    }
    return 0;
}
