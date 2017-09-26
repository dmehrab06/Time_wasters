#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;


string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

class gl{
public:
    int gcd;
    int lcm;
    gl(int a,int b){
        gcd=a;
        lcm=b;
    }

};
template <typename X>
bool bin_search(X N,vector<X>A){
    int l=A.size();
    int low,high,mid;
    low=0;
    high=l-1;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==N)return true;
        else if(A[mid]<N)low=mid+1;
        else{
            high=mid-1;
        }
    }
    return false;
}
template <typename Y>
int bin_search2(Y N,vector<Y>A){
    int l=A.size();
    int index=-1;
    int low,high,mid;
    low=0;
    high=l-1;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==N){
            index=mid;
            break;
        }
        else if(A[mid]<N)low=mid+1;
        else{
            high=mid-1;
        }
    }
    return index;
}
gl gcdlcm(vector<int>num){
    int a=num[0];
    int b=num[1];
    int gcd;
    while(a){
        int tmp=a;
        a=b%a;
        b=tmp;
    }
    gcd=b;
    int lcm=(num[1]*num[0])/gcd;
    int l=num.size();
    for(int i=2;i<l;++i){
        int tmpa=num[i];
        int tmpb=gcd;
        while(tmpa){
            int tmp=tmpa;
            tmpa=tmpb%tmpa;
            tmpb=tmp;
        }
        gcd=tmpb;
        lcm=(lcm*num[i])/gcd;
    }
    gl R(gcd,lcm);
    return R;
}

int main(){
//while(1){
    vector<int>A;
    vector<int>B;
    vector<int>C;
    vector<int>D;

        int n;
        scanf("%d",&n);
        int tmp=n;
        while(n--){
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            A.push_back(a);
            B.push_back(b);
            C.push_back(c);
            D.push_back(d);
        }
        vector<int>AB;
        vector<int>CD;
        for(int i=0;i<tmp;++i){
            for(int j=0;j<tmp;++j){
                AB.push_back(A[i]+B[j]);
            }
        }
        for(int i=0;i<tmp;++i){
            for(int j=0;j<tmp;++j){
                CD.push_back(C[i]+D[j]);
            }
        }
        sort(CD.begin(),CD.end());
        long long int ans=0;
        int l=AB.size();
        for(int i=0;i<l;++i){
            int a=AB[i];
            if(bin_search(-a,CD))ans++;
        }
        printf("%lld\n",ans);

    return 0;
}
