#include <bits/stdc++.h>

using namespace std;

//int xpointsexist[200005];



int main(){
    char type[7];
    long long int  n,x;
    cin>>n>>x;
    int dis=0;
    for(int i=1;i<=n;++i){
        int d;
        scanf("%s %d",type,&d);
        if(type[0]=='+'){
            x+=(long long int)d;
        }
        else if(type[0]=='-'){
            if(x>=d){
                x-=(long long int)d;
            }
            else{
                dis++;
            }
        }


    }
    cout<<x<<" "<<dis<<"\n";
    return 0;
}
