#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int a[100],i=0,j,k;
    while(!cin.eof())
    {
        cin>>a[i];
        i++;
    }
    cout<<"Enter the number's position you want :"<<endl;
    cin>>k;

    for(j=0; j<i; j++)
    {
        if(a[j]==k)
        {
            cout<<j<<endl;
        }
    }
}
