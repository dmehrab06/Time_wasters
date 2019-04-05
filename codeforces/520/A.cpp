/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define MDD 1000000007
using namespace std;

int arr[105];
int can[105];

int main(){
    int n;
    scanf("%d",&n);
    for(int i =1; i<=n; ++i){
        scanf("%d",&arr[i]);
    }
    arr[0] = 0; arr[n+1] = 1001;
    int c = 0;
    for(int i = 1;i<=n;++i){
        if((arr[i]-1)==arr[i-1] && (arr[i]+1)==arr[i+1]){
            can[i] = 1;
        }
    }
    int mxcons = 0;
    int curcons = 0;
    for(int i = 1; i<=n; ++i){
        if(can[i]==1){
            curcons++;
        }
        else{
            mxcons = max(curcons,mxcons);
            curcons = 0;
            
        }
    }
    mxcons = max(curcons,mxcons);
    printf("%d\n",mxcons);
    return 0;
}