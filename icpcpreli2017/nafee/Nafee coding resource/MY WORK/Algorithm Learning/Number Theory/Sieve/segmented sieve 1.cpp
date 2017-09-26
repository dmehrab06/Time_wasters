#include <bits/stdc++.h>
using namespace std;
void simpleSieve(int n, vector<int> &v)
{
    int i, j, k;
    bool mark[n+1];
    memset(mark, true, sizeof(mark));
    mark[1] = false;
    for (i = 4; i <= n; i+=2) mark[i] = false;
    for (i = 3; i <= sqrt(n+1); i++)
    {
        if (mark[i])
        {
            for (j = i*i; j <= n; j += 2*i)
            {
                mark[j] = false;
            }
        }
    }
    for (i = 2; i <= n; i++)
    {
        if ( mark[i] )
        {
            v.push_back(i);
        }
    }
}
void segmentedSieve(int n)
{
    int i, j, k, segSize = sqrt(n), low, high, s, current, first;
    int segNumber = ceil(n/segSize);
    bool mark[segSize];
    vector<int> v;
    simpleSieve(sqrt(n+1), v);
    s = v.size();
    for (j = 0; j < s; j++) cout << v[j] << " ";
    for (i = 1; i < segNumber; i++)
    {
        memset(mark, true, sizeof(mark));
        low = i*segSize + 1;
        high = low + segSize-1;
        //cout << "s = " << s << endl;
        for (j = 0; j < s; j++)
        {
            current = v[j];
            first = ceil((double)low / v[j]);
            //cout << "first = " << first << endl;
            for (k = first; k*current <=high ; k++)
            {
                mark[ k*current-low ] = false;
            }
        }
        for (j = 0; j < segSize && j+low<=n; j++)
        {
            if ( mark[j] ) cout << j+low << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> v;
    int n, i, j;
    while(1)
    {
        cin >> n;
        segmentedSieve(n);
        cout << endl << endl;
    }
    return 0;
}
