#include <stdio.h>
#include <string.h>
int main(){
    int t;
    scanf("%d",&t);
    if(t!=0){
        scanf(" ");
    }
    int tt=1;
    double R;
    int n;
    int A[27];
    int B[27];
    char a[105];
    char b[105];
    while(t--){
        gets(a);
        gets(b);
        int i;
        for(i=1;i<=26;++i){
            A[i]=0;
            B[i]=0;
        }
        i=0;
        int l=strlen(a);
        while(i<l){
            char c;
            c=a[i];
            if(c>=97 && c<=122){
                c-=32;
            }
            if(c>=65 && c<=90){
                int a;
                a=c-64;
                A[a]++;
            }
            i++;
        }
        i=0;
        l=strlen(b);
        while(i<l){
            char c;
            c=b[i];
            if(c>=97 && c<=122){
                c-=32;
            }
            if(c>=65 && c<=90){
                int a;
                a=c-64;
                B[a]++;
            }
            i++;
        }
        int same=1;
        i=1;
        while(i<=26){
            if(A[i]!=B[i]){
                same=0;
                break;
            }
            i++;
        }
        if(same){
            printf("Case %d: Yes\n",tt);
        }
        else{
            printf("Case %d: No\n",tt);
        }
        tt++;
 
    }
    return 0;
}
