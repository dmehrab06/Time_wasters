#include <bits/stdc++.h>
#define MDD 1000000007
#define eps 0.0000000001
using namespace std;

int city[100005];
int citynew[100005];

int divv[100003][135];

double fdarr[100003]; //1 er ta thakbe na
int mularr[100003]; //1 er ta thakbe na

void foo(int N){
    for(int i=1;i<=N;++i){
        divv[i][0]=0;
    }
    for(int i=1;i<=N;++i){
        int b=sqrt(i);
        for(int j=1;j<=b;++j){
            if(i%j==0){
                divv[i][divv[i][0]+1]=j;
                divv[i][0]++;
                int c=i/j;
                if(c!=j){
                    divv[i][divv[i][0]+1]=c;
                    divv[i][0]++;
                }
            }
        }
    }
}

int multi(int N, int R){
    long long int s=1;
    for(int i=(1+R);i<=N;i+=R){
        s=s*city[i];
        if(s>=MDD){
            s%=MDD;
        }
    }
    return (int)s;
}

int getmul(int i){
    long long int a=mularr[i];
    a=a*(long long int)city[1];
    a%=MDD;
    return (int)a;
}

int getfd(int i){
    double ans=fdarr[i];
    ans+=log10(city[1]);
    int ans2=(int)ans;
    ans=ans-(double)ans2;
    double best=floor(pow(10.0,ans+eps));
    int a=(int)best;
    return a;
}

int getfdbyval(double val){
    double ans=val;
    ans+=log10(city[1]);
    int ans2=(int)ans;
    ans=ans-(double)ans2;
    double best=floor(pow(10.0,ans+eps));
    int a=(int)best;
    return a;
}

double fdforarr(int N, int R){
    double ans=0.0000000000;
    for(int i=(1+R);i<=N;i+=R){
        ans=ans+log10(city[i]);
    }
    return ans;
}

int fdcal(int N, int R){
    double ans=0.0000000000;
    for(int i=(1+R);i<=N;i+=R){
        ans=ans+log10(city[i]);
    }
    //cout<<ans<<"\n";

    int ans2=(int)ans;
    ans=ans-(double)ans2;
    double best=floor(pow(10.0,ans+eps));
    int a=(int)best;
    return a;
}

long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0){
        return 1;
    }
    if(x==1){
        return b;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}
long long int findMMI(long long int n,long long int M)
{
    return modpow(n,M-2,M);
}

int eucmodInv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if (x1 < 0)
       x1+=m0;
    return x1;
}

void updmul(int k, int p){
    long long int pmul=(long long int)mularr[k];
    int pfrnd=city[p];
    pmul=pmul*eucmodInv(pfrnd,MDD);
    if(pmul>=MDD){
        pmul%=MDD;
    }
    pmul=pmul*(long long int)citynew[p];
    if(pmul>=MDD){
        pmul%=MDD;
    }
    mularr[k]=(int)pmul;
}

void updfd(int k, int p){
    double pf=fdarr[k];
    double plog=log10((double)city[p]);
    pf-=plog;
    double nlog=log10((double)citynew[p]);
    pf+=nlog;
    fdarr[k]=pf;
}

int setflag=0;

set<int>updcity;
set<int>::iterator it;
int main(){
    int N;
    scanf("%d",&N);
    if(N<=10){
        for(int i=1;i<=N;++i){
            scanf("%d",&city[i]);
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int comm;
            scanf("%d",&comm);
            if(comm==1){
                int p,f;
                scanf("%d %d",&p,&f);
                city[p]=f;

            }
            else{
                int R;
                scanf("%d",&R);
                double fd;
                long long int ml;

                ml=multi(N,R);
                fd=fdforarr(N,R);
                ml=ml*(long long int)city[1];
                ml%=MDD;
                int ff;
                ff=getfdbyval(fd);
                printf("%d %lld\n",ff,ml);

            }
        }
    }
    else{
        for(int i=1;i<=N;++i){
            scanf("%d",&city[i]);
        }
        foo(N);
        for(int r=1;r<=N;++r){
            mularr[r]=multi(N,r);
            fdarr[r]=fdforarr(N,r);
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int comm;
            scanf("%d",&comm);
            if(comm==1){
                setflag=1;
                int p,f;
                scanf("%d %d",&p,&f);
                updcity.insert(p);
                citynew[p]=f;

            }
            else{
                if(setflag==1){
                    for(it=updcity.begin();it!=updcity.end();++it){
                        int p=*it;
                        if(p!=1){
                            int pcur=p-1;
                            int bb=sqrt(pcur);
                            for(int kk=1;kk<=bb;++kk){
                                if(pcur%kk==0){
                                    //int k=divv[pcur][kk];
                                    updmul(kk,p);
                                    updfd(kk,p);
                                    int k=pcur/kk;
                                    if(k!=kk){
                                        updmul(k,p);
                                        updfd(k,p);
                                    }
                                }
                            }
                        }
                        city[p]=citynew[p];
                    }
                    updcity.clear();
                    setflag=0;
                }
                int R;
                scanf("%d",&R);
                int fd;
                int ml;

                ml=getmul(R);
                fd=getfd(R);
                printf("%d %d\n",fd,ml);

            }
        }
    }
    return 0;
}

