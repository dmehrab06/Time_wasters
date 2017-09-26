#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int R,C,M,K,J;
    cin>>R>>C>>M>>K>>J;
    long long int Marr[4];
    long long int Karr[4];
    long long int Jarr[4];
    Marr[1]=M;
    Marr[2]=K;
    Marr[3]=J;
    Karr[1]=K;
    Karr[2]=J;
    Karr[3]=M;
    Jarr[1]=J;
    Jarr[2]=M;
    Jarr[3]=K;
    int flag=0;
    //try to get M first then k and j
    for(int i=1;i<=3;++i){
        M=Marr[i];
        K=Karr[i];
        J=Jarr[i];
        if(M%R==0){
            long long int Cleft=C-(M/R);
            if(Cleft>0){
                for(int jj=1;jj<=2;++jj){
                    if(jj==2){
                        long long int t=K;
                        K=J;
                        J=t;
                    }
                    if(K%R==0){
                        long long int Cleft2=Cleft-(K/R);
                        if(Cleft2>0){
                            if((J%Cleft2==0) && (J/Cleft2)==R){
                                flag=1;
                            }
                        }
                    }
                    if(K%Cleft==0){
                        long long int Rleft=R-(K/Cleft);
                        if(Rleft>0){
                            if((J%Rleft==0) && (J/Rleft)==Cleft){
                                flag=1;
                            }
                        }
                    }
                }
            }
        }
        //try with C for M
        if(M%C==0){
            long long int Rleft=R-(M/C);
            if(Rleft>0){
                for(int jj=1;jj<=2;++jj){
                    if(jj==2){
                        long long int t=K;
                        K=J;
                        J=t;
                    }
                    if(K%C==0){
                        long long int Rleft2=Rleft-(K/C);
                        if(Rleft2>0){
                            if((J%Rleft2==0) && (J/Rleft2)==C){
                                flag=1;
                            }
                        }
                    }
                    if(K%Rleft==0){
                        long long int Cleft=C-(K/Rleft);
                        if(Cleft>0){
                            if((J%Cleft==0) && (J/Cleft)==Rleft){
                                flag=1;
                            }
                        }
                    }
                }
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag)cout<<"Yes\n";

    else{
        cout<<"No\n";
    }
}
