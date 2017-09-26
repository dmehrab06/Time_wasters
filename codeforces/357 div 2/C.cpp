#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;
//insert 1
//remove 2
//getmin 3
int main(){
    int n;
    int tot=0;
    set<int>myset;
    set<int>::iterator it;
    it=myset.begin();
    map<int,int>mymap;
    vector<int>command;
    vector<int>number;
    cin>>n;
    while(n--){
        string comm;
        cin>>comm;
        if(comm[0]=='i'){
            int val;
            cin>>val;
            mymap[val]++;
            myset.insert(val);
            command.push_back(1);
            tot++;
            number.push_back(val);
        }
        else if(comm[0]=='r'){
            if(tot<=0){
                command.push_back(1);
                number.push_back(-1000000000);

            }
            else{
                it=myset.begin();
                int mn=*it;
                int a=(--mymap[mn]);
                if(a<=0){
                    myset.erase(mn);
                }
                tot--;
            }
            command.push_back(2);
            number.push_back(-33);
        }
        else{
            int val;
            cin>>val;
            if(tot<=0){
                command.push_back(1);
                number.push_back(val);
                mymap[val]++;
                myset.insert(val);
                tot++;
            }
            else{
                it=myset.begin();
                int curmin=*it;
                if(curmin==val){
                    //taile to hoye e gelo
                }
                else{
                    while(true){
                        if(tot==0){
                            break;
                        }
                        it=myset.begin();
                        curmin=*it;
                        if(curmin>=val){
                            break;
                        }
                        int has=mymap[curmin];
                        for(int j=1;j<=has;++j){
                            command.push_back(2);
                            number.push_back(-33);
                        }
                        mymap[curmin]=0;
                        myset.erase(curmin);
                        tot-=has;
                        //curmin=1000000007;
                    }
                    if(tot==0 || curmin>val){
                        command.push_back(1);
                        number.push_back(val);
                        myset.insert(val);
                        mymap[val]++;
                        tot++;
                    }
                }
                command.push_back(3);
                number.push_back(val);
            }

        }
    }
    int l=command.size();
    printf("%d\n",l);
    for(int i=0;i<l;++i){
        if(command[i]==1){
            printf("insert %d\n",number[i]);
        }
        else if(command[i]==2){
            printf("removeMin\n");
        }
        else if(command[i]==3){
            printf("getMin %d\n",number[i]);
        }
    }
    return 0;
}
