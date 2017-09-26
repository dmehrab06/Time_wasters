#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

int Memory[26];

void decmem(){
    for(int i=0;i<26;++i){
        Memory[i]--;
    }
}

int main(){
    int t;
    for(int i=0;i<26;++i){
        Memory[i]=0;
    }
    scanf("%d",&t);
    int cs=1;
    char name[503];
    while(t--){
        int day,k;
        scanf("%d %d %s",&day,&k,name);
        int rec=0;
        for(int i=0;i<day;++i){
            decmem();
            char cur=name[i];
            if(Memory[cur-'A']>=0){
                rec++;
            }
            Memory[cur-'A']=k;
        }
        printf("Case %d: %d\n",cs++,rec);
    }
    return 0;
}
