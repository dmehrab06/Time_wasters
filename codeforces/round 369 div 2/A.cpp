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

using namespace std;

//Data Structure used: 2D doubly linked list
//store val; up, down, left and right node
//take row+2, col+2 area to avoid null pointer hasty checking
//when swapping two rectangle only outer boundary pointers need to be updated

char seat[1006][10];

int main(){
    int N;
    scanf("%d",&N);
    FREP(i,1,N){
        scanf("%s",seat[i]);
    }
    int f=0;
    FREP(i,1,N){
        if(seat[i][0]=='O' && seat[i][1]=='O'){
            f=1;
            seat[i][0]='+';
            seat[i][1]='+';
            break;
        }
        else if(seat[i][3]=='O' && seat[i][4]=='O'){
            f=1;
            seat[i][3]='+';
            seat[i][4]='+';
            break;
        }
    }
    if(f){
        printf("YES\n");
        FREP(i,1,N){
            printf("%s\n",seat[i]);
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}
