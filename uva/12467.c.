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
// T = text, P = pattern
int b[MAX_N], n, m;
// b = back table, n = length of T, m = length of P
void kmpPreprocess() {
//
    int i = 0;
    int j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j =b[j];
        i++; j++;
        b[i] = j; // observe i = 8, 9, 10,
    }
}
int mxmatched;
void kmpSearch() {
// this is similar as kmpPreprocess(), but on string T
int i = 0, j = 0;
// starting values
    while (i < n) {
    // search through string T
        while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++;
    // if same, advance both pointers
        if(j>mxmatched){
            mxmatched=j;
        }
        if (j == m) {
        // a match found when j == m
          //  printf("P is found at index %d in T\n", i - j);
            j = b[j];
        // prepare j for the next possible match
        }
    }
}



int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d ",&t);

    while(t--){
        scanf("%s",P);
        n=strlen(P);
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
        //string ans="";
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

