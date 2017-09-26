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

VI red;
VI blue;

void parse(char *seg){
    int l=strlen(seg);
    int s=0;
    FREP(i,0,(l-2)){
        s=s*10+seg[i]-'0';
    }
    if(seg[l-1]=='B'){
        blue.PB(s);
    }
    else{
        red.PB(s);
    }
}

char seg[10];
int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        LLI a,b;
        cin>>a>>b;
        LLI area=a*b;
        if(area%6==0){
            if(min(a,b)<2){
                printf("No\n");
            }
            else{
                printf("Yes\n");
            }
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
