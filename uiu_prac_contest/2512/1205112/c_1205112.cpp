#include <iostream>
using namespace std;
typedef struct xx{
    int min;
    int max;
    int sum;
}values;
int A[105];
values minmaxsumcombine(values b,values c){
    int l=b.max;
    int s=b.min;
    int sum=(b.sum+c.sum);
    if(c.max>b.max){
        l=c.max;
    }
    if(c.min<b.min){
        s=c.min;
    }
    values ret;
    ret.min=s;
    ret.max=l;
    ret.sum=sum;
    return ret;
}
values minmaxsumdivide(int p,int q){
    if(p==q){
        values a;
        a.min=A[p];a.max=A[p];a.sum=A[p];
        return a;
    }
    values b,c;
    int r=(p+q)/2;
    b=minmaxsumdivide(p,r);
    c=minmaxsumdivide(r+1,q);
    values fin;
    fin=minmaxsumcombine(b,c);
    return fin;
}

int main(){
    int n;
    int i=0;
    cin>>n;
    while(n--){
        cin>>A[i];
        i++;
    }
    int low,high;
    cin>>low>>high;
    values ans;
    ans=minmaxsumdivide(low,high);
    cout<<ans.min<<" "<<ans.max<<" "<<ans.sum<<"\n";
    return 0;
}
