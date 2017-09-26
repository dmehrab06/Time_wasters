#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int myjugsid[12];
int myjugscapacity[12];
int myjugsstate[12];
int pour(int A,int B,int C)
{
    int a=A,b=0,count=1;  //a is full, b is empty initially
    while(a!=C && b!=C)
    {
        int tmp=min(a,B-b); //checking if space left in b(i.e B-b) is > or < water in a;
        a-=tmp;
        b+=tmp;
        count++;         //Transferring from a to b;
        if(a==C || b==C)
            break;
        if(a==0)
        {
            a=A;count++;     //if a is empty, fill it again
        }
        if(b==B)
        {
            b=0;count++;    //if b is full, empty it
        }

    }
    return count;
}

struct operation{
    int type;
    int src;
    int dest;
    operation(int t, int s, int d){
        type=t;
        src=s;
        dest=d;
    }
    void printop(){
        if(type==1 || type==2){
            printf("%d %d\n",type,src);
        }
        else{
            printf("%d %d %d\n",type,src,dest);
        }
    }
};

void sim(int need, int totaljugs)
{
    while(1){
        for(int i=1;i<=totaljugs-1;++i){
            for(int j=i+1;j<=totaljugs;++j){
                if(myjugsstate[i]!=myjugscapacity[i]){
                    cout<<1<<" "<<myjugsid[i]<<"\n";
                    myjugsstate[i]=myjugscapacity[i];
                    if(myjugsstate[i]==need){
                        return;
                    }
                }
                int b=myjugscapacity[j]-myjugsstate[j];
                int a=myjugsstate[i];
                int topour=min(a,b);
                if(topour!=0){
                    cout<<3<<" "<<myjugsid[i]<<" "<<myjugsid[j]<<"\n";
                    myjugsstate[i]-=topour;
                    myjugsstate[j]+=topour;
                    if(myjugsstate[i]==need || myjugsstate[j]==need){
                        return;
                    }
                }
                if(myjugsstate[i]!=0){
                    if(myjugsstate[j]!=0){
                        cout<<2<<" "<<myjugsid[j]<<"\n";
                    }
                    cout<<3<<" "<<myjugsid[i]<<" "<<myjugsid[j]<<"\n";
                    myjugsstate[j]=myjugsstate[i];
                    myjugsstate[i]=0;
                }
            }
        }

    }
}

vector<operation>allops;

int dummysim(int need, int totaljugs)
{
    int op=0;
    while(1){
        for(int i=1;i<=totaljugs-1;++i){
            for(int j=i+1;j<=totaljugs;++j){
                if(myjugsstate[i]!=myjugscapacity[i]){
                    //cout<<1<<" "<<myjugsid[i]<<"\n";
                    operation o1(1,myjugsid[i],-1);
                    allops.push_back(o1);
                    op++;
                    myjugsstate[i]=myjugscapacity[i];
                    if(myjugsstate[i]==need){
                        return op;
                    }
                }
                int b=myjugscapacity[j]-myjugsstate[j];
                int a=myjugsstate[i];
                int topour=min(a,b);
                if(topour!=0){
                    //cout<<3<<" "<<myjugsid[i]<<" "<<myjugsid[j]<<"\n";
                    operation o3(3,myjugsid[i],myjugsid[j]);
                    allops.push_back(o3);
                    op++;
                    myjugsstate[i]-=topour;
                    myjugsstate[j]+=topour;
                    if(myjugsstate[i]==need || myjugsstate[j]==need){
                        return op;
                    }
                }
                if(myjugsstate[i]!=0){
                    if(myjugsstate[j]!=0){
                       // cout<<2<<" "<<myjugsid[j]<<"\n";
                       operation o2(2,myjugsid[j],-1);
                       allops.push_back(o2);
                       op++;
                    }
                    //cout<<3<<" "<<myjugsid[i]<<" "<<myjugsid[j]<<"\n";
                    operation o3(3,myjugsid[i],myjugsid[j]);
                    allops.push_back(o3);
                    op++;
                    myjugsstate[j]=myjugsstate[i];
                    myjugsstate[i]=0;
                }
            }
        }

    }
}

int gcd(int a,int b)
{
   if(b==0)
    return a;
   else
    return gcd(b,a%b);
}

int jugs[12];

