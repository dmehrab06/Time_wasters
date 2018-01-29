#include <iostream>
#include <cstdio>
using namespace std;

int A[200];
int rightmost(int low, int high,int n,int index){
    int i=index;
    int mid;
    if(low>high){
        return i;
    }

        mid=(low+high)/2;

        if(A[mid]>n){
            return rightmost(low,mid-1,n,i);
        }
        else{
            if(A[mid]==n){
                i=mid;
            }
            return rightmost(mid+1,high,n,i);
        }
}
int leftmost(int low, int high,int n,int index){
    int i=index;
    int mid;
    if(low>high){
        return i;
    }

        mid=(low+high)/2;

        if(A[mid]<n){
            return leftmost(mid+1,high,n,i);
        }
        else{

            if(A[mid]==n){
                i=mid;
            }
            return leftmost(low,mid-1,n,i);
        }


}
int main(){
    int t;
    int ele;
    cin>>t>>ele;
    int i=0;
    int n=t;
    while(t--){
        cin>>A[i];
        i++;
    }
    int left,right;
    left=leftmost(0,n-1,ele,-1);
    right=rightmost(0,n-1,ele,-1);
    printf("%d %d\n",left,right);
}
