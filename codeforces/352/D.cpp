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

int a[26];

struct myitem{
    int val;
    int freq;
    myitem(){
        val=0;
        freq=0;
    }
    myitem(int a,int b){
        val=a;
        freq=b;
    }
};

bool mycompare(myitem &a, myitem &b){
    return a.val<b.val;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    map<int,int>coins;
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        coins[a]++;
    }
    map<int,int>::iterator it;
    vector<myitem>allcoins;
    for(it=coins.begin();it!=coins.end();++it){
        int v=it->first;
        int f=it->second;
        myitem robin(v,f);
        allcoins.push_back(robin);
    }
    myitem dummy1(0,0);
    myitem dummy2(1000000007,0);
    allcoins.push_back(dummy1);
    allcoins.push_back(dummy2);
    sort(allcoins.begin(),allcoins.end(),mycompare);
    int first=1;
    int last=allcoins.size()-2;
    int mnval=allcoins[first].val;
    int mxval=allcoins[last].val;
    int mxn=allcoins[last].freq;
    int mnn=allcoins[first].freq;
    int curdif=mxval-mnval;
    int dayspassed=0;
    int ans; //duita thakle ki hobe pore handle;
    while(true){
        if(curdif<=1){
            ans=curdif;
            break;
        }
        if(first==last){
            //something
            ans=0;
            break;
        }
        if(first+1==last){
            //something

        }
        int mxjumpday=mxn*(mxval-allcoins[last-1].val);
        int mnjumpday=mnn*(allcoins[first+1].val-mnval);
        if((dayspassed+max(mxjumpday,mnjumpday))>=k){
            //something then break
            int daysleft=k-dayspassed;
            int valincreasemust=daysleft/mnn;
            int valdecreasemust=daysleft/mxn;
            ans=(mxval-valdecreasemust)-(mnn+valincreasemust);
            break;
        }
        else{
            if(mxjumpday>mnjumpday){
                dayspassed+=mxjumpday;
                last--;
                mxval=allcoins[last].val;
                mxn=allcoins[last].freq+mxn;
                int mndayspassed=0;
                while(true){
                    int tempnxtjump=(allcoins[first+1].val-mnval)*mnn;
                    if((mndayspassed+tempnxtjump)<mxjumpday){
                        mndayspassed+=tempnxtjump;
                        first++;
                        mnval=allcoins[first].val;
                        mnn=allcoins[first].freq+mnn;
                    }
                    else if((mndayspassed+tempnxtjump)==mxjumpday){
                        mndayspassed+=tempnxtjump;
                        first++;
                        mnval=allcoins[first].val;
                        mnn=allcoins[first].freq+mnn;
                        break;
                    }
                    else{
                        int daysleft=mxjumpday-mndayspassed;
                        int valincreasesmust=daysleft/mnn;
                        int furthervalincreases=daysleft%mnn;
                        allcoins[first-1].val=mnval+valincreasesmust;
                        allcoins[first-1].freq=mnn-furthervalincreases;
                        allcoins[first].val=mnval+valincreasesmust+1;
                        allcoins[first].freq=furthervalincreases;
                        first-=1;
                        mnn=allcoins[first].freq;
                        mnval=allcoins[first].val;
                        break;
                    }

                }
            }
            else{
                dayspassed+=mnjumpday;
                first++;
                mnval=allcoins[first].val;
                mnn=allcoins[first].freq+mnn;
                int mxdayspassed=0;
                while(true){
                    int tempnxtjump=(mxval-allcoins[last-1].val)*mxn;
                    if((mxdayspassed+tempnxtjump)<mnjumpday){
                        mxdayspassed+=tempnxtjump;
                        last--;
                        mxval=allcoins[last].val;
                        mxn=allcoins[last].freq+mxn;
                    }
                    else if((mxdayspassed+tempnxtjump)==mnjumpday){
                        mxdayspassed+=tempnxtjump;
                        last--;
                        mxval=allcoins[last].val;
                        mxn=allcoins[last].freq+mxn;
                        break;
                    }
                    else{
                        int daysleft=mnjumpday-mxdayspassed;
                        int valincreasesmust=daysleft/mxn;
                        int furthervalincreases=daysleft%mxn;
                        allcoins[last+1].val=mxval-valincreasesmust;
                        allcoins[last+1].freq=mxn-furthervalincreases;
                        allcoins[last].val=mxval-valincreasesmust-1;
                        allcoins[last].freq=furthervalincreases;
                        first+=1;
                        mxn=allcoins[last].freq;
                        mxval=allcoins[last].val;
                        break;
                    }

                }
            }
        }
        curdif=mxval-mnval;
    }
    cout<<ans<<"\n";
    return 0;
}
