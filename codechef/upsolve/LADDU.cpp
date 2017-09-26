#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        string type;
        cin>>n>>type;
        int avg;
        if(type[0]=='I')avg=200;
        else{
            avg=400;
        }
        long long int total=0;
        while(n--){
            string win;
            cin>>win;
            if(win[0]=='B'){
                int sever;
                cin>>sever;
                total+=(long long int)sever;
            }
            else if(win[0]=='T'){
                total+=300;
            }
            else{
                if(win[8]=='H'){
                    total+=50;
                }
                else{
                    int rnk;
                    cin>>rnk;
                    int bonus= max((20-rnk),0);
                    total+=(300+bonus);
                }
            }
        }
        cout<<total/(long long int)avg<<"\n";
    }
    return 0;

}
