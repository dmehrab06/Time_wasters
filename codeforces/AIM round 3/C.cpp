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
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)

using namespace std;
char str[100006];
int main(){
    scanf("%s",str);
    int l=strlen(str)-1;
    int start=-1;
    FREP(i,0,l){
        if(str[i]>'a'){
            start=i;
            break;
        }
    }
    if(start==-1){
        str[l]='z';
        printf("%s\n",str);
    }
    else{
        FREP(i,start,l){
            if(str[i]=='a'){
                break;
            }
            str[i]--;
        }
        printf("%s\n",str);
    }
    return 0;
}
