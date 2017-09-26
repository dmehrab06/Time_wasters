#include <bits/stdc++.h>
using namespace std;
#define SIZE 999999
long long a, b, c, d, e, f;
char output[SIZE], input[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    strcpy(output, "");
    //cout << output << endl;
    while( gets(input) )
    {
        if ( strncasecmp(input, ".......", strlen(".......")-1) == 0 )
        {
            break;
        }
        strcat(output, input);
        strcat(output, " ");
    }
    cout << output << endl;
    return 0;
}
