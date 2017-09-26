#include <bits/stdc++.h>

using namespace std;

//int xpointsexist[200005];

set<int>xs;

map<int,int>xidxs;
map<int,int>xsize;
vector< set< int > >ysforxs;

int main(){
    set<int>emp;
    ysforxs.push_back(emp);
    int n;
    xs.insert(1000000007);
    scanf("%d",&n);
    char type[7];
    int nxt=1;
    for(int i=1;i<=n;++i){
        int x,y;
        scanf("%s %d %d",type,&x,&y);
        if(type[0]=='a'){
            int idx;
            xs.insert(x);
            if(xidxs.find(x)==xidxs.end()){
                xidxs[x]=nxt;
                xsize[x]=2;
                idx=nxt;
                nxt++;
                set<int>line;
                ysforxs.push_back(line);
                ysforxs[idx].insert(1000000007);
                ysforxs[idx].insert(y);
            }
            else{
                idx=xidxs[x];
                ysforxs[idx].insert(y);
                xsize[x]++;
            }
        }
        else if(type[0]=='r'){
            //xs.erase(x);
            int idx=xidxs[x];
            ysforxs[idx].erase(y);
            xsize[x]--;
            if(xsize[x]==1){
                xs.erase(x);
                cout<<"erasing "<<x<<"\n";
            }
        }
        else if(type[0]=='f'){
            set<int>::iterator itup;
            itup=xs.upper_bound (x);
            int foundx=*itup;
            cout<<"found x "<<foundx<<"\n";
            if(foundx>1000000000){
                printf("-1\n");
            }
            else{
                int idx=xidxs[foundx];
                set<int>::iterator itlow;
                itlow=ysforxs[idx].upper_bound(y);
                int foundy=*itlow;
                cout<<"found y "<<foundy<<"\n";
                if(foundy>1000000000){
                    printf("-1\n");
                }
                else{
                    printf("%d %d\n",foundx,foundy);
                }
            }
        }
    }
    return 0;
}
