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
    bool search(string key) {
        TrieNode *p = root;
        int len = key.size();
        for (int i=0;i<len;i++){
            int idx = key[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        if (p->value!=0){
            return true;
        }else{
            return false;
        }
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

    void delete(string s){ //deletes a single instance of that word
        //add korte hobe
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
    Trie trie;
    cout<<trie.search("mykey")<<"\n";
    cout<<trie.insert("mykey")<<"\n";
    cout<<trie.search("mykey")<<"\n";
    cout<<trie.startsWith("myk")<<"\n";
    cout<<trie.startsWith("myey")<<"\n";
    cout<<trie.insert("mykeys")<<"\n";
    cout<<trie.insert("mykey")<<"\n";
    cout<<trie.insert("mykey")<<"\n";
    cout<<trie.insert("mykeys")<<"\n";
    cout<<trie.insert("myeys")<<"\n";
    cout<<trie.startsWith("myey")<<"\n";
    return 0;
}

