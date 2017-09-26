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

set<string>allstrings;
vector< vector <string> >edges;

void dfs(string cur, int n){
    int l=cur.size();
    if(l==n){
        allstrings.insert(cur);
        return;
    }
    int u=cur[0]-'a';
    string tmp="";
    for(int i=1;i<l;++i){
        tmp+=cur[i];
    }
    int deg=edges[u].size();
    for(int i=0;i<deg;++i){
        string next=edges[u][i];
        next+=tmp;
        dfs(next,n);
    }
}

int main(){
    int t;
    int cs=1;

    cin>>t;
    while(t--){
    vector<int>time;
    vector<int>requ;
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        time.push_back(a);
        time.push_back(b);
        time.push_back(c);
        time.push_back(d);
        for(int i=1;i<=4;++i){
            requ.push_back(i);
        }
        for(int i=0;i<4;++i){
            for(int j=i+1;j<4;++j){
                if(time[i]>time[j]){
                    int tmp=time[i];
                    time[i]=time[j];
                    time[j]=tmp;
                    tmp=requ[i];
                    requ[i]=requ[j];
                    requ[j]=tmp;
                }
            }
        }
        string type1="GET";
        string type3="UPDATE";
        string type2="POST";
        string type4="DELETE";
        int times,req;
        cin>>times>>req;
        int reqtypefreq[5];
        for(int i=1;i<=4;++i){
            reqtypefreq[i]=0;
        }
        for(int i=1;i<=req;++i){
            string req;
            cin>>req;
            if(req==type1){
                reqtypefreq[1]++;
            }
            if(req==type2){
                reqtypefreq[2]++;
            }
            if(req==type3){
                reqtypefreq[3]++;
            }
            if(req==type4){
                reqtypefreq[4]++;
            }
        }
        int proc=0;
        for(int i=0;i<4;++i){
            int type=requ[i];
            int timeperreq=time[i];
            int totalrequthis=reqtypefreq[type];
            int canproc=times/timeperreq;
            if(totalrequthis<=canproc){
                proc+=totalrequthis;
                times-=(totalrequthis*timeperreq);
            }
            else{
                proc+=canproc;
                break;
            }
        }
        printf("Case %d: %d\n",cs++,proc);
    }
    return 0;
}
