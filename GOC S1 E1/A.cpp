//ds--
//algo--implementation

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
char s[100005];
char t[10005];
int main(){
    int ts;
    scanf("%d",&ts);
    while(ts--){
        scanf("%s",s);
        int l=strlen(s)-1;
        int tl=0;
        FREP(i,0,l){
            if(ISSML(s[i])){
                t[tl]=s[i];
                tl++;
            }
            else if(ISNUM(s[i])){
                int todo=s[i]-'0'-1;
                int curl=tl;
                FREP(k,1,todo)
                    FREP(j,0,(curl-1))
                        t[tl++]=t[j];
            }
        }
        t[tl]='\0';
        //printf("%s\n",t);
        int q;
        scanf("%d",&q);
        while(q--){
            int x;
            scanf("%d",&x);
            if(x>tl){
                printf("-1\n");
            }
            else{
                printf("%c\n",t[x-1]);
            }
        }
    }
    return 0;
}
