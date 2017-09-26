#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

struct Node{
    char name;
    int degree;
    Node(){
        name='#';
        degree=0;
    }
    Node(char a , int b){
        name=a;
        degree=b;
    }
    void incdeg(){
        degree++;
    }
    char getname(){
        return name;
    }
};

class MyStack{
    public:
    Node thestack[1005];
    int tp=0;
    MyStack(){
        thestack[tp]=Node('$',-1);
        tp++;
    }
    void push(Node n){
        thestack[tp]=n;
        tp++;
    }
    void pop(){
        if(tp>0)tp--;
    }
    Node top(){
        return thestack[tp-1];
    }
};

int main(){
    int t;
    scanf("%d",&t);
    char str[69];
    int deg[26];
    int cs=1;
    while(t--){

        for(int i=0;i<26;++i){
            deg[i]=0;
        }
        scanf("%s",str);
        int l=strlen(str);
        //str[l]='$';
       // str[l+1]='\0';
        //l++;
        MyStack ms;
        for(int i=0;i<l;++i){
            char cur=str[i];
            if(cur==ms.top().name){
                deg[cur-'A']=ms.top().degree;
                ms.pop();
            }
            else{
                Node par=ms.top();
                ms.pop();
                char parname=par.name;
                par.incdeg();
                ms.push(par);
                if(parname=='$'){
                    Node a(cur,0);
                    ms.push(a);
                }
                else{
                    Node a(cur,1);
                    ms.push(a);
                }
            }
        }
        printf("Case %d\n",cs++);
        for(int i=0;i<26;++i){
            if(deg[i]>0){
                printf("%c = %d\n",i+'A',deg[i]);
            }
        }
    }
    return 0;
}

//(a.x−c.x)*(b.y−a.y)−(a.x−b.x)*(c.y−a.y)
