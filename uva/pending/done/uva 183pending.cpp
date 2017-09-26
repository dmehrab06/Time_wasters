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
using namespace std;

char type[3];
char mat[202][202];
char str[202];
int it;

void fillupmatrix(int rl,int rh,int cl,int ch, char c){
    FREP(i,rl,rh)
        FREP(j,cl,ch)mat[i][j]=c;
    return;
}

void solvebtod(int rl, int rh, int cl , int ch){
    if(rl>rh || cl>ch)return;
    if(rl==rh && cl==ch){
        printf("%c",mat[rl][cl]);
        return;
    }
    char a=mat[rl][cl];
    int f=1;
    FREP(i,rl,rh){
        FREP(j,cl,ch){
            if(mat[i][j]!=a){
                f=0;
                break;
            }
        }
        if(!f)break;
    }
    if(f){
        printf("%c",a);
        return;
    }
    else{
        int rm=(rl+rh)/2;
        int cm=(cl+ch)/2;
        printf("D");
        solvebtod(rl,rm,cl,cm);
        solvebtod(rl,rm,cm+1,ch);
        solvebtod(rm+1,rh,cl,cm);
        solvebtod(rm+1,rh,cm+1,ch);
    }
}

void solvedtob(int rl, int rh, int cl , int ch){
    if(rl>rh || cl>ch)return;
    if(str[it]!='D'){
        fillupmatrix(rl,rh,cl,ch,str[it]);
        it++;
        return;
    }
    else{
        it++;
        int rm=(rl+rh)/2;
        int cm=(cl+ch)/2;
        //printf("D");
        solvedtob(rl,rm,cl,cm);
        solvedtob(rl,rm,cm+1,ch);
        solvedtob(rm+1,rh,cl,cm);
        solvedtob(rm+1,rh,cm+1,ch);
        //return;
    }

}

int main(){
    int r,c;
    while(scanf("%s",type)==1 && type[0]!='#'){
        scanf("%d %d",&r,&c);
        scanf("%s",str);
        if(type[0]=='B'){
            int p=0;
            FREP(i,1,r){
                FREP(j,1,c){
                    mat[i][j]=str[p];
                    p++;
                }
            }
            printf("D%4d%4d\n",r,c);
            solvebtod(1,r,1,c);
        }
        else if(type[0]=='D'){
            //solve
            printf("B%4d%4d\n",r,c);
            it=0;
            solvedtob(1,r,1,c);
            FREP(i,1,r)FREP(j,1,c)printf("%c",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
