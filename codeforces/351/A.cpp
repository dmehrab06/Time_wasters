#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int chevonacci[100];

int bsearch(int low, int high, int X){
    if(X==1){
        return 0;
    }
    if(X==2){
        return 1;
    }
    int mid=(low+high)/2;
    if(chevonacci[mid]==X)return mid;
    if(chevonacci[mid]>X)return bsearch(low,mid-1,X);
    if(chevonacci[mid]<X){
        if(chevonacci[mid+1]==X){
            return mid+1;
        }
        else if(chevonacci[mid+1]>X){
            return mid;
        }
        else{
            return bsearch(mid+1,high,X);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>moments;
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        moments.push_back(a);
    }
   // moments.push_back(90);
    int nxtleavemoment=15;
    int watched=15;
    for(int i=0;i<n;++i){
        if(moments[i]<=nxtleavemoment){
            watched=moments[i];
            nxtleavemoment=watched+15;
        }
    }
    if(nxtleavemoment>=90){
        cout<<"90\n";
    }
    else{
        cout<<nxtleavemoment<<"\n";
    }

}
