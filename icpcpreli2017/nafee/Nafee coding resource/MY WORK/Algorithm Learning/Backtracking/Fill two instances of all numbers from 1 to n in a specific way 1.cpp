#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
int n;
int prin[SIZE], taken[SIZE], elements[SIZE];

int ifArOk(int n)
{
    //cout << "inside ifArOk, n = " << n << endl;
    int i, j, m, sIdx, eIdx;
    for (i = 1; i <= n; i++)
    {
        //cout << "i = " << i << endl;
        for (j = 1; j <= 2*n; j++)
        {
            //cout << prin[j] << " ";
            if ( prin[j]==i )
            {
                eIdx = j;
            }
        }
        //cout << endl;
        //cout << "sIdx = " << sIdx << endl;
        for (j = 2*n; j >= 1; j--)
        {
            //cout << prin[j] << " ";
            if ( prin[j]==i )
            {
                sIdx = j;
            }
        }
        //cout << endl;
        //cout << "eIdx = " << eIdx << endl;
        if ( eIdx-sIdx != i+1 ) break;
    }
    if (i == n+1)
    {
        for (j = 1; j <= 2*n; j++)
        {
            cout << prin[j] << " ";
        }
        cout << endl;
        return 1;
    }
    return 0;
}

int myFunction(int pos )
{
    //cout << "pos = " << pos << endl;
    int i, j, k, m;
    if (pos >= 2*n+1)
    {
//        for (i = 1; i <= 2*n; i++) cout << prin[i] << " ";
//        cout << endl;
        ifArOk(n);
        return 1;
    }
    for (i = 1; i <= 2*n; i++)
    {
        if ( !taken[i] )
        {
            taken[i] = 1;
            prin[pos] = elements[i];
            myFunction( pos+1 );
            taken[i] = 0;
        }
    }
    return 0;
}


int myFill(int n)
{
    int i, j, k;
    memset(taken, 0, sizeof(taken));
    for (i = 1; i <= n; i++)
    {
        elements[2*i-1] = i;
        elements[2*i] = i;
    }
    myFunction(1);
}
int main()
{
    cin >> n;
    myFill(n);

//    prin[1] = 3;
//    prin[2] = 1;
//    prin[3] = 2;
//    prin[4] = 1;
//    prin[5] = 3;
//    prin[6] = 2;

    //ifArOk(3);

    cout << endl << endl << endl;
    return main();
}
