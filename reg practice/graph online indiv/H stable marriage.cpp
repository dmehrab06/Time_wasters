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
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000001

using namespace std;

//0 0
//1 khub besi
//1 khub kom

int boyfree[1005];
int girlfree[1005];
vector<VI>boypref;
vector<VI>girlpref;
int girlproposed[1005][1005];
//int boyproposed[1005][1005];
int boypriority[1005][1005];
void init(int n){
    FREP(i,1,n){
        boyfree[i]=-1;
        girlfree[i]=-1;
        FREP(j,1,n){
            girlproposed[i][j]=-1;
           // boypriority[i][j]=0;
        }
    }
}




int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        init(n);
        boypref.clear();
        girlpref.clear();
        VI line;
        FREP(i,1,(n+3)){
            boypref.PB(line);
            girlpref.PB(line);
        }
        FREP(i,1,n){
            FREP(j,1,n){
                int a;
                scanf("%d",&a);
                girlpref[i].PB(a);
            }
        }
        FREP(i,1,n){
            FREP(j,1,n){
                int a;
                scanf("%d",&a);
                boypref[i].PB(a);
                boypriority[i][a]=j;
            }
        }
        while(true){
            int f=1;
            FREP(i,1,n){
                if(girlfree[i]==-1){
                    f=0;
                    FREP(j,0,(n-1)){
                        int curboy=girlpref[i][j];
                        int prop=0;
                        if(girlproposed[i][curboy]==-1){
                            girlproposed[i][curboy]=1;
                            prop=1;
                            if(boyfree[curboy]==-1){
                                boyfree[curboy]=i;
                                girlfree[i]=curboy;
                            }
                            else{
                                int boytakenby=boyfree[curboy];
                                if(boypriority[curboy][i]<boypriority[curboy][boytakenby]){
                                    girlfree[boytakenby]=-1;
                                    girlfree[i]=curboy;
                                    boyfree[curboy]=i;
                                }
                            }
                        }
                        if(prop){
                            break;
                        }
                    }
                }
            }
            if(f){
                break;
            }
        }
        if(cs>1){
            printf("\n");
        }
        FREP(i,1,n){
            printf("%d\n",girlfree[i]);
        }
        cs++;
    }
    return 0;
}
