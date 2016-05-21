#include <bits/stdc++.h>


using namespace std;
int ans[1000007];
int main(){
    int n,q;
    int even=0;
    int odd=0;
    int onepos=1;
    int twopos=2;
    int twoquery=0;
    scanf("%d %d",&n,&q);
    int swapflag=0;
    for(int i=1;i<=q;++i){
        int type;
        scanf("%d",&type);
        if(type==1){
            swapflag=0;
            if(twoquery%2){
                even+=2;
                if(even<=0){
                    even+=n;
                }
                else if(even>n){
                    even-=n;
                }
                swap(onepos,twopos);
                twoquery=0;
            }
            int shift;
            scanf("%d",&shift);
            even-=shift;
            odd-=shift;
            if(even<=0){
                even+=n;
            }
            else if(even>n){
                even-=n;
            }
            if(odd<=0){
                odd+=n;
            }
            else if(odd>n){
                odd-=n;
            }
            onepos+=shift;
            twopos+=shift;
            if(onepos<=0){
                onepos+=n;
            }
            else if(onepos>n){
                onepos-=n;
            }
            if(twopos<=0){
                twopos+=n;
            }
            else if(twopos>n){
                twopos-=n;
            }
        }
        else if(type==2){
            if(swapflag==0){
                swapflag=1;
                twoquery=1;
            }
            else{
                twoquery++;
            }
        }
        cout<<onepos<<" "<<twopos<<"\n";

    }
    if(twoquery%2){
        even+=2;
        if(even<=0){
            even+=n;
        }
        else if(even>n){
            even-=n;
        }
        swap(onepos,twopos);
        twoquery=0;
    }
    cout<<onepos<<" "<<twopos<<"\n";
    for(int i=1;i<=n;++i){
            if(i%2){
                int nw=i+odd;
                if(nw<=0){
                    nw+=n;
                }
                else if(nw>n){
                    nw-=n;
                }
                ans[i]=nw;
            }
            else{
                int nw=i+even;
                if(nw<=0){
                    nw+=n;
                }
                else if(nw>n){
                    nw-=n;
                }
                ans[i]=nw;
            }
        }
        int ansonepos;
        for(int i=1;i<=n;++i){
            if(ans[i]==1){
                ansonepos=i;
                break;
            }
        }
        int startpos=ansonepos-onepos+1;
        if(startpos<=0){
            startpos+=n;
        }
        for(int i=startpos;i<=n;++i){
            printf("%d ",ans[i]);
        }
        for(int i=1;i<startpos;++i){
            printf("%d ",ans[i]);
        }
        printf("\n");
}
