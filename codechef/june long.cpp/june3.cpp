#include <bits/stdc++.h>

using namespace std;

char a[1000007];
char b[1000007];

int main(){
    int t;
    scanf("%d ",&t);
    for(int j=1;j<=t;++j){
        scanf("%s %s",a,b);
        int alen=strlen(a);
        //int blen=strlen(b);
        int oneflag=1;
        for(int i=0;i<alen;++i){
            if(a[i]=='0'){
                oneflag=0;
                break;
            }
        }
        int zeroflag=1;
        for(int i=0;i<alen;++i){
            if(a[i]=='1'){
                zeroflag=0;
                break;
            }
        }
        if(oneflag || zeroflag){
            printf("Unlucky Chef\n");
        }
        else{
            int oneneedstobezero=0;
            int zeroneedstobeone=0;
            for(int i=0;i<alen;++i){
                if(a[i]!=b[i]){
                    if(a[i]=='0'){
                        zeroneedstobeone++;
                    }
                    else{
                        oneneedstobezero++;
                    }
                }
            }
            printf("Lucky Chef\n%d\n",max(zeroneedstobeone,oneneedstobezero));
        }

    }
    return 0;
}
