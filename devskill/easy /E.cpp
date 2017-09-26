/*-------property of the half blood prince-----*/

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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int L[1005][1005];
//int dp[1005][1005];

void init(){
    memset(L,0,sizeof(L));
}

int lcs( char *X, char *Y, int m, int n )
{
   int i, j;
    init();
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int solve(char str[], int n)
{
   // Creata another string to store reverse of 'str'
   char rev[1005];
   for(int i=(n-1);i>=0;--i){
    rev[(n-1)-i]=str[i];
   }
   rev[n]='\0';
   //strcpy(rev, str);
   //strrev(rev);

   // The output is length of string minus length of lcs of
   // str and it reverse
   return (n - lcs(str, rev, n, n));
}

bool ispal(char str[]){
    int l=strlen(str);
    int k=l/2;
    FREP(i,0,k){
        if(str[i]!=str[(l-1-i)])return false;
    }
    return true;
}

char str[1005];
int main()
{
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%s",str);
        int l=strlen(str);

        int ans=solve(str,l);
        if(ispal(str))ans=0;
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;

}
