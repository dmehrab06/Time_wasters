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


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        value = 0;
        parent = NULL; //need parent for delete operation
        for (int i=0;i<26;i++){
            children[i] = NULL;
        }
        freq = 0;
    }
    int value;
    int freq;
    int childofparent; //0 theke 25 er moddhe kichu ekta
    TrieNode* children[26];
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
            int idx = s[i] - 'a';
            if (! p->children[idx]){
                p->children[idx] = new TrieNode();
            }
            p->children[idx]->parent = p;
            p->children[idx]->childofparent = idx;
            p = p->children[idx];
        }
        count++;
        p->value = count;
        p->freq++;
        return p->freq;
    }

    // Returns if the word is in the trie.
    int search(string key) {
        TrieNode *p = root;
        int len = key.size();
        int matched = 0;
        for (int i=0;i<len;i++){
            int idx = key[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
                matched++;
            }else{
                return matched;
            }
        }
        return matched;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        int len = prefix.size();
        for (int i=0;i<len;i++){
            int idx = prefix[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int screenmatch(string scr, string nd){
    if(scr.size()>nd.size()){
        return -10000000;
    }
    int matched = 0;
    FREP(i,0,scr.size()-1){
        if(scr[i]!=nd[i])return -10000000;
        matched++;
    }
    return matched;
}

int main(){
    int t;
    cin>>t;
    FREP(cs,1,t){
        Trie trie;
        vector<string>ss;
        int n;
        cin>>n;
        FREP(i,1,n){
            string s;cin>>s;
            ss.PB(s);
        }
        string curscreen = "";
        int strokes = 0;
        FREP(i,0,ss.size()-1){
            string req = ss[i];
            int stroke1 = req.size()-screenmatch(curscreen,req)+1;
            int triehas = trie.search(req);
            //cout<<"triehas: "<<triehas<<"\n";
            int stroke2 = (req.size()-triehas)+3;
            //cout<<"from screen "<<stroke1<<" from undo "<<stroke2<<"\n";
            strokes+=min(stroke1,stroke2);
            curscreen = req;
            trie.insert(req);
        }
        printf("Case #%d: %d\n",cs,strokes-2);
    }
    return 0;
}

