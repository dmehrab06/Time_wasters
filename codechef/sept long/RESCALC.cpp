#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
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

vector<PII>scores;
int type[105][105];

int calc(int i){
    int sz=type[i][0];
    int arr[8];
    FREP(k,1,7)arr[k]=0;
    FREP(j,1,sz){
        arr[type[i][j]]++;
    }
    int score=sz;
    while(true){
        int lft=0;
        FREP(k,1,6){
            if(arr[k]){
                arr[k]--;
                lft++;
            }
        }
        if(lft==6){
            score+=4;
        }
        else if(lft==5){
            score+=2;
        }
        else if(lft==4){
            score+=1;
        }
        else{
            break;
        }
    }
    return score;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            int tot;
            scanf("%d",&tot);
            type[i][0]=tot;
            FREP(k,1,tot){
                scanf("%d",&type[i][k]);
            }
        }
        FREP(i,1,n){
            int get=calc(i);
          //  cout<<get<<"\n";
            PII pp=make_pair(get,i);
            scores.PB(pp);
        }
        sort(scores.begin(),scores.end());
        int l=scores.size();
        if(l==1){
            printf("chef\n");
        }
        else{
            PII mx1=scores[l-1];
            PII mx2=scores[l-2];
            if(mx1.first==mx2.first){
                printf("tie\n");
            }
            else{
                if(mx1.second==1){
                    printf("chef\n");
                }
                else{
                    printf("%d\n",mx1.second);
                }
            }
        }
        scores.clear();
    }
    return 0;
}
