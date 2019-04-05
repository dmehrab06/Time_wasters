#include <bits/stdc++.h>

using namespace std;

vector< vector<int> >g;

int deg[26];

void init(){
    for(int i = 0;i<26; ++i){
        vector<int>line;
        g.push_back(line);
        deg[i] = 0;
    }
}

vector<string>words;
vector<int>topo;

void makeg(int n){
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            string si = words[i];
            string sj = words[j];
            int l = min((int)si.size(),(int)sj.size());
            int eadded = 0;
            for(int k = 0; k<l; ++k){
                if(si[k]!=sj[k]){
                    int ci = si[k]-'a';
                    int cj = sj[k]-'a';
                    int f = 1;
                    for(int kk = 0; kk<g[ci].size(); ++kk){
                        if(g[ci][kk]==cj){
                            f = 0;
                            break;
                        }
                    }
                    if(f){
                        //cout<<"adding edge "<<ci<<" to "<<cj<<"\n";
                        g[ci].push_back(cj);
                        deg[cj]++;
                    }
                    eadded = 1;
                    break;
                }
            }
            if(!eadded){
                if((int)si.size()>sj.size()){
                    g[1].push_back(2);
                    deg[2]++;
                    g[2].push_back(1);
                    deg[1]++;
                }
            }
        }
    }
}

bool istopo(){
    set< pair<int,int> > node_info;
    for(int i = 0; i<26; ++i){
        node_info.insert(make_pair(deg[i],i));
    }
    int proc = 0;
    while(proc<26){
        pair<int,int>cur = *(node_info.begin());
        node_info.erase(cur);
        if(cur.first>0){
            return false;
        }
        int nd = cur.second;
        topo.push_back(nd);
        proc++;
        for(int k = 0; k<g[nd].size(); ++k){
            int nxt = g[nd][k];
            deg[nxt]--;
            node_info.insert(make_pair(deg[nxt],nxt));
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; ++i){
        string w;
        cin>>w;
        words.push_back(w);
    }
    init();
    makeg(n);
    if(istopo()){
        for(int i = 0; i<26; ++i){
            printf("%c",topo[i]+'a');
        }
        printf("\n");
    }
    else{
        printf("Impossible\n");
    }
    return 0;
}