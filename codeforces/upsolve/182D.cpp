#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
using namespace std;
//credit:geeksforgeeks

void solve(char str[], int M, int lps[])
{
    int len = 0;
    int i=1;

    lps[0] = 0;
    while (i < M){
       if (str[i] == str[len]){
           len++;
           lps[i] = len;
           i++;
       }
       else  {
          if (len != 0) {
            len = lps[len-1];
          }
          else{
             lps[i] = 0;
             i++;
          }
       }
    }
}

int MYLEN=-1;
bool isRepeat(char str[])
{
    int n = strlen(str);
    int lps[n];

   solve(str, n, lps);

   int len = lps[n-1];

    if(len>0 && n%(n-len)==0){
        //cout<<(n-len)<<"\n";
        MYLEN=(n-len);
        return true;
    }
    else{
        return false;
    }
}

char txt1[100006];
char txt2[100006];
char reptxt1[100006];
char reptxt2[100006];
int main()
{
    scanf("%s %s",txt1,txt2);
    bool t1=isRepeat(txt1);
    if(!t1){
        MYLEN=strlen(txt1);
    }
    int l1=strlen(txt1);
    int val1=l1/MYLEN;
    FREP(i,0,(MYLEN-1)){
        reptxt1[i]=txt1[i];
    }
    reptxt1[MYLEN]='\0';

    bool t2=isRepeat(txt2);
    if(!t2){
        MYLEN=strlen(txt2);
    }
    int l2=strlen(txt2);
    int val2=l2/MYLEN;
    FREP(i,0,(MYLEN-1)){
        reptxt2[i]=txt2[i];
    }
    reptxt2[MYLEN]='\0';
    if(strcmp(reptxt1,reptxt2)!=0){
        printf("0\n");
        return 0;
    }
    map<int,int>div;
    FREP(i,1,val1){
        if(val1%i==0){
            div[i]++;
        }
    }
    FREP(i,1,val2){
        if(val2%i==0){
            div[i]++;
        }
    }
    int cnt=0;
    map<int,int>::iterator it;
    for(it=div.begin();it!=div.end();++it){
        if(it->second>1)cnt++;
    }
    cout<<cnt<<"\n";
   return 0;
}
