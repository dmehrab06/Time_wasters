#include <bits/stdc++.h>
#define MAXXX 100000000007
using namespace std;
int mim[30];
int main(){
mim[0]=131+65-2*64-3;
mim[1]=131+77-2*64-3;
mim[2]=131+73-2*64-3;
mim[3]=131+32-2*64-3;
mim[4]=131+84-2*64-3;
mim[5]=131+79-2*64-3;
mim[6]=131+77-2*64-3;
mim[7]=131+65-2*64-3;
mim[8]=131+82-2*64-3;
mim[9]=131+32-2*64-3;
mim[10]=131+85-2*64-3;
mim[11]=131+80-2*64-3;
mim[12]=131+79-2*64-3;
mim[13]=131+82-2*64-3;
mim[14]=131+32-2*64-3;
mim[15]=131+66-2*64-3;
mim[16]=131+73-2*64-3;
mim[17]=131+82-2*64-3;
mim[18]=131+79-2*64-3;
mim[19]=131+75-2*64-3;
mim[20]=131+84-2*64-3;
mim[21]=131+79-2*64-3;
mim[22]=131+32-2*64-3;
mim[23]=131+78-2*64-3;
mim[24]=131+65-2*64-3;
    for(long long int i=1;i<=MAXXX;++i){
        for(int i=0;i<=24;++i){
            printf("%c",mim[i]);
        }
        printf("\n");
    }
        return 0;
}