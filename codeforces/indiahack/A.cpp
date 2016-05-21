#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int GCD(int a,int b){
    return a==0?b:GCD(b%a,a);
}

string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

struct myitem{
    int x;
    int y;
    myitem(){
        x=0;
        y=0;
    }
    myitem(int a, int b){
        x=a;
        y=b;
    }
    bool operator=(const myitem &b){
        return x==b.x && y==b.y;

    }
};


int representative[200005];
int sizeofrep[200005];
int findrep(int a, int * rep){
    if(rep[a]!=a){
        return rep[a]=findrep(rep[a], rep);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y, int * rep){
    int xp,yp;
    xp=findrep(x,rep);
    yp=findrep(y, rep);
    representative[yp]=xp;
}
long long int NC2(int n){
    if(n<2)return 0;
    long long int huda=n;
    huda=huda*(huda-1);
    return huda/2;
}
vector<int>zeropos;
int binsearchsmallerorequal(int l, int r, int val){
    int mid=(l+r)/2;
    if(zeropos[mid]==val){
        return mid;
    }
    else if(zeropos[mid]<val){
        if(mid+1>r){
            return mid;
        }
        else if(zeropos[mid+1]>val){
            return mid;
        }
        else{
            return binsearchsmallerorequal(mid+1,r,val);
        }
    }
    else{
        return binsearchsmallerorequal(l,mid-1,val);
    }
}

int binsearch(int l, int r, int fp, int bp){
    int mid=(l+r)>>1;
    int len=max(zeropos[mid]-zeropos[fp],zeropos[bp]-zeropos[mid]);
    int len1=1000000009,len2=1000000009;
    if((mid-1)>=fp){
        len1=max(zeropos[mid-1]-zeropos[fp],zeropos[bp]-zeropos[mid-1]);
    }
    if((mid+1)<=bp){
        len2=max(zeropos[mid+1]-zeropos[fp],zeropos[bp]-zeropos[mid+1]);
    }
    if(len1>=len && len2>=len){
        return mid;
    }
    else{
        if(len2<len1){
            return binsearch(mid+1,r,fp,bp);
        }
        else{
            return binsearch(l,mid-1,fp,bp);

        }
    }
}

int binsearchgreaterorequal(int l, int r, int val){
    int mid=(l+r)/2;
    if(zeropos[mid]==val){
        return mid;
    }
    else if(zeropos[mid]>val){
        if(mid-1<l){
            return mid;
        }
        else if(zeropos[mid-1]<val){
            return mid;
        }
        else{
            return binsearchgreaterorequal(l,mid-1,val);
        }
    }
    else{
        return binsearchsmallerorequal(mid+1,r,val);
    }
}



int main(){
    int n;
    cin>>n;
    vector<int>balls;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        balls.push_back(a);
    }
    sort(balls.begin(),balls.end());
    int flag=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                int a=balls[i];
                int b=balls[j];
                int c=balls[k];
                if(a!=b && a!=c && b!=c && abs(b-a)<=2 && abs(c-a)<=2 && abs(b-c)<=2){
                    flag=1;
                }
            }
        }
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
