#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int indiv2[100006];
int indiv1[100006];


int main(){
    set< pair<int,int> >all;
    pair<int,int>a(-1,2);
    pair<int,int>b(-2,1);
    all.insert(a);
    all.insert(b);
    set<pair<int,int>>::iterator it;
    for(it=all.begin();it!=all.end();++it){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    all.erase(a);
    for(it=all.begin();it!=all.end();++it){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    pair<int,int>c(-3,2);
    all.insert(c);
    for(it=all.begin();it!=all.end();++it){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    return 0;

}
