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
using namespace std;

int representative[20005];
int findrep(int a){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a]);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y){
    int xp,yp;
    xp=findrep(x);
    yp=findrep(y);
    representative[yp]=xp;
}

void init(){
    FREP(i,0,1006){
        representative[i]=i;
    }
}

int carf[1004];
int carb[1004];

int main(){
    int N;
    int cs=1;
    while(scanf("%d",&N)==1 && N){
        init();
        set< PII >car;
        int mustwrong=0;
        FREP(i,1,N){
            int a,b;
            scanf("%d %d",&a,&b);
            PII pp=make_pair(a,b);
            if((a+b+1)>N)mustwrong++;
            else{
                car.insert(pp);
            }
        }
      //  cout<<car.size()<<"\n";
        int baadase=(N-mustwrong)-car.size();
       // cout<<baadase<<"\n";
        set<PII>::iterator it;
        int sz=1;
        for(it=car.begin();it!=car.end();++it){
            carf[sz]=(*it).first;
            carb[sz]=(*it).second;
            sz++;
        }
        FREP(i,1,(sz-1)){
            FREP(j,(i+1),(sz-1)){
                if(i==j)continue;
                if(carf[i]==carf[j] || carb[i]==carb[j]){
                    int up=findrep(i);
                    int vp=findrep(j);
                    if(up!=vp){
                        unionfind(i,j);
                    }
                }
            }
        }
        int correct=0;
        FREP(i,1,(sz-1)){
         //   cout<<representative[i]<<"\n";
            if(representative[i]==i){
                correct++;
            }
        }
        int total=N-(correct+baadase);
        printf("Case %d: %d\n",cs++,total);
    }
    return 0;
}
