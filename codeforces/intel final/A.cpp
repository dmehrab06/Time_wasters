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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int arr[12]={0,3,0,-4,2,3,-5,3,-4,2,3,-5};
string arr2[7]={"saturday","sunday","monday","tuesday","wednesday","thursday","friday"};
string a1,a2;
int main(){
    cin>>a1>>a2;
    int id1,id2;
    FREP(i,0,6){
        if(a1==arr2[i])id1=i;
        if(a2==arr2[i])id2=i;
    }
    int f=0;
    FREP(i,1,11){
        int nxt=id1+arr[i];
        if(nxt>=7){
            nxt-=7;
        }
        else if(nxt<0){
            nxt+=7;
        }
        if(nxt==id2){
            f=1;
            break;
        }
    }
    if(f){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
