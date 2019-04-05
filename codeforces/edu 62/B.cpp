/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9
#define MDD 1000000007

using namespace std;

char s[105];

int main(){
    int t;
    scanf("%d",&t);

    for(int cs = 1; cs<=t; ++cs){
        int n;
        scanf("%d %s",&n,s);
        if(n==1){
            printf("0\n");
        }
        else if(s[0]=='>' || s[n-1]=='<'){
            printf("0\n");
        }
        else{
            int c1 = 0;
            for(int i = 0; i<n; ++i){
                if(s[i]=='>'){
                    break;
                }
                c1++;
            }
            int c2 = 0;
            for(int i = n-1; i>=0; --i){
                if(s[i]=='<'){
                    break;
                }
                c2++;
            }
            printf("%d\n",min(c1,c2));
        }
    }
    return 0;
}