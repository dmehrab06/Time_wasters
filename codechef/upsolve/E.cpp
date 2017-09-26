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

struct matrixval{
    int val;
    int row;
    int col;
    myitem(){
        val=0;
        row=0;
        col=0;
    }
    myitem(int v, int r, int c){
        val=v;
        row=r;
        col=c;
    }
};

bool mycompare(matrixval a, matrixval b){
    return a.val<b.val;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<matrixval>allvals;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int x;
            scanf("%d",&x);
            matrixval mm(x,n,m);
            allvals.push_back(mm);
        }
    }
    vector<int>rowmaxvals(n+1,0);
    vector<int>colmaxvals(m+1,0);
    for(int i=1;i<=n;++i){
        rowmaxvals[i]=0;
    }
    for(int j=1;j<=m;++j){
        colmaxvals[j]=0;
    }
    vector< vector<int> >finalmatrix;
    vector<int>line(m+1);
    for(int i=1;i<=n+1;++i){
        finalmatrix.push_back(line);
    }

    for(int i=0;i<n;++i){
        myitem p=points[i];
            xpair[p.x]++;


            ypair[p.y]++;

    }
    long long int way=0;
    for (map<int,int>::iterator it=xpair.begin(); it!=xpair.end(); ++it){
        int nn=it->second;
        way+=NC2(nn);
    }
    for (map<int,int>::iterator it=ypair.begin(); it!=ypair.end(); ++it){
        int nn=it->second;
        way+=NC2(nn);
    }
    for (map< pair<int,int>,int>::iterator it=pointcount.begin(); it!=pointcount.end(); ++it){
        int nn=it->second;
        way-=NC2(nn);
    }
    printf("%I64d\n",way);



}
