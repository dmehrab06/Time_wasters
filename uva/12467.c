#define MAX_N 1000003
#include <stdio.h>
#include <string.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


char T[MAX_N],P[MAX_N];
char ans[MAX_N];

int b[MAX_N], n, m;
void kmpPreprocess() {
    int i = 0;
    int j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j =b[j];
        i++; j++;
        b[i] = j;
    }
}
int mxmatched;
void kmpSearch() {

int i = 0, j = 0;

    while (i < n) {

        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;

        if(j>mxmatched){
            mxmatched=j;
        }
        if (j == m) {

            j = b[j];
        }
    }
}



int main(){

    int t;
    scanf("%d ",&t);

    while(t--){
        scanf("%s",P);
        n=strlen(P);
        int f=1;
        int pal;
        int tocheck=n/2;
        for(pal=0;pal<=tocheck;++pal){
            if(P[pal]!=P[n-pal-1]){
                f=0;
                break;
            }
        }
        if(f){
            printf("%s\n",P);
            continue;
        }
        m=n;
        int j=n-1;
        T[m]='\0';
        int i;
        for(i=0;i<m;++i){
            T[i]=P[j];
            j--;
        }
        mxmatched=-1;
        kmpPreprocess();
        kmpSearch();

        ans[mxmatched]='\0';
        int k=0;
        for(j=mxmatched-1;j>=0;--j){
            ans[k]=P[j];
            k++;
        }
        printf("%s\n",ans);

    }
    return 0;
}

