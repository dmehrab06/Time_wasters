#include <iostream>
#include <cstdio>
using namespace std;

int A[200];
int leftmost(int low, int high){
    int index=-1;
    int mid;
    while(index==-1 && low<=high){

        mid=(low+high)/2;

        if(A[mid]>mid){
            high=mid-1;
        }
        else if(A[mid]<mid){
            low=mid+1;
        }
        else{
            if(A[mid-1]!=(mid-1)){
                index=mid;
            }
            else{
                high=mid-1;
            }
        }
    }
    return index;
}
int rightmost(int low, int high){
    int index=-1;
    int mid;
    while(index==-1 && low<=high){

        mid=(low+high)/2;

        if(A[mid]>mid){
            high=mid-1;
        }
        else if(A[mid]<mid){
            low=mid+1;
        }
        else{
            if(A[mid+1]==(mid+1)){
                low=mid+1;
            }
            else{
                index=mid;
            }
        }
    }
    return index;
}
int main(){
    int t;
    cin>>t;
    int i=0;
    int n=t;
    while(t--){
        cin>>A[i];
        i++;
    }
    int left,right;
    left=leftmost(0,n-1);
    right=rightmost(0,n-1);
    printf("%d %d\n",left,right);
}
