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
    int n,k;
    cin>>n>>k;
    string room;
    cin>>room;
    zeropos.push_back(0);
    int zeros=0;
    for(int i=0;i<n;++i){
        if(room[i]=='0'){
            zeropos.push_back(i+1);
            zeros++;
        }
    }
    for(int i=1;i<=zeros;++i){
        printf("%d\n",zeropos[i]);
    }
    printf("\n");
    int fp=1;
    int bp=1+k;
    int maxlen=10000009;
    int fastposition;
    for(int i=fp;i<=bp;++i){
        if(max(zeropos[i]-zeropos[fp],zeropos[bp]-zeropos[i])<maxlen){
            maxlen=max(zeropos[i]-zeropos[fp],zeropos[bp]-zeropos[i]);
            fastposition=i;
        }
    }
    while(bp<=zeros){
        int len1=100000009;
        if(fastposition>=fp && fastposition<=bp)len1=max(zeropos[fastposition]-zeropos[fp],zeropos[bp]-zeropos[fastposition]);
        int len2=100000009;
        while(true){
            if(fastposition+1>=fp && fastposition+1<=bp){
                len2=max(zeropos[fastposition+1]-zeropos[fp],zeropos[bp]-zeropos[fastposition+1]);
                if(len2<len1){
                    fastposition++;
                    maxlen=min(maxlen,len2);
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }


        fp++;
        bp++;
    }
    cout<<maxlen<<"\n";
}
