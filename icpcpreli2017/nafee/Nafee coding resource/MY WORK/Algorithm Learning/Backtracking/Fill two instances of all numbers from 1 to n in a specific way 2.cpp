#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
int taken[SIZE], prin[SIZE], elements[SIZE];
int n;
int myFunction(int cur)
{
    int a, b, c, i;
    if (cur > n)
    {
        return true;
    }
    for (i = 1; i <= 2*n; i++)
    {
        if ( i+cur+1 <= 2*n )
        {
            if ( prin[i]==-1 && prin[i+cur+1]== -1)
            {
                prin[i] = cur;
                prin[i+cur+1] = cur;
            }
            if ( myFunction(cur+1) )
            {
                return true;
            }
            prin[i] = -1;
            prin[i+cur+1] = -1;
        }
    }
    return false;
}

void myFill(int n)
{
    int a, b, c, i;
    memset(taken, 0, sizeof(taken));
    for (i = 1; i <= n; i++)
    {
        elements[2*i-1] = i;
        prin[i] = -1;
    }
    if (  myFunction(n) )
    {
        for (i = 1; i <= 2*n; i++)
        {
            cout << prin[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    myFill(n);
    cout << endl << endl << endl;
    return main();
}
