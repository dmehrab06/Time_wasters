/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
using namespace std;

char s[100005];

int getidx(int ll){
    int ss = 0;
    for(int i=0;i<ll;++i)ss+=s[i]-'0';
    if((s[ll-1]-'0')%2){
        int newss = ss-(s[ll-1]-'0');
        if((s[ll-2]-'0')%2==0 && newss%3==0){
            return ll-1;
        }
        else{
            return -1;
        }
    }
    else{
        if(s[ll-2]>s[ll-1]){
            int newss = ss-(s[ll-1]-'0');
            if((s[ll-2]-'0')%2==0 && newss%3==0){
                return ll-1;
            }
            else{
                return -1;
            }
        }
        else{
            int idx = -1;
            for(int i = 0; i<(ll-1);++i){
                int newss = ss - s[i]- '0';
                if(newss%3==0 && (s[i]<s[i+1])){
                    return i;
                }
                else if(newss%3==0){
                    idx = i;
                }
            }
            int newss = ss-s[ll-1]-'0';
            if(newss%3==0 && (s[ll-2]-'0')%2==0){
                idx = ll-1;
            }
            return idx;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int ll = strlen(s);
        int id = getidx(ll);
        if(id==-1)printf("-1\n");
        else{
            for(int i=0;i<ll;++i){
                if(i!=id){
                    printf("%c",s[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
