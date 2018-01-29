/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<string>alls;

map<string, set<string> > allphonemap;
map<string, set<string> > ansphonemap;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        value = 0;
        parent = NULL; //need parent for delete operation
        for (int i=0;i<10;i++){
            children[i] = NULL;
        }
        freq = 0;
    }
    int value;
    int freq;
    int childofparent; //0 theke 25 er moddhe kichu ekta
    TrieNode* children[10];
    TrieNode* parent;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }

    // Inserts a word into the trie.
    int insert(string s) {
        TrieNode *p = root;
        int len = s.size();
        for (int i=0;i<len;i++){
            p->value = 1;
            int idx = s[i] - '0';
            if (! p->children[idx]){
                p->children[idx] = new TrieNode();
            }
            p->children[idx]->parent = p;
            p->children[idx]->childofparent = idx;
            p = p->children[idx];
        }
        count++;
        p->value = -1;
        p->freq++;
        return p->freq;
    }

    void arrange(){
        dfs(root,"");
    }

    void dfs(TrieNode *cur, string myst){
        if(cur->value==-1){
            alls.PB(myst);
            return;
        }
        for(int i = 0;i<10;++i){
            if(cur->children[i]){
                myst.PB(i+'0');
                dfs(cur->children[i],myst);
                myst.pop_back();
            }
        }
        return;
    }
private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
    int n;
    cin>>n;
    FREP(i,1,n){
        string person;
        cin>>person;
        int hasnum;
        cin>>hasnum;
        FREP(k,1,hasnum){
            string num;
            cin>>num;
            REVV(num);
            set<string>line;
            if(allphonemap.find(person)==allphonemap.end()){
                allphonemap[person] = line;
                ansphonemap[person] = line;
            }
            allphonemap[person].insert(num);
        }
    }
    //cout<<"done\n";
    map<string, set<string> >:: iterator it;
    for(it = allphonemap.begin(); it!=allphonemap.end();++it){
        string nm = it->first;
        //cout<<"found "<<nm<<"\n";
        set<string>pps = it->second;
        set<string>::iterator it2;
        Trie trie;
        for(it2 = pps.begin();it2!=pps.end();++it2){
            string cc = *it2;
            //cout<<"inserting "<<cc<<"\n";
            trie.insert(cc);
        }
        //cout<<"doing for "<<nm<<"\n";
        alls.clear();
        trie.arrange();
        for(int i = 0;i<(int)alls.size();++i){
            string cur = alls[i];
            REVV(cur);
            //cout<<"dasha will have "<<cur<<"\n";
            ansphonemap[nm].insert(cur);
        }
    }
    cout<<ansphonemap.size()<<"\n";
    for(it=ansphonemap.begin();it!=ansphonemap.end();++it){
        string key = it->first;
        cout<<key<<" ";
        set<string>myps = it->second;
        cout<<myps.size()<<" ";
        set<string>::iterator it2;
        for(it2=myps.begin();it2!=myps.end();++it2){
            cout<<*it2<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

