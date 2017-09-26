#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)

using namespace std;

//Data Structure used: 2D doubly linked list
//store val; up, down, left and right node
//take row+2, col+2 area to avoid null pointer hasty checking
//when swapping two rectangle only outer boundary pointers need to be updated

LLI grid[503][503];

int main(){
    int N;
    scanf("%d",&N);
    FREP(i,1,N){
        FREP(j,1,N){
            cin>>grid[i][j];
        }
    }
    if(N==1){
        printf("1\n");
        return 0;
    }
    if(N%2==0){
        //can affect one row and one col
        //and maybe a diagonal
        int afr,afc; //afffected rw, col;
        FREP(i,1,N){
            FREP(j,1,N){
                if(grid[i][j]==0){
                    afr=i;
                    afc=j;
                }
            }
        }
        LLI need=0;
        FREP(i,1,2){
            if(i==afr){
                continue;
            }
            FREP(j,1,N){
                need+=grid[i][j];
            }
            break;
        }
        LLI sum1=0,sum2=0;
        FREP(i,1,N){
            sum1+=grid[afr][i];
        }
        FREP(i,1,N){
            sum2+=grid[i][afc];
        }
        if(sum1!=sum2){
            printf("-1\n");
            return 0;
        }
        if(afr==afc){
            //affected diag1;
            LLI sum3=0;
            FREP(i,1,N){
                sum3+=grid[i][i];
            }
            if(sum1!=sum3){
                printf("-1\n");
            }
            else{
                LLI ans=need-sum3;
                if(ans<1){
                    printf("-1\n");
                }
                else{
                    cout<<ans<<"\n";
                }
            }
        }
        else if((afr+afc)==(N+1)){
            //affected diag2;
            LLI sum3=0;
            FREP(i,1,N){
                sum3+=grid[i][(N+1)-i];
            }
            if(sum1!=sum3){
                printf("-1\n");
            }
            else{
                LLI ans=need-sum3;
                if(ans<1){
                    printf("-1\n");
                }
                else{
                    cout<<ans<<"\n";
                }
            }
        }
        else{
            //no diag affected;
            LLI ans=need-sum1;
            if(ans<1){
                printf("-1\n");
            }
            else{
                cout<<ans<<"\n";
            }
        }
    }
    else{
        //odd;
        int afr,afc; //afffected rw, col;
        FREP(i,1,N){
            FREP(j,1,N){
                if(grid[i][j]==0){
                    afr=i;
                    afc=j;
                }
            }
        }
        //jodi middle ta hoy sob affected;
        LLI need=0;
        FREP(i,1,2){
            if(i==afr){
                continue;
            }
            FREP(j,1,N){
                need+=grid[i][j];
            }
            break;
        }
        int mid=(N+1)/2;
        if(afr==mid && afc==mid){
            //sob affected , sum soman hoilei kebol 1, naile baad
            LLI globsum=0;
            FREP(i,1,N){
                globsum+=grid[i][i];
            }
            LLI sum=0;
            FREP(i,1,N){
                sum+=grid[i][(N+1)-i];
            }
            if(sum!=globsum){
                printf("-1\n");
                return 0;
            }
            LLI sum1=0, sum2=0;
            FREP(i,1,N){
                sum1+=grid[afr][i];
            }
            FREP(i,1,N){
                sum2+=grid[i][afc];
            }
            if(sum1!=sum2 || (sum1!=globsum)){
                printf("-1\n");
                return 0;
            }
            LLI ans=need-sum1;
            if(ans<1){
                printf("-1\n");
            }
            else{
                cout<<ans<<"\n";
            }
        }
        else{
            //eibar ek diagonal e max
            LLI sum1=0,sum2=0;
            FREP(i,1,N){
                sum1+=grid[afr][i];
            }
            FREP(i,1,N){
                sum2+=grid[i][afc];
            }
            if(sum1!=sum2){
                printf("-1\n");
                return 0;
            }
            if(afr==afc){
                //affected diag1;
                LLI sum3=0;
                FREP(i,1,N){
                    sum3+=grid[i][i];
                }
                if(sum1!=sum3){
                    printf("-1\n");
                }
                else{
                    LLI ans=need-sum3;
                    if(ans<1){
                        printf("-1\n");
                    }
                    else{
                        cout<<ans<<"\n";
                    }
                }
            }
            else if((afr+afc)==(N+1)){
                //affected diag2;
                LLI sum3=0;
                FREP(i,1,N){
                    sum3+=grid[i][(N+1)-i];
                }
                if(sum1!=sum3){
                    printf("-1\n");
                }
                else{
                    LLI ans=need-sum3;
                    if(ans<1){
                        printf("-1\n");
                    }
                    else{
                        cout<<ans<<"\n";
                    }
                }
            }
            else{
                //no diag affected;
                LLI ans=need-sum1;
                if(ans<1){
                    printf("-1\n");
                }
                else{
                    cout<<ans<<"\n";
                }
            }
        }
    }
}
