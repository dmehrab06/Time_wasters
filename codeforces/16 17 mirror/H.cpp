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

char all[103][103];
int len[103];
int todo[103];
char pattern[103];
int leftout[103];

bool matches(int id){
    int lid=strlen(all[id]);
    int ll=strlen(pattern);
    if(lid!=ll)return false;
    bool b=true;
    FREP(i,0,(ll-1)){
        if(pattern[i]=='?')continue;
        else if(pattern[i]!=all[id][i]){
            b=false;break;
        }
    }
    return b;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        scanf("%s",all[i]);
        len[i]=strlen(all[i]);
        leftout[i]=1;
    }
    FREP(i,1,m){
        scanf("%d",&todo[i]);
        leftout[todo[i]]=0;
    }
    int l=len[todo[1]];
    FREP(i,2,m){
        if(len[todo[i]]!=l){
            printf("No\n");
            return 0;
        }
    }
    FREP(cur,0,(l-1)){
        char here=all[todo[1]][cur];
        int f=1;
        FREP(i,2,m){
            if(all[todo[i]][cur]!=here){
                f=0;
                break;
            }
        }
        if(f){
            pattern[cur]=here;
        }
        else{
            pattern[cur]='?';
        }
    }
    pattern[l]='\0';
    FREP(i,1,n){
        if(leftout[i]==1){
            if(matches(i)){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    printf("%s\n",pattern);
    return 0;
}
