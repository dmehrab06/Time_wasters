#include<bits/stdc++.h>
#define MOD 1000000007
#define MX 100010
#define ll long long
#define sc(n) scanf("%d",&n)
#define pr(m) printf("%d\n",m)
#define pi acos(-1.0)

using namespace std;

struct jobs{
    ll s;
    ll d;
    ll start,finish;

};

bool cmp(struct jobs a,struct jobs b)
{
    if(a.start==b.start)return a.finish<b.finish;
    return a.start<b.start;
}
int main()
{
    int n;
    cin>>n;
    struct jobs jobArr[205];

    for(int i=0;i<n;i++){

        cin>>jobArr[i].s>>jobArr[i].d;
        jobArr[i].start=jobArr[i].s,jobArr[i].finish=jobArr[i].s+jobArr[i].d-1;
        bool mara=0;

        for(int j=0;j<i;j++){
            if((jobArr[i].start>=jobArr[j].start &&jobArr[i].start<=jobArr[j].finish)||((jobArr[i].finish>=jobArr[j].start &&jobArr[i].finish<=jobArr[j].finish)))
            {
                mara=1;
                break;
            }
        }
        ll falseStart=1,falseFinish=jobArr[i].d;
        if(mara){
            for(int j=0;j<i;j++){
                if((falseStart>=jobArr[j].start &&falseStart<=jobArr[j].finish)||((falseFinish>=jobArr[j].start &&falseFinish<=jobArr[j].finish))){
                    falseStart=jobArr[j].finish+1;
                    falseFinish=falseStart+jobArr[i].d-1;
                }
            }
            jobArr[i].start=falseStart;
            jobArr[i].finish=falseFinish;
        }

        cout<<jobArr[i].start<<" "<<jobArr[i].finish<<endl;
        sort(jobArr,jobArr+i,cmp);
    }

    return 0;
}
