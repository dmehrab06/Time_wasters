#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
char vajjo[205];
char *vagfol;
void strconv(long long int a, char* p){
    long long int temp=a;
    int len=0;
    while(temp){
        temp/=10;
        len++;
    }
    p[len]='\0';
    len--;
    temp=a;
    while(len>=0){
        int q;
        q=temp%10;
        char c;
        c=q+48;
        p[len]=c;
        len--;
        temp/=10;
    }
}
void omitvajjo(){
    int l=strlen(vajjo);
    int p=0;
    while(p<l){
        vajjo[p]=vajjo[p+1];
        p++;
    }
}
long long int divide(long long int vajok){
    char *intvajjo;
    int l=strlen(vajjo);
    intvajjo=new char[l+1];
    vagfol=new char[l+1];
    int intvajjopointer=0;
    if(vajjo[0]=='-'){
        omitvajjo();
    }
    int nowpointer=0;
    int vagfolpointer=0;
    long long int intermod;
    int vagfolflag=0;
    while(nowpointer<l){
        intvajjo[intvajjopointer]=vajjo[nowpointer];
        intvajjo[intvajjopointer+1]='\0';
        long long int inter=0;
        int ppp=0;
        int lll=strlen(intvajjo);
        while(ppp<lll){
            inter*=10;
            int p=intvajjo[ppp]-48;
            inter+=p;
            ppp++;
        }
        long long int intervagfol=inter/vajok;
        if(intervagfol){
            vagfolflag=1;
        }
        intermod=(inter)-(intervagfol*vajok);
        char a=intervagfol+48;
        if(vagfolflag){
            vagfol[vagfolpointer]=a;
            vagfolpointer++;
        }
       // if(intermod){
            char *anotherstring;
            anotherstring=new char[l+1];
            strconv(intermod,anotherstring);
            strcpy(intvajjo,anotherstring);
            intvajjopointer=strlen(anotherstring);
            delete[] anotherstring;
      //  }
        nowpointer++;
    }
    delete [] intvajjo;
    vagfol[vagfolpointer]='\0';
    return intermod;
}
int main(){
    int t;
    int tt=1;
    cin>>t;
    while(t--){
        cin>>vajjo;
        long long int vajok;
        cin>>vajok;
        if(vajok<0){
            vajok*=(-1);
        }
        long long int mod=divide(vajok);
        if(mod==0){
            cout<<"Case "<<tt<<": divisible\n";
        }
        else{
            cout<<"Case "<<tt<<": not divisible\n";
        }
        delete[] vagfol;
        tt++;
    }
    return 0;
}
