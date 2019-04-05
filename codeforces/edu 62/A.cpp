/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9
#define MDD 1000000007

using namespace std;

char s[105];

int main(){
    int t;
    cin>>t;
    
    for(int i = 1; i<=n; ++i){
        cin>>mystery[i];
    }

    int day = 0;
    int curpage = 0;
    int mxcurpage = -1;
    while(curpage<n){


        do{
            curpage++;
            //cout<<"reading : "<<curpage<<"\n";
            mxcurpage = max(mxcurpage,mystery[curpage]);
            cout<<curpage<<" "<<mxcurpage<<"\n";
        }while(mxcurpage!=curpage);

        //cout<<"read until page "<<curpage<<"\n";
        day++;

    }

    cout<<day<<"\n";
}