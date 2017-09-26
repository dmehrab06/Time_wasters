#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;
vector<int>arr;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    long long int curmex=1;
    int l=arr.size();
    for(int i=0;i<l;++i){
        if(arr[i]==curmex){
            curmex++;
        }
        else{
            if(arr[i]>curmex){
                arr[i]=curmex;
                curmex++;
            }
        }
    }
    cout<<curmex<<"\n";

}
