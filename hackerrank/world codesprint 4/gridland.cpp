#include <bits/stdc++.h>
#define MDD 100003
using namespace std;

int letterhashes[26]={2,7,3,5,13,61,17,53,107,19,23,29,41,93,71,11,37,31,101,59,97,47,81,83,103,73};

char totest1[2411]; //1 theke shuru hoise
char totest2[2411]; //1 theke shuru hoise

vector < vector <int> >hashtable;
char first[603];
char second[603];

void init(int N){
        totest1[0]=' ';
        totest2[0]=' ';
        int len1=1;
        for(int i=0;i<N;++i){
            totest1[len1]=first[i];
            len1++;
        }
        for(int i=N-1;i>=0;--i){
            totest1[len1]=second[i];
            len1++;
        }
        for(int i=0;i<N;++i){
            totest1[len1]=first[i];
            len1++;
        }
        for(int i=N-1;i>0;--i){
            totest1[len1]=second[i];
            len1++;
        }
        totest1[len1]='\0';
        int len2=1;
        for(int i=0;i<N;++i){
            totest2[len2]=second[i];
            len2++;
        }
        for(int i=N-1;i>=0;--i){
            totest2[len2]=first[i];
            len2++;
        }
        for(int i=0;i<N;++i){
            totest2[len2]=second[i];
            len2++;
        }
        for(int i=N-1;i>0;--i){
            totest2[len2]=first[i];
            len2++;
        }
        totest2[len2]='\0';
}

bool brutecompare(int idx1, int idx2, int l){
    if(idx1>0 && idx2>0){
        for(int i=0;i<l;++i){
            if(totest1[idx1+i]!=totest1[idx2+i]){
                return false;
            }
        }
        return true;
    }
    else if(idx1>0 && idx2<0){
        idx2=idx2*(-1);
        for(int i=0;i<l;++i){
            if(totest1[idx1+i]!=totest2[idx2+i]){
                return false;
            }
        }
        return true;
    }
    else{
        idx1=idx1*(-1);
        idx2=idx2*(-1);
        for(int i=0;i<l;++i){
            if(totest2[idx1+i]!=totest2[idx2+i]){
                return false;
            }
        }
        return true;
    }
}

int poww10[10005];
void powinit(){
    poww10[0]=1;
    for(int i=0;i<10005;++i){
        poww10[i]=poww10[i-1]*2;
        poww10[i]%=MDD;
    }
}
int main(){
    int P;
    cin>>P;
    powinit();
    while(P--){
        int N;
        int ANS=0;
        scanf("%d",&N);
        int len=(N<<1);
        scanf("%s %s",first,second);
        init(N);
        printf("%s %s",totest1,totest2);
        vector<int>line;
        for(int i=0;i<=(MDD+2);++i){
            hashtable.push_back(line);
            hashtable[i].push_back(0);
        }
        cout<<"in hash1\n";
        int hash1init=0;
        int ll1=(N<<2)-1;
        for(int i=1;i<=(len);++i){
            hash1init=hash1init*2+letterhashes[totest1[i]-'a'];
            hash1init%=MDD;
        }
        int MM=len-1;
        hashtable[hash1init][0]++;
        hashtable[hash1init].push_back(1);
        ANS++;
        int prevmsb=letterhashes[totest1[1]-'a'];
        int fp1=2;
        int bp1=len+1;
        while(bp1<=ll1){
            int from=poww10[MM]*prevmsb;
            hash1init=hash1init-from;
            if(hash1init<0){
                hash1init+=MDD;
            }
            hash1init%=MDD;
            hash1init=hash1init*2+letterhashes[totest1[bp1]-'a'];
            prevmsb=letterhashes[totest1[fp1]-'a'];
            hash1init%=MDD;
            if(hashtable[hash1init][0]==0){
                hashtable[hash1init][0]++;
                hashtable[hash1init].push_back(fp1);
                ANS++;
            }
            else{
                int l=hashtable[hash1init][0];
                int found=0;
                for(int i=1;i<=l;++i){
                    if(brutecompare(hashtable[hash1init][i],fp1,len)){
                        found=1;
                        break;
                    }
                }
                if(found){

                }
                else{
                    hashtable[hash1init][0]++;
                    hashtable[hash1init].push_back(fp1);
                    ANS++;
                }
            }
            fp1++;
            bp1++;

        }
        int hash2init=0;
        int ll2=(N<<2)-1;
        for(int i=1;i<=(len);++i){
            hash2init=hash2init*2+letterhashes[totest2[i]-'a'];
            hash2init%=MDD;
        }
        //int MM=len-1;
        if(hashtable[hash2init][0]==0){
            hashtable[hash2init][0]++;
            hashtable[hash2init].push_back(-1);
            ANS++;
        }
        else{
            int l=hashtable[hash2init][0];
            int found=0;
            for(int i=1;i<=l;++i){
                if(brutecompare(hashtable[hash2init][i],-1,len)){
                    found=1;
                    break;
                }
            }
            if(found){

            }
            else{
                hashtable[hash2init][0]++;
                hashtable[hash2init].push_back(-1);
                ANS++;
            }
        }
        prevmsb=letterhashes[totest2[1]-'a'];
        int fp2=2;
        int bp2=len+1;
        while(bp2<=ll2){
            int from=poww10[MM]*prevmsb;
            hash2init=hash2init-from;
            if(hash2init<0){
                hash2init+=MDD;
            }
            hash2init%=MDD;
            hash2init=hash2init*2+letterhashes[totest2[bp2]-'a'];
            hash2init%=MDD;
            prevmsb=letterhashes[totest2[fp2]-'a'];
            if(hashtable[hash2init][0]==0){
                hashtable[hash2init][0]++;
                hashtable[hash2init].push_back(-fp2);
                ANS++;
            }
            else{
                int l=hashtable[hash2init][0];
                int found=0;
                for(int i=1;i<=l;++i){
                    if(brutecompare(hashtable[hash2init][i],-fp2,len)){
                        found=1;
                        break;
                    }
                }
                if(found){

                }
                else{
                    hashtable[hash2init][0]++;
                    hashtable[hash2init].push_back(-fp2);
                    ANS++;
                }
            }
            fp2++;
            bp2++;

        }
        printf("%d\n",ANS);
        hashtable.clear();
    }
}
