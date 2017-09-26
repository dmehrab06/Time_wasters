#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void)
{
    char num1[200], num2[200];
    char result_arr[400] = {'\0'};
    int left_shift = 0;
   //cin>>num1>>num2;

   int n1 = strlen(num1);
    int n2 = strlen(num2);
    //cout<<n1<<" "<<n2<<endl;

    for(int i = n2-1; i >= 0; i--)
    {
        int carry = 0, k = left_shift;
        for(int j = n1-1; j >= 0; j--)
        {
            int partial_result = (num1[j] - '0')*(num2[i] - '0') + carry;
            if(result_arr[k])
                partial_result += result_arr[k] - '0';
            result_arr[k++] = partial_result%10 + '0';
            carry = partial_result/10;
        }
        if(carry > 0)
            result_arr[k] = carry +'0';
        left_shift++;
    }
    //printf("%s\n", result_arr);

    int len = strlen(result_arr);

    for(int i = len-1; i >= 0; i-- )
        printf("%c", result_arr[i]);
    printf("\n");
}
