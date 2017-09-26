#include <bits/stdc++.h>
using namespace std;
#define SIZE 999999
char str1[SIZE], str2[SIZE];
long long startIdx;
int main()
{
    freopen("input.txt", "r", stdin);
    gets(str1);
    //cout << str1 << endl << endl << endl;;
    gets(str2);
    //cout << str2 << endl;
    //return 0;
    while(1)
    {
        if ( startIdx + strlen(str2) > strlen(str1) )
        {
            break;
        }
        if ( strncmp(str1+startIdx, str2, strlen(str2)-1) == 0 )
        {
            cout << startIdx << endl;
            startIdx += (strlen(str2)-1);
        }
        startIdx++;
    }
    return 0;
}
