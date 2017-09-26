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
#define LLI unsigned long long int
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

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

char s[50007];

int main(){
    scanf("%s",s);
    int l=strlen(s);
    if(l<26){
        printf("-1\n");
        return 0;
    }
    int cnt[26];
    int f=0;
    for(int i=0;(i+26-1)<l;++i){
        for(int k=0;k<26;++k){
            cnt[k]=0;
        }
        for(int k=0;k<26;++k){
            if(ISCAP(s[i+k])){
                cnt[s[i+k]-'A']++;
            }
        }
        int hobe=1;
        FREP(k,0,25){
            if(cnt[k]>1){
                hobe=0;
                break;
            }
        }
        if(hobe){
            vector<int>ok;
            FREP(k,0,25){
                if(cnt[k]==0){
                    ok.push_back(k);
                }
            }
            int asi=0;
            for(int k=0;k<26;++k){
                if(!ISCAP(s[i+k])){
                    s[i+k]=ok[asi++]+'A';
                }
            }
            f=1;
            break;
        }
    }
    if(!f){
        printf("-1\n");
    }
    else{
        FREP(i,0,(l-1)){
            if(!ISCAP(s[i])){
                s[i]='A';
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
