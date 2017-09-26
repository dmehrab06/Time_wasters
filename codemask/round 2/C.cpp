#include <bits/stdc++.h>
int daystillnow[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
char bangmonths[15][50]={"Baishakh", "Jaishtha", "Ashar", "Sraban", "Bhadra", "Ashwin", "Kartik" ,"Agrahayan", "Poush", "Magh", "Falgun", "Chaitra"};


int getday ( int day , int month , int leap_year)
{
  int td;
  td=day+daystillnow[month];
    if(month>2 && leap_year){
        td++;
    }
  return td;
}

int isleap(int year){
   if(   (year%400==0) || (year%100 && year%4==0))return 1;
   return 0;
}

int ldr[14]={0,104,135,166,197,228,259,289,319,349,14,44,74};
int rdr[14]={104,134,165,196,227,258,288,318,348,365,43,73,104};

int main()
{
    int T,cs=1;
    int ed,em,ey;
    int bd,bm,by;
    int lpyear,days;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d",&ed,&em,&ey);

        lpyear=isleap(ey);

        days=getday(ed,em,lpyear);
        if(days<104+lpyear)
                by=ey-594;
            else{
                by=ey-593;}
        if(lpyear==0)
        {

            if(1<=days&&days<=13)
            {
                bd=days+17;
                bm=9;
            }
            else{
                for(int i=1;i<=12;++i){
                    if(ldr[i]<=days && days<=rdr[i]){
                        bd=days-ldr[i]+1;
                        bm=i;
                        break;
                    }
                }
            }

        }

        else

        {
            if(1<=days&&days<=13)
            {
                bd=days+17;
                bm=9;
            }
            for(int i=1;i<=9;++i){
                if(ldr[i]+1<=days && days<=rdr[i]+1){
                    bd=days-(ldr[i]);
                    bm=i;
                    break;
                }
            }

            if(14<=days&&days<=43)
            {
                bd=days-13;
                bm=10;
            }
            else if(44<=days&&days<=74)
            {
                bd=days-43;
                bm=11;
            }
            else if(75<=days&&days<=104)
            {
                bd=days-74;
                bm=12;
            }

        }

        printf("Case %d: %d, %s, %d\n",cs++,bd,bangmonths[bm-1],by);


    }


    return 0;

}
