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
#define MDD 2000000011
using namespace std;

string str5;
string str6;
bool match5(int until){
    string tmp="";
    RFREP(i,500,(500-until+1)){
        tmp.push_back(str5[i]);
    }
    int sz=tmp.size();
    vector<int>ans;
    FREP(i,0,1040)ans.push_back(0);
    FREP(i,0,(sz-1)){
        FREP(j,0,(sz-1)){
            ans[i+j]+=(tmp[i]-'0')*(tmp[j]-'0');
        }
    }
    FREP(i,0,(sz-1)){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    FREP(i,0,(until-1)){
        if((ans[i]+'0')!=str5[500-i])return false;
    }
    return true;
}

void precalc5(){
    FREP(i,0,500){
        str5.push_back('0');
    }
    str5[500]='5';
    int nw=1;
    RFREP(i,499,0){
        nw++;
        int f=0;
        FREP(j,1,9){
            str5[i]=j+'0';
            if(match5(nw)){
                f=1;
                break;
            }
        }
        if(!f){
            str5[i]='0';
        }
    }
}

bool match6(int until){
    string tmp="";
    RFREP(i,500,(500-until+1)){
        tmp.push_back(str6[i]);
    }
    int sz=tmp.size();
    vector<int>ans;
    FREP(i,0,1040)ans.push_back(0);
    FREP(i,0,(sz-1)){
        FREP(j,0,(sz-1)){
            ans[i+j]+=(tmp[i]-'0')*(tmp[j]-'0');
        }
    }
    FREP(i,0,(sz-1)){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    FREP(i,0,(until-1)){
        if((ans[i]+'0')!=str6[500-i])return false;
    }
    return true;
}

void precalc6(){
    FREP(i,0,500){
        str6.push_back('0');
    }
    str6[500]='6';
    int nw=1;
    RFREP(i,499,0){
        nw++;
        int f=0;
        FREP(j,1,9){
            str6[i]=j+'0';
            if(match6(nw)){
                f=1;
                break;
            }
        }
        if(!f){
            str6[i]='0';
        }
    }
}

int main(){
    precalc5();
    precalc6();
    reverse(str5.begin(),str5.end());
    reverse(str6.begin(),str6.end());
    cout<<str5<<"\n";
    cout<<str6<<"\n";
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case #%d:",cs++);
        if(n==1){
            printf(" 0 1 5 6\n");
        }
        else{
            if(str5[n-1]=='0' && str6[n-1]=='0'){
                printf(" Impossible\n");
            }
            else{
                if(str5[n-1]!='0'){
                    printf(" ");
                    RFREP(i,(n-1),0){
                        printf("%c",str5[i]);
                    }
                }
                if(str6[n-1]!='0'){
                    printf(" ");
                    RFREP(i,(n-1),0){
                        printf("%c",str6[i]);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
