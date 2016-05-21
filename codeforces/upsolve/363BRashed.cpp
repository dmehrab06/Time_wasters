#include<iostream>
#include<vector>

using namespace std;

long n,k;
vector<long> h;
int minDistance(int gap);

int main()
{
    cin>>n>>k;
    h.resize(n);
    for(int i = 0; i<n; i++)
    {
        cin>>h[i];
    }

    int answer = minDistance(k);
    cout<<answer;
    return 0;

}

int minDistance(int gap)
{
    int index = 0;
    if(gap == 1)
    {
        int minimum = 101;

        for(int i = 0; i < n; i++)
        {
            if(h[i] < minimum)
            {
                minimum = h[i];
                index = i;
            }
        }
        return index+1;
    }
    if(gap == n)
        return 1;
    int sumH = 300;
    int sum = 0;
    int k;
    for(int i = 0; i<n-gap+1; i++)
    {
        if(i == 0)
        {
            for(k = 0; k < gap; k++)
            {
                sum+=h[k];
            }
        }
        else {
            sum+=h[i+gap-1];
            sum-=h[i-1];
        }

        if(sum < sumH)
        {
            sumH = sum;
            index = i;
        }

    }

    return index+1;

}
