#include<stdio.h>
#include<string.h>
int main()
{
    char A[1003];
    int m,n,i,j;
    scanf("%d ",&m);
    for(j=0; j<m; j++)
    {
        //scanf("%s",A);
        //fflush(stdin);
        gets(A);
        //scanf ("%[^\n]%*c", A);
        //scanf("%[^\n]%*c",A);
        n=strlen(A);
 
        for(i=0; i<n; i++)
        {
            if(A[i]>64&&A[i]<91 ||A[i]>96&&A[i]<123)
                A[i]=A[i]+3;
        }
        char temp;
        for(i=0; i<n/2; i++)
        {
            temp=A[i];
            A[i]=A[n-1-i];
            A[n-1-i]=temp;
        }
 
        for(i=n/2; i<n; i++)
        {
 
                A[i]=A[i]-1;
        }
 
        /*for(i=0; i<n/2; i++)
        {
            temp=A[i];
            A[i]=A[n-1-i];
            A[n-1-i]=temp;
        }*/
 
        printf("%s\n",A);
        //puts(A);
        //printf("\n");
 
    }
   return 0;
}