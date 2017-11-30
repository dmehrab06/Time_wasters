
/*
 * Complete the function below.
 */

#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)


vector<string>curanagrams;

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

    void _anag(vector<int>lettcnt, int l, int need){
        curanagrams.clear();
        //cout<<"cleared\n";
        dfs(lettcnt,"",l,root,need);
    }

    void dfs(vector<int>lettcnt,string curfound,int l, TrieNode *curnode, int need) {
        //cout<<"curstate: \n";
        //FREP(i,0,25)if(lettcnt[i])cout<<i+'a'<<" : "<<lettcnt[i]<<"\n";
        //cout<<"curfound: "<<curfound<<"\n";
        if(curanagrams.size()==need)return;
        if(curfound.size()==l){
            if((curnode->value)){
                curanagrams.PB(curfound);
                return;
            }
        }
        TrieNode *p = curnode;
        FREP(i,0,25){
            if(lettcnt[i]==0)
                continue;
            else{
                if(p->children[i]){
                    lettcnt[i]--;
                    curfound.PB(i+'a');
                    dfs(lettcnt,curfound,l,p->children[i],need);
                    curfound.pop_back();
                    lettcnt[i]++;
                }
            }
        }
    }

private:
    TrieNode* root;
    int count;
};

vector <string> anagram_query(vector <string> intial_words, vector <string> queries) {
    Trie trie;
    FREP(i,0,intial_words.size()-1)trie.insert(intial_words[i]);
    vector<string>ret;
    FREP(i,0,queries.size()-1){
        if(queries[i][0]=='1'){
            //type 1 query
            //get the string
            string ss = "";
            FREP(k,2,queries[i].size()-1){
                ss.PB(queries[i][k]);
            }
            trie.insert(ss);
        }
        else{
            string ss = "";
            int lastidx = 1;
            vector<int>cnt;
            FREP(k,0,25)cnt.PB(0);
            int sz = 0;
            FREP(k,2,queries[i].size()-1){
                lastidx = k;
                if(queries[i][k]==' ')break;
                cnt[queries[i][k]-'a']++;
                sz++;
            }
            int need = 0;
            FREP(k,lastidx+1,queries[i].size()-1){
                need = need*10+(queries[i][k]-'0');
            }
            trie._anag(cnt,sz,need);
            if(curanagrams.size()<need)ret.PB(":-(");
            else{
                string myst="";
                FREP(k,0,need-1){
                    if(k>0)myst.PB(' ');
                    FREP(kk,0,curanagrams[k].size()-1){
                        myst.PB(curanagrams[k][kk]);
                    }
                }
                ret.PB(myst);
            }
        }
    }
    return ret;
}
