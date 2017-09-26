#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cuma[500002];
int cumg[500002];
int cumt[500002];
int cumc[500002];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int l;
    scanf("%d",&l);
    string ACGT;
    cin>>ACGT;
    int need=l/4;
    int a=0,g=0,c=0,t=0;
    for(int i=0;i<l;++i){
        if(ACGT[i]=='A'){
            a++;
        }
        else if(ACGT[i]=='G'){
            g++;
        }
        if(ACGT[i]=='C'){
            c++;
        }
        if(ACGT[i]=='T'){
            t++;
        }
    }
    int tins,tdel,ains,adel,cins,cdel,gins,gdel;
    tins=(need-t);
    if(tins<0)tins=0;
    tdel=t-need;
    if(tdel<0)tdel=0;
    ains=(need-a);
    if(ains<0)ains=0;
    adel=a-need;
    if(adel<0)adel=0;
    cins=(need-c);
    if(cins<0)cins=0;
    cdel=c-need;
    if(cdel<0)cdel=0;
    gins=(need-g);
    if(gins<0)gins=0;
    gdel=g-need;
    if(gdel<0)gdel=0;
    int totins=tins+ains+cins+gins;
    int todel=tdel+adel+cdel+gdel;
    string edited="#";
    edited+=ACGT;
    cuma[0]=0;
    cumg[0]=0;
    cumc[0]=0;
    cumt[0]=0;
    for(int i=1;i<=l;++i){
        if(edited[i]=='A'){
            cuma[i]=cuma[i-1]+1;
        }
        else{
            cuma[i]=cuma[i-1];
        }
        if(edited[i]=='G'){
            cumg[i]=cumg[i-1]+1;
        }
        else{
            cumg[i]=cumg[i-1];
        }
        if(edited[i]=='C'){
            cumc[i]=cumc[i-1]+1;
        }
        else{
            cumc[i]=cumc[i-1];
        }
        if(edited[i]=='T'){
            cumt[i]=cumt[i-1]+1;
        }
        else{
            cumt[i]=cumt[i-1];
        }
    }
    int ln=l+9;
    int i=1;
    int j=i;
    printf("asi\n");
    for(;i<=j && i<=l;){
        //int j=i;
        printf("%d %d\n",i,j);
        while(j<=l){
            int hasa=cuma[j]-cuma[i-1];
            int hasc=cumc[j]-cumc[i-1];
            int hasg=cumg[j]-cumg[i-1];
            int hast=cumt[j]-cumt[i-1];
            if(hasa>=adel && hast>=tdel && hasc>=cdel && hasg>=gdel){
                if((j-i+1)<ln){
                    ln=j-i+1;
                    break;
                }
            }
            j++;

        }
        while(i<=l){
            i++;
            int hasa=cuma[j]-cuma[i-1];
            int hasc=cumc[j]-cumc[i-1];
            int hasg=cumg[j]-cumg[i-1];
            int hast=cumt[j]-cumt[i-1];
            if(!(hasa>=adel && hast>=tdel && hasc>=cdel && hasg>=gdel)){
                break;
            }
            else{
                if((j-i+1)<ln){
                    ln=j-i+1;
                }
            }

        }
    }
    printf("%d\n",ln);
    return 0;
}