int smallgcdmaps[7][1030];
int smallgcdmapmaxheight[7][1030];
int smallgcdmapsjugs[7][1030];

void findgcd(int mask){
    int t=mask;
    int m=1;
    int pos=1;
    vector<int>onepos;
    while(pos<=10){
        if(m&t)onepos.push_back(pos);
        pos++;
        m<<=1;
    }
    int G=jugs[onepos[0]];
    int N=onepos.size();
    int mx=G;
    if(N>1){
        for(int i=1;i<N;++i){

            G=gcd(G,jugs[onepos[i]]);
            mx=max(mx,jugs[onepos[i]]);
        }

    }
    if(G<=5){
        int l=smallgcdmaps[G][0];
        smallgcdmaps[G][l+1]=mask;
        smallgcdmapmaxheight[G][l+1]=mx;
        smallgcdmapsjugs[G][l+1]=N;
        smallgcdmaps[G][0]++;
        smallgcdmapmaxheight[G][0]++;
    }

}

struct waterjugs{
    int mask;
    int maxheight;
    int totaljugs;
    waterjugs(int m,int h, int n){
        mask=m;
        maxheight=h;
        totaljugs=n;
    }
};

bool mycompare(waterjugs a, waterjugs b){
    if(a.maxheight==b.maxheight){
        return a.totaljugs<b.totaljugs;
    }
    return a.maxheight<b.maxheight;
}

struct singlejug{
    int id;
    int height;
    singlejug(int i,int h){
        id=i;
        height=h;
    }
};

bool mycompare1(singlejug a, singlejug b){
    if(a.height==b.height){
        return a.id<b.id;
    }
    return a.height<b.height;
}

int main()
{
    for(int i=1;i<=5;++i){
        smallgcdmaps[i][0]=0;
        smallgcdmapmaxheight[i][0]=0;
        smallgcdmapsjugs[i][0]=0;
    }
   int N;
    int A;
    scanf("%d %d",&N,&A);

    for(int i=1;i<=N;++i){
        scanf("%d",&jugs[i]);
    }
    int mx=-1;
    for(int i=1;i<=N;++i){
        mx=max(mx,jugs[i]);
    }
    int G=jugs[1];
    if(N>1){
        G=gcd(jugs[1],jugs[2]);
        if(N>2){
            for(int i=3;i<=N;++i){
                G=gcd(G,jugs[i]);
            }
        }
    }
    if(A%G || mx<A){
        printf("-1\n");
    }
    else{
        int maskend=1<<N;
        for(int i=1;i<maskend;++i){
            findgcd(i);
        }

        vector<waterjugs>candidates;
        for(int i=1;i<=5;++i){
            if(A%i==0){
                int len=smallgcdmaps[i][0];
                for(int j=1;j<=len;++j){
                    int mask=smallgcdmaps[i][j];
                    int maxheight=smallgcdmapmaxheight[i][j];
                    int jugn=smallgcdmapsjugs[i][j];
                    if(maxheight>=A && jugn>1){
                        waterjugs w(mask,maxheight,jugn);
                        candidates.push_back(w);
                    }
                }
            }
        }
        if(candidates.size()==0){
            int eqflag=0;
            for(int i=1;i<=N;++i){
                if(jugs[i]==A){
                    printf("1\n");
                    printf("1 %d\n",i);
                    eqflag=1;
                }
            }
            if(!eqflag)
            printf("-1\n");
        }
        else{
            sort(candidates.begin(),candidates.end(),mycompare);
            waterjugs selected=candidates[0];
            int selectedmask=selected.mask;
            int m=1;
            int pos=1;
            vector<singlejug>allselected;
            while(pos<=10){
                if(m&selectedmask){
                    singlejug JUG(pos,jugs[pos]);
                    allselected.push_back(JUG);
                }
                pos++;
                m<<=1;
            }
            sort(allselected.begin(),allselected.end(),mycompare1);
            int l=allselected.size();
            for(int i=1;i<=l;++i){
                myjugsid[i]=allselected[i-1].id;
                myjugscapacity[i]=allselected[i-1].height;
                myjugsstate[i]=0;
            }
            int op=dummysim(A,l);
            printf("%d\n",op);
            int allop=allops.size();
            for(int i=0;i<allop;++i){
                allops[i].printop();
            }

        }
    }
    return 0;
}
