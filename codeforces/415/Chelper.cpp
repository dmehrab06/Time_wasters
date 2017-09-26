#include <bits/stdc++.h>

using namespace std;

int cnt[100];
int setarr[100];

void printPowerSet(int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    cout<<pow_set_size<<"\n";
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
            int mxx=0;
            int mnn=1000;
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j)){
            mxx=max(mxx,setarr[j]);
            mnn=min(mnn,setarr[j]);
          }

       }
       //cout<<mxx<<" "<<mnn<<"\n";
       if(mxx>=1 && mxx<=set_size && mnn>=1 && mnn<=set_size){
            cnt[mxx]++;
            cnt[mnn]--;
       }

    }
}

/*Driver program to test printPowerSet*/
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        setarr[i]=i+1;
    }
    printPowerSet(n);
    for(int i=1;i<=n;++i){
        printf("%d ",cnt[i]);
    }
    printf("\n");
    //getchar();
    return 0;
}
